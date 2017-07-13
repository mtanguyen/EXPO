PROGRAM = FASTNet

CC = g++
DEBUG = -g
OBJECTS = ../build
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

src = $(wildcard *.cpp)
obj = $(addprefix $(OBJECTS)/,$(src:.cpp=.o))
dep = $(obj:.o=.d)

$(PROGRAM): $(obj)
	$(CC) $(LFLAGS) $(OBJS) -o $(PROGRAM)

$(obj): $(OBJECTS)/%.o: %.cpp build/
	$(CC) $(CFLAGS) $(src)

clean:
	\rm $(OBJECTS)/*.o*~ $(PROGRAM)

tar:
	tar cfv $(PROGRAM).tar $(src)

#PREFIX = /usr/local
# .PHONY: install
# install: FASTNet
# 	mkdir -p $(DESTDIR)$(PREFIX)/bin
# 	cp $< $(DESTDIR)$(PREFIX)/bin/FASTNet

# .PHONY: uninstall
# uninstall:
# 	rm -f $(DESTDIR)$(PREFIX)/bin/FASTNet
