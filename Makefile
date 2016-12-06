#Makefile du tp2 par Yohan GRACIA et Zifan YAO

CC      = g++
CFLAGS  = -Wall -c
OFLAGS = -Wall -o


all: TP2Voyage clean

TP2Voyage: main.o Trajet.o TrajetSimple.o TrajetCompose.o Parcours.o Catalogue.o
    $(CC) $(OFLAGS) TP2Voyage main.o Trajet.o TrajetSimple.o TrajetCompose.o Parcours.o Catalogue.o

main.o: main.cpp
    $(CC) $(CFLAGS) main.cpp

Trajet.o: Trajet.cpp Trajet.h
    $(CC) $(CFLAGS) Trajet.cpp Trajet.h

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h
    $(CC) $(CFLAGS) TrajetSimple.cpp TrajetSimple.h

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h
    $(CC) $(CFLAGS) TrajetCompose.cpp TrajetCompose.h

Parcours.o: Parcours.cpp Parcours.h
    $(CC) $(CFLAGS) Parcours.cpp Parcours.h

Catalogue.o: Catalogue.cpp Catalogue.h
    $(CC) $(CFLAGS) Catalogue.cpp Catalogue.h

.PHONY: clean cleanest

clean:
    rm *.o

cleanest: clean
    rm TP2Voyage