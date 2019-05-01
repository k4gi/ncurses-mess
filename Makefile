walk:
	g++ Character.cpp walk.cpp -lncurses -o walk
info:
	gcc info.c -lncurses -o info
hello:
	gcc hello.c -lncurses -o hello
two:
	gcc two.c -lncurses -o two
window:
	gcc window.c -lncurses -o window
input:
	g++ input.cpp -lncurses -o input
enigma:
	g++ list.cpp enigma_machine.cpp enigma_front.cpp -lncurses -o enigma
listest:
	g++ list.cpp listest.cpp -lncurses -o listest
enigmatest:
	g++ enigma_machine.cpp enigmatest.cpp -o enigmatest
map:
	g++ map.cpp -lncurses -o map
cave:
	g++ Character.cpp cave.cpp -lncurses -o cave
pyramid:
	g++ pyramid.cpp -lncurses -o pyramid
snake:
	g++ snake.cpp snake_game.cpp -lncurses -o snake -g
sidescroll:
	g++ sidescroll.cpp -lncurses -o sidescroll
testing:
	g++ snake.cpp list.cpp testing.cpp -lncurses -o testing
