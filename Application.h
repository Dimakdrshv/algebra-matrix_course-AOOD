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
    template <typename T> static void safeInput(T& value);
    
    static void printMenu();
    static void printInfo();

    static void InputMatrixSettings(short int& type, short int& rows, short int& columns);
    static void InputMatrixSettings(std::string& path, short int& type);
    static void InputType(short int& type);
    static void InputValue(short int& value, short int type);
    static void InputForOperations(short int& type1, short int& type2, short int& value1, short int& value2, short int step);
    static void OutputMatrixSettings(short int& type, short int& value);
    static void OutputMatrixSettings(std::string& path, short int& type, short int& value);

    static void exitOperation();
    static void KeyboardInputMatrix();
    static void FileInputMatrix();
    static void MatrixAddition();
    static void MatrixSubtraction();
    static void DigitMultiplication();
    static void MatrixMultiplication();
    static void VectorMultiplication();
    static void EqualMatrix();
    static void MatrixAssigment();
    static void LoadMatrixToFile();
    static void OutputMatrix();
    static void DeleteMatrix();
    static void ClearConsole();
    
    static void ExecuteOperation(const std::function<void()>& func);

public:
    void StartApplication();
};

