#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "TScanTable.h"
#include <vector>
#include "TWarAndWorld.h"

class InputHandler
{
private:
	TTable* _table;
    std::vector<char> _punctMark{ { '\n', '\t', ' ', '.', ',', '!', '?', ':', ';', '"', '(', ')', '-', '[', ']', '*'} }; 
    int _bookNumId;
public:
	InputHandler(TTable* table) {
		_table = table;
        _bookNumId = 0;
	}
    
	void Execution(std::string Path) {
        std::ifstream input(Path); // открываем файл по заданному пути

        TypeSymbol typeSym = TypeSymbol::DEFAULT;
        TypeLetter letter = TypeLetter::DEFAULT;
        BookNumber bookNum = BookNumber::DEFAULT;;
        if (input.is_open())
        {

            std::string input_line;
            while (getline(input, input_line)) {
                std::string tmp_str;

                for (int i = 0; i < input_line.size(); i++) {
                    if (std::find(_punctMark.begin(), _punctMark.end(), input_line[i]) == _punctMark.end()) { // проход итератора, если не находим Mark, 
                        if (!('0' <= input_line[i]&& input_line[i] <= '9')) {
                            tmp_str += input_line[i];
                        }
                    }
                    else {
                        if (tmp_str != "") {
                            if (tmp_str == "ТОM") {
                                _bookNumId++;
                                switch (_bookNumId) {
                                case 1:
                                    bookNum = BookNumber::FIRST; break;
                                case 2:
                                    bookNum = BookNumber::SECOND; break;
                                case 3:
                                    bookNum = BookNumber::THIRD; break;
                                case 4:
                                    bookNum = BookNumber::FORTH; break;
                                }
                            }

                            if (tmp_str == "ЭПИЛОГ") {
                                bookNum = BookNumber::EPILOGUE;
                            }

                            if (('a' <= tmp_str[0] && tmp_str[0] <= 'z') || ('A' <= tmp_str[0] && tmp_str[0] <= 'Z')) {
                                typeSym = TypeSymbol::LATINIC;
                            }
                            else {
                                typeSym = TypeSymbol::CYRILLIC;
                            }

                            if (('А' <= tmp_str[0] && tmp_str[0] <= 'Я') || ('A' <= tmp_str[0] && tmp_str[0] <= 'Z')) {
                                letter = TypeLetter::СAPITAL;
                            }
                            else {
                                letter = TypeLetter::SMALL;
                            }
                            WordProcessing(tmp_str, typeSym, letter, bookNum);
                            tmp_str.clear();
                        }

                    }               
                }
            }; 
        }

        input.close();
        std::cout << "The file has been read" << std::endl;
	}
    
    
private:

    void WordProcessing( std::string st, TypeSymbol typeSym, TypeLetter letter, BookNumber bookNum ) {
        auto *wordsInWarAndPeace = new TWarAndWorld(bookNum, typeSym, letter, st.size());
        bool result = _table->InsertRecord(st, wordsInWarAndPeace);
        if (!result && _table->GetRetCode() == TAB_RECORD_DOUBLE) {
            auto value = (TWarAndWorld*)_table->GetValuePtr();
            value->AddCount( bookNum);
            delete wordsInWarAndPeace;
        }
    }
    
};

