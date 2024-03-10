all: bin/test

bin/test: obj/mainTest.o obj/joueur.o obj/ennemi.o obj/sort.o obj/objet.o obj/effet.o
	g++ -g obj/mainTest.o obj/joueur.o obj/ennemi.o obj/sort.o obj/objet.o obj/effet.o -o bin/test

obj/mainTest.o: src/mainTest.cpp src/joueur.h src/ennemi.h #src/sort.h src/objet.h
	g++ -g -Wall -c src/mainTest.cpp -o obj/mainTest.o

obj/joueur.o: src/joueur.cpp src/joueur.h src/sort.h src/objet.h
	g++ -g -Wall -c src/joueur.cpp -o obj/joueur.o

obj/ennemi.o: src/ennemi.cpp src/ennemi.h src/sort.h
	g++ -g -Wall -c src/ennemi.cpp -o obj/ennemi.o

obj/sort.o: src/sort.cpp src/effet.cpp src/sort.h src/effet.h
	g++ -g -Wall -c src/sort.cpp -o obj/sort.o

obj/objet.o: src/objet.cpp src/effet.cpp src/objet.h src/effet.h
	g++ -g -Wall -c src/objet.cpp -o obj/objet.o
obj/effet.o: src/effet.cpp src/effet.h
	g++ -g -Wall -c src/effet.cpp -o obj/effet.o

# doc: doc/doxyfile
#   doxygen doc/doxyfile

clean:
	rm obj/*.o

veryclean: clean
	rm src/*.out