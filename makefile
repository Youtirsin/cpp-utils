compile = g++ -W -Wall
build = build

threadpool:
	$(compile) -o $(build)/threadpool tests/threadpool.cpp

.PHONY:
clean:
	rm $(build)/*

