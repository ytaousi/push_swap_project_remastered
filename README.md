# checker
95% completed - not yet normed 
# push_swap algo
0% completed - not started yet

Concept of The project:|
------------------------
  The idea is simple, You have two stacks called Stack A and Stack B.
Stack A is given a random list of unorganized numbers.

  You must take the random list of numbers in Stack A and sort them so that Stack A is organized from smallest to largest.
There are only a few moves you’re allowed to use to manipulate the stacks.

The main goal of this project is to organize Stack A in as few actions as possible.

The moves are named: sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb.

linked list is easier to implement these moves :

sa || sb : Swap 2 first elements of the stack.

ss : sa && sb

ra || rb : Put the first element last, and all elements go UP by one.

rr : ra && rb

rra || rrb : Put the last element first, and all elements go DOWN by one.

rrr : rra && rrb

pa || pb : Take the first element at the top of stack and put it at the top of the other stack.

