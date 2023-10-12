#include "DoubleLinkedList.h"
#include "pch.h"

DoubleLinkedList::DoubleLinkedList()
{
	//各変数を生成する
	m_Node = new DoubleLinkedList::Node;
	m_Node->scoredata = new ScoreData;
	m_Node->next = new DoubleLinkedList::Node;
	m_Node->prev = new DoubleLinkedList::Node;
	m_Node->next->scoredata = new ScoreData;
	m_Node->prev->scoredata = new ScoreData;
	m_Iterator = new DoubleLinkedList::Iterator;
	m_ConstIterator = new DoubleLinkedList::ConstIterator;
	m_HeadConstIterator = new DoubleLinkedList::ConstIterator;
	m_HeadIterator = new DoubleLinkedList::Iterator;
	m_TailConstIterator	= new DoubleLinkedList::ConstIterator;
	m_TailIterator = new DoubleLinkedList::Iterator;

	//各ノードの初期化
	m_HeadNode = m_Node;
	m_HeadNode->next = m_Node->next;
	m_HeadNode->prev = m_Node->prev;
	m_TailNode = m_Node;
	m_TailNode->next = m_Node->next;
	m_TailNode->prev = m_Node->prev;

	//ダミーデータをスコアに入れる
	ScoreData_Init(m_Node->scoredata);
	ScoreData_Init(m_Node->next->scoredata);
	ScoreData_Init(m_Node->prev->scoredata);
	
	//各イテレータの初期化
	m_ConstIterator->operator=(m_Node);
    (*m_Iterator)=m_Node;

	(*m_HeadConstIterator) = m_HeadNode;
	(*m_HeadIterator) = m_HeadNode;
	(*m_TailConstIterator) = m_TailNode;
	(*m_TailIterator) = m_TailNode;

	data_Count = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
	
}

int DoubleLinkedList::Count_Data()const
{
	return data_Count;
}

void DoubleLinkedList::Push_Back(DoubleLinkedList::ConstIterator& _iterator,ScoreData* _scoredata)
{
	//イテレータから参照取得
	*m_Node=*_iterator;
	if (m_Node->prev)
	{
	    //参照場所の前にダミー以外のデータがあればノードを差し込む
		/*if (m_Node->prev->scoredata&&
			!(m_Node->prev->scoredata->Score == 0 &&
			m_Node->prev->scoredata->UserName == "dummy"))
		{
			m_Node->prev->next = new DoubleLinkedList::Node;
			m_Node->prev->next->scoredata = _scoredata;
			m_Node->prev->next->prev = m_Node->prev;
			m_Node->prev = m_Node->prev->next;
		}
		else*/
		{
			//データの挿入
			m_Node->prev->scoredata = _scoredata;
		}
	}
	else
		return;


	//要素を増やしたときに前の要素がnullなら先頭要素を更新
     	m_Node->prev->next = m_Node;
	    m_Node = m_Node->prev;
	if (!m_Node->prev)
	{
		m_Node->prev = new DoubleLinkedList::Node;
		m_HeadNode = m_Node;
		(*m_HeadConstIterator) = m_HeadNode;
		(*m_HeadIterator) = m_HeadNode;
	}

	--_iterator;
	data_Count++;
	//要素を増やしたときに前の要素がnullなら先頭要素を更新
	//if (!m_Node->prev->prev)
	//{
	//	m_Node->prev->prev = new DoubleLinkedList::Node;
	//}
	//this->m_Node->prev->next = m_Node;
	//m_Node = m_Node->prev;
	//if (!m_Node->prev)
	//{
	//	m_HeadNode = m_Node;
	//	(*m_HeadConstIterator) = m_HeadNode;
	//	(*m_HeadIterator) = m_HeadNode;
	//}
	//

	//--_iterator;

	//data_Count++;

	////要素を後ろにずらす
	//if (m_Node->prev)
	//{
	//	//現在位置の前の次を現在位置とする
	//	m_Node->prev->next = m_Node;
	//	//現在位置を前の位置にする
	//	m_Node = m_Node->prev;
	//	if (!m_Node->prev)
	//	{
	//		//前の位置をnewする
	//		m_Node->prev = new DoubleLinkedList::Node;
	//	}
	//}
	//else
	//{
	//	m_Node->prev = new DoubleLinkedList::Node;
	//	
	//	//現在位置の前の次に現在位置を代入する
	//	m_Node->prev->next = m_Node;
	//	//現在位置を前の位置にする
	//	m_Node = m_Node->prev;
	//	//前の位置をnewする
	//	m_Node->prev = new DoubleLinkedList::Node;
	//	
	//}
	////増やす次の要素が先頭要素だった場合に先頭を更新する
	//	if (m_Node->prev == *(*Get_HeadIterator()))
	//{
	//	m_HeadNode = m_Node;
	//	*m_HeadConstIterator = (m_HeadNode);
	//	*m_HeadIterator = (m_HeadConstIterator);
	//}
	////要素を後ろにずらす
	//	--_iterator;
	//	(*m_TailConstIterator) = m_TailNode;
	//	(*m_TailIterator) = m_TailConstIterator;
}

bool DoubleLinkedList::Delete_Data(ConstIterator& _iterator)
{
	*m_Node = *_iterator;
	if (!m_Node->prev)           //指定されたイテレータにデータがなければ処理を抜け出す
		return false;

	//指定されたイテレータのデータがダミーであれば処理を抜け出す
	ScoreData* tempScore=new ScoreData;
	ScoreData_Init(tempScore);
	if (Check_Data(&_iterator,tempScore))
		return false;
	if (m_Node == m_TailNode)
	{
		m_TailNode = m_Node->prev;
		(*m_TailConstIterator) = m_TailNode;
		(*m_TailIterator) = m_TailNode;
		--_iterator;
	}
	else if (m_Node == m_HeadNode)
	{
		m_HeadNode = m_Node->next;
		(*m_HeadConstIterator) = m_HeadNode;
		(*m_HeadIterator) = m_HeadNode;
		++_iterator;
	}
	//else
	//{

	//}

	delete m_Node;
	data_Count--;
	return true;

	////m_Node = *_iterator;

	//////指定されたイテレータのデータがダミーであれば処理を抜け出す
	////if (m_Node->scoredata->Score == 0 &&
	////	m_Node->scoredata->UserName == "dummy")
	////	return false;
	////if (m_Node == m_TailNode)
	////{
	////	m_TailNode = m_Node->prev;
	////	(*m_TailConstIterator) = m_TailNode;
	////	(*m_TailIterator) = m_TailNode;
	////	--_iterator;
	////}
	////else if (m_Node == m_HeadNode)
	////{
	////	m_HeadNode = m_Node->next;
	////	(*m_HeadConstIterator) = m_HeadNode;
	////	(*m_HeadIterator) = m_HeadNode;
	////	++_iterator;
	////}
	////else
	////{

	////}

	////delete m_Node;
	////return true;

	/*ScoreData* tempScore = new ScoreData;
	ScoreData_Init(tempScore);
	const DoubleLinkedList::Node* tempNode = *(*_iterator);
	if (Check_Data(_iterator,tempScore)==true)
	{
    	delete tempScore;
	    return false;
	}
	else
	{
		tempNode->prev->next = tempNode->next;
		tempNode->next->prev = tempNode->prev;
		_iterator->operator=(tempNode->next);

		delete tempScore;
		delete tempNode;
		return true;
	}*/
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

void DoubleLinkedList::Iterator::operator=(DoubleLinkedList::Node* _node)
{
	mp_Node = _node;
}

DoubleLinkedList::ConstIterator::ConstIterator()
{
	mp_Node = nullptr;
}

DoubleLinkedList::ConstIterator::~ConstIterator()
{
	
}

DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator--()
{
	if(mp_Node->prev)
	mp_Node = mp_Node->prev;

	return *this;
}

void DoubleLinkedList::ConstIterator::operator--(int)
{
}

DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator++()
{
	//ScoreData* tempData=new ScoreData;
	//ScoreData_Init(tempData);

	////データの移行
	//mp_Node->next->prev = mp_Node;
	//mp_Node = mp_Node->next;

	////移行後のデータの次の要素のデータが初期化されていなかったら初期化する
	//if (!mp_Node->next)
	//{
	//	mp_Node->next=new DoubleLinkedList::Node;
	//	mp_Node->next->scoredata = new ScoreData;
	//	mp_Node->next->scoredata->Score = 0;
	//	mp_Node->next->scoredata->UserName = "dummy";
	//}
	//delete tempData;
	if(mp_Node->next)
	mp_Node = mp_Node->next;
	return *this;
}

void DoubleLinkedList::ConstIterator::operator++(int)
{
	mp_Node = mp_Node->next;
}

DoubleLinkedList::Node& DoubleLinkedList::ConstIterator::operator*()const
{
	if (mp_Node != nullptr)
		return *mp_Node;
	else
	{
		DoubleLinkedList::Node tempNode;
		return tempNode;
	}
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
	const DoubleLinkedList::Node tempNode = *(*_constiterator);
	//引数のイテレータがnullptrでない場合にチェックを行う
	if (tempNode.scoredata!=nullptr)
	{
		if (tempNode.scoredata->Score == _checker->Score&&
			tempNode.scoredata->UserName == _checker->UserName)
			return true;
	}
	return false;
}

ScoreData* Set_ScoreData(int _score, const char * _username)
{
	ScoreData* temp = new ScoreData;
	temp->Score = _score;
	temp->UserName = _username;
	return temp;
}
