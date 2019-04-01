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
	g++ list.cpp enigma_front.cpp -lncurses -o enigma
clean:
	rm walk info hello two window input enigma
