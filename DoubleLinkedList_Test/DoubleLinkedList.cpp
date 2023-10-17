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
	m_Node->prev = new DoubleLinkedList::Node;
	m_Node->prev->scoredata = new ScoreData;
	
	m_Node->prev->next = m_Node;
	
	//各ノードの初期化
	m_HeadNode = m_Node;
	m_HeadNode->prev = m_Node->prev;
	m_TailNode = m_Node;

	data_Count = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
	m_Node = m_TailNode;

	//末尾要素から順番に削除
	while (m_Node != m_HeadNode)
	{
		m_Node = m_Node->prev;
		delete m_Node->next;
	}
	delete m_Node;
}

int DoubleLinkedList::Count()const//データ個数を返す
{
	return data_Count;
}

void DoubleLinkedList::Push_Back(DoubleLinkedList::ConstIterator* _iterator,ScoreData* _scoredata)
{
	//イテレータから参照取得
	DoubleLinkedList::Node* tempNode = new DoubleLinkedList::Node;
	tempNode->scoredata = _scoredata;
	
	m_Node = m_HeadNode;

	while (m_Node != m_TailNode->next||m_TailNode==*(*_iterator))//先頭から末尾まで照合を繰り返す
	{
		if(m_Node==*(*_iterator))
		{
			//ノードの挿入処理
			tempNode->next = m_Node;
			tempNode->prev = m_Node->prev;
			m_Node->prev->next = tempNode;
			m_Node->prev = tempNode;

			if (m_Node == m_HeadNode||data_Count==0)//先頭要素の更新
			{
				m_HeadNode = m_Node->prev;
			}

			data_Count++;
			return;
		}
		m_Node = m_Node->next;
	}

	return;
}

bool DoubleLinkedList::Delete(ConstIterator& _iterator)
{
	m_Node = m_HeadNode;
	while (m_Node != m_TailNode->next)
	{
		if (m_Node == *_iterator)//*_iteratorが有効な参照であれば通る
		{
			//指定されたイテレータのデータがダミーであれば処理を抜け出す
			ScoreData* tempScore = new ScoreData;
			if (m_Node->scoredata->Score == tempScore->Score&&
				m_Node->scoredata->UserName == tempScore->UserName)
			{
				delete tempScore;
				return false;
			}
			//指定されたイテレータが先頭または末尾であれば位置を更新して削除

			if (m_Node == m_TailNode)//末尾はダミーだが念のため
			{
				m_TailNode = m_Node->prev;
				--_iterator;
			}
			else if (m_Node == m_HeadNode)
			{
				//先頭要素の更新を行い、対象のデータを削除
				m_HeadNode = m_Node->next;
				++_iterator;
				delete m_Node;
				m_Node = nullptr;
				data_Count--;
				return true;
			}

			//前後のデータの繋がりを作って、対象のデータを削除
			--_iterator;
			m_Node->next->prev = m_Node->prev;
			m_Node->prev->next = m_Node->next;
			delete m_Node;
			m_Node = nullptr;
			data_Count--;
			return true;
		}
		m_Node = m_Node->next;
	}
	return false;
}

DoubleLinkedList::Iterator* DoubleLinkedList::Get_HeadIterator()//先頭イテレータを渡す
{
	DoubleLinkedList::Iterator* tempIterator=new DoubleLinkedList::Iterator;
	DoubleLinkedList::Node* tempNode = *(*tempIterator);
	tempNode = m_HeadNode;
	(*tempIterator) = tempNode;
	return tempIterator;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_HeadConstIterator()const//先頭コンストイテレータを渡す
{
	DoubleLinkedList::ConstIterator* tempConstIterator = new DoubleLinkedList::ConstIterator(m_HeadNode);
	return tempConstIterator;

}

DoubleLinkedList::Iterator* DoubleLinkedList::Get_TailIterator()//末尾イテレータを渡す
{
	DoubleLinkedList::Iterator* tempIterator = new DoubleLinkedList::Iterator();
	DoubleLinkedList::Node* tempNode = *(*tempIterator);
	tempNode = m_TailNode;
	(*tempIterator) = tempNode;
	return tempIterator;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_TailConstIterator()const//末尾コンストイテレータを渡す
{
	DoubleLinkedList::ConstIterator* tempConstIterator = new DoubleLinkedList::ConstIterator(m_TailNode);
	return tempConstIterator;
}


DoubleLinkedList::Node * DoubleLinkedList::Iterator::operator*()//イテレータの指す要素を取得(非const)
{
	if (mp_Node != nullptr)
	{
		return mp_Node;
	}
	else
	{
		return nullptr;
	}
}

void DoubleLinkedList::Iterator::operator=(DoubleLinkedList::Node* _node)//ノードを代入する
{
	mp_Node = _node;
}

DoubleLinkedList::ConstIterator::ConstIterator()//コンストラクタ
{
	mp_Node = nullptr;
}

DoubleLinkedList::ConstIterator::ConstIterator(Node *_node)//コンストラクタ(参照)
{
	mp_Node = _node;
}

DoubleLinkedList::ConstIterator::~ConstIterator()//デストラクタ
{
}

DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator--()//先頭に向かって進める(前置)
{
	if (mp_Node)
	{
		if (mp_Node->prev)
			mp_Node = mp_Node->prev;
	}
	return *this;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::ConstIterator::operator--(int)//先頭に向かって進める(後置)
{
	DoubleLinkedList::ConstIterator* temp = new DoubleLinkedList::ConstIterator;
	*temp = *this;
	--(*this);
	return temp;
}

DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator++()//末尾に向かって進める(前置)
{
	if (mp_Node)
	{
		if (mp_Node->next)
			mp_Node = mp_Node->next;
	}
	return *this;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::ConstIterator::operator++(int)//末尾に向かって進める(後置)
{
	DoubleLinkedList::ConstIterator* temp = new DoubleLinkedList::ConstIterator;
	*temp = *this;
	++(*this);
	return temp;
}

const DoubleLinkedList::Node* DoubleLinkedList::ConstIterator::operator*()const//イテレータの指す要素を取得(const)
{
	if (mp_Node != nullptr)
	{
		const DoubleLinkedList::Node* tempNode = mp_Node;
		return tempNode;
	}
	else
	{
		return nullptr;
	}
}

DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator & constiterator)//コピーコンストラクタ
{
	this->mp_Node = constiterator.mp_Node;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::ConstIterator::operator=(const DoubleLinkedList::ConstIterator& _constiterator)//代入する
{
	mp_Node = _constiterator.mp_Node;
	return this;
}

bool DoubleLinkedList::ConstIterator::operator==(const ConstIterator* _constiterator)//イテレータが同じか比較する
{
	if (mp_Node == *(*_constiterator))
	{
		return true;
	}
	return false;
}

bool DoubleLinkedList::ConstIterator::operator!=(const ConstIterator* _constiterator)//イテレータが異なるか比較する
{
	if (mp_Node != *(*_constiterator))
	{
		return true;
	}
	return false;
}
