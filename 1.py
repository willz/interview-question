
def main():
    input_a = [1, 2, 4, 5]
    input_b = [3, 9]
    w = input_a + input_b
    total_v = sum(input_a)
    # init table
    INF = 0xffffffff
    f = [INF] * (total_v + 1)
    tags = [0] * (total_v + 1)
    for e in w:
        if e <= total_v:
            f[e] = 1
            tags[e] = e

    for wi in w:
        for v in range(total_v, -1, -1):
            if wi <= v:
                if f[v - wi] != INF:
                    f[v] = min(f[v], f[v - wi] + 1)
                    if f[v] == f[v - wi] + 1:
                        tags[v] = wi

    # output
    v = total_v
    while tags[v] != v:
        print tags[v],
        v -= tags[v]
    print tags[v]
    print f[total_v]


if __name__ == '__main__':
    main()
