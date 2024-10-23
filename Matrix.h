#pragma once

#include "ProjectException.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

enum Types { INT = 1, FLOAT = 2, DOUBLE = 3 };

template<class T> class Matrix {
private:
	T** matrix;
	int rows;
	int columns;
	Types type;
	void SetMatrixData();
public:

	Matrix(int rows = 0, int columns = 0);
	~Matrix();

	void InputMatrixFromFile(std::string path);
	void InputOwnMatrix();
	void OutputMatrixInFile(std::string path);
	void OutputMatrix();

	Matrix<T>& operator=(const Matrix<T>& other);
	bool operator==(const Matrix<T>& other);
	bool operator!=(const Matrix<T>& other);
	template<class U> Matrix<decltype(T{} - U{})> operator-(const Matrix<U>& other);
	template<class U> Matrix<decltype(T{} + U{})> operator+(const Matrix<U>& other);
	template<class U> Matrix<decltype(T{} * U{})> operator*(const U& value);
	template<class U> Matrix<decltype(T{} * U{})> operator*(const Matrix<U>& other);

	int getRows() const;
	int getColumns() const;
	T** getMatrix() const;
};

template<class T>
void Matrix<T>::SetMatrixData() {
	matrix = new T * [this->rows];
	for (size_t i = 0; i < this->rows; i++) {
		matrix[i] = new T[this->columns];
	}
}

template<class T>
Matrix<T>::Matrix(int rows, int columns) {
	this->rows = rows;
	this->columns = columns;
	std::string typeName = typeid(T).name();
	this->type = typeName == "int"   ? Types::INT :
				 typeName == "float" ? Types::FLOAT :
									   Types::DOUBLE;
	this->SetMatrixData();
}

template<class T>
Matrix<T>::~Matrix() {
	for (size_t i = 0; i < this->rows; i++)
		delete[] this->matrix[i];
	delete[] this->matrix;
	this->rows = this->columns = NULL;
}

template<class T>
void Matrix<T>::InputMatrixFromFile(std::string path) {
	std::ifstream fin;
	fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	try { 
		fin.open(path);
	} 
	catch (const std::ios_base::failure& e) { 
		throw ProjectException("Îøèáêà èìåíè ôàéëà.");
	}
	std::string info;
	std::vector<T> elements;
	while (!fin.eof()) {
		fin >> info;
		if (this->rows == NULL)
			this->rows = std::stoi(info);
		else if (this->columns == NULL)
			this->columns = std::stoi(info);
		else {
			auto ptr = std::find(info.begin(), info.end(), '.');
			if (ptr != info.end())
				*ptr = ',';
			if (this->type == INT) {
				int value = std::stoi(info);
				elements.push_back(value);
			}
			else if (this->type == FLOAT) {
				float value = std::stof(info);
				elements.push_back(value);
			}
			else {
				double value = std::stod(info);
				elements.push_back(value);
			}
		}
		info.clear();
	}
	this->SetMatrixData();
	short int index = 0;
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			this->matrix[i][j] = elements[index++];
		}
	}
	elements.~vector();
}

template<class T>
void Matrix<T>::InputOwnMatrix() {
	std::cout << "Ââåäèòå ýëåìåíòû ìàòðèöû:" << std::endl;
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			std::cin >> this->matrix[i][j];
		}
	}
}

template<class T>
void Matrix<T>::OutputMatrixInFile(std::string path) {
	while (true) {
		if (path.find(".txt") == std::string::npos) {
			std::cout << "Íåâåðíîå èìÿ ôàéëà ïîïðîáóéòå åùå ðàç." << std::endl;
			std::cin >> path;
		}
		else break;
	}
	std::ofstream fout;
	fout.open(path, std::ofstream::app);
	fout << "Ðàçìåðû ìàòðèöû: " << this->rows << " " << this->columns << "\n" << "Ýëåìåíòû ìàòðèöû:" << "\n";
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			fout << this->matrix[i][j] << "\t";
		}
		fout << "\n";
	}
}

template<class T>
void Matrix<T>::OutputMatrix() {
	std::cout << "Ðàçìåðû ìàòðèöû: " << this->rows << " " << this->columns << std::endl << "Ýëåìåíòû ìàòðèöû:" << std::endl;
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			this->type == INT ? std::cout << " " << std::setw(8) << this->matrix[i][j] : std::cout << " " << std::fixed << std::setprecision(2) << std::setw(10) << this->matrix[i][j];
		}
		std::cout << std::endl;
	}
}

template<class T>
inline int Matrix<T>::getRows() const
{
	return this->rows;
}

template<class T>
inline int Matrix<T>::getColumns() const
{
	return this->columns;
}

template<class T>
inline T** Matrix<T>::getMatrix() const
{
	return this->matrix;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
	this->~Matrix();
	this->rows = other.getRows();
	this->columns = other.getColumns();
	this->SetMatrixData();
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			this->matrix[i][j] = other.getMatrix()[i][j];
		}
	}
	return *this;
}

template<class T>
bool Matrix<T>::operator==(const Matrix<T>& other) {
	if (this->rows == other.getRows() && this->columns == other.getColumns()) {
		for (size_t i = 0; i < this->rows; i++) {
			for (size_t j = 0; j < this->columns; j++) {
				if (this->matrix[i][j] != other.getMatrix()[i][j])
					return false;
			}
		}
		return true;
	}
	return false;
}

template<class T>
bool Matrix<T>::operator!=(const Matrix<T>& other) { return !(*this == other); }

template<class T>
template<class U>
Matrix<decltype(T{} - U{})> Matrix<T>::operator-(const Matrix<U>& other) {
	if (this->rows != other.getRows() || this->columns != other.getColumns())
		throw ProjectException("Íåâîçìîæíî âûïîëíèòü îïåðàöèþ \"-\" ñ äàííûìè ìàòðèöàìè.");
	Matrix<decltype(T{} - U{})> temp(this->rows, this->columns);
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			temp.getMatrix()[i][j] = this->matrix[i][j] - other.getMatrix()[i][j];
		}
	}
	return temp;
}

template<class T>
template<class U>
Matrix<decltype(T{} + U{})> Matrix<T>::operator+(const Matrix<U>& other) {
	if (this->rows != other.getRows() || this->columns != other.getColumns())
		throw ProjectException("Íåâîçìîæíî âûïîëíèòü îïåðàöèþ \"+\" ñ äàííûìè ìàòðèöàìè.");
	Matrix<decltype(T{} + U{})> temp(this->rows, this->columns);
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			temp.getMatrix()[i][j] = this->matrix[i][j] + other.getMatrix()[i][j];
		}
	}
	return temp;
}

template<class T>
template<class U>
Matrix<decltype(T{} * U{})> Matrix<T>::operator*(const U& value) {
	Matrix<decltype(T{} * U{})> temp(this->rows, this->columns);
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			temp.getMatrix()[i][j] = this->matrix[i][j];
			temp.getMatrix()[i][j] *= value;
		}
	}
	return temp;
}

template<class T>
template<class U>
Matrix<decltype(T{} * U{})> Matrix<T>::operator*(const Matrix<U>& other) {
	if (this->columns != other.getRows())
		throw ProjectException("Íåâîçìîæíî âûïîëíèòü îïåðàöèþ \"*\" ñ äàííûìè ìàòðèöàìè.");
	else {
		Matrix<decltype(T{} * U{})> temp(this->rows, other.getColumns());
		for (size_t i = 0; i < this->rows; i++) {
			for (size_t j = 0; j < other.getColumns(); j++) {
				temp.getMatrix()[i][j] = 0;
				for (size_t k = 0; k < this->columns; k++) {
					temp.getMatrix()[i][j] += this->matrix[i][k] * other.getMatrix()[k][j];
				}
			}
		}
		return temp;
	}
}
