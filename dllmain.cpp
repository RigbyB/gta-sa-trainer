#include <Windows.h>
#include <iostream>
#include <sstream>
#include <vector>

#include "offsets.h"
#include "cheats/SpawnVehicleCheat.h"
#include "cheats/FlyCheat.h"
#include "cheats/CallCheat.h"

// TODO: Remove, these are temporary
static uintptr_t CHEAT_MONEY_ARMOR_HEALTH = 0x3B230;
static uintptr_t CHEAT_INCREASE_WANTED_LEVEL = 0x3B280;
static uintptr_t CHEAT_CLEAR_WANTED_LEVEL = 0x3B310;
static uintptr_t CHEAT_WEATHER_SUNNY = 0x3B330;
static uintptr_t CHEAT_WEATHER_SUPER_HOT = 0x3B340;
static uintptr_t CHEAT_WEATHER_CLOUDY = 0x3B350;
static uintptr_t CHEAT_WEATHER_THUNDERSTORM = 0x3B360;
static uintptr_t CHEAT_WEATHER_FOGGY = 0x3B370;
static uintptr_t CHEAT_INCREASE_SPEED = 0x3B380;
static uintptr_t CHEAT_DECREASE_SPEED = 0x3B3B0;

static uintptr_t CHEAT_1 = 0x3C0A0;
static uintptr_t CHEAT_2 = 0x3C1F0;
static uintptr_t CHEAT_3 = 0x3CA20;
static uintptr_t CHEAT_4 = 0x3CA30;
static uintptr_t CHEAT_5 = 0x3CA40;
static uintptr_t CHEAT_6 = 0x3CA50;
static uintptr_t CHEAT_7 = 0x3CA60;
static uintptr_t CHEAT_8 = 0x3CA70;
static uintptr_t CHEAT_9 = 0x3CA80;
static uintptr_t CHEAT_10 = 0x3CA90;

std::vector<std::string> split_string(std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string word;
    while (std::getline(ss, word, delimiter)) {
        result.push_back(word);
    }
    return result;
}

std::vector<Cheat*> cheats;

DWORD WINAPI InputThread(LPVOID lpParam) {
    std::cout << "InputThread loaded." << std::endl;

    while (true) {
        std::string _input;
        std::getline(std::cin, _input);
        std::vector<std::string> args = split_string(_input, ' ');

        if (args.size() < 1) {
            std::cout << "No command entered." << std::endl;
            continue;
        }

        for (size_t i = 0; i < cheats.size(); i++) {
            Cheat* cheat = cheats.at(i);
            if (cheat->GetName() == args.at(0)) {
                cheat->Run(args);
                break;
            }

            if (i == cheats.size() - 1)
                std::cout << "Command not found." << std::endl;
        }
    }
    return 0;
}

DWORD WINAPI CheatThread(LPVOID lpParam) {
    // Init console
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    std::cout << "GTA SA Hack Loaded." << std::endl;

    // Init cheats
    cheats.push_back(new SpawnVehicleCheat());
    cheats.push_back(new FlyCheat());
    cheats.push_back(new CallCheat());
    std::cout << "Cheats loaded." << std::endl;

    // Create input thread
    CreateThread(
        NULL,
        0,
        InputThread,
        &lpParam,
        0,
        NULL
    );

    while (true) {
        for (Cheat* cheat : cheats) {
            if (cheat->GetEnabled())
                cheat->Tick();
        }
    }
}

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        CreateThread(
            NULL,
            0,
            CheatThread,
            &hModule,
            0,
            NULL
        );
    }
    
    // TODO: unload
    return TRUE;
}

