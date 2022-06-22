#pragma once

#include <Windows.h>

static uintptr_t SPAWN_VEHICLE = 0x3C620;

// TODO: Don't think this is true at all in hindsight.
static uintptr_t PLAYER_PED_PTR = 0x7FC7D8;

static uintptr_t base_address = (uintptr_t)GetModuleHandle(L"gta-sa.exe");