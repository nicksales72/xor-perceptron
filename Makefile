CC = clang
CFLAGS = -Wall -I/include  
LDFLAGS = -lm
TARGET = main
SRC = src/*

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
