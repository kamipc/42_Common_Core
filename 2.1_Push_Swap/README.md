# Push_swap

## Main objective

In this project you receive a varied amount of integers and you need to organize then in crescent order using a set number of instructions.
Also you have to try and be as eficient as possible doing it with the least instructions.
Those instructions are:

- `sa` or `swap a`: Swap the first 2 elements at the top of stack **a**.
- `sb` or `swap b`: Swap the first 2 elements at the top of stack **b**`.
- `ss`: **sa** and **sb** at the same time.
- `pa` or `push a`: Take the first element at the top of **b** and put it at the top of **a**.
- `pb` or `push b`: Take the first element at the top of **a** and put it at the top of **b**.
- `ra` or `rotate a`: Shift up all elements of stack **a** by 1, the first element becomes the last.
- `rb` or `rotate b`: Shift up all elements of stack **b** by 1, the first element becomes the last.
- `rr`: **ra** and **rb** at the same time.
- `rra` or `reverse rotate a`: Shift down all elements of stack **a**, the last element becomes the first.
- `rrb` or `reverse rotate b`: Shift down all elements of stack **b**, the last element becomes the first.
- `rrr`: **rra** and **rrb** at the same time.

