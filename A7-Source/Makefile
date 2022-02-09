CC_EXEC = g++
CC_FLAGS = -std=c++11
CC = $(CC_EXEC) $(CC_FLAGS)
Object_files = main.o Tools.o Exceptions.o Utrip.o Hotel.o User.o Room.o DeluxeRoom.o LuxuryRoom.o PremiumRoom.o StandardRoom.o Reserve.o ManageFilter.o MainFilter.o CityFilter.o PriceFilter.o StarFilter.o ReserveFilter.o Comment.o Rating.o ReserveDate.o

all: utrip.out

utrip.out: $(Object_files)
	$(CC) $(Object_files) -o utrip.out

main.o: main.cpp Utrip.hpp
	$(CC) -c main.cpp

Tools.o: Tools.cpp Tools.hpp Hotel.hpp Room.hpp DeluxeRoom.hpp LuxuryRoom.hpp PremiumRoom.hpp StandardRoom.hpp
	$(CC) -c Tools.cpp

Exceptions.o: Exceptions.cpp Exceptions.hpp
	$(CC) -c Exceptions.cpp

Utrip.o: Utrip.cpp Utrip.hpp Exceptions.hpp User.hpp ManageFilter.hpp Tools.hpp Hotel.hpp Room.hpp DeluxeRoom.hpp LuxuryRoom.hpp PremiumRoom.hpp StandardRoom.hpp
	$(CC) -c Utrip.cpp

Hotel.o: Hotel.cpp Hotel.hpp Exceptions.hpp DeluxeRoom.hpp LuxuryRoom.hpp PremiumRoom.hpp StandardRoom.hpp Comment.hpp Rating.hpp
	$(CC) -c Hotel.cpp

User.o: User.cpp User.hpp Exceptions.hpp Room.hpp DeluxeRoom.hpp LuxuryRoom.hpp PremiumRoom.hpp StandardRoom.hpp Reserve.hpp
	$(CC) -c User.cpp

Room.o: Room.cpp Room.hpp ReserveDate.hpp
	$(CC) -c Room.cpp

DeluxeRoom.o: DeluxeRoom.cpp DeluxeRoom.hpp Room.hpp
	$(CC) -c DeluxeRoom.cpp

LuxuryRoom.o: LuxuryRoom.cpp LuxuryRoom.hpp Room.hpp
	$(CC) -c LuxuryRoom.cpp

PremiumRoom.o: PremiumRoom.cpp PremiumRoom.hpp Room.hpp
	$(CC) -c PremiumRoom.cpp

StandardRoom.o: StandardRoom.cpp StandardRoom.hpp Room.hpp
	$(CC) -c StandardRoom.cpp

Reserve.o: Reserve.cpp Reserve.hpp Room.hpp
	$(CC) -c Reserve.cpp

ManageFilter.o: ManageFilter.cpp ManageFilter.hpp MainFilter.hpp CityFilter.hpp PriceFilter.hpp StarFilter.hpp ReserveFilter.hpp
	$(CC) -c ManageFilter.cpp

MainFilter.o: MainFilter.cpp MainFilter.hpp Hotel.hpp
	$(CC) -c MainFilter.cpp

CityFilter.o: CityFilter.cpp CityFilter.hpp MainFilter.hpp
	$(CC) -c CityFilter.cpp

PriceFilter.o: PriceFilter.cpp PriceFilter.hpp MainFilter.hpp
	$(CC) -c PriceFilter.cpp

StarFilter.o: StarFilter.cpp StarFilter.hpp MainFilter.hpp
	$(CC) -c StarFilter.cpp

ReserveFilter.o: ReserveFilter.cpp ReserveFilter.hpp MainFilter.hpp
	$(CC) -c ReserveFilter.cpp

Comment.o: Comment.cpp Comment.hpp
	$(CC) -c Comment.cpp
	
Rating.o: Rating.cpp Rating.hpp
	$(CC) -c Rating.cpp
	
ReserveDate.o: ReserveDate.cpp ReserveDate.hpp
	$(CC) -c ReserveDate.cpp
 
.PHONY: cleans
clean:
	rm -r *.o
	rm utrip.out
