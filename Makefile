
# all: bin/exemple bin/test


# bin/exemple: obj/mainExemple.o obj/image.o 
# 	g++ -g obj/mainExemple.o obj/image.o -o bin/exemple

# bin/test: obj/mainTest.o obj/image.o 
# 	g++ -g obj/mainTest.o obj/image.o -o bin/test
	
# obj/mainExemple.o: src/mainExemple.cpp src/pixel.h src/image.h 
# 	g++ -g -Wall -c src/mainExemple.cpp -o obj/mainExemple.o

# obj/mainTest.o: src/mainTest.cpp src/pixel.h src/image.h 
# 	g++ -g -Wall -c src/mainTest.cpp -o obj/mainTest.o

# obj/image.o: src/image.h src/image.cpp src/pixel.h
# 	g++ -g -Wall -c src/image.cpp -o obj/image.o

# doc: doc/doxyfile
#   doxygen doc/doxyfile
	
clean:
	rm obj/*.o
	
veryclean: clean
	rm src/*.out
