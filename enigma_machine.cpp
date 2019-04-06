#include "enigma_machine.h"

enigma_machine::enigma_machine() {
	wheels = {
		{"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "R"},
		{"AJDKSIRUXBLHWTMCQGZNPYFVOE", "F"},
		{"BDFHJLCPRTXVZNYEIWGAKMUSQO", "W"},
		{"ESOVPZJAYQUIRHXLNFTGKDCMWB", "K"},
		{"VZBRGITYUPSDNHLXAWMJQOFECK", "A"},
		{"JPGVOUMFYQBENHZRDKASXLICTW", "AN"},
		{"NZJHGRCXMYSWBOUFAIVLPEKQDT", "AN"},
		{"FKQHTLXOCBJSPDZRAMEWNIUYGV", "AN"}
	};
	reflectors = {
		"EJMZALYXVBWFCRQUONTSPIKHGD",
		"YRUHQSLDPXNGOKMIEBFZCWVJAT",
		"FVPJIAOYEDRZXWGCTKUQSBNMHL"
	};
	keyboard = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	plugboard = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	working_wheels = NULL;
	working_reflector = NULL;
}

void enigma_machine::set_wheel(int slot, int wheel, int set) {
	working_wheels[slot][0] = keyboard;
	working_wheels[slot][1] = wheels[wheel][0];
	working_wheels[slot][2] = wheels[wheel][1];
	for(int i = 0;i<set;i++) {
		rotate(slot);
	}
}

void enigma_machine::rotate(int slot) {
	working_wheels[slot][0] = working_wheels[slot][0].substr(1,std::string::npos).append(1,working_wheels[slot][0][0]);
	working_wheels[slot][1] = working_wheels[slot][1].substr(1,std::string::npos).append(1,working_wheels[slot][1][0]);
}

void enigma_machine::set_reflector(int ref) {
	working_reflector = reflectors[ref];
}

void enigma_machine::set_plugboard(std::string plug) {
	plugboard = plug;
}

char enigma_machine::encode_char(int slot, boolean reverse, char in) {
	char out = working_wheels[slot][0][keyboard.find(in)];
	if(!reverse) {
		char = working_wheels[slot][1][working_wheels[slot][0].find(out)];
	} else {
		char = working_wheels[slot][0][working_wheels[slot][1].find(out)];
	}
	out = keyboard[working_wheels[slot][0].find(out)];
	return out;
}

std::string enigma_machine::encode(std::string in) {
	if(working_wheels != NULL && working_reflector != NULL) {
	} else {
		return "ERROR: machine not set up";
	}
}
