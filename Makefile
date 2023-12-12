NAME				:= philo

ADDSAN				:= -g -fsanitize=address

SOURCE				:= source/*.c

SOURCE_UTIL			:= source/source_util/*.c

COMPILE				:= gcc -o $(NAME) $(SOURCE) $(SOURCE_UTIL) $(ADDSAN)

all:
					$(COMPILE)

test1: all
					echo The philosopher should not eat and should die.
					./philo 1 800 200 200
					
test2: all
					echo No philosopher should die.
					./philo 5 800 200 200

test3: all
					echo No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
					./philo 5 800 200 200 7

test4: all
					echo No philosopher should die.
					./philo 4 410 200 200

test5: all
					echo One philosopher should die.
					./philo 4 310 200 100

clean: fclean

fclean:
					rm $(NAME)

re: all

.SILENT: