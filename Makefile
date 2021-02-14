CC := g++
TARGET := qlog
CFLAGS = -I $(IDIR) -Wall -std=c++17

ODIR := ./obj
SDIR := ./src
IDIR := ./inc

_DEPS := QLog.h fileHandler.h
DEPS := $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ := main.o QLog.o fileHandler.o
OBJ := $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(TARGET)
