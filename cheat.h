#pragma once

#include <vector>
#include <string>

class Cheat {
public:
	virtual void Run(std::vector<std::string> args) { }
	virtual void Tick() { }

	std::string GetName();
	void SetName(std::string name);

	bool GetEnabled();
	void SetEnabled(bool _enable);

private:
	std::string name;
	bool enabled = false;
};