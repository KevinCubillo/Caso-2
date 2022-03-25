output: Quicksort.o Insertionsort.o FreetextSearch.o
	g++ Quicksort.o -o quicksort && g++ Insertionsort.o -o insertionsort && g++ FreetextSearch.o -o freetextsearch
Quicksort.o: Quicksort.cpp
	g++ -c Quicksort.cpp


Insertionsort.o: Insertionsort.cpp
	g++ -c Insertionsort.cpp


FreetextSearch.o: FreetextSearch.cpp
	g++ -c FreetextSearch.cpp


clean:
	rm *.o freetextsearch insertionsort quicksort






