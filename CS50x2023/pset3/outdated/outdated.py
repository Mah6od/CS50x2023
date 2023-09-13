months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]

while True:
    date = input("Date: ").strip()

    if "/" in date:
        month, day, year = date.split("/")

    elif "," in date:
        date = date.replace(",", "")
        month, day, year = date.split(" ")
        if month in months:
            month = months.index(month) + 1

    try:
        if int(month) > 12 or int(day) > 31:
            continue
        else:
            break
    except ValueError:
        continue

print(year + "-" + f"{int(month):02}" + "-" + f"{int(day):02}")