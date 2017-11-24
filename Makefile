all:
	g++ main.cpp game.cpp -o main -lsfml-system -lsfml-window -lsfml-graphics
clean:
	rm main
