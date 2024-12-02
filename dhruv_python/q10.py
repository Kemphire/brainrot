def find_occurrences(string, substring):
    indices = []
    index = string.find(substring)
    while index != -1:
        indices.append(index)
        index = string.find(substring, index + 1)
    return indices if indices else -1

string = input("Enter the main string: ")
substring = input("Enter the substring to find: ")
result = find_occurrences(string, substring)
if result == -1:
    print(f"'{substring}' is not present in '{string}'.")
else:
    print(f"Indices of occurrences: {result}")
