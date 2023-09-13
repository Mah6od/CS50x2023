from cs50 import get_int


def create_half_pyramid(height):
    for i in range(height):
        spaces = " " * (height - i - 1)
        hashes = "#" * (i + 1)
        print(spaces + hashes + "  " + hashes)


# Prompt the user for the pyramid's height
while True:
    height = get_int("Height (1-8): ")
    if height >= 1 and height <= 8:
        break

# Generate the half-pyramids
create_half_pyramid(height)