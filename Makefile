all: main.cpp Hero.o Monster.o Boss.o Tulong.o IceSword.o
	clang++ -o run main.cpp Hero.o Monster.o Boss.o Tulong.o IceSword.o
	
Hero.o: Hero.cpp Hero.h
	clang++ -c Hero.cpp
	
Boss.o: Boss.cpp Boss.h
	clang++ -c Boss.cpp
	
Monster.o: Monster.cpp Monster.h
	clang++ -c Monster.cpp
	
Tulong.o: Tulong.cpp Tulong.h
	clang++ -c Tulong.cpp
	
IceSword.o: IceSword.cpp IceSword.h
	clang++ -c IceSword.cpp

# test the methods of all class 
# Test Boss class
TestBoss: TestBoss.cpp Hero.o Boss.o Tulong.o IceSword.o
	clang++ -o TestBoss TestBoss.cpp Hero.o Boss.o Tulong.o IceSword.o
	./TestBoss < TestBoss01.txt | diff - output01.txt
	./TestBoss < TestBoss02.txt | diff - output02.txt

# Test Monster class
TestMonster: TestMonster.cpp Hero.o Monster.o Tulong.o IceSword.o
	clang++ -o TestMonster TestMonster.cpp Hero.o Monster.o Tulong.o IceSword.o
	./TestMonster < TestMonster01.txt | diff - output03.txt
	./TestMonster < TestMonster02.txt | diff - output04.txt
	
clean:
	rm -f *.o 