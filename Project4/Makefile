all:mstdriver debug
mstdriver:node.h node.cpp graph.h graph.cpp edge.h edge.cpp set.h set.cpp msttest.cpp msttest.h
			g++ -std=c++11 edge.cpp set.cpp node.cpp graph.cpp msttest.cpp -o mstdriver				
debug:node.h node.cpp graph.h graph.cpp edge.h edge.cpp set.h set.cpp
			g++ -g -std=c++11 edge.cpp set.cpp node.cpp graph.cpp msttest.cpp -o mstdebug
clean:		
			rm -f mstdriver