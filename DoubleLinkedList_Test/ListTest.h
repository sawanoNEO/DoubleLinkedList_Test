#pragma once
#include "DoubleLinkedList.h"

void ScoreData_Init(ScoreData* _scoredata);
bool Check_Data(DoubleLinkedList::ConstIterator* _constiterator, ScoreData* _checker);      //Node�̒��̃f�[�^�������̂��̂Ɠ��ꂪ��r����(�e�X�g�p�֐�)
ScoreData* Set_ScoreData(int _score, const char* _username); //���уf�[�^��������(�e�X�g�p)