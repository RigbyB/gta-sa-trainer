#pragma once

#include <Windows.h>

#include "offsets.h"

typedef void (*SpawnVehicleFn)(int vehicle_id);

static SpawnVehicleFn SpawnVehicle = (SpawnVehicleFn)(base_address + SPAWN_VEHICLE);