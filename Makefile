bin/testTableEntry: testTableEntry.cpp TableEntry.h	
	mkdir -p bin 
	g++ -o bin/testTableEntry testTableEntry.cpp

clean:
	rm -rf *.o *.gch bin
