# Dining Philosophers Problem

All philosophers are treated as indivdual threads. And have one fork.

Each thread can access any fork as long as it is not in use. (facilitated with the use of one mutex per fork.)

Threads can not signal between each other.

So in the case of 5 diners, two may eat at any one moment.

From the moment they start eating, a timer starts, specified within the call to the program as a parameter.

Busy-wait timers are in use for precision.

There are 5 tests this program has been tested for.

Test Parameters - (thread_count, time_to_die, time_to_eat, time_to_sleep, number_of_meals)

Navigate to project root, type `` make ``

run `` ./philo 1 800 200 200 `` One Philossopher Has Only One Fork, and will timeout.

run `` ./philo 5 800 200 200 ``

run `` ./philo 5 800 200 200 7 ``

run `` ./philo 4 410 200 200 ``

run `` ./philo 4 310 200 100 `` Test should finish with a thread timeout.

Task is resource intensive, and failure will occur with memory constraints.
