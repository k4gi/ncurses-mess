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
	std::string working_wheels[3][3] = {
		{"","",""},
		{"","",""},
		{"","",""}
	};
	std::string working_reflector = "";

	
	char encode_char(int slot, bool reverse, char in);
	void rotate(int slot);
	bool notch_active(int slot);
public:
	enigma_machine();
	void set_wheel(int slot, int wheel, int set);
	void set_reflector(int ref);
	void set_plugboard(std::string plug);
	std::string encode(std::string in);
};

#endif
