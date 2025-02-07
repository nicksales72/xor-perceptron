CC = clang
CFLAGS = -Wall -I../include  
LDFLAGS = -lm
TARGET = main
SRC = main.c activation.c utils.c mlp.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
