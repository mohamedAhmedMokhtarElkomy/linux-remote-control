file_name = main.cpp
output_name = main.exe

all: build run clean

build:
	g++ -o $(output_name) $(file_name) command.cpp

run: build
	./main.exe

clean:
	@rm *.exe
	@echo "data is removed successfully"