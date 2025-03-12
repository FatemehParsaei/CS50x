from cs50 import get_string


text = get_string("Text: ")


# Count the number of letters, words, and sentences in the text
letters_Count = 0
words_Count = 1
sentence_Count = 0


for i in range(len(text)):
    if text[i].isalpha():  # counts the letters
        letters_Count += 1

    elif text[i].isspace():  # counts the words
        words_Count += 1

    elif text[i] == '.' or text[i] == '!' or text[i] == '?':  # counts the sentences
        sentence_Count += 1

 # Compute the Coleman-Liau index
L = letters_Count / words_Count * 100
S = sentence_Count / words_Count * 100

index = 0.0588 * L - 0.296 * S - 15.8
grade = round(index)

# Print the grade level
if grade < 1:
    print("Before Grade 1")
elif grade > 15:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
