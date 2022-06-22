#pragma once

#include "../cheat.h"

class CallCheat : public Cheat {
public:
	CallCheat();
	void Run(std::vector<std::string> args) override;
};