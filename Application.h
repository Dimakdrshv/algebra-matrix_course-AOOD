#pragma once

#include "Matrix.h"
#include "ProjectException.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono> 
#include <functional>

class Application {
private:
    static void printMenu();
    static void printInfo();

    static void InputMatrixSettings(short int& type, short int& rows, short int& columns);
    static void InputMatrixSettings(std::string& path, short int& type);
    static void InputType(short int& type);
    static void InputValue(short int& value, short int type);
    static void InputForOperations(short int& type1, short int& type2, short int& value1, short int& value2, short int step);
    static void OutputMatrixSettings(short int& type, short int& value);
    static void OutputMatrixSettings(std::string& path, short int& type, short int& value);

    static void zeroOperation();
    static void firstOperation();
    static void secondOperation();
    static void thirdOperation();
    static void fourthOperation();
    static void fifthOperation();
    static void sixthOperation();
    static void seventhOperation();
    static void eigthOperation();
    static void nineOperation();
    static void tenthOperation();
    static void eleventhOperation();
    static void twelfthOperation();
    static void thirteenthOperation();
    
    static void ExecuteOperation(const std::function<void()>& func);

public:
    void StartApplication();
};

