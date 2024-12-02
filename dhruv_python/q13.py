import re

def validate_name(name):
    if not re.match("^[A-Za-z ]+$", name):
        raise ValueError("The name contains digits or special characters, which are not allowed.")

def main():
    try:
        name = input("Enter your name: ")

        validate_name(name)

        print(f"Hello, {name}!")

    except ValueError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
