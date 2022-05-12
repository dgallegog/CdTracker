#pragma once
#include <Windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>


class DebugConsole
{
public:
	void Init(char* title, int width, int height, char* fname);
	int Print(char* fmt, ...);
};
