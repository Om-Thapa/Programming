import os
import random
import shutil
import pickle as pkl
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
from tqdm import tqdm
from nltk.translate.bleu_score import corpus_bleu, SmoothingFunction
from torch.utils.data import Dataset
import transformers
from transformers import (
    BertTokenizer,
    BertForMaskedLM,
    GPT2Tokenizer,
    GPT2LMHeadModel,
    get_linear_schedule_with_warmup
)
# from pycocoevalcap.cider.cider_scorer import CiderScorer
# rs = RS()
smoothing_function = SmoothingFunction().method1

max_length = {'RSICD':36,'UCM':24,'SYDNEY':22}

def set_seed(seed):
    torch.manual_seed(seed)
    torch.cuda.manual_seed(seed)
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = False

# Set the seed value
seed = 77777
set_seed(seed)

def remove_punctuation(word):
    import string
    # Using str.maketrans() to create a translation table
    translator = str.maketrans("", "", string.punctuation)
    # Using translate() to remove punctuations from the word
    word_without_punctuation = word.translate(translator)
    return word_without_punctuation


class split_model:
    def __init__(self,vocab,tokenizer,max_length):
        import torch
        self.vocab = vocab
        self.tokenizer = tokenizer
        self.max_length = max_length
    def __call__(self):
        inputx = []
        outputx = []
        for sentence in self.vocab:
            temp = [remove_punctuation(i) for i in sentence.split()]
            for i in range(1,len(temp)):
                inp,out = temp[:i],temp[i]
                inputx.append(self.tokenizer(' '.join(inp), truncation=True, padding='max_length', max_length=self.max_length, return_tensors='pt'))
                outputx.append([self.tokenizer(out, return_tensors='pt')['input_ids'].item()]*self.max_length)
        return inputx,outputx

class vocabulary:
    def __init__(self,corpus):
        self.corpus = ' '.join(corpus)
    def __call__(self):
        return list(set(self.corpus.split()))
    
# Tokenize and prepare data
class CustomDataset(Dataset):
    def __init__(self, texts, labels):
        self.texts = texts
        self.labels = labels

    def __len__(self):
        return len(self.texts)

    def __getitem__(self, idx):
        import torch
        text = self.texts[idx]
        label = self.labels[idx]
        input_ids = text['input_ids'].squeeze()
        attention_mask = text['attention_mask'].squeeze()

        return {'input_ids': input_ids, 'attention_mask': attention_mask, 'labels': torch.tensor(label)}



class Data_processing:
    
    @staticmethod
    def Make_corpus_by_sliding_windows(sentences, window_size):
        output = []
        for sentence in sentences:
            if len(sentence)<window_size:
                output.append(sentence)
            else:
                for i in range(len(sentence) - window_size + 1):
                    sub_list = sentence[i:i+window_size]
                    output.append(sub_list)
        return output
    
    @staticmethod
    def Indexing_of_sentences(corpus,index,window_size):
        return Data_processing.Make_corpus_by_sliding_windows([[index[word] for word in sentence.split()] for sentence in corpus], window_size)
    
    @staticmethod
    def Load_matrix(path,include_top):
        import numpy as np
        np.set_printoptions(suppress=True)
        metrices = []
        for ele in path:
            if type(ele)==str and ele.endswith('.npy'):
                matrix = np.load(ele,allow_pickle=True)
            else:
                ele = np.array(ele)
                if ele.ndim==1:
                    ele = ele.reshape(1,-1)
                matrix = ele
            metrices.append(matrix)
        metrices = np.concatenate(metrices,axis=1,dtype=np.float64)
        if include_top==False:
            metrices = metrices[1:]
        return metrices
    
    @staticmethod
    def Ordinal_indicator(n):
        if n % 100 in {11, 12, 13}:
            return str(n) + "th"
        elif n % 10 == 1:
            return str(n) + "st"
        elif n % 10 == 2:
            return str(n) + "nd"
        elif n % 10 == 3:
            return str(n) + "rd"
        else:
            return str(n) + "th"

    @staticmethod
    def Euclidian_distance(A,B,length=None):
        import numpy as np
        A = np.array(A)
        B = np.array(B)
        if length:
            return round(np.linalg.norm(A-B),length)
        else:
            return np.linalg.norm(A-B)
    
    @staticmethod
    def Absolute_matrix(corpus,vocab_size):
        import numpy as np
        metrices = np.zeros([vocab_size])
        for corpa in corpus:
            for ele in corpa:
                metrices[ele] += 1
        return metrices
    
    @staticmethod
    def Bigram_count(corpus):
        bg = {}
        for i in corpus:
            for j in range(len(i)):
                for k in range(j+1):
                    if ((i[k],i[j])) not in bg.keys():
                        bg[(i[k],i[j])] = 1
                    else:
                        bg[(i[k],i[j])] += 1
        return bg
    
    @staticmethod
    def Pair_matrix(corpus,vocab_size):
        from numpy import zeros,identity
        pair = zeros([vocab_size,vocab_size])
        bigram = Data_processing.Bigram_count(corpus)
        for bg in bigram.keys():
            (p,q) = bg
            pair[p,q] = bigram[bg]
            pair[q,p] = bigram[bg]
        return pair

    @staticmethod
    def Adjacency_matrix_by_pretrained_features(metrices):
        import numpy as np
        shape = metrices.shape[0]
        adjacency = np.zeros((shape,shape))
        for rows in range(shape):
            for columns in range(rows):
                dist = Data_processing.Euclidian_distance(metrices[rows], metrices[columns])
                adjacency[rows][columns] = dist
                adjacency[columns][rows] = dist
            adjacency[rows][rows] = 1
        return adjacency
    
    @staticmethod
    def Adjacency_matrix_by_PMI(abs_mat,pair_mat,vocab_size,corpus_len):
        from numpy import zeros,log2
        pmi = zeros((vocab_size,vocab_size))
        for i in range(1,vocab_size):
            for j in range(1,vocab_size):
                if i==j:
                    pmi[i,j] = 1
                else:
                    if abs_mat[i]!=0 and abs_mat[j]!=0:
                        pmi[i,j] = (pair_mat[i,j]*corpus_len)/(abs_mat[i]*abs_mat[j])
                        if pmi[i,j]<= 10e-6:
                            pmi[i,j] = 10e-6
                        pmi[i,j] = log2(pmi[i,j])
                        if pmi[i,j] <0:
                            pmi[i,j] = 0
        return pmi
    
    @staticmethod
    def Degree_matrix(corpus,vocab_size):
        import numpy as np
        pair = Data_processing.Pair_matrix(corpus,vocab_size)
        degree_matrix = np.diag(np.count_nonzero(pair, axis=1))
        return degree_matrix
    
    @staticmethod
    def DAD_matrix(adj_mat,deg_mat):
        import numpy as np
        diagonal = deg_mat.diagonal()
        diagonal = np.where(diagonal==0,np.inf,diagonal)
        deg_half_mat = np.diag(diagonal**-0.5)
        return deg_half_mat.dot(adj_mat).dot(deg_half_mat)
    
    @staticmethod
    def Initinal_feature_matrix_by_identity(vocab_size):
        import numpy as np
        return np.eye(vocab_size)
    
    @staticmethod
    def Initinal_feature_matrix_by_summation(adj_mat,count_only=True,normalize=True):
        import numpy as np
        temp = np.count_nonzero(adj_mat,axis=1).reshape(-1) if count_only else np.sum(adj_mat,axis=1).reshape(-1)
        temp = np.diag(temp)
        return temp/temp.max() if normalize else temp
        
    @staticmethod
    def Initinal_feature_matrix_by_embeddings(adj_mat,embedding_size=256):
        import torch
        if isinstance(adj_mat, int):
            layer = torch.nn.Embedding(adj_mat, embedding_size)
            candidates = torch.arange(adj_mat,dtype=torch.int32)
            embeddings = layer(candidates)
            return embeddings.detach().numpy()
        elif hasattr(adj_mat, '__iter__'):
            adj_mat = torch.tensor(adj_mat,dtype=torch.int32)
            summe = adj_mat.sum(axis=1)
            max_ele = summe.max().item()
            layer = torch.nn.Embedding(max_ele + 1, embedding_size)
            feature = layer(summe)
            return feature.detach().numpy()
    @staticmethod
    def Initinal_feature_matrix_by_embeddings_summation(adj_mat_sum,adj_mat_emb=None,embedding_size=256,count_only=True,normalize=True):
        if adj_mat_emb==None:
            adj_mat_emb = adj_mat_sum
        F1 = Data_processing.Initinal_feature_matrix_by_summation(adj_mat_sum,count_only,normalize)
        F2 = Data_processing.Initinal_feature_matrix_by_embeddings(adj_mat_emb,embedding_size)
        return F1.dot(F2)
    @staticmethod
    def Initialize_weights_he(size,const=1,div_factor=1,normalized=False):
        import numpy as np
        if normalized:
            he_limit = np.sqrt(div_factor / (size[0]))
            weights = np.random.uniform(low=-he_limit, high=he_limit, size=size)
        else:
            stddev = np.sqrt(div_factor / size[0])
            weights = np.random.normal(loc=0.0, scale=stddev, size=size)
        return const*weights
    
    @staticmethod
    def Initialize_weights_xavier(size,const=1,div_factor=1,normalized=False):
        import numpy as np
        if normalized:
            xavier_limit = np.sqrt(div_factor / (sum(size)))
            weights = np.random.uniform(low=-xavier_limit, high=xavier_limit, size=size)
        else:
            stddev = np.sqrt(div_factor / (size[0]+size[1]))
            weights = np.random.normal(loc=0.0, scale=stddev, size=size)
        return const*weights
    
    @staticmethod
    def Gaussian_normalization(matrix,axis=None,const=1):
        import numpy as np
        matrix = np.array(matrix)
        mean = np.mean(matrix,axis=axis,keepdims=True)
        std = np.std(matrix,axis=axis,keepdims=True)
        std[std==0]=1
        return const*(matrix-mean)/std
    
    @staticmethod
    def Devide_by_max(matrix,axis=None):
        import numpy as np
        div_fact = np.max(np.abs(matrix),axis=axis,keepdims=True)
        div_fact[div_fact==0] = 1
        return np.array(matrix)/div_fact
    
    @staticmethod
    def Devide_by_maxmin(matrix,axis=None):
        import numpy as np
        div_fact = (0.5*(np.max(matrix,axis=axis,keepdims=True)+np.min(matrix,axis=axis,keepdims=True)))
        div_fact[div_fact==0] = 1
        return np.array(matrix)/div_fact
    
    @staticmethod
    def Devide_by_log_shape(matrix,axis=0,base=2):
        import numpy as np
        div_fact = np.log(np.shape(matrix)[axis])/np.log(base)
        return np.array(matrix)/div_fact
    
    @staticmethod
    def ReLU(matrix):
        import numpy as np
        temp = np.array(matrix)
        temp[temp<0]=0
        return temp
    
    @staticmethod
    def SoftMax(matrix,axis=1):
        import numpy as np
        max_vals = np.max(matrix, axis=axis, keepdims=True)
        exp_x = np.exp(matrix - max_vals)
        # Calculate softmax along the specified axis
        sum_exp_x = np.sum(exp_x, axis=axis, keepdims=True)
        softmax_values = exp_x / sum_exp_x
        return softmax_values
    
    @staticmethod
    def Sigmoid(matrix):
        import numpy as np
        return 1/(1+np.exp(-matrix))
    
    
class FastText:
    def __init__(self, embedding_size=256, windows_size=5, min_count=0):
        from gensim.models import FastText
        self.model = FastText(vector_size=embedding_size, window=windows_size, min_count=min_count)
        self.embedding_size = embedding_size

    def __call__(self, sentences):
        import numpy as np
        embedding_matrix = np.zeros((1,self.embedding_size),dtype=np.float64)
        lines = []
        words = set()
        for line in sentences:
            lines.append(line.split())
            words.update(line.split())
        self.model.build_vocab(lines)
        self.model.train(lines, total_examples=self.model.corpus_count, epochs=16)
        for word in words:
            embedding_matrix = np.concatenate((embedding_matrix, self.model.wv[word].reshape(1,-1)), axis=0)
        return embedding_matrix
    
class Glove:
    def __init__(self, embedding_size=256, learning_rate=0.05, window=5, threads = 4):
        self.embedding_size = embedding_size
        self.learning_rate = learning_rate
        self.window = window
        self.threads = threads

    def __call__(self, sentences):
        from glove import Glove, Corpus
        import numpy as np
        corpus_model = Corpus()
        lines = []
        words = []
        for line in sentences:
            lines.append(line.split())
            words.update(line.split())
        corpus_model.fit(lines, window=self.window)
        glove_model = Glove(no_components=self.embedding_size, learning_rate=self.learning_rate, max_count=16)
        glove_model.fit(corpus_model.matrix, epochs=16, no_threads=self.threads)
        glove_model.add_dictionary(corpus_model.dictionary)

        # Retrieve word vectors (note: adding a zero vector for the first row)
        word_vectors = [glove_model.word_vectors[glove_model.dictionary[word]] for word in words]
        word_vectors.insert(0, np.zeros(self.embedding_size))
        embedding_matrix = np.array(word_vectors)
        return embedding_matrix
    
class WordtoVec:
    def __init__(self, embedding_size=256, windows_size=5, min_count=0):
        from gensim.models import Word2Vec
        self.model = Word2Vec(vector_size=embedding_size, window=windows_size, min_count=min_count)
        self.embedding_size = embedding_size

    def __call__(self, sentences):
        import numpy as np
        embedding_matrix = np.zeros((1,self.embedding_size),dtype=np.float64)
        lines=[]
        words=set()
        for line in sentences:
            lines.append(line.split())
            words.update(line.split())
        self.model.build_vocab(lines)
        self.model.train(lines, total_examples=self.model.corpus_count, epochs=16)
        for word in words:
            embedding_matrix = np.concatenate((embedding_matrix, self.model.wv[word].reshape(1,-1)), axis=0)
        return embedding_matrix    

class CustomDataset(Dataset):
    def __init__(self, texts, tokenizer, max_length):
        self.texts = texts
        self.tokenizer = tokenizer
        self.max_length = max_length

    def __len__(self):
        return len(self.texts)

    def __getitem__(self, idx):
        encoded = self.tokenizer(
            self.texts[idx],
            truncation=True,
            padding="max_length",
            max_length=self.max_length,
            return_tensors="pt",
            add_special_tokens=False
        )
        labels = encoded["input_ids"].clone()
        return {
            "input_ids": encoded["input_ids"].squeeze(0),
            "attention_mask": encoded["attention_mask"].squeeze(0),
            "labels": labels.squeeze(0),
        }


class BERT:
    def __init__(self, embedding_size=None, learning_rate=0.05, batch_size=64, epochs=16):
        self.embedding_size = embedding_size
        self.lr = learning_rate
        self.batch_size = batch_size
        self.epochs = epochs

    @staticmethod
    def create_index(sentences):
        """Create a unique word list (no regex)."""
        vocab = set()
        for sent in sentences:
            for token in sent.split():
                token = "".join(ch for ch in token if ch.isalnum())
                if token:
                    vocab.add(token.lower())
        return sorted(vocab)

    @staticmethod
    def get_max_length(sentences):
        """Compute safe max length = longest sentence tokens + 5."""
        max_tokens = max(len(s.split()) for s in sentences)
        return max_tokens + 5

    def __call__(self, sentences):
        # --- tokenizer setup ---
        indexes = self.create_index(sentences)
        tokenizer = BertTokenizer.from_pretrained("bert-base-uncased")
        if tokenizer.pad_token is None:
            tokenizer.add_special_tokens({'pad_token': tokenizer.eos_token})
        added = tokenizer.add_tokens([w for w in indexes if w not in tokenizer.vocab])

        # --- model setup ---
        model = BertForMaskedLM.from_pretrained("bert-base-uncased")
        if added > 0:
            model.resize_token_embeddings(len(tokenizer))

        # --- get max_length automatically ---
        max_length = self.get_max_length(sentences)

        # --- dataset & dataloader ---
        train_data = CustomDataset(sentences, tokenizer, max_length)
        train_dataloader = DataLoader(train_data, batch_size=self.batch_size, shuffle=True)

        device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        model.to(device)
        optimizer = torch.optim.AdamW(model.parameters(), lr=self.lr)
        scheduler = get_linear_schedule_with_warmup(
            optimizer, 0, len(train_dataloader)
        )

        model.train()
        for epoch in range(self.epochs):
            for batch in train_dataloader:
                inputs = batch["input_ids"].to(device)
                mask = batch["attention_mask"].to(device)
                labels = batch["labels"].to(device)
                loss = model(inputs, attention_mask=mask, labels=labels).loss
                loss.backward()
                torch.nn.utils.clip_grad_norm_(model.parameters(), 3)
                optimizer.step()
                scheduler.step()
                optimizer.zero_grad()

        # --- embeddings ---
        model.eval()
        embeddings = []
        with torch.no_grad():
            for word in indexes:
                toks = tokenizer(word, return_tensors="pt", add_special_tokens=False)
                toks = {k: v.to(device) for k, v in toks.items()}
                feat = model.bert(**toks).last_hidden_state.squeeze(0)
                if self.embedding_size:
                    layer = torch.nn.Linear(feat.shape[-1], self.embedding_size).to(device)
                    feat = layer(feat)
                embeddings.append(feat.mean(dim=0).cpu().numpy())

        embeddings = np.vstack([[np.zeros_like(embeddings[0])], embeddings])
        return embeddings

class GPT2:
    def __init__(self, embedding_size=None, learning_rate=0.05, batch_size=64, epochs=16):
        self.embedding_size = embedding_size
        self.lr = learning_rate
        self.batch_size = batch_size
        self.epochs = epochs

    @staticmethod
    def create_index(sentences):
        """Create a unique token index (no regex)."""
        vocab = set()
        for sent in sentences:
            for token in sent.split():
                token = "".join(ch for ch in token if ch.isalnum())
                if token:
                    vocab.add(token.lower())
        return sorted(vocab)

    @staticmethod
    def get_max_length(sentences):
        """Compute safe max length = longest sentence tokens + 5."""
        max_tokens = max(len(s.split()) for s in sentences)
        return max_tokens + 5

    def __call__(self, sentences):
        # --- tokenizer setup ---
        transformers.logging.set_verbosity_error()
        indexes = self.create_index(sentences)
        tokenizer = GPT2Tokenizer.from_pretrained("gpt2")
        if tokenizer.pad_token is None:
            tokenizer.add_special_tokens({'pad_token': tokenizer.eos_token})
        # add missing words to tokenizer
        base_vocab = tokenizer.get_vocab()
        added = tokenizer.add_tokens([w for w in indexes if w not in base_vocab])

        # --- model setup ---
        model = GPT2LMHeadModel.from_pretrained("gpt2")
        if added > 0:
            model.resize_token_embeddings(len(tokenizer))

        # --- automatic max_length ---
        max_length = self.get_max_length(sentences)

        # --- dataset & dataloader ---
        train_data = CustomDataset(sentences, tokenizer, max_length)
        train_dataloader = DataLoader(train_data, batch_size=self.batch_size, shuffle=True)

        device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        model.to(device)
        optimizer = torch.optim.AdamW(model.parameters(), lr=self.lr)
        scheduler = get_linear_schedule_with_warmup(
            optimizer, 0, len(train_dataloader)
        )

        model.train()
        for epoch in range(self.epochs):
            for batch in train_dataloader:
                inputs = batch["input_ids"].to(device)
                mask = batch["attention_mask"].to(device)
                labels = batch["labels"].to(device)
                loss = model(inputs, attention_mask=mask, labels=labels).loss
                loss.backward()
                torch.nn.utils.clip_grad_norm_(model.parameters(), 3)
                optimizer.step()
                scheduler.step()
                optimizer.zero_grad()

        # --- extract embeddings ---
        model.eval()
        embeddings = []
        with torch.no_grad():
            for word in indexes:
                toks = tokenizer(word, return_tensors="pt")
                toks = {k: v.to(device) for k, v in toks.items()}
                feature = model.transformer(**toks).last_hidden_state.squeeze(0)
                if self.embedding_size:
                    layer = torch.nn.Linear(feature.shape[-1], self.embedding_size).to(device)
                    feature = layer(feature)
                embeddings.append(feature.mean(dim=0).cpu().numpy())

        embeddings = np.vstack([[np.zeros_like(embeddings[0])], embeddings])
        return embeddings
    
class TextGCN:
    def __init__(self, embedding_size=256, windows_size=5):
        self.embedding_size = embedding_size
        self.windows_size = windows_size
        self.process = Data_processing()

    @staticmethod
    def create_index(sentences):
        """Create a dictionary mapping each unique word to an index (1-based)."""
        vocab = set()
        for sent in sentences:
            for token in sent.split():
                token = "".join(ch for ch in token if ch.isalnum())
                if token:
                    vocab.add(token.lower())
        return {word: i + 1 for i, word in enumerate(sorted(vocab))}

    def __call__(self, sentences):
        import numpy as np

        # --- Create word-to-index mapping ---
        indexes = self.create_index(sentences)

        # --- Proceed with TextGCN pipeline ---
        corpus = self.process.Indexing_of_sentences(sentences, indexes, self.windows_size)
        vocab_size = len(indexes) + 1

        abs_mat = self.process.Absolute_matrix(corpus, vocab_size)
        pair_mat = self.process.Pair_matrix(corpus, vocab_size)
        adj_mat = self.process.Adjacency_matrix_by_PMI(abs_mat, pair_mat, vocab_size, len(corpus))
        deg_mat = self.process.Degree_matrix(corpus, vocab_size)
        DAD_mat = self.process.DAD_matrix(adj_mat, deg_mat)

        # --- Feature propagation (2-layer GCN) ---
        F = self.process.Initinal_feature_matrix_by_embeddings(adj_mat, embedding_size=self.embedding_size)
        W = self.process.Initialize_weights_xavier(
            [F.shape[1], self.embedding_size], div_factor=vocab_size, const=1, normalized=True
        )
        F = DAD_mat.dot(F).dot(W)
        F = self.process.Sigmoid(F)
        F = self.process.Gaussian_normalization(F, axis=1)

        W = self.process.Initialize_weights_xavier(
            [F.shape[1], self.embedding_size], div_factor=vocab_size, const=1, normalized=True
        )
        F = DAD_mat.dot(F).dot(W)
        F = self.process.Sigmoid(F)
        F = self.process.Gaussian_normalization(F, axis=1)
        F = self.process.Devide_by_max(F, axis=1)

        return F
        
embedding_models = {
    "word2vec": WordtoVec,
    "fasttext": FastText,
    "glove": Glove,
    "bert": BERT,
    "gpt2": GPT2,
    "textgcn": TextGCN,
}
