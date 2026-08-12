# Compiler Lab Experiment 1

Aim: To write a C program to find the ε — closure of all states of any given NFA with ε transition.

## Algorithm

1. Start
2. Read the number of states `n`.
3. Read the `n` states and store them in the `states` array.
4. Open the file `automata.txt` for reading.
5. Select a state from the `states` array.
6. Set the selected state as the current state.
7. Add the current state to the result array.
8. Read `state1`, `input`, and `state2` from the file.
9. Check whether `state1` is equal to the current state.
10. If `state1` is equal to the current state, check whether `input` is `e`.
11. If `input` is `e`, add `state2` to the result array.
12. Set `state2` as the current state.
13. Repeat Steps 8–12 until the end of the file is reached.
14. Display the epsilon closure of the selected state.
15. Reset the file pointer using `rewind()`.
16. Repeat Steps 5–15 for all states.
17. Close the file.
18. Stop.

```c
#include<stdio.h>
#include<string.h>
char result[20][20], copy[3], states[20][20];
void add_state(char a[3], int i) {
strcpy(result[i], a);
}
void display(int n) {
int k = 0;
printf("\nEpsilon closure of %s = { ", copy);
while (k < n) {
printf(" %s", result[k]);
k++;
}
printf(" }\n");
}
int main() {
FILE *INPUT;
INPUT = fopen("automata.txt", "r");
char state[3];
int end, i = 0, n, k = 0;
char state1[3], input[3], state2[3];
printf("\nEnter the no of states: ");
scanf("%d",&n);
printf("\nEnter the states (max 20) \n");
for (k = 0; k < n; k++) {
scanf("%s", states[k]);
}
for (k = 0; k < n; k++) {
i = 0;
strcpy(state, states[k]);
strcpy(copy, state);
add_state(state, i++);
while (1) {
end = fscanf(INPUT, "%s%s%s", state1, input, state2);
if (end == EOF) break;
if (strcmp(state, state1) == 0) {
if (strcmp(input, "e") == 0) {
add_state(state2, i++);
strcpy(state, state2);
}
}

}
display(i);
rewind(INPUT);
}
return 0;
}
```
