def pyramid(height):
    for i in range(1, height + 1):
        print('*' * (2 * i - 1))


def reverse_pyramid(height):
    for i in range(height, 0, -1):
        print('*' * (2 * i - 1))

height = int(input("Enter the height of the pyramid: "))

pyramid(height)

reverse_pyramid(height)
