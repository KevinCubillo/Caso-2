output: Quicksort.o
	g++ Quicksort.o -o quicksort
Quicksort.o: Quicksort.cpp
	g++ -c Quicksort.cpp

output: Insertionsort.o
	g++ Insertionsort.o -o insertionsort
Insertionsort.o: Insertionsort.cpp
	g++ -c Insertionsort.cpp

output: FreetextSearch.o
	g++ Insertionsort.o -o freetextsearch
FreetextSearch.o: FreetextSearch.cpp
	g++ -c FreetextSearch.cpp





