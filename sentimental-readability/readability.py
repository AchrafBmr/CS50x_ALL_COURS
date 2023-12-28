# TODO
from cs50 import get_string
import re


def main():
    # ask user text
    text = get_string("Text: ")

    # count letters
    letters = len([i for i in text if i.isalpha()])

    # count words
    words = len(text.split())

    # If the end of the string matches the pattern,
    # the last element will be an empty string
    sntnc = len(re.split('[.!?]', text)) - 1

    # calculate the average number of letters per 100 words
    mid_l = letters * 100 / words

    # calculate the average number of sentences per 100 words
    mid_s = sntnc * 100 / words

    # find coleman-Liau index
    index = 0.0588 * mid_l - 0.296 * mid_s - 15.8

    if index < 1:
        # output in the case when the score is less than 1
        print("Before Grade 1")
    elif index >= 16:
        # output in the case when the score is greater than or equal to 16
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")


main()