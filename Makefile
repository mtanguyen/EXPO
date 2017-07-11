src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
dep = $(obj:.o=.d)

CC = g++
LDFLAGS = -lGL -lglut -lpng -lz -lm

FASTNet: $(obj) src
	$(CC) -o $@ $^ $(LDFLAGS)

%.d: %.cpp
	@$(CPP) $(CFlAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(obj) FASTNet
.PHONY: cleandep
cleandep:
	rm -f $(dep)

.PHONY: src
	$(MAKE) -C src/

PREFIX = /usr/local

.PHONY: install
install: FASTNet
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/FASTNet

.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/FASTNet