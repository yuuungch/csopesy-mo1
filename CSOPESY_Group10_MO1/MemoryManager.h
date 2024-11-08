#pragma once
#include <map>
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <string>
#include <vector>
#include "AConsole.h"

using namespace std;

class MemoryManager {
private:
    int overallMemory;
    int availableMemory;
    int perFrame;
    int perProcess;
    int frameCount;

    map<string, AConsole*> memoryConsoles;

public:
    MemoryManager(int overallMemory, int perFrame, int perProcess);

    void displayMemoryDetails() const;
    void addConsoletoMemory(AConsole* newConsole);

    int getOverallMemory() const;
    void setOverallMemory(int overallMemory);
    int getPerFrame() const;
    void setPerFrame(int perFrame);
    int getPerProcess() const;
    void setPerProcess(int perProcess);

    static string getCurrentTime();
};