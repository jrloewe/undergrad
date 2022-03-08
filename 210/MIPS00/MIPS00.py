i = 0

# Because Python does not have native do-while loops,
# it must be simulated through other means.
while True:
    print(i, end="")
    i += 1
    if (i >= 10):
        break
