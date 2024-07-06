def gen3result(n: int) -> dict:
    d = {}
    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            for k in range(j + 1, n + 1):
                key = i ** 2 + j ** 2 + k ** 2
                d[key] = d.get(key, 0) + 1
    return [key for key, value in d.items() if value == 1]
l = sorted(gen3result(10))
with open("answers.txt", "w") as file:
    for key in l:
        file.write(str(key) + "\n")
    file.write(str(sum(l)))