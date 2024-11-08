#include <map>
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <string>
#include <vector>
#include "AConsole.h"
#include "MemoryManager.h"

using namespace std;

MemoryManager::MemoryManager(int overallMemory, int perFrame, int perProcess) {
    this->overallMemory = overallMemory;
    this->perFrame = perFrame;
    this->perProcess = perProcess;

    availableMemory = overallMemory;

    // setup memory frame
    this->frameCount = overallMemory / perFrame;
}

void MemoryManager::displayMemoryDetails() const {
    cout << "Timestamp: " << getCurrentTime() << endl;
	cout << "Numbe of processes in memory: " << memoryConsoles.size() << endl;
	cout << "Total external fragmentation in KB: " << "TODO" << endl;

}

void MemoryManager::addConsoletoMemory(AConsole* newConsole) {
    memoryConsoles[newConsole->getName()] = newConsole;
    availableMemory -= perProcess;
}

int MemoryManager::getOverallMemory() const {
    return overallMemory;
}

void MemoryManager::setOverallMemory(int overallMemory) {
    this->overallMemory = overallMemory;
}

int MemoryManager::getPerFrame() const {
    return perFrame;
}

void MemoryManager::setPerFrame(int perFrame) {
    this->perFrame = perFrame;
}

int MemoryManager::getPerProcess() const {
    return perProcess;
}

void MemoryManager::setPerProcess(int perProcess) {
    this->perProcess = perProcess;
}

string MemoryManager::getCurrentTime() {
    time_t now = time(0);
    tm localTime;
    localtime_s(&localTime, &now);
    char buffer[50];
    strftime(buffer, sizeof(buffer), "(%m/%d/%Y %H:%M:%S%p)", &localTime);
    return buffer;
}