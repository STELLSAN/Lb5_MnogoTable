#pragma once
#include <string>
#include <stdio.h> 
#include <time.h> 
#include "TScanTable.h" 
#include "TSortTable.h" 
#include "TWarAndWorld.h"
#include "InputHandler.h"


class TestScan
{
    std::vector<char> _punctMarks{ '\n', '\t', ' ', '.', ',', '!', '?', ':', ';', '"', '(', ')', '-', '[', ']', '*' };
public:
    double TestInsert(TTable* a, std::string st, TWarAndWorld* waw) {
        clock_t start = clock();
        a->InsertRecord(st, waw);
        clock_t end = clock();
        return  (double)(end - start) / CLOCKS_PER_SEC;
    }

    double TestFind(TTable* a, std::string st) {
        clock_t start = clock();
        a->FindRecord(st);
        clock_t end = clock();
        return  (double)(end - start) / CLOCKS_PER_SEC;
    }

    double TestDelete(TTable* a, std::string st) {
        clock_t start = clock();
        a->DeleteRecord(st);
        clock_t end = clock();
        return  (double)(end - start) / CLOCKS_PER_SEC;
    }


    double TestBubbleSort(TScanTable* a) {
        TSortTable* a2 = new TSortTable(*a);
        a2->SetSortMethod(BubbleSort);
        clock_t start = clock();
        a2->SortData();
        clock_t end = clock();

        return  (double)(end - start) / CLOCKS_PER_SEC;
    }

    double TestFreeChoice(TScanTable* a) {
        TSortTable* a2 = new TSortTable(*a);
        a2->SetSortMethod(FreeChoice);
        clock_t start = clock();
        a2->SortData();
        clock_t end = clock();
        return  (double)(end - start) / CLOCKS_PER_SEC;

    }
    double TestQuickSort(TScanTable* a) {
        TSortTable* a2 = new TSortTable(*a);
        a2->SetSortMethod(QuickSort);
        clock_t start = clock();
        a2->SortData();
        clock_t end = clock();
        return  (double)(end - start) / CLOCKS_PER_SEC;

    }

    double TestMergeSort(TScanTable* a) {
        TSortTable* a2 = new TSortTable(*a);
        a2->SetSortMethod(MergeSort);
        clock_t start = clock();
        a2->SortData();
        clock_t end = clock();
        return  (double)(end - start) / CLOCKS_PER_SEC;

    }
    double TestInsertSort(TScanTable* a) {
        TSortTable* a2 = new TSortTable(*a);
        a2->SetSortMethod(InsertSort);
        clock_t start = clock();
        a2->SortData();
        clock_t end = clock();
        return  (double)(end - start) / CLOCKS_PER_SEC;

    }
    double TestWordSearch(TTable* tst, std::string Path) {
        std::ifstream in(Path );
        double value = 0;
        std::vector<char> _punctMark_{ { '\n', '\t', ' ', '.', ',', '!', '?', ':', ';', '"', '(', ')', '-', '[', ']', '*'} };
        if (in.is_open())
        {

            std::string line;
            while (getline(in, line)) {
                std::string tempStr;

                
                for (int i = 0; i < line.size(); i++) {
                    if (std::find(_punctMark_.begin(), _punctMark_.end(), line[i]) == _punctMark_.end()) {
                        if (!('0' <= line[i] && line[i] <= '9')) {
                            tempStr += line[i];

                        }

                    }
                    else {
                        value+=WordFind(tst, tempStr);
                        tempStr.clear();
                    }

                }
            }
        };
        return value;
    }

    double WordFind(TTable* tst, std::string st) {
        clock_t start = clock();
        tst->FindRecord(st);
        clock_t end = clock();
        return  (double)(end - start) / CLOCKS_PER_SEC;
    }

};

