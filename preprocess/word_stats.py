import sys

max_line_length = 0
max_word_length = 0
max_words = 0

with open(sys.argv[1]) as f:
    for line in f:
        max_line_length = max(max_line_length, len(line))
        words = line.split(" ")
        max_words = max(max_words, len(words))
        max_word_length = max(max_word_length, max(len(word) for word in words))

print(f'{max_words=} {max_word_length=} {max_line_length=}')