#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

// fastChooses
template<class T>
uint64_t fastChoose(T* weight, T total_weight, double *random_number);

template<class T>
uint64_t fastChooseSkip(T* weight, T total_weight, double *random_number, uint64_t skip);

// Print data
template<class T>
void PrintArray1nd(std::string text, T* array, uint64_t size);

template<class T>
void PrintArray2nd(std::string text, T* array, uint64_t size1, uint64_t size2);

template<class T>
void PrintArray3nd(std::string text, T* array, uint64_t size1, uint64_t size2, uint64_t size3);

template<class T>
void PrintArray4nd(std::string text, T* array, uint64_t size1, uint64_t size2, uint64_t size3, uint64_t size4);

void PrintMutation(const Mutation& mutation);

// Some
uint64_t GetNewHaplotype(uint64_t haplotype, uint64_t site, uint64_t DS, uint64_t sites);

// Calculate indexes
std::vector<uint64_t> GetIndexes(int64_t index, uint64_t max_index);

// Validate data
void CheckValue(double value, std::string smth);

void CheckIndex(int64_t index, uint64_t max_index, std::string smth);

