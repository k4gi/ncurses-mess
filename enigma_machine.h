#ifndef ENIGMA_MACHINE_H
#define ENIGMA_MACHINE_H

#include <string>

class enigma_machine {
	std::string wheels[8][2] = {
		{"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "R"},
		{"AJDKSIRUXBLHWTMCQGZNPYFVOE", "F"},
		{"BDFHJLCPRTXVZNYEIWGAKMUSQO", "W"},
		{"ESOVPZJAYQUIRHXLNFTGKDCMWB", "K"},
		{"VZBRGITYUPSDNHLXAWMJQOFECK", "A"},
		{"JPGVOUMFYQBENHZRDKASXLICTW", "AN"},
		{"NZJHGRCXMYSWBOUFAIVLPEKQDT", "AN"},
		{"FKQHTLXOCBJSPDZRAMEWNIUYGV", "AN"}
	};
	std::string reflectors[3] = {
		"EJMZALYXVBWFCRQUONTSPIKHGD",
		"YRUHQSLDPXNGOKMIEBFZCWVJAT",
		"FVPJIAOYEDRZXWGCTKUQSBNMHL"
	};
	std::string keyboard = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string plugboard = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string working_wheels[3][3];
public:
	enigma_machine();
	void set(int ref, int slot1, int set1, int slot2, int set2, int slot3, int set3);
	std::string encode(std::string in);
}

#endif
