CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
dep = $(obj:.o=.d)

FASTNet: $(obj)
	$(CC) $(LFLAGS) $(obj) -o FASTNet

$(obj): $(src)
	$(CC) $(CFLAGS) $(src)

clean:
	\rm $(obj) $(PROGRAM)

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
