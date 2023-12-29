# Compilator
CXX = g++

# Executable
EXEC = output

# CXXFLAGS
# LDFLAGS

# $(CXX) to use variable


all: $(EXEC)

# creates an executable output
$(EXEC): main.o option.o util.o american_put.o asian_call.o asian_put.o barrier_call.o barrier_put.o euro_dividend_call.o euro_dividend_put.o european_call.o european_put.o lookback_call.o lookback_put.o 
	$(CXX) -o $(EXEC) main.o option.o util.o american_put.o asian_call.o asian_put.o barrier_call.o barrier_put.o euro_dividend_call.o euro_dividend_put.o european_call.o european_put.o lookback_call.o lookback_put.o

# creates main.o
main.o: main.cpp
	$(CXX) -c main.cpp

option.o: option.cpp
	$(CXX) -c option.cpp

util.o: util.cpp
	$(CXX) -c util.cpp

american_put.o: american_put.cpp
	$(CXX) -c american_put.cpp
	
asian_call.o: asian_call.cpp
	$(CXX) -c asian_call.cpp
	
asian_put.o: asian_put.cpp
	$(CXX) -c asian_put.cpp

barrier_call.o: barrier_call.cpp
	$(CXX) -c barrier_call.cpp

barrier_put.o: barrier_put.cpp
	$(CXX) -c barrier_put.cpp

euro_dividend_call.o: euro_dividend_call.cpp
	$(CXX) -c euro_dividend_call.cpp

euro_dividend_put.o: euro_dividend_put.cpp
	$(CXX) -c euro_dividend_put.cpp

european_call.o: european_call.cpp
	$(CXX) -c european_call.cpp
	
european_put.o: european_put.cpp
	$(CXX) -c european_put.cpp

lookback_call.o: lookback_call.cpp
	$(CXX) -c lookback_call.cpp

lookback_put.o: lookback_put.cpp
	$(CXX) -c lookback_put.cpp


# to remove all .o files, works only in Linux
clean:
	rm *.o
	
cleanall: clean
	rm $(EXEC)