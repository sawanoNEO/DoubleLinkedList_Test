#include "DoubleLinkedList.h"
#include "pch.h"

DoubleLinkedList::DoubleLinkedList()
{
	m_Node = new DoubleLinkedList::Node;
	m_Node->scoredata = new ScoreData;
	m_Node->next = new DoubleLinkedList::Node;
	m_Node->prev = new DoubleLinkedList::Node;
	m_Node->next->scoredata = new ScoreData;
	m_Node->prev->scoredata = new ScoreData;
	m_ConstIterator = new DoubleLinkedList::ConstIterator;
	m_Iterator = new DoubleLinkedList::Iterator;

	m_HeadNode = m_Node;
	m_HeadNode->next = m_Node->next;
	m_HeadNode->prev = m_Node->prev;
	m_TailNode = m_Node;
	m_TailNode->next = m_Node->next;
	m_TailNode->prev = m_Node->prev;

	ScoreData_Init(m_Node->scoredata);
	ScoreData_Init(m_Node->next->scoredata);
	ScoreData_Init(m_Node->prev->scoredata);
	
	m_ConstIterator->operator=(m_Node);
	m_Iterator->operator=(m_ConstIterator);
	m_HeadConstIterator = m_Iterator;
	m_HeadIterator = m_Iterator;
	m_TailIterator = m_Iterator;
	m_TailConstIterator = m_Iterator;
}

DoubleLinkedList::~DoubleLinkedList()
{
	delete m_Node;
}

//10/10からはここの作業から
int DoubleLinkedList::Count_Data()const
{
	ScoreData* tempScore;
	tempScore=Set_ScoreData(0,"dummy");
	int dataCount = 0;
	DoubleLinkedList::ConstIterator * citr;
	citr = Get_TailConstIterator();
	DoubleLinkedList::Node* node;
	node = citr->operator*();

	while (node->scoredata->Score)
	{
		dataCount++;
		node = node->prev;
	}



	return dataCount;
}

void DoubleLinkedList::Push_Back(ConstIterator* _iterator,ScoreData* _scoredata)
{
	if (_iterator->operator*())
	{
		m_Node = _iterator->operator*();
		m_Node->scoredata = _scoredata;
	}
	if (m_Node->next->scoredata)
	{
		//現在位置の前の次を現在位置とする
		m_Node->prev->next = m_Node;
		//現在位置を前の位置にする
		m_Node = m_Node->prev;
		//前の位置をnewする
		m_Node->prev = new DoubleLinkedList::Node;
	}
	//増やす次の要素が先頭要素だった場合に先頭を更新する
	if (m_Node->next == Get_HeadIterator()->operator*())
	{
		m_HeadNode = m_Node;
		m_HeadConstIterator->operator=(m_HeadNode);
		m_HeadIterator->operator = (m_HeadConstIterator);
	}
		_iterator->operator=(m_Node);
	
		m_TailNode = m_HeadNode->next;
		m_TailConstIterator->operator=(m_TailNode);
		m_TailIterator->operator=(m_TailConstIterator);

}

bool DoubleLinkedList::Delete_Data(ConstIterator* _iterator)
{

	DoubleLinkedList::Node* tempNode = _iterator->operator*();
	tempNode->prev->next = tempNode->next;
	tempNode->next->prev = tempNode->prev;
	_iterator->operator=(tempNode->next);
	delete tempNode;
	return true;
}

DoubleLinkedList::Iterator* DoubleLinkedList::Get_HeadIterator()
{
	return m_HeadIterator;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_HeadConstIterator()const
{
	return m_HeadConstIterator;
}

DoubleLinkedList::Iterator* DoubleLinkedList::Get_TailIterator()
{
	return m_TailIterator;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_TailConstIterator()const
{
	return m_TailConstIterator;
}


DoubleLinkedList::Node * DoubleLinkedList::Iterator::operator*()
{
	return mp_Node;
}

void DoubleLinkedList::Iterator::operator=(ConstIterator *_constiterator)
{
	this->mp_Node = _constiterator->operator*();
}

DoubleLinkedList::ConstIterator::ConstIterator()
{
}

DoubleLinkedList::ConstIterator::~ConstIterator()
{
	
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::ConstIterator::operator--()
{
	if (mp_Node->prev==nullptr)
	{
		mp_Node->prev->next = mp_Node;
		mp_Node = mp_Node->prev;
	}
	if (!&mp_Node)
	{
		mp_Node = new DoubleLinkedList::Node;
		mp_Node->scoredata->Score = 0;
		mp_Node->scoredata->UserName = "dummy";
	}
	return this;

}

void DoubleLinkedList::ConstIterator::operator--(int)
{
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::ConstIterator::operator++()
{
	mp_Node = mp_Node->next;
	if (!&mp_Node->next->scoredata)
	{
		mp_Node->next->scoredata->Score = 0;
		mp_Node->next->scoredata->UserName = "dummy";
	}
	return this;
}

void DoubleLinkedList::ConstIterator::operator++(int)
{
	mp_Node = mp_Node->next;
}

DoubleLinkedList::Node * DoubleLinkedList::ConstIterator::operator*()const
{
	if (mp_Node!=nullptr)
		return mp_Node;
	else
		return nullptr;
}

DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator & constiterator)
{
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::ConstIterator::operator=(DoubleLinkedList::Node* _node)
{
	mp_Node = _node;
	return this;
}

bool DoubleLinkedList::ConstIterator::operator==(ConstIterator* _constiterator)
{
	return false;
}

bool DoubleLinkedList::ConstIterator::operator!=(ConstIterator* _constiterator)
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

void ScoreData_Init(ScoreData * _scoredata)
{
	ScoreData* temp;
	temp = Set_ScoreData(0, "dummy");
	*_scoredata = *temp;
}

bool Check_Data(DoubleLinkedList::ConstIterator* _constiterator, ScoreData* _checker)
{
	if (_constiterator->operator*()!=nullptr)
	{
		if (_constiterator->operator*()->scoredata == _checker)
			return true;
	}
	else
		return false;
	return false;
}

ScoreData* Set_ScoreData(int _score, const char * _username)
{
	ScoreData* temp = new ScoreData;
	temp->Score = _score;
	temp->UserName = _username;
	return temp;
}
