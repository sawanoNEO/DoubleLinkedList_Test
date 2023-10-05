#include "DoubleLinkedList.h"
#include "pch.h"

DoubleLinkedList::DoubleLinkedList()
{
	m_Node = new Node;
	m_Head = m_Node;
	m_Tail = m_Node;

	m_Node->scoredata.Score = 00000;
	m_Node->scoredata.UserName = "nothing";
	m_Node->prev = m_Node;//暫定的な処置、本番では削除する
}

DoubleLinkedList::~DoubleLinkedList()
{
	delete m_Node;
}

int DoubleLinkedList::Count_Data()const
{
	return 0;
}

void DoubleLinkedList::Push_Back(ConstIterator* _iterator,ScoreData _scoredata)
{
	//DoubleLinkedList::Iterator* iterator =_iterator;
	//Node* node = _iterator->operator*;
	//node->scoredata = _scoredata;
}

bool DoubleLinkedList::Delete_Data(ConstIterator* _iterator)
{
	return false;
}

DoubleLinkedList::Iterator * DoubleLinkedList::Get_Iterator()
{
	return nullptr;
}

DoubleLinkedList::Iterator* DoubleLinkedList::Get_HeadIterator()
{
	return nullptr;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_HeadConstIterator()
{
	return &ConstIterator();
}

DoubleLinkedList::Iterator* DoubleLinkedList::Get_TailIterator()
{
	return nullptr;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_TailConstIterator()
{
	return &ConstIterator();
}

Node * DoubleLinkedList::Get_Node()
{
	//Node* node = new Node;
	//node->prev = new Node;
		return m_Node;
}

Node * DoubleLinkedList::Get_HeadNode()
{
	return m_Head;
}

Node * DoubleLinkedList::Get_TailNode()
{
	return m_Tail;
}


Node * DoubleLinkedList::Iterator::operator*()
{
	return nullptr;
}

DoubleLinkedList::ConstIterator::ConstIterator()
{
}

DoubleLinkedList::ConstIterator::~ConstIterator()
{
}

void DoubleLinkedList::ConstIterator::operator--()
{
}

void DoubleLinkedList::ConstIterator::operator++()
{
}

Node * const DoubleLinkedList::ConstIterator::operator*()
{
	return nullptr;
}

DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator & constiterator)
{
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator=(ConstIterator)
{
	return ConstIterator();
}

bool DoubleLinkedList::ConstIterator::operator==(ConstIterator)
{
	return false;
}

bool DoubleLinkedList::ConstIterator::operator!=(ConstIterator)
{
	return false;
}

//void DoubleLinkedList::ConstIterator::Push_ScoreData(int _score, const char * _username)
//{
//	//Node* temp=new Node;
//	//temp=this->operator*;
//	//temp->scoredata.Score = _score;
//	//temp->scoredata.UserName = _username;
//
//}

//bool Check_Data(ScoreData _scoredata, int _score, const char * _username)
//{
//	if (_scoredata.Score == _score && _scoredata.UserName == _username)
//	{
//		return true;
//	}
//
//	return false;
//}

bool Check_Data(ScoreData _scoredata, ScoreData _checker)
{
	return false;
}

void Set_ScoreData(ScoreData _scoredata, int _score, const char * _username)
{
	_scoredata.Score = _score;
	_scoredata.UserName = _username;
}
