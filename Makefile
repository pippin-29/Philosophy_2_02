NAME				:= philo

ADDSAN				:= -g -fsanitize=address

SOURCE				:= 	\
						source/ascii_to_int.c \
						source/error.c \
						source/init.c \
						source/main.c \
						source/print.c \
						source/print2.c \
						source/routine.c \
						source/routine2.c \
						source/start.c \
						source/time.c

COMPILE				:= gcc -o $(NAME) $(SOURCE)

all:
					$(COMPILE)

test1:
					echo The philosopher should not eat and should die.
					./philo 1 800 200 200
					
test2:
					echo No philosopher should die.
					./philo 5 800 200 200

test3:
					echo No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
					./philo 5 800 200 200 7

test4:
					echo No philosopher should die.
					./philo 4 410 200 200

test5:
					echo One philosopher should die?.
					./philo 4 310 200 100

clean: fclean

fclean:
					rm $(NAME)

re: all

.SILENT: