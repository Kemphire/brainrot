def swap_first_n(str1, str2, n):
    if n > min(len(str1), len(str2)):
        return "Error: 'n' is larger than the length of one or both strings."
    return str2[:n] + str1[n:], str1[:n] + str2[n:]

str1 = input("Enter the first string: ")
str2 = input("Enter the second string: ")
n = int(input("Enter the number of characters to swap: "))
result = swap_first_n(str1, str2, n)
print("Swapped strings:", result)
