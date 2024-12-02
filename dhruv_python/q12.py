t1 = (1, 2, 5, 7, 9, 2, 4, 6, 8, 10)

half_length = len(t1) // 2
print("First half of the tuple:", t1[:half_length])
print("Second half of the tuple:", t1[half_length:])

even_tuple = tuple(x for x in t1 if x % 2 == 0)
print("Even numbers tuple:", even_tuple)

t2 = (11, 13, 15)
concatenated_tuple = t1 + t2
print("Concatenated tuple:", concatenated_tuple)

max_value = max(t1)
min_value = min(t1)
print(f"Maximum value in the tuple: {max_value}")
print(f"Minimum value in the tuple: {min_value}")
