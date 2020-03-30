all:mstdriver debug
mstdriver:nodelist.h nodelist.cpp node.h node.cpp graph.h graph.cpp edge.h edge.cpp set.h set.cpp msttest.cpp msttest.h
			g++ -std=c++11 nodelist.cpp edge.cpp set.cpp node.cpp graph.cpp msttest.cpp -o mstdriver				
debug:nodelist.h nodelist.cpp node.h node.cpp graph.h graph.cpp edge.h edge.cpp set.h set.cpp msttest.cpp msttest.h
			g++ -g -std=c++11 nodelist.cpp edge.cpp set.cpp node.cpp graph.cpp msttest.cpp -o mstdebug
clean:		
			rm -f mstdriver