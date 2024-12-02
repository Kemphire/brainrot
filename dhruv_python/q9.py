import string

def file_operations(file_path):
    try:
        with open(file_path, 'r') as file:
            content = file.read()
            lines = content.splitlines()

            num_chars = len(content)
            num_words = len(content.split())
            num_lines = len(lines)
            
            print(f"Total characters: {num_chars}")
            print(f"Total words: {num_words}")
            print(f"Total lines: {num_lines}")

            char_frequency = {}
            for char in content:
                if char in char_frequency:
                    char_frequency[char] += 1
                else:
                    char_frequency[char] = 1
            
            print("\nCharacter frequency:")
            for char, freq in char_frequency.items():
                print(f"'{char}': {freq}")
            
            words = content.split()
            print("\nWords in reverse order:")
            print(' '.join(reversed(words)))

            with open('File1.txt', 'w') as file1, open('File2.txt', 'w') as file2:
                for index, line in enumerate(lines, start=1):
                    if index % 2 == 0:  # Even line
                        file1.write(line + '\n')
                    else:  # Odd line
                        file2.write(line + '\n')

            print("\nEven lines copied to 'File1.txt' and odd lines to 'File2.txt'.")
    
    except FileNotFoundError:
        print(f"The file '{file_path}' does not exist.")

file_path = input("Enter the file path: ")
file_operations(file_path)
