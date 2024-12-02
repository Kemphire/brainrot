def char_classification(char):
    if char.isalpha():
        print(f"'{char}' is a letter.")
        if char.isupper():
            print("It is an uppercase letter.")
        else:
            print("It is a lowercase letter.")
    elif char.isdigit():
        print(f"'{char}' is a numeric digit.")
        digit_names = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
        print(f"The name of the digit is: {digit_names[int(char)]}")
    else:
        print(f"'{char}' is a special character.")

char = input("Enter a character: ")
if len(char) == 1:
    char_classification(char)
else:
    print("Please enter a single character.")
