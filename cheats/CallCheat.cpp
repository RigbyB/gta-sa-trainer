#include "CallCheat.h"
#include <iostream>
#include <array>
#include "../offsets.h"
#include "../structs/CPlayerPed.h"

CallCheat::CallCheat() {
	SetName("call");
}

typedef uintptr_t (__thiscall* GetTranslatedText)(uintptr_t self, const char* text_name);
typedef void (__cdecl* ShowMessage)(uintptr_t message_ptr, int a, int b, int c);

void CallCheat::Run(std::vector<std::string> args) {
	uintptr_t test = (base_address + 0x549960);

	// TODO: I don't think these are the actual function names / purposes, I just didn't really know at the time.
	GetTranslatedText get_translated_text = (GetTranslatedText)(base_address + 0x2CDA20);
	ShowMessage show_message = (ShowMessage)(base_address + 0x194CB0);

	uintptr_t msg = get_translated_text(test, "NOCD");
	show_message(msg, 1, 0, 0);
}