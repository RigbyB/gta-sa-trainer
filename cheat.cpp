#include "cheat.h"

std::string Cheat::GetName() {
	return name;
}

void Cheat::SetName(std::string _name) {
	name = _name;
}

bool Cheat::GetEnabled() {
	return enabled;
}

void Cheat::SetEnabled(bool _enable) {
	enabled = _enable;
}