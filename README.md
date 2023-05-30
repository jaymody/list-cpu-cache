```shell
$ clang --include stack_list.c main.c && ./a.out
Push:     3.691 ms
Pop:      4.610 ms
Iter v1:  0.253 ms
Iter v2:  7.333 ms

$ clang -O3 --include stack_list.c main.c && ./a.out
Push:     3.450 ms
Pop:      4.409 ms
Iter v1:  0.243 ms
Iter v2:  6.883 ms

$ clang --include stack_arr.c main.c && ./a.out
Push:     1.556 ms
Pop:      0.420 ms
Iter v1:  0.191 ms
Iter v2:  0.205 ms

$ clang -O3 --include stack_arr.c main.c && ./a.out
Push:     1.600 ms
Pop:      0.001 ms
Iter v1:  0.083 ms
Iter v2:  0.091 ms
```
