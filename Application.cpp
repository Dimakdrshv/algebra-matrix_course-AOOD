#include "Application.h"

struct Matrices {
    std::vector<Matrix<int>*> intMatrices;
    std::vector<Matrix<float>*> floatMatrices;
    std::vector<Matrix<double>*> doubleMatrices;

    int intTempValue; float floatTempValue; double doubleTempValue;

} matrices;

void Application::printMenu() {
    std::cout << "======================================================================\n" <<
                 " |                       Âûáåðèòå äåéñòâèå                          |\n" <<
                 " | 1.  Ââåñòè ìàòðèöó âðó÷íóþ                                       |\n" <<
                 " | 2.  Çàãðóçèòü ìàòðèöó èç ôàéëà                                   |\n" <<
                 " | 3.  Ñëîæèòü ìàòðèöû                                              |\n" <<
                 " | 4.  Âû÷åñòü ìàòðèöû                                              |\n" <<
                 " | 5.  Óìíîæèòü ìàòðèöó íà ÷èñëî                                    |\n" <<
                 " | 6.  Óìíîæèòü ìàòðèöû                                             |\n" <<
                 " | 7.  Óìíîæèòü ìàòðèöó íà âåêòîð                                   |\n" <<
                 " | 8.  Ñðàâíèòü ìàòðèöû                                             |\n" <<
                 " | 9.  Ïðèñâîåíèå ìàòðèö                                            |\n" <<
                 " | 10. Çàãðóçèòü çàïèñàííûå ìàòðèöû îïðåäåëåííîãî òèïà â ôàéë       |\n" <<
                 " | 11. Âûâåñòè ìàòðèöû îïðåäåëåííîãî òèïà íà ýêðàí                  |\n" <<
                 " | 12. Óäàëèòü ìàòðèöó                                              |\n" <<
                 " | 13. Î÷èñòèòü êîíñîëü                                             |\n" <<
                 " | 14. Èíôîðìàöèÿ î ïðîãðàììå                                       |\n" <<
                 " | 0.  Âûéòè                                                        |\n" <<
                 "======================================================================\n" <<
                 "Âàø âûáîð: ";
}

void Application::printInfo() {
    std::cout << "======================================================================\n" <<
                 " |                       Èíôîðìàöèÿ î ïðîãðàììå                     |\n" <<
                 " |   Ïðîãðàììà íàïèñàíà äëÿ âûïîëíåíèÿ äåéñòâèé ñ ìàòðèöàìè,        |\n" <<
                 " | êàæäàÿ èç êîòîðûõ èìååò ñîáñòâåííûé òèï äàííûõ, êîòîðûé çàäàåòñÿ |\n" <<
                 " | ïîëüçîâàòåëåì ñ êëàâèàòóðû. Ìàòðèöû õðàíÿòñÿ â 3 ðàçëè÷íûõ       |\n" <<
                 " | êîëëåêöèÿõ: Ìàòðèöû öåëî÷èñëåííîãî òèïà äàííûõ - int,            |\n" <<
                 " | âåùåñòâåííîãî - float, è ðàñøèðåííîãî âåùåñòâåííîãî - double.    |\n" <<
                 " |   Ïåðåãðóæåííûå îïåðàöèè \"+,-,*\" âûïîëíÿþòñÿ òàêèì îáðàçîì,      |\n" <<
                 " | ÷òî ïîëó÷èâøàÿ ìàòðèöà çàïèñûâàåòñÿ â êîëëåêöèþ ñ íàèáîëüøèì     |\n" <<
                 " | òèïîì äàííûõ, îòíîñèòåëüíî ìàòðèö\\÷èñåë, ñ êîòîðîìè              |\n" <<
                 " | ïðîèçâîäÿòñÿ äåéñòâèÿ.                                           |\n" <<
                 " |   Ïðåãðóæåííûå îïåðàöèè \"==, =\" âûïîëíÿþòñÿ îòíîñèòåëüíî         |\n" <<
                 " | ìàòðèö îäíîãî òèïà äàííûõ.                                       |\n" <<
                 " |   Òàêæå ïðåäóñìîòðåíà îïåðàöèÿ óäàëåíèÿ ìàòðèö è ïðåäëîæåíû      |\n" <<
                 " | âàðèàíòû ââîäà-âûâîäà ïîëó÷èâøèõñÿ ìàòðèö.                       |\n" <<
                 "======================================================================\n";
}

void Application::InputMatrixSettings(short int& type, short int& rows, short int& columns) {
    std::cout << "======================================================\n" 
              << " |           Ââåäèòå òèï ââîäèìîé ìàòðèöû           |\n" 
              << " | 1. int                                           |\n" 
              << " | 2. float                                         |\n" 
              << " | 3. double                                        |\n" 
              << "======================================================\n";
    while (true) {
        std::cout << ">>> ";
        std::cin >> type;
        if (type >= 1 && type <= 3) break;
        else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
    }
    std::cout << "Ââåäèòå êîëè÷åñòâî ñòðîê ìàòðèöû\n";
    while (true) {
        std::cout << ">>> ";
        std::cin >> rows;
        if (rows >= 1 && rows <= 6) break;
        else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
    }
    std::cout << "Ââåäèòå êîëè÷åñòâî ñòîáöîâ ìàòðèöû\n";
    while (true) {
        std::cout << ">>> ";
        std::cin >> columns;
        if (columns >= 1 && columns <= 6) break;
        else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
    }
}

void Application::InputMatrixSettings(std::string& path, short int& type) {
    std::cout << "Ââåäèòå ïóòü äî ôàéëà, ñ êîòîðîãî õîòèòå ñ÷èòàòü ìàòðèöó\n"
              << ">>> ";
    std::cin >> path;
    std::cout << "======================================================\n"
              << " |           Ââåäèòå òèï ââîäèìîé ìàòðèöû           |\n"
              << " | 1. int                                           |\n"
              << " | 2. float                                         |\n"
              << " | 3. double                                        |\n"
              << "======================================================\n";
    while (true) {
        std::cout << ">>> ";
        std::cin >> type;
        if (type >= 1 && type <= 3) break;
        else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
    }
}

void Application::InputType(short int& type) {
    while (true) {
        std::cout << ">>> ";
        std::cin >> type;
        if (type == 1) {
            if (matrices.intMatrices.size() != 0) {
                std::cout << "Êîëè÷åñòâî ìàòðèö ñ äàííûì òèïîì äàííûõ: " << matrices.intMatrices.size() << std::endl;
                break;
            }
            else std::cout << "Â äàííîì òèïå äàííûõ ïîêà íåò çàäàííûõ ìàòðèö." << std::endl;
        }
        else if (type == 2) {
            if (matrices.floatMatrices.size() != 0) {
                std::cout << "Êîëè÷åñòâî ìàòðèö ñ äàííûì òèïîì äàííûõ: " << matrices.floatMatrices.size() << std::endl;
                break;
            }
            else std::cout << "Â äàííîì òèïå äàííûõ ïîêà íåò çàäàííûõ ìàòðèö." << std::endl;
        }
        else if (type == 3) {
            if (matrices.doubleMatrices.size() != 0) {
                std::cout << "Êîëè÷åñòâî ìàòðèö ñ äàííûì òèïîì äàííûõ: " << matrices.doubleMatrices.size() << std::endl;
                break;
            }
            else std::cout << "Â äàííîì òèïå äàííûõ ïîêà íåò çàäàííûõ ìàòðèö." << std::endl;
        }
        else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
    }
}

void Application::InputValue(short int& value, short int type) {
    while (true) {
        std::cout << ">>> ";
        std::cin >> value;
        if (type == 1 && value > 0 && value <= matrices.intMatrices.size()) break;
        else if (type == 2 && value > 0 && value <= matrices.floatMatrices.size()) break;
        else if (type == 3 && value > 0 && value <= matrices.doubleMatrices.size()) break;
        else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
    }
}

void Application::InputForOperations(short int& type1, short int& type2, short int& value1, short int& value2, short int operationNumber) {
    if (operationNumber == 3 || operationNumber == 4 || operationNumber == 6) {
        std::cout << "======================================\n"
                  << " |    Ââåäèòå òèï ïåðâîé ìàòðèöû    |\n"
                  << " | 1. int                           |\n"
                  << " | 2. float                         |\n"
                  << " | 3. double                        |\n"
                  << "======================================\n";
        InputType(type1);
        std::cout << "Ââåäèòå íîìåð ìàòðèöû â êîëëåêöèè ìàòðèö äàííîãî òèïà" << std::endl;
        InputValue(value1, type1);
        std::cout << "======================================\n"
                  << " |    Ââåäèòå òèï âòîðîé ìàòðèöû    |\n" 
                  << " | 1. int                           |\n"
                  << " | 2. float                         |\n"
                  << " | 3. double                        |\n"
                  << "======================================\n";
        InputType(type2);
        std::cout << "Ââåäèòå íîìåð ìàòðèöû â êîëëåêöèè ìàòðèö äàííîãî òèïà" << std::endl;
        InputValue(value2, type2);
        std::cout << "=======================================================================\n" 
                  << " | Åñëè îïåðàöèÿ âûïîëíèòñÿ, òî ïîëó÷èâøàÿñÿ ìàòðèöà áóäåò äîáàâëåíà |\n"
                  << " | â êîëëåêöèþ, êîòîðàÿ èìååò áîëüøèé òèï äàííûõ, èíà÷å âûâåäåòñÿ    |\n" 
                  << " | ñîîáùåíèå îá îøèáêå.                                              |\n"
                  << "=======================================================================\n";
    }
    else if (operationNumber == 8 || operationNumber == 9) {
        std::cout << "==============================\n"
                  << " |    Ââåäèòå òèï ìàòðèö    |\n"
                  << " | 1. int                   |\n"
                  << " | 2. float                 |\n"
                  << " | 3. double                |\n"
                  << "==============================\n";
        InputType(type1);
        std::cout << "Ââåäèòå íîìåð ïåðâîé ìàòðèöû" << std::endl;
        InputValue(value1, type1);
        std::cout << "Ââåäèòå íîìåð âòîðîé ìàòðèöû" << std::endl;
        InputValue(value2, type1);
    }
    else if (operationNumber == 5) {
        std::cout << "===============================\n"
                  << " |    Ââåäèòå òèï ìàòðèöû    |\n"
                  << " | 1. int                    |\n"
                  << " | 2. float                  |\n"
                  << " | 3. double                 |\n"
                  << "===============================\n";
        InputType(type1);
        std::cout << "Ââåäèòå íîìåð ìàòðèöû" << std::endl;
        InputValue(value1, type1);
        std::cout << "==================================\n"
                  << " |    Ââåäèòå òèï ïåðåìåííîé    |\n"
                  << " | 1. int                       |\n"
                  << " | 2. float                     |\n"
                  << " | 3. double                    |\n"
                  << "=================================\n";
        while (true) {
            std::cout << ">>> ";
            std::cin >> type2;
            if (type2 >= 1 && type2 <= 3) break;
            else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
        }
        std::cout << "Ââåäèòå çíà÷åíèå ïåðåìåííîé: ";
        if (type2 == 1) std::cin >> matrices.intTempValue;
        else if (type2 == 2) std::cin >> matrices.floatTempValue;
        else std::cin >> matrices.doubleTempValue;
        std::cout << "=======================================================================\n"
                  << " | Åñëè îïåðàöèÿ âûïîëíèòñÿ, òî ïîëó÷èâøàÿñÿ ìàòðèöà áóäåò äîáàâëåíà |\n"
                  << " | â êîëëåêöèþ, êîòîðàÿ èìååò áîëüøèé òèï äàííûõ, èíà÷å âûâåäåòñÿ    |\n"
                  << " | ñîîáùåíèå îá îøèáêå.                                              |\n"
                  << "=======================================================================\n";
    }
    else if (operationNumber == 7) {
        std::cout << "===============================\n"
                  << " |    Ââåäèòå òèï ìàòðèöû    |\n"
                  << " | 1. int                    |\n"
                  << " | 2. float                  |\n"
                  << " | 3. double                 |\n"
                  << "===============================\n";
        InputType(type1);
        std::cout << "Ââåäèòå íîìåð ìàòðèöû" << std::endl;
        InputValue(value1, type1);
        std::cout << "=======================================\n"
                  << " |    Ââåäèòå òèï âåêòîðà ñòîëáöà    |\n"
                  << " | 1. int                            |\n"
                  << " | 2. float                          |\n"
                  << " | 3. double                         |\n"
                  << "=======================================\n";
        while (true) {
            std::cout << ">>> ";
            std::cin >> type2;
            if (type2 >= 1 && type2 <= 3) break;
            else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
        }
        std::cout << "=======================================================================\n"
                  << " | Åñëè îïåðàöèÿ âûïîëíèòñÿ, òî ïîëó÷èâøàÿñÿ ìàòðèöà áóäåò äîáàâëåíà |\n"
                  << " | â êîëëåêöèþ, êîòîðàÿ èìååò áîëüøèé òèï äàííûõ, èíà÷å âûâåäåòñÿ    |\n"
                  << " | ñîîáùåíèå îá îøèáêå.                                              |\n"
                  << "=======================================================================\n";
    }
    else {
        std::cout << "=========================================\n"
                  << " |    Ââåäèòå òèï óäàëÿåìîé ìàòðèöû    |\n"
                  << " | 1. int                              |\n"
                  << " | 2. float                            |\n"
                  << " | 3. double                           |\n"
                  << "========================================\n";
        InputType(type1);
        int msg;
        std::cout << "================================================\n"
                  << " |               Ââåäèòå îïåðàöèþ             |\n"
                  << " | 1. Óäàëèòü îïðåäåëåííóþ ìàòðèöó            |\n"
                  << " | 2. Óäàëèòü âñå ìàòðèöû äàííîãî òèïà äàííûõ |\n"
                  << "================================================\n";
        while (true) {
            std::cout << ">>> ";
            std::cin >> msg;
            if (msg == 1) {
                std::cout << "Ââåäèòå íîìåð ìàòðèöû, êîòîðóþ õîòèòå óäàëèòü" << std::endl;
                InputValue(value1, type1);
                break;
            }
            else if (msg == 2) { value1 = -1; return; }
            else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
        }
    }
}

void Application::OutputMatrixSettings(short int& type, short int& value) {
    std::cout << "=========================================\n"
              << " |    Ââåäèòå òèï âûâîäèìîé ìàòðèöû    |\n"
              << " | 1. int                              |\n"
              << " | 2. float                            |\n"
              << " | 3. double                           |\n"
              << "========================================\n";
    InputType(type);
    int msg;
    std::cout << "================================================\n"
              << " |               Ââåäèòå îïåðàöèþ             |\n"
              << " | 1. Âûâåñòè îïðåäåëåííóþ ìàòðèöó            |\n"
              << " | 2. Âûâåñòè âñå ìàòðèöû äàííîãî òèïà äàííûõ |\n"
              << "================================================\n";
    while (true) {
        std::cout << ">>> ";
        std::cin >> msg;
        if (msg == 1) break;
        else if (msg == 2) { value = -1; return; }
        else std::cout << "Âû ââåëè íåêîððåêòíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << std::endl;
    }
    std::cout << "Ââåäèòå íîìåð ìàòðèöû, êîòîðóþ õîòèòå âûâåñòè" << std::endl;
    InputValue(value, type);
}

void Application::OutputMatrixSettings(std::string& path, short int& type, short int& value) {
    std::cout << "Ââåäèòå ïóòü äî ôàéëà, â êîòîðûé õîòèòå âûâåñòè ìàòðèöó\n"
              << ">>> ";
    std::cin >> path;
    OutputMatrixSettings(type, value);
}

void Application::zeroOperation() {
    if (matrices.intMatrices.size() > 0 || matrices.floatMatrices.size() > 0 || matrices.doubleMatrices.size() > 0) {
        std::string path; std::cout << "Ââåäèòå ïóòü ê ôàéëó, â êîòîðûé çàïèøóòñÿ âñå ñîçäàííûå ìàòðèöû\n>>> "; std::cin >> path;
        for (size_t i = 0; i < matrices.intMatrices.size(); i++)
            matrices.intMatrices[i]->OutputMatrixInFile(path);
        for (size_t i = 0; i < matrices.floatMatrices.size(); i++)
            matrices.floatMatrices[i]->OutputMatrixInFile(path);
        for (size_t i = 0; i < matrices.doubleMatrices.size(); i++)
            matrices.doubleMatrices[i]->OutputMatrixInFile(path);
        std::cout << "Çàâåðøåíèå ïðîãðàììû. Âñå ñîçäàííûå ìàòðèöû çàïèñàíû â ôàéë";
    }
    else std::cout << "Çàâåðøåíèå ïðîãðàììû.";
    exit(0);
}

void Application::firstOperation() {
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

void Application::secondOperation() {
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

void Application::thirdOperation() {
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

void Application::fourthOperation() {
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

void Application::fifthOperation() {
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

void Application::sixthOperation() {
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

void Application::seventhOperation() {
    short int type1, type2, value1;
    InputForOperations(type1, type2, value1, value1, 7);
    Matrix<int>* intTemp = new Matrix<int>();
    Matrix<float>* floatTemp = new Matrix<float>();
    Matrix<double>* doubleTemp = new Matrix<double>();
    try {
        if (type1 == 1) {
            if (type2 == 1) {
                Matrix<int>* TempVector = new Matrix<int>(matrices.intMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Ðàçìåð òåêóùåãî âåêòîðà: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *intTemp = *matrices.intMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else if (type2 == 2) {
                Matrix<float>* TempVector = new Matrix<float>(matrices.intMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Ðàçìåð òåêóùåãî âåêòîðà: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *floatTemp = *matrices.intMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else {
                Matrix<double>* TempVector = new Matrix<double>(matrices.intMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Ðàçìåð òåêóùåãî âåêòîðà: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *doubleTemp = *matrices.intMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
        }
        else if (type1 == 2) {
            if (type2 == 1) {
                Matrix<int>* TempVector = new Matrix<int>(matrices.floatMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Ðàçìåð òåêóùåãî âåêòîðà: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *floatTemp = *matrices.floatMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else if (type2 == 2) {
                Matrix<float>* TempVector = new Matrix<float>(matrices.floatMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Ðàçìåð òåêóùåãî âåêòîðà: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *floatTemp = *matrices.floatMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else {
                Matrix<double>* TempVector = new Matrix<double>(matrices.floatMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Ðàçìåð òåêóùåãî âåêòîðà: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *doubleTemp = *matrices.floatMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
        }
        else {
            if (type2 == 1) {
                Matrix<int>* TempVector = new Matrix<int>(matrices.doubleMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Ðàçìåð òåêóùåãî âåêòîðà: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *doubleTemp = *matrices.doubleMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else if (type2 == 2) {
                Matrix<float>* TempVector = new Matrix<float>(matrices.doubleMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Ðàçìåð òåêóùåãî âåêòîðà: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
                TempVector->InputOwnMatrix();
                *doubleTemp = *matrices.doubleMatrices[value1 - 1] * *TempVector;
                TempVector->~Matrix();
            }
            else {
                Matrix<double>* TempVector = new Matrix<double>(matrices.doubleMatrices[value1 - 1]->getRows(), 1);
                std::cout << "Ðàçìåð òåêóùåãî âåêòîðà: (" << TempVector->getRows() << ", " << TempVector->getColumns() << ")" << std::endl;
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

void Application::eigthOperation() {
    short int type, value1, value2;
    InputForOperations(type, type, value1, value2, 8);
    if (type == 1) *matrices.intMatrices[value1 - 1] == *matrices.intMatrices[value2 - 1] ? std::cout << "Ìàòðèöû ðàâíîçíà÷íû" << std::endl : std::cout << "Ìàòðèöû íåðàâíîçíà÷íû" << std::endl;
    else if (type == 2) *matrices.floatMatrices[value1 - 1] == *matrices.floatMatrices[value2 - 1] ? std::cout << "Ìàòðèöû ðàâíîçíà÷íû" << std::endl : std::cout << "Ìàòðèöû íåðàâíîçíà÷íû" << std::endl;
    else *matrices.doubleMatrices[value1 - 1] == *matrices.doubleMatrices[value2 - 1] ? std::cout << "Ìàòðèöû ðàâíîçíà÷íû" << std::endl : std::cout << "Ìàòðèöû íåðàâíîçíà÷íû" << std::endl;
}

void Application::nineOperation() {
    short int type, value1, value2;
    InputForOperations(type, type, value1, value2, 9);
    if (type == 1) *matrices.intMatrices[value1 - 1] = *matrices.intMatrices[value2 - 1];
    else if (type == 2) *matrices.floatMatrices[value1 - 1] = *matrices.floatMatrices[value2 - 1];
    else *matrices.doubleMatrices[value1 - 1] = *matrices.doubleMatrices[value2 - 1];
}

void Application::tenthOperation() {
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

void Application::eleventhOperation() {
    short int type, value;
    OutputMatrixSettings(type, value);
    switch (type) {
    case 1: {
        if (value != -1) matrices.intMatrices[value - 1]->OutputMatrix();
        else {
            for (size_t i = 0; i < matrices.intMatrices.size(); i++) {
                std::cout << "Ìàòðèöà íîìåð " << i + 1 << ":" << std::endl;
                matrices.intMatrices[i]->OutputMatrix();
            }
        }
        break;
    }
    case 2: {
        if (value != -1) matrices.floatMatrices[value - 1]->OutputMatrix();
        else {
            for (size_t i = 0; i < matrices.floatMatrices.size(); i++) {
                std::cout << "Ìàòðèöà íîìåð " << i + 1 << ":" << std::endl;
                matrices.floatMatrices[i]->OutputMatrix();
            }
        }
        break;
    }
    case 3: {
        if (value != -1) matrices.doubleMatrices[value - 1]->OutputMatrix();
        else {
            for (size_t i = 0; i < matrices.doubleMatrices.size(); i++) {
                std::cout << "Ìàòðèöà íîìåð " << i + 1 << ":" << std::endl;
                matrices.doubleMatrices[i]->OutputMatrix();
            }
        }
        break;
    }
    }
}

void Application::twelfthOperation() {
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

void Application::thirteenthOperation() {
    std::cout << "Î÷èùàþ îêíî âûâîäà..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    system("cls");
}

void Application::ExecuteOperation(const std::function<void()>& func) {
    short back;
    while (true) {
        func();
        std::cout << "==============================\n"
            << " | Âåðíóòüñÿ â ãëàâíîå ìåíþ |\n"
            << " | 1. Äà                    |\n"
            << " | 2. Íåò                   |\n"
            << "==============================\n";
        while (true) {
            std::cout << ">>> ";
            std::cin >> back;
            if (back == 1) return;
            else if (back == 2) break;
            else std::cout << "Ââåäåíà íåâåðíàÿ îïåðàöèÿ." << std::endl;
        }
    }
}

void Application::StartApplication() {
    int option;
    std::vector <std::function<void()>> FuncVector = { Application::zeroOperation, Application::firstOperation, Application::secondOperation,
        Application::thirdOperation, Application::fourthOperation, Application::fifthOperation, Application::sixthOperation,
        Application::seventhOperation, Application::eigthOperation, Application::nineOperation, Application::tenthOperation,
        Application::eleventhOperation, Application::twelfthOperation, Application::thirteenthOperation, Application::printInfo };
    while (true) {
        printMenu();
        std::cin >> option;
        if (option < 0 || option > 14) std::cout << "Âû íåâåðíî ââåëè çíà÷åíèå îïåðàöèè. Ïîïðîáóéòå åùå ðàç." << std::endl;
        else if (option == 0 || option == 14) ExecuteOperation(FuncVector[option]);
        else if (option == 13) thirteenthOperation();
        else {
            if (option == 1 || option == 2) ExecuteOperation(FuncVector[option]);
            else if ((option == 3 || option == 4 || option == 5 || option == 6 || option == 7 || option == 10 || option == 11 || option == 12)
                && (matrices.intMatrices.size() > 0 || matrices.floatMatrices.size() > 0 || matrices.doubleMatrices.size() > 0)) ExecuteOperation(FuncVector[option]);
            else if ((option == 8 || option == 9) && (matrices.intMatrices.size() > 1 || matrices.floatMatrices.size() > 1 || matrices.doubleMatrices.size() > 1))
                ExecuteOperation(FuncVector[option]);
            else std::cout << "Íåäîñòàòî÷íî äàííûõ äëÿ âûïîëíåíèÿ äàííîé îïåðàöèè" << std::endl;
        }
    }
}
