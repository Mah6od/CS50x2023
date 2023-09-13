text = input("Text: ").lower()
words = len(text.split())
letters = sum(c.isalpha() for c in text)
sentences = text.count(".") + text.count("!") + text.count("?")

L = (letters / words) * 100
S = (sentences / words) * 100

coleman = round(0.0588 * L - 0.296 * S - 15.8)

if coleman >= 16:
    print("Grade 16+")
elif coleman < 1:
    print("Before Grade 1")
else:
    print("Grade:", coleman)
