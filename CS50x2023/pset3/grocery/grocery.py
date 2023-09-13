from collections import OrderedDict

grocery = OrderedDict()

def main():
    try:
        while True:
            # Prompt the user for input
            item = input().strip().upper()

            if item in grocery:
                grocery[item] += 1
            else:
                grocery[item] = 1

    except EOFError:
        pass  # Catch Ctrl-D input

    for item, count in sorted(grocery.items()):
        print(f"{count} {item}")

if __name__ == "__main__":
    main()