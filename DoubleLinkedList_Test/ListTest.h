#pragma once
#include "DoubleLinkedList.h"

void ScoreData_Init(ScoreData* _scoredata);
bool Check_Data(DoubleLinkedList::ConstIterator* _constiterator, ScoreData* _checker);      //Nodeの中のデータが引数のものと同一が比較する(テスト用関数)
ScoreData* Set_ScoreData(int _score, const char* _username); //成績データを代入する(テスト用)