#include "FlyCheat.h"
#include <iostream>
#include <Windows.h>
#include "../offsets.h"
#include "../structs/CPlayerPed.h"

FlyCheat::FlyCheat() {
	SetName("fly");
}

void FlyCheat::Run(std::vector<std::string> args) {
	if (args.size() < 2) {
		// Enable
		// TODO: Toggle
		if (GetEnabled()) {
			std::cout << "Disabled fly." << std::endl;
			SetEnabled(false);
		} else {
			std::cout << "Enabled fly." << std::endl;
			SetEnabled(true);
		}
	} else {
		// Speed
		speed = std::stof(args.at(1));
		std::cout << "Fly speed set to " << speed << "." << std::endl;
	}
}

void FlyCheat::Tick() {
	CPlayerPed* player = *(CPlayerPed**)(base_address + PLAYER_PED_PTR);
	if (!player)
		return;

	float final_speed = speed;
	Vector final_velocity = { 0, 0, 0 };
	// TODO: Key cancel
	// W
	if (GetAsyncKeyState(0x57) & 0x8000) {
		final_velocity.x += 1.0f;
	}
	// S
	if (GetAsyncKeyState(0x53) & 0x8000) {
		final_velocity.x -= 1.0f;
	}
	// A
	if (GetAsyncKeyState(0x41) & 0x8000) {
		final_velocity.y -= 1.0f;
	}
	// D
	if (GetAsyncKeyState(0x44) & 0x8000) {
		final_velocity.y += 1.0f;
	}
	// Space
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		final_velocity.z += 1.0f;
	}
	// Ctrl
	if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
		final_velocity.z -= 1.0f;
	}
	// Shift 
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
		final_speed *= 2.0f;
	}

	player->velocity = final_velocity * speed;
}