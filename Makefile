FLAGS = -pedantic-errors -std=c++11

maps.o: maps.cpp TimeIntervals.h AttackFunctions.h 
	g++ $(FLAGS) -c $<

cafe.o: cafe.cpp TimeIntervals.h AttackFunctions.h
	g++ $(FLAGS) -c $<

AttackFunctions.o: AttackFunctions.cpp TimeIntervals.h AttackFunctions.h
	g++ $(FLAGS) -c $<

TimeIntervals.o: TimeIntervals.cpp TimeIntervals.h AttackFunctions.h
	g++ $(FLAGS) -c $<

main.o: main.cpp TimeIntervals.h AttackFunctions.h
	g++ $(FLAGS) -c $<

main: maps.o cafe.o AttackFunctions.o TimeIntervals.o  main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f main main.o cafe.o maps.o AttackFunction.o main.tgz

tar:
	tar -czvf gcd.tgz *.cpp *.h

.PHONY: clean tar

