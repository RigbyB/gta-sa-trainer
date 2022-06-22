#pragma once

#include "../cheat.h"

class SpawnVehicleCheat : public Cheat {
public:
	SpawnVehicleCheat();
	void Run(std::vector<std::string> args) override;
};