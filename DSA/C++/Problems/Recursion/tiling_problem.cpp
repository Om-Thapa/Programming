// Given a "2 x n" board and tiles of size "2 x 1", the task is to count the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. 

int tilingProblem(int n){
    if(n==0 || n==1){
        return 1;
    }
    return tilingProblem(n-1) + tilingProblem(n-2); // 2x1 tile can be placed horizontally or vertically
}