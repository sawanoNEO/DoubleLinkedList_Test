#include "pch.h"
#include "ListTest.h"

//void ScoreData_Init(ScoreData * _scoredata)
//{
//	ScoreData* temp;
//	temp = Set_ScoreData(0, "dummy");
//	*_scoredata = *temp;
//}

//bool Check_Data(DoubleLinkedList::ConstIterator* _constiterator, ScoreData* _checker)
//{
//	const DoubleLinkedList::Node *reciveNode = *(*_constiterator);
//	const DoubleLinkedList::Node *tempNode = reciveNode;
//	//引数のイテレータがnullptrでない場合にチェックを行う
//	if (tempNode->scoredata != nullptr)
//	{
//		if (tempNode->scoredata->Score == _checker->Score&&
//			tempNode->scoredata->UserName == _checker->UserName)
//			return true;
//	}
//	return false;
//}

ScoreData Set_ScoreData(int _score, const char * _username)
{
	ScoreData temp;
	temp.Score = _score;
	temp.UserName = _username;
	return temp;
}
