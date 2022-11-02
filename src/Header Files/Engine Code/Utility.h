#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <assert.h>

class Utility
{

public:

	enum class Severity
	{
		Default = 5,
		Success = 10,
		Warning = 14,
		Failure = 12
	};

	static void Initialize();

	static void Log(const std::string& outputMessage, Severity severity = Severity::Default);

private:
	
	static HANDLE consoleHandle;
};