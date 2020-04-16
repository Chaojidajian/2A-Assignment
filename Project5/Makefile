all:undirectedGraphdriver debug
undirectedGraphdriver:edge.cpp edge.h graph.cpp graph.h min_q.cpp min_q.h node.cpp node.h undirectedGraphtest.cpp undirectedGraphtest.h
			g++ -std=c++11 edge.cpp graph.cpp min_q.cpp node.cpp undirectedGraphtest.cpp -o undirectedGraphdriver				
debug:edge.cpp edge.h graph.cpp graph.h min_q.cpp min_q.h node.cpp node.h undirectedGraphtest.cpp undirectedGraphtest.h
			g++ -g -std=c++11 edge.cpp graph.cpp min_q.cpp node.cpp undirectedGraphtest.cpp -o debug
run:
	./undirectedGraphdriver
clean:		
	rm -f undirectedGraphdriver
	rm -f debug