#include "Application.h"

struct Matrices {
    std::vector<Matrix<int>*> intMatrices;
    std::vector<Matrix<float>*> floatMatrices;
    std::vector<Matrix<double>*> doubleMatrices;

    int intTempValue; float floatTempValue; double doubleTempValue;

} matrices;

template <typename T>
void Application::safeInput(T& value) {
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream stream(input);
        bool isValid = true;
        if (stream >> value) {
            if constexpr (std::is_integral<T>::value) {
                if (input.find('.') != std::string::npos || input.find(',') != std::string::npos) {
                    isValid = false;
                }
            }
            char leftover;
            if (stream >> leftover) isValid = false;
            if (isValid) break;
        }
        else isValid = false;
        if (!isValid) {
            std::cout << "Некорректный ввод. Пожалуйста, попробуйте еще раз.\n>>> ";
        }
    }
}

void Application::printMenu() {
    std::cout << "======================================================================\n" <<
                 " |                       Выберите действие                          |\n" <<
                 " | 1.  Ввести матрицу вручную                                       |\n" <<
                 " | 2.  Загрузить матрицу из файла                                   |\n" <<
                 " | 3.  Сложить матрицы                                              |\n" <<
                 " | 4.  Вычесть матрицы                                              |\n" <<
                 " | 5.  Умножить матрицу на число                                    |\n" <<
                 " | 6.  Умножить матрицы                                             |\n" <<
                 " | 7.  Умножить матрицу на вектор                                   |\n" <<
                 " | 8.  Сравнить матрицы                                             |\n" <<
                 " | 9.  Присвоение матриц                                            |\n" <<
                 " | 10. Загрузить записанные матрицы определенного типа в файл       |\n" <<
                 " | 11. Вывести матрицы определенного типа на экран                  |\n" <<
                 " | 12. Удалить матрицу                                              |\n" <<
                 " | 13. Очистить консоль                                             |\n" <<
                 " | 14. Информация о программе                                       |\n" <<
                 " | 0.  Выйти                                                        |\n" <<
                 "======================================================================\n" <<
                 "Ваш выбор: ";
}

void Application::printInfo() {
    std::cout << "======================================================================\n" <<
                 " |                       Информация о программе                     |\n" <<
                 " |   Программа написана для выполнения действий с матрицами,        |\n" <<
                 " | каждая из которых имеет собственный тип данных, который задается |\n" <<
                 " | пользователем с клавиатуры. Матрицы хранятся в 3 различных       |\n" <<
                 " | коллекциях: Матрицы целочисленного типа данных - int,            |\n" <<
                 " | вещественного - float, и расширенного вещественного - double.    |\n" <<
                 " |   Перегруженные операции \"+,-,*\" выполняются таким образом,      |\n" <<
                 " | что получившая матрица записывается в коллекцию с наибольшим     |\n" <<
                 " | типом данных, относительно матриц\\чисел, с которыми              |\n" <<
                 " | производятся действия.                                           |\n" <<
                 " |   Прегруженные операции \"==, =\" выполняются относительно         |\n" <<
                 " | матриц одного типа данных.                                       |\n" <<
                 " |   Также предусмотрена операция удаления матриц и предложены      |\n" <<
                 " | различные варианты ввода-вывода получившихся матриц.             |\n" <<
                 "======================================================================\n";
}

void Application::InputMatrixSettings(short int& type, short int& rows, short int& columns) {
    std::cout << "======================================================\n" 
              << " |           Введите тип вводимой матрицы           |\n" 
              << " | 1. int                                           |\n" 
              << " | 2. float                                         |\n" 
              << " | 3. double                                        |\n" 
              << "======================================================\n";
    while (true) {
        std::cout << ">>> ";
        safeInput(type);
        if (type >= 1 && type <= 3) break;
        else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
    }
    std::cout << "Введите количество строк матрицы\n";
    while (true) {
        std::cout << ">>> ";
        safeInput(rows);
        if (rows >= 1 && rows <= 6) break;
        else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
    }
    std::cout << "Введите количество стобцов матрицы\n";
    while (true) {
        std::cout << ">>> ";
        safeInput(columns);
        if (columns >= 1 && columns <= 6) break;
        else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
    }
}

void Application::InputMatrixSettings(std::string& path, short int& type) {
    std::cout << "Введите путь до файла, с которого хотите считать матрицу\n"
              << ">>> ";
    safeInput(path);
    std::cout << "======================================================\n"
              << " |           Введите тип вводимой матрицы           |\n"
              << " | 1. int                                           |\n"
              << " | 2. float                                         |\n"
              << " | 3. double                                        |\n"
              << "======================================================\n";
    while (true) {
        std::cout << ">>> ";
        safeInput(type);
        if (type >= 1 && type <= 3) break;
        else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
    }
}

void Application::InputType(short int& type) {
    while (true) {
        std::cout << ">>> ";
        safeInput(type);
        if (type == 1) {
            if (matrices.intMatrices.size() != 0) {
                std::cout << "Количество матриц с данным типом данных: " << matrices.intMatrices.size() << std::endl;
                break;
            }
            else std::cout << "В данном типе данных пока нет заданных матриц." << std::endl;
        }
        else if (type == 2) {
            if (matrices.floatMatrices.size() != 0) {
                std::cout << "Количество матриц с данным типом данных: " << matrices.floatMatrices.size() << std::endl;
                break;
            }
            else std::cout << "В данном типе данных пока нет заданных матриц." << std::endl;
        }
        else if (type == 3) {
            if (matrices.doubleMatrices.size() != 0) {
                std::cout << "Количество матриц с данным типом данных: " << matrices.doubleMatrices.size() << std::endl;
                break;
            }
            else std::cout << "В данном типе данных пока нет заданных матриц." << std::endl;
        }
        else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
    }
}

void Application::InputValue(short int& value, short int type) {
    while (true) {
        std::cout << ">>> ";
        safeInput(value);
        if (type == 1 && value > 0 && value <= matrices.intMatrices.size()) break;
        else if (type == 2 && value > 0 && value <= matrices.floatMatrices.size()) break;
        else if (type == 3 && value > 0 && value <= matrices.doubleMatrices.size()) break;
        else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
    }
}

void Application::InputForOperations(short int& type1, short int& type2, short int& value1, short int& value2, short int operationNumber) {
    if (operationNumber == 3 || operationNumber == 4 || operationNumber == 6) {
        std::cout << "======================================\n"
                  << " |    Введите тип первой матрицы    |\n"
                  << " | 1. int                           |\n"
                  << " | 2. float                         |\n"
                  << " | 3. double                        |\n"
                  << "======================================\n";
        InputType(type1);
        std::cout << "Введите номер матрицы в коллекции матриц данного типа" << std::endl;
        InputValue(value1, type1);
        std::cout << "======================================\n"
                  << " |    Введите тип второй матрицы    |\n" 
                  << " | 1. int                           |\n"
                  << " | 2. float                         |\n"
                  << " | 3. double                        |\n"
                  << "======================================\n";
        InputType(type2);
        std::cout << "Введите номер матрицы в коллекции матриц данного типа" << std::endl;
        InputValue(value2, type2);
        std::cout << "=======================================================================\n" 
                  << " | Если операция выполнится, то получившаяся матрица будет добавлена |\n"
                  << " | в коллекцию, которая имеет больший тип данных, иначе выведется    |\n" 
                  << " | сообщение об ошибке.                                              |\n"
                  << "=======================================================================\n";
    }
    else if (operationNumber == 8 || operationNumber == 9) {
        std::cout << "==============================\n"
                  << " |    Введите тип матриц    |\n"
                  << " | 1. int                   |\n"
                  << " | 2. float                 |\n"
                  << " | 3. double                |\n"
                  << "==============================\n";
        InputType(type1);
        std::cout << "Введите номер первой матрицы" << std::endl;
        InputValue(value1, type1);
        std::cout << "Введите номер второй матрицы" << std::endl;
        InputValue(value2, type1);
    }
    else if (operationNumber == 5) {
        std::cout << "===============================\n"
                  << " |    Введите тип матрицы    |\n"
                  << " | 1. int                    |\n"
                  << " | 2. float                  |\n"
                  << " | 3. double                 |\n"
                  << "===============================\n";
        InputType(type1);
        std::cout << "Введите номер матрицы" << std::endl;
        InputValue(value1, type1);
        std::cout << "==================================\n"
                  << " |    Введите тип переменной    |\n"
                  << " | 1. int                       |\n"
                  << " | 2. float                     |\n"
                  << " | 3. double                    |\n"
                  << "=================================\n";
        while (true) {
            std::cout << ">>> ";
            safeInput(type2);
            if (type2 >= 1 && type2 <= 3) break;
            else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
        }
        std::cout << "Введите значение переменной: ";
        if (type2 == 1) safeInput(matrices.intTempValue);
        else if (type2 == 2) safeInput(matrices.floatTempValue);
        else safeInput(matrices.doubleTempValue);
        std::cout << "=======================================================================\n"
                  << " | Если операция выполнится, то получившаяся матрица будет добавлена |\n"
                  << " | в коллекцию, которая имеет больший тип данных, иначе выведется    |\n"
                  << " | сообщение об ошибке.                                              |\n"
                  << "=======================================================================\n";
    }
    else if (operationNumber == 7) {
        std::cout << "===============================\n"
                  << " |    Введите тип матрицы    |\n"
                  << " | 1. int                    |\n"
                  << " | 2. float                  |\n"
                  << " | 3. double                 |\n"
                  << "===============================\n";
        InputType(type1);
        std::cout << "Введите номер матрицы" << std::endl;
        InputValue(value1, type1);
        std::cout << "=======================================\n"
                  << " |    Введите тип вектора столбца    |\n"
                  << " | 1. int                            |\n"
                  << " | 2. float                          |\n"
                  << " | 3. double                         |\n"
                  << "=======================================\n";
        while (true) {
            std::cout << ">>> ";
            safeInput(type2);
            if (type2 >= 1 && type2 <= 3) break;
            else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
        }
        std::cout << "=======================================================================\n"
                  << " | Если операция выполнится, то получившаяся матрица будет добавлена |\n"
                  << " | в коллекцию, которая имеет больший тип данных, иначе выведется    |\n"
                  << " | сообщение об ошибке.                                              |\n"
                  << "=======================================================================\n";
    }
    else {
        std::cout << "=========================================\n"
                  << " |    Введите тип удаляемой матрицы    |\n"
                  << " | 1. int                              |\n"
                  << " | 2. float                            |\n"
                  << " | 3. double                           |\n"
                  << "========================================\n";
        InputType(type1);
        int msg;
        std::cout << "================================================\n"
                  << " |               Введите операцию             |\n"
                  << " | 1. Удалить определенную матрицу            |\n"
                  << " | 2. Удалить все матрицы данного типа данных |\n"
                  << "================================================\n";
        while (true) {
            std::cout << ">>> ";
            safeInput(msg);
            if (msg == 1) {
                std::cout << "Введите номер матрицы, которую хотите удалить" << std::endl;
                InputValue(value1, type1);
                break;
            }
            else if (msg == 2) { value1 = -1; return; }
            else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
        }
    }
}

void Application::OutputMatrixSettings(short int& type, short int& value) {
    std::cout << "=========================================\n"
              << " |    Введите тип выводимой матрицы    |\n"
              << " | 1. int                              |\n"
              << " | 2. float                            |\n"
              << " | 3. double                           |\n"
              << "========================================\n";
    InputType(type);
    int msg;
    std::cout << "================================================\n"
              << " |               Введите операцию             |\n"
              << " | 1. Вывести определенную матрицу            |\n"
              << " | 2. Вывести все матрицы данного типа данных |\n"
              << "================================================\n";
    while (true) {
        std::cout << ">>> ";
        safeInput(msg);
        if (msg == 1) break;
        else if (msg == 2) { value = -1; return; }
        else std::cout << "Вы ввели некорректное число. Попробуйте снова." << std::endl;
    }
    std::cout << "Введите номер матрицы, которую хотите вывести" << std::endl;
    InputValue(value, type);
}

void Application::OutputMatrixSettings(std::string& path, short int& type, short int& value) {
    std::cout << "Введите путь до файла, в который хотите вывести матрицу\n";
    while (true) {
        std::cout << ">>> ";
        safeInput(path);
        if (path.find(".txt") == std::string::npos) {
            std::cout << "Неверное имя файла попробуйте еще раз." << std::endl;
        }
        else break;
    }
    OutputMatrixSettings(type, value);
}

void Application::exitOperation() {
    if (matrices.intMatrices.size() > 0 || matrices.floatMatrices.size() > 0 || matrices.doubleMatrices.size() > 0) {
        std::string path; std::cout << "Введите путь к файлу, в который запишутся все созданные матрицы\n";
        while (true) {
            std::cout << ">>> ";
            safeInput(path);
            if (path.find(".txt") == std::string::npos) {
                std::cout << "Неверное имя файла попробуйте еще раз." << std::endl;
            }
            else break;
        }
        for (size_t i = 0; i < matrices.intMatrices.size(); i++)
            matrices.intMatrices[i]->OutputMatrixInFile(path);
        for (size_t i = 0; i < matrices.floatMatrices.size(); i++)
            matrices.floatMatrices[i]->OutputMatrixInFile(path);
        for (size_t i = 0; i < matrices.doubleMatrices.size(); i++)
            matrices.doubleMatrices[i]->OutputMatrixInFile(path);
        std::cout << "Завершение программы. Все созданные матрицы записаны в файл";
    }
    else std::cout << "Завершение программы.";
    exit(0);
}

void Application::KeyboardInputMatrix() {
    short int type, rows, columns;
    InputMatrixSettings(type, rows, columns);
    if (type == 1) {
        matrices.intMatrices.push_back(new Matrix<int>(rows, columns));
        matrices.intMatrices.back()->InputOwnMatrix();
    }
    else if (type == 2) {
        matrices.floatMatrices.push_back(new Matrix<float>(rows, columns));
        matrices.floatMatrices.back()->InputOwnMatrix();
    }
    else if (type == 3) {
        matrices.doubleMatrices.push_back(new Matrix<double>(rows, columns));
        matrices.doubleMatrices.back()->InputOwnMatrix();
    }
}

void Application::FileInputMatrix() {
    std::string path;
    short int type;
    InputMatrixSettings(path, type);
    try {
        if (type == 1) {
            matrices.intMatrices.push_back(new Matrix<int>());
            matrices.intMatrices.back()->InputMatrixFromFile(path);
        }
        else if (type == 2) {
            matrices.floatMatrices.push_back(new Matrix<float>());
            matrices.floatMatrices.back()->InputMatrixFromFile(path);
        }
        else if (type == 3) {
            matrices.doubleMatrices.push_back(new Matrix<double>());
            matrices.doubleMatrices.back()->InputMatrixFromFile(path);
        }
    }
    catch (const ProjectException& ex) {
        std::cout << ex.what() << std::endl;
    }
    if (matrices.intMatrices.size() != 0 && matrices.intMatrices.back()->getRows() == 0) matrices.intMatrices.pop_back();
    else if (matrices.floatMatrices.size() != 0 && matrices.floatMatrices.back()->getRows() == 0) matrices.floatMatrices.pop_back();
    else if (matrices.doubleMatrices.size() != 0 && matrices.doubleMatrices.back()->getRows() == 0) matrices.doubleMatrices.pop_back();
}

void Application::MatrixAddition() {
    short int type1, type2, value1, value2;
    InputForOperations(type1, type2, value1, value2, 3);
    Matrix<int>* intTemp = new Matrix<int>();
    Matrix<float>* floatTemp = new Matrix<float>();
    Matrix<double>* doubleTemp = new Matrix<double>();
    try {
        if (type1 == 1) {
            if (type2 == 1) *intTemp = *matrices.intMatrices[value1 - 1] + *matrices.intMatrices[value2 - 1];
            else if (type2 == 2) *floatTemp = *matrices.intMatrices[value1 - 1] + *matrices.floatMatrices[value2 - 1];
            else *doubleTemp = *matrices.intMatrices[value1 - 1] + *matrices.doubleMatrices[value2 - 1];
        }
        else if (type1 == 2) {
            if (type2 == 1) *floatTemp = *matrices.floatMatrices[value1 - 1] + *matrices.intMatrices[value2 - 1];
            else if (type2 == 2) *floatTemp = *matrices.floatMatrices[value1 - 1] + *matrices.floatMatrices[value2 - 1];
            else *doubleTemp = *matrices.floatMatrices[value1 - 1] + *matrices.doubleMatrices[value2 - 1];
        }
        else {
            if (type2 == 1) *doubleTemp = *matrices.doubleMatrices[value1 - 1] + *matrices.intMatrices[value2 - 1];
            else if (type2 == 2) *doubleTemp = *matrices.doubleMatrices[value1 - 1] + *matrices.floatMatrices[value2 - 1];
            else *doubleTemp = *matrices.doubleMatrices[value1 - 1] + *matrices.doubleMatrices[value2 - 1];
        }
    }
    catch (const ProjectException& ex) { std::cout << ex.what() << std::endl; }
    if (intTemp->getRows() != NULL) matrices.intMatrices.push_back(intTemp);
    else if (floatTemp->getRows() != NULL) matrices.floatMatrices.push_back(floatTemp);
    else if (doubleTemp->getRows() != NULL) matrices.doubleMatrices.push_back(doubleTemp);
}

void Application::MatrixSubtraction() {
    short int type1, type2, value1, value2;
    InputForOperations(type1, type2, value1, value2, 4);
    Matrix<int>* intTemp = new Matrix<int>();
    Matrix<float>* floatTemp = new Matrix<float>();
    Matrix<double>* doubleTemp = new Matrix<double>();
    try {
        if (type1 == 1) {
            if (type2 == 1) *intTemp = *matrices.intMatrices[value1 - 1] - *matrices.intMatrices[value2 - 1];
            else if (type2 == 2) *floatTemp = *matrices.intMatrices[value1 - 1] - *matrices.floatMatrices[value2 - 1];
            else *doubleTemp = *matrices.intMatrices[value1 - 1] - *matrices.doubleMatrices[value2 - 1];
        }
        else if (type1 == 2) {
            if (type2 == 1) *floatTemp = *matrices.floatMatrices[value1 - 1] - *matrices.intMatrices[value2 - 1];
            else if (type2 == 2) *floatTemp = *matrices.floatMatrices[value1 - 1] - *matrices.floatMatrices[value2 - 1];
            else *doubleTemp = *matrices.floatMatrices[value1 - 1] - *matrices.doubleMatrices[value2 - 1];
        }
        else {
            if (type2 == 1) *doubleTemp = *matrices.doubleMatrices[value1 - 1] - *matrices.intMatrices[value2 - 1];
            else if (type2 == 2) *doubleTemp = *matrices.doubleMatrices[value1 - 1] - *matrices.floatMatrices[value2 - 1];
            else *doubleTemp = *matrices.doubleMatrices[value1 - 1] - *matrices.doubleMatrices[value2 - 1];
        }
    }
    catch (const ProjectException& ex) { std::cout << ex.what() << std::endl; }
    if (intTemp->getRows() != NULL) matrices.intMatrices.push_back(intTemp);
    else if (floatTemp->getRows() != NULL) matrices.floatMatrices.push_back(floatTemp);
    else if (doubleTemp->getRows() != NULL) matrices.doubleMatrices.push_back(doubleTemp);
}

void Application::DigitMultiplication() {
    short int type1, type2, value1;
    InputForOperations(type1, type2, value1, value1, 5);
    Matrix<int>* intTemp = new Matrix<int>();
    Matrix<float>* floatTemp = new Matrix<float>();
    Matrix<double>* doubleTemp = new Matrix<double>();
    try {
        if (type1 == 1) {
            if (type2 == 1) *intTemp = *matrices.intMatrices[value1 - 1] * matrices.intTempValue;
            else if (type2 == 2) *floatTemp = *matrices.intMatrices[value1 - 1] * matrices.floatTempValue;
            else *doubleTemp = *matrices.intMatrices[value1 - 1] * matrices.doubleTempValue;
        }
        else if (type1 == 2) {
            if (type2 == 1) *floatTemp = *matrices.floatMatrices[value1 - 1] * matrices.intTempValue;
            else if (type2 == 2) *floatTemp = *matrices.floatMatrices[value1 - 1] * matrices.floatTempValue;
            else *doubleTemp = *matrices.floatMatrices[value1 - 1] * matrices.doubleTempValue;
        }
        else {
            if (type2 == 1) *doubleTemp = *matrices.doubleMatrices[value1 - 1] * matrices.intTempValue;
            else if (type2 == 2) *doubleTemp = *matrices.doubleMatrices[value1 - 1] * matrices.floatTempValue;
            else *doubleTemp = *matrices.doubleMatrices[value1 - 1] * matrices.doubleTempValue;
        }
    }
    catch (const ProjectException& ex) { std::cout << ex.what() << std::endl; }
    if (intTemp->getRows() != NULL) matrices.intMatrices.push_back(intTemp);
    else if (floatTemp->getRows() != NULL) matrices.floatMatrices.push_back(floatTemp);
    else if (doubleTemp->getRows() != NULL) matrices.doubleMatrices.push_back(doubleTemp);

}

void Application::MatrixMultiplication() {
    short int type1, type2, value1, value2;
    InputForOperations(type1, type2, value1, value2, 6);
    Matrix<int>* intTemp = new Matrix<int>();
    Matrix<float>* floatTemp = new Matrix<float>();
    Matrix<double>* doubleTemp = new Matrix<double>();
    try {
        if (type1 == 1) {
            if (type2 == 1) *intTemp = *matrices.intMatrices[value1 - 1] * *matrices.intMatrices[value2 - 1];
            else if (type2 == 2) *floatTemp = *matrices.intMatrices[value1 - 1] * *matrices.floatMatrices[value2 - 1];
            else *doubleTemp = *matrices.intMatrices[value1 - 1] * *matrices.doubleMatrices[value2 - 1];
        }
        else if (type1 == 2) {
            if (type2 == 1) *floatTemp = *matrices.floatMatrices[value1 - 1] * *matrices.intMatrices[value2 - 1];
            else if (type2 == 2) *floatTemp = *matrices.floatMatrices[value1 - 1] * *matrices.floatMatrices[value2 - 1];
            else *doubleTemp = *matrices.floatMatrices[value1 - 1] * *matrices.doubleMatrices[value2 - 1];
        }
        else {
            if (type2 == 1) *doubleTemp = *matrices.doubleMatrices[value1 - 1] * *matrices.intMatrices[value2 - 1];
            else if (type2 == 2) *doubleTemp = *matrices.doubleMatrices[value1 - 1] * *matrices.floatMatrices[value2 - 1];
            else *doubleTemp = *matrices.doubleMatrices[value1 - 1] * *matrices.doubleMatrices[value2 - 1];
        }
    }
    catch (const ProjectException& ex) { std::cout << ex.what() << std::endl; }
    if (intTemp->getRows() != NULL) matrices.intMatrices.push_back(intTemp);
    else if (floatTemp->getRows() != NULL) matrices.floatMatrices.push_back(floatTemp);
    else if (doubleTemp->getRows() != NULL) matrices.doubleMatrices.push_back(doubleTemp);
}

void Application::VectorMultiplication() {
    short int type1, type2, value1;
    InputForOperations(type1, type2, value1, value1, 7);
    Matrix<int>* intTemp = new Matrix<int>();
    Matrix<float>* floatTemp = new Matrix<float>();
    Matrix<double>* doubleTemp = new Matrix<double>();
    try {
        if (type1 == 1) {
            if (type2 == 1) {
                Matrix<int>* TempVector = new Matrix<int>(matrices.intMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Размер текущего вектора: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *intTemp = *matrices.intMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else if (type2 == 2) {
                Matrix<float>* TempVector = new Matrix<float>(matrices.intMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Размер текущего вектора: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *floatTemp = *matrices.intMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else {
                Matrix<double>* TempVector = new Matrix<double>(matrices.intMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Размер текущего вектора: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *doubleTemp = *matrices.intMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
        }
        else if (type1 == 2) {
            if (type2 == 1) {
                Matrix<int>* TempVector = new Matrix<int>(matrices.floatMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Размер текущего вектора: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *floatTemp = *matrices.floatMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else if (type2 == 2) {
                Matrix<float>* TempVector = new Matrix<float>(matrices.floatMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Размер текущего вектора: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *floatTemp = *matrices.floatMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else {
                Matrix<double>* TempVector = new Matrix<double>(matrices.floatMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Размер текущего вектора: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *doubleTemp = *matrices.floatMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
        }
        else {
            if (type2 == 1) {
                Matrix<int>* TempVector = new Matrix<int>(matrices.doubleMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Размер текущего вектора: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *doubleTemp = *matrices.doubleMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else if (type2 == 2) {
                Matrix<float>* TempVector = new Matrix<float>(matrices.doubleMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Размер текущего вектора: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *doubleTemp = *matrices.doubleMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else {
                Matrix<double>* TempVector = new Matrix<double>(matrices.doubleMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Размер текущего вектора: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *doubleTemp = *matrices.doubleMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
        }
    }
    catch (const ProjectException& ex) { std::cout << ex.what() << std::endl; }
    if (intTemp->getRows() != NULL) matrices.intMatrices.push_back(intTemp);
    else if (floatTemp->getRows() != NULL) matrices.floatMatrices.push_back(floatTemp);
    else if (doubleTemp->getRows() != NULL) matrices.doubleMatrices.push_back(doubleTemp);
}

void Application::EqualMatrix() {
    short int type, value1, value2;
    InputForOperations(type, type, value1, value2, 8);
    if (type == 1) *matrices.intMatrices[value1 - 1] == *matrices.intMatrices[value2 - 1] ? std::cout << "Матрицы равнозначны" << std::endl : std::cout << "Матрицы неравнозначны" << std::endl;
    else if (type == 2) *matrices.floatMatrices[value1 - 1] == *matrices.floatMatrices[value2 - 1] ? std::cout << "Матрицы равнозначны" << std::endl : std::cout << "Матрицы неравнозначны" << std::endl;
    else *matrices.doubleMatrices[value1 - 1] == *matrices.doubleMatrices[value2 - 1] ? std::cout << "Матрицы равнозначны" << std::endl : std::cout << "Матрицы неравнозначны" << std::endl;
}

void Application::MatrixAssigment() {
    short int type, value1, value2;
    InputForOperations(type, type, value1, value2, 9);
    if (type == 1) *matrices.intMatrices[value1 - 1] = *matrices.intMatrices[value2 - 1];
    else if (type == 2) *matrices.floatMatrices[value1 - 1] = *matrices.floatMatrices[value2 - 1];
    else *matrices.doubleMatrices[value1 - 1] = *matrices.doubleMatrices[value2 - 1];
}

void Application::LoadMatrixToFile() {
    short int type, value;
    std::string path;
    OutputMatrixSettings(path, type, value);
    switch (type) {
    case 1: {
        if (value != -1) matrices.intMatrices[value - 1]->OutputMatrixInFile(path);
        else {
            for (size_t i = 0; i < matrices.intMatrices.size(); i++)
                matrices.intMatrices[i]->OutputMatrixInFile(path);
        }
        break;
    }
    case 2: {
        if (value != -1) matrices.floatMatrices[value - 1]->OutputMatrixInFile(path);
        else {
            for (size_t i = 0; i < matrices.floatMatrices.size(); i++)
                matrices.floatMatrices[i]->OutputMatrixInFile(path);
        }
        break;
    }
    case 3: {
        if (value != -1) matrices.doubleMatrices[value - 1]->OutputMatrixInFile(path);
        else {
            for (size_t i = 0; i < matrices.doubleMatrices.size(); i++)
                matrices.doubleMatrices[i]->OutputMatrixInFile(path);
        }
        break;
    }
    }
}

void Application::OutputMatrix() {
    short int type, value;
    OutputMatrixSettings(type, value);
    switch (type) {
    case 1: {
        if (value != -1) matrices.intMatrices[value - 1]->OutputMatrix();
        else {
            for (size_t i = 0; i < matrices.intMatrices.size(); i++) {
                std::cout << "Матрица номер " << i + 1 << ":" << std::endl;
                matrices.intMatrices[i]->OutputMatrix();
            }
        }
        break;
    }
    case 2: {
        if (value != -1) matrices.floatMatrices[value - 1]->OutputMatrix();
        else {
            for (size_t i = 0; i < matrices.floatMatrices.size(); i++) {
                std::cout << "Матрица номер " << i + 1 << ":" << std::endl;
                matrices.floatMatrices[i]->OutputMatrix();
            }
        }
        break;
    }
    case 3: {
        if (value != -1) matrices.doubleMatrices[value - 1]->OutputMatrix();
        else {
            for (size_t i = 0; i < matrices.doubleMatrices.size(); i++) {
                std::cout << "Матрица номер " << i + 1 << ":" << std::endl;
                matrices.doubleMatrices[i]->OutputMatrix();
            }
        }
        break;
    }
    }
}

void Application::DeleteMatrix() {
    short int type, value;
    InputForOperations(type, type, value, value, 12);
    if (type == 1) {
        if (value == -1) {
            for (size_t i = 0; i < matrices.intMatrices.size(); i++)
                matrices.intMatrices[i]->~Matrix();
            matrices.intMatrices.clear();
        }
        else {
            matrices.intMatrices[value - 1]->~Matrix();
            matrices.intMatrices.erase(matrices.intMatrices.begin() + value - 1);
        }
    }
    else if (type == 2) {
        if (value == -1) {
            for (size_t i = 0; i < matrices.floatMatrices.size(); i++)
                matrices.floatMatrices[i]->~Matrix();
            matrices.floatMatrices.clear();
        }
        else {
            matrices.floatMatrices[value - 1]->~Matrix();
            matrices.floatMatrices.erase(matrices.floatMatrices.begin() + value - 1);
        }
    }
    else {
        if (value == -1) {
            for (size_t i = 0; i < matrices.doubleMatrices.size(); i++)
                matrices.doubleMatrices[i]->~Matrix();
            matrices.doubleMatrices.clear();
        }
        else {
            matrices.doubleMatrices[value - 1]->~Matrix();
            matrices.doubleMatrices.erase(matrices.doubleMatrices.begin() + value - 1);
        }
    }
}

void Application::ClearConsole() {
    std::cout << "Очищаю окно вывода..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    system("cls");
}

void Application::ExecuteOperation(const std::function<void()>& func) {
    short back;
    while (true) {
        func();
        std::cout << "==============================\n"
            << " | Вернуться в главное меню |\n"
            << " | 1. Да                    |\n"
            << " | 2. Нет                   |\n"
            << "==============================\n";
        while (true) {
            std::cout << ">>> ";
            safeInput(back);
            if (back == 1) return;
            else if (back == 2) break;
            else std::cout << "Введена неверная операция." << std::endl;
        }
    }
}

void Application::StartApplication() {
    int option;
    std::vector <std::function<void()>> FuncVector = { Application::exitOperation, Application::KeyboardInputMatrix, Application::FileInputMatrix,
        Application::MatrixAddition, Application::MatrixSubtraction, Application::DigitMultiplication, Application::MatrixMultiplication,
        Application::VectorMultiplication, Application::EqualMatrix, Application::MatrixAssigment, Application::LoadMatrixToFile,
        Application::OutputMatrix, Application::DeleteMatrix, Application::ClearConsole, Application::printInfo };
    while (true) {
        printMenu();
        safeInput(option);
        if (option < 0 || option > 14) std::cout << "Вы неверно ввели значение операции. Попробуйте еще раз." << std::endl;
        else if (option == 0 || option == 14) ExecuteOperation(FuncVector[option]);
        else if (option == 13) ClearConsole();
        else {
            if (option == 1 || option == 2) ExecuteOperation(FuncVector[option]);
            else if ((option == 3 || option == 4 || option == 5 || option == 6 || option == 7 || option == 10 || option == 11 || option == 12)
                && (matrices.intMatrices.size() > 0 || matrices.floatMatrices.size() > 0 || matrices.doubleMatrices.size() > 0)) ExecuteOperation(FuncVector[option]);
            else if ((option == 8 || option == 9) && (matrices.intMatrices.size() > 1 || matrices.floatMatrices.size() > 1 || matrices.doubleMatrices.size() > 1))
                ExecuteOperation(FuncVector[option]);
            else std::cout << "Недостаточно данных для выполнения данной операции" << std::endl;
        }
    }
}