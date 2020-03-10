all:qtdriver debug
qtdriver:city.h city.cpp tree.h tree.cpp qttest.h qttest.cpp
			g++ -std=c++11 city.cpp tree.cpp qttest.cpp -o qtdriver				
debug:city.h city.cpp tree.h tree.cpp qttest.h qttest.cpp
		g++ -g -std=c++11 city.cpp tree.cpp qttest.cpp -o qttest
clean:		
			rm -f qtdriver