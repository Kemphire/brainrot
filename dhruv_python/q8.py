def cube_of_even_integers_for_loop(input_list):
    cubes = []
    for item in input_list:
        if isinstance(item, int) and item % 2 == 0:
            cubes.append(item ** 3)
    return cubes

def cube_of_even_integers_comprehension(input_list):
    return [item ** 3 for item in input_list if isinstance(item, int) and item % 2 == 0]

input_list = [1, 2, 3, 4, 'a', 5.5, 6, 'hello', 8]

cubes_for_loop = cube_of_even_integers_for_loop(input_list)
print("Cubes using for loop:", cubes_for_loop)

cubes_comprehension = cube_of_even_integers_comprehension(input_list)
print("Cubes using list comprehension:", cubes_comprehension)
