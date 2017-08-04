CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++0x $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LINCUL += -lcurl
PROGRAM = FASTNet
LOGS = ../doc/logs/*.txt

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
dep = $(obj:.o=.d)

$(PROGRAM): $(obj)
	$(CC) $(LFLAGS) $(obj) -o $(PROGRAM) $(LINCUL)

$(obj): $(src)
	$(CC) $(CFLAGS) $(src)

clean:
	\rm $(obj) $(PROGRAM) $(LOGS)

tar:
	tar cfv $(PROGRAM).tar $(src)
