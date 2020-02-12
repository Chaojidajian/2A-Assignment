all:openhttest orderedhttest
openhttest:open_table.h user.h user.cpp open_table.cpp openhttest.cpp
			g++ -std=c++11 open_table.cpp user.cpp openhttest.cpp -o openhtdriver
orderedhttest:chain_table.h user.h user.cpp orderedhttest.cpp chain_table.cpp
			g++ -std=c++11 chain_table.cpp user.cpp chain.cpp orderedhttest.cpp -o orderedhtdriver						
clean:		
			rm -f orderedhttest
			rm -f openhttest