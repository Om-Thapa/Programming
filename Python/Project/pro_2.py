# 1. Print star pattern for any odd n
def print_star_pattern(n):
    """
    For an odd integer n, prints a pattern like:
    For n = 3:
         *
        * *
         *
    For n = 5:
          *
         * *
        *   *
         * *
          *
    """
    if n % 2 == 0:
        print("n must be an odd number")
        return

    center = n // 2
    for i in range(n):
        pad = abs(i - center)
        # Calculate inner spacing: if negative, we print just one star
        inner = n - 2 * (pad + 1)
        # Print left padding
        print(" " * pad, end="")
        if inner < 0:
            # For the top and bottom row, only one star is printed.
            print("*")
        else:
            # Print two stars separated by inner spaces.
            print("" + " " * inner + "")


# 2. Transform string so that every n-th character is uppercase
def transform_string(s, n):
    """
    Given a string s and an integer n, returns a string where every n-th character
    (based on 1-indexing) is uppercase and the rest are lowercase.
    Edge cases: if n <= 0 or n > len(s), returns an error message.
    
    Example:
      s = "python", n = 2  => "pYtHoN"
    """
    if n <= 0 or n > len(s):
        return "Invalid input: n must be between 1 and the length of the string."
    
    s_lower = s.lower()
    result = ""
    for i, ch in enumerate(s_lower):
        # (i+1) is the 1-indexed position
        if (i + 1) % n == 0:
            result += ch.upper()
        else:
            result += ch
    return result


# 3. Bitwise operation program without eval or operator module
def bitwise_operation(a, b, op):
    """
    Takes two integers (a and b) and a string operator (op) which can be one of:
    '&', '|', '^', '<<', '>>'. Returns the result of the operation.
    If the operator is invalid, returns an error message.
    """
    if op == "&":
        return a & b
    elif op == "|":
        return a | b
    elif op == "^":
        return a ^ b
    elif op == "<<":
        return a << b
    elif op == ">>":
        return a >> b
    else:
        return "Invalid operator"


# 4. Print number pattern using only loops and conditionals
def print_number_pattern(n):
    """
    For any odd positive integer n, prints a pattern of sequential numbers:
    For n = 3:
       1
       2 3
       4 5 6
    Constraint: Only loops and conditional statements are used.
    """
    if n <= 0 or n % 2 == 0:
        print("n must be a positive odd number")
        return

    count = 1
    for i in range(n):
        # For row i, print (i+1) numbers.
        for j in range(i + 1):
            # Print each number followed by a space without using string multiplication or join.
            print(count, end=" ")
            count += 1
        print()  # Newline after each row


# 5. Check if a string is a palindrome using only slicing.
def is_palindrome(s):
    """
    Returns True if the string s is a palindrome.
    The function ignores spaces and is case-insensitive.
    
    Example:
      Input: "A man a plan a canal Panama"
      Output: True
    """
    normalized = s.replace(" ", "").lower()
    return normalized == normalized[::-1]


# Testing the functions
if _name_ == "_main_":
    print("Star pattern for n = 3:")
    print_star_pattern(3)
    print("\nStar pattern for n = 5:")
    print_star_pattern(5)

    print("\nTransformed string for s = 'python', n = 2:")
    print(transform_string("python", 2))

    print("\nBitwise operations:")
    a, b = 5, 3
    for op in ["&", "|", "^", "<<", ">>", "invalid"]:
        print(f"{a} {op} {b} = {bitwise_operation(a, b, op)}")

    print("\nNumber pattern for n = 3:")
    print_number_pattern(3)

    test_string = "A man a plan a canal Panama"
    print(f"\nIs the string '{test_string}' a palindrome?")
    print(is_palindrome(test_string))