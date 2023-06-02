#pragma once

#include<fstream>
#include<iostream>
#include<string>
#include<vector>

#include"TWarAndWorld.h"
#include"TScanTable.h"


class InputHandler
{
private:
    TTable* _ttbl;
    const std::vector<char> _punctMark = { '\n', '\t', ' ', '.', ',', '!', '?', ':', ';', '"', '(', ')', '-', '[', ']', '*'};
    int bookNumID;
public:
    
    InputHandler(TTable* table) {
        _ttbl = table;
        bookNumID = 0;
    }

    void ProcessInput(std::string filePath) {
        std::ifstream in(filePath ); 

        TypeSymbols typeTemp = TypeSymbols::DEFAULT;
        Letter firstTemp = Letter::DEFAULT;
        BookNum vol = BookNum::DEFAULT;;
        if (in.is_open())
        {

            std::string line;
            while (getline(in, line)) {
                std::string tempStr;

                for (int i = 0; i < line.size(); i++) {
                    if (std::find(_punctMark.begin(), _punctMark.end(), line[i]) == _punctMark.end()) {
                        if (!('0' <= line[i]&& line[i] <= '9')) {
                            tempStr += line[i];
                            
                        }

                    }
                    else {
                        if (tempStr != "") {
                            if (tempStr == "ÒÎM") {
                                bookNumID++;
                                switch (bookNumID) {
                                case 1:
                                    vol = BookNum::FIRST; break;
                                case 2:
                                    vol = BookNum::SECOND; break;
                                case 3:
                                    vol = BookNum::THIRD; break;
                                case 4:
                                    vol = BookNum::FORTH; break;
                                }
                            }

                            if (tempStr == "Ýïèëîã")
                                vol = BookNum::EPILOGUE;
                            

                            if (('a' <= tempStr[0]&& tempStr[0] <= 'z' )|| ('A' <= tempStr[0] && tempStr[0] <= 'Z'))
                                typeTemp = TypeSymbols::LATINIC;
                            else
                                typeTemp = TypeSymbols::CYRILIC;

                            if (('À' <= tempStr[0] && tempStr[0] <= 'ß') || ('A' <= tempStr[0] && tempStr[0] <= 'Z'))
                                firstTemp = Letter::ÑAPITAL;
                            else
                                firstTemp = Letter::SMALL;
                            WordProcessing(tempStr, typeTemp, firstTemp, vol);
                            tempStr.clear();
                        }

                    }               
                }
            };
          
        }
        in.close();
        std::cout << "File has been read" << std::endl;
	}

private:
    void WordProcessing(std::string st, TypeSymbols ts, Letter lttr, BookNum bnum) {
        auto *wordsInWarAndPeace = new TWarAndWorld(bnum, ts, lttr, st.size());
        _ttbl->InsertRecord(st, wordsInWarAndPeace);
        if (_ttbl->GetRetCode() == TAB_RECORD_DOUBLE) {
            auto value = (TWarAndWorld*)_ttbl->GetValuePtr();
            value->AddCount(bnum);
            delete wordsInWarAndPeace;
        }
    }



};

