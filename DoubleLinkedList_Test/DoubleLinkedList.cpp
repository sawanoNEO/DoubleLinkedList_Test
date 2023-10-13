#include "DoubleLinkedList.h"
#include "pch.h"

DoubleLinkedList::DoubleLinkedList()
{
	//各変数を生成する
	m_Node = new DoubleLinkedList::Node;

	m_HeadNode = new DoubleLinkedList::Node;
	m_HeadNode->scoredata = new ScoreData;
	m_HeadNode->next = new DoubleLinkedList::Node;
	m_HeadNode->prev = new DoubleLinkedList::Node;
	m_HeadNode->next->scoredata = new ScoreData;
	m_HeadNode->prev->scoredata = new ScoreData;
	m_TailNode = new DoubleLinkedList::Node;

	m_Node->scoredata = new ScoreData;
	m_Node->next = new DoubleLinkedList::Node;
	m_Node->prev = new DoubleLinkedList::Node;
	m_Node->next->scoredata = new ScoreData;
	m_Node->prev->scoredata = new ScoreData;
	
	m_Node->prev->next = m_Node;
	m_Node->next->prev = m_Node;
	
	//各ノードの初期化
	m_HeadNode = m_Node;
	m_HeadNode->next = m_Node->next;
	m_HeadNode->prev = m_Node->prev;
	m_TailNode = m_Node;
	m_TailNode->next = m_Node->next;
	m_TailNode->prev = m_Node->prev;

	//ダミーデータをスコアに入れる
	//ScoreData_Init(m_Node->scoredata);
	//ScoreData_Init(m_Node->next->scoredata);
	//ScoreData_Init(m_Node->prev->scoredata);

	data_Count = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
	
}

int DoubleLinkedList::Count()const
{
	return data_Count;
}

void DoubleLinkedList::Push_Back(DoubleLinkedList::ConstIterator* _iterator,ScoreData* _scoredata)
{
	//イテレータから参照取得
	//DoubleLinkedList::Node* tempNode = new DoubleLinkedList::Node;
	//*tempNode=*_iterator;
	m_Node = *(*_iterator);
	if (m_Node&&m_Node->prev)
	{
	    //参照場所の前にダミー以外のデータがあればノードを差し込む
		if (m_Node->prev->scoredata&&
			!(m_Node->prev->scoredata->Score == 0 &&
			m_Node->prev->scoredata->UserName == "dummy"))
		{
			//新しくデータを作ればいいじゃないか
			DoubleLinkedList::Node* insertNode = new DoubleLinkedList::Node;
			insertNode->scoredata = _scoredata;
			insertNode->next = m_Node;
			insertNode->prev = m_Node->prev;
			m_Node->prev->next = insertNode;
			m_Node->prev = insertNode;
		
			//m_Node->prev->next = new DoubleLinkedList::Node;
			//m_Node->prev->next->scoredata = _scoredata;
			//m_Node->prev->next->prev = m_Node->prev;
			//m_Node->prev = m_Node->prev->next;
			//m_Node->prev->next = m_Node;
		}
		else
		{
			//*m_Node=*_iterator;
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
	}

	//--_iterator;
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

bool DoubleLinkedList::Delete(ConstIterator& _iterator)
{
	m_Node = *_iterator;
	if (!m_Node || !m_Node->prev)           //指定されたイテレータにデータがなければ処理を抜け出す
		return false;

	//指定されたイテレータのデータがダミーであれば処理を抜け出す
	ScoreData* tempScore=new ScoreData;
	//ScoreData_Init(tempScore);
	if (m_Node->scoredata->Score==tempScore->Score&&
		m_Node->scoredata->UserName==tempScore->UserName)
		return false;
	
	//指定されたイテレータが先頭または末尾であれば位置を更新して削除
	
	if (m_Node == m_TailNode)//末尾はダミーだが念のため
	{
		m_TailNode = m_Node->prev;
		--_iterator;
	}
	else if (m_Node == m_HeadNode)
	{
		m_HeadNode = m_Node->next;
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
	DoubleLinkedList::Iterator* tempIterator=new DoubleLinkedList::Iterator;
	DoubleLinkedList::Node* tempNode = *(*tempIterator);
	tempNode = m_HeadNode;
	(*tempIterator) = tempNode;
	return tempIterator;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_HeadConstIterator()const
{
	DoubleLinkedList::ConstIterator* tempConstIterator = new DoubleLinkedList::ConstIterator;
	(*tempConstIterator) = m_HeadNode;
	return tempConstIterator;

}

DoubleLinkedList::Iterator* DoubleLinkedList::Get_TailIterator()
{
	DoubleLinkedList::Iterator* tempIterator = new DoubleLinkedList::Iterator;
	DoubleLinkedList::Node* tempNode = *(*tempIterator);
	tempNode = m_TailNode;
	(*tempIterator) = tempNode;
	return tempIterator;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_TailConstIterator()const
{
	DoubleLinkedList::ConstIterator* tempConstIterator = new DoubleLinkedList::ConstIterator;
	(*tempConstIterator) = m_TailNode;
	return tempConstIterator;
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
	/*mp_Node = new DoubleLinkedList::Node;*/
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

DoubleLinkedList::Node* DoubleLinkedList::ConstIterator::operator*()const
{
	if (mp_Node != nullptr)
		return mp_Node;
	else
	{
		return nullptr;
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

