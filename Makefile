file_name = main.cpp
output_name = main.exe

all: build run clean


build:
	gcc $(file_name) -o $(output_name)

run:
	./main.exe

clean:
	@rm *.exe
	@echo "data is removed successfully"