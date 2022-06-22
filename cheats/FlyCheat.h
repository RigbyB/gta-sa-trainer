#pragma once

#include "../cheat.h"

class FlyCheat : public Cheat {
public:
	FlyCheat();
	void Run(std::vector<std::string> args) override;
	void Tick() override;

	float speed = 1.0f;
};