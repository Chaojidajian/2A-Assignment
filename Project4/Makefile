all:mstdriver debug
mstdriver:node.h node.cpp graph.h graph.cpp
			g++ -std=c++11 node.cpp graph.cpp -o mstdriver				
debug:node.h node.cpp graph.h graph.cpp
			g++ -g -std=c++11 node.cpp graph.cpp -o mstdebug
clean:		
			rm -f mstdriver