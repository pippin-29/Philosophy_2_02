# Dining Philosophers Problem

All philosophers are treated as indivdual threads. And have one fork.

Each thread can access any fork as long as it is not in use. (facilitated with the use of one mutex per fork.)

Threads can not signal between each other.

So in the case of 5 diners, two may eat at any one moment.

From the moment they start eating, a timer starts, specified within the call to the program as a parameter.

If they do not acquire 2 forks ... still more to come
