## Push_swap

**This is the first big project at school 42 relating to algorithms.**

The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. We have at disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks. It contains two programs:
  - The first, named checker which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.
  - The second one called push_swap which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts integer arguments received.

Some examples of the use of the programs:
- Calculate the number of instructions needed to sort the arguments:
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -
```
- Check if the stack is actually properly sorted:
```
>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
