# Menu items and their prices
menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

def main():
    # Initialize the order list and total cost
    order = []
    total_cost = 0.0

    print("Welcome to Felipe's Taqueria!")

    try:
        while True:
            # Prompt the user for input
            item = input("Enter an item (or press Ctrl-D to finish): ").strip().title()

            # Check for EOF (Ctrl-D) input
            if not item:
                break

            # Check if the item is in the menu
            if item in menu:
                # Add the item to the order list
                order.append(item)

                # Update the total cost
                total_cost += menu[item]

                # Display the current total cost
                print(f"Total cost: ${total_cost:.2f}")
            else:
                print("Invalid item. Please choose an item from the menu.")

    except EOFError:
        pass  # Catch Ctrl-D input

    print("\nThank you for your order!")
    if order:
        print("Your order:")
        for item in order:
            print(item)
        print(f"Total cost: ${total_cost:.2f}")

if __name__ == "__main__":
    main()
