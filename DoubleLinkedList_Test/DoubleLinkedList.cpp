#include "DoubleLinkedList.h"
#include <assert.h>
#include "pch.h"

DoubleLinkedList::DoubleLinkedList()
{
	//各変数を生成する
	m_HeadNode = new DoubleLinkedList::Node;
	m_HeadNode->next = new DoubleLinkedList::Node;
	m_HeadNode->prev = new DoubleLinkedList::Node;
	m_TailNode = new DoubleLinkedList::Node;

	m_HeadNode->prev = new DoubleLinkedList::Node;
	m_HeadNode->prev->next = m_HeadNode;
	
	//各ノードの初期化
	m_TailNode = m_HeadNode;

	data_Count = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
	DoubleLinkedList::Node* tempNode = m_TailNode;

	//末尾要素から順番に削除
	while (tempNode != m_HeadNode)
	{
		tempNode = tempNode->prev;
		delete tempNode->next;
	}
	delete tempNode;
}

int DoubleLinkedList::Count()const//データ個数を返す
{
	return data_Count;
}

bool DoubleLinkedList::Insert(DoubleLinkedList::ConstIterator& _iterator,ScoreData _scoredata)
{
	if (!_iterator.mp_Node)
	{
		return false;
	}
	//挿入用ノード生成
	DoubleLinkedList::Node* insertNode = new DoubleLinkedList::Node;
	insertNode->scoredata = _scoredata;

	insertNode->prev = _iterator.mp_Node->prev;
	insertNode->next = _iterator.mp_Node;
	_iterator.mp_Node->prev->next = insertNode;
	_iterator.mp_Node->prev = insertNode;

	if (_iterator.mp_Node == m_HeadNode)
	{
		m_HeadNode = _iterator.mp_Node->prev;
	}

	data_Count++;

	return true;
}

bool DoubleLinkedList::Delete(ConstIterator& _iterator)
{
	ScoreData tempScore;

	//イテレータの参照がnullまたはダミーだった場合、処理を抜ける
	if (!_iterator.mp_Node||
		(_iterator.mp_Node->scoredata.Score==tempScore.Score&&
		 _iterator.mp_Node->scoredata.UserName==tempScore.UserName))
	{
		return false;
	}

	//対象のイテレータと先頭ノードが同じなら先頭ノードを移動させる
	if (m_HeadNode == _iterator.mp_Node)
	{
		m_HeadNode = _iterator.mp_Node->next;
	}

	_iterator.mp_Node->prev->next = _iterator.mp_Node->next;//前の次を今の次にする
	_iterator.mp_Node = _iterator.mp_Node->prev;//今を前にする
	delete _iterator.mp_Node->next->prev;//前になった今の次の前を消す
	_iterator.mp_Node->next->prev = _iterator.mp_Node->prev;//前になった今の次を前になった今にする

	data_Count--;
	return true;
}

DoubleLinkedList::Iterator DoubleLinkedList::Get_HeadIterator()//先頭イテレータを渡す
{
	DoubleLinkedList::Iterator tempIterator(m_HeadNode);
	return tempIterator;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::Get_HeadConstIterator()const//先頭コンストイテレータを渡す
{
	DoubleLinkedList::ConstIterator tempConstIterator(m_HeadNode);
	return tempConstIterator;

}

DoubleLinkedList::Iterator DoubleLinkedList::Get_TailIterator()//末尾イテレータを渡す
{
	DoubleLinkedList::Iterator tempIterator(m_TailNode);
	return tempIterator;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::Get_TailConstIterator()const//末尾コンストイテレータを渡す
{
	DoubleLinkedList::ConstIterator tempConstIterator(m_TailNode);
	return tempConstIterator;
}



DoubleLinkedList::Iterator::Iterator()
{
	mp_Node = nullptr;
}

DoubleLinkedList::Iterator::Iterator(Node * _node)
{
	mp_Node = _node;
}

ScoreData DoubleLinkedList::Iterator::operator*()//イテレータの指す要素を取得(非const)
{
	assert(mp_Node);
	assert(mp_Node->scoredata.UserName != "dummy"||mp_Node->prev->scoredata.UserName!="dummy");
	return mp_Node->scoredata;
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

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator--()//先頭に向かって進める(前置)
{
	assert(mp_Node);
	assert(mp_Node->prev->scoredata.UserName != "dummy");
	if (mp_Node->prev)
	{
		mp_Node = mp_Node->prev;
	}
	return *this;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator--(int)//先頭に向かって進める(後置)
{
	DoubleLinkedList::ConstIterator temp;
	temp = *this;
	--(*this);
	return temp;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator++()//末尾に向かって進める(前置)
{
	assert(mp_Node);
	if (mp_Node->next)
	{
		mp_Node = mp_Node->next;
	}
	return *this;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator++(int)//末尾に向かって進める(後置)
{
	DoubleLinkedList::ConstIterator temp;
	temp = *this;
	++(*this);
	return temp;
}

const ScoreData DoubleLinkedList::ConstIterator::operator*()const//イテレータの指す要素を取得(const)
{
	assert(mp_Node);
	assert(mp_Node->scoredata.UserName != "dummy" || mp_Node->prev->scoredata.UserName != "dummy");
	return mp_Node->scoredata;
}

DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator& constiterator)//コピーコンストラクタ
{
	this->mp_Node = constiterator.mp_Node;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator=(const DoubleLinkedList::ConstIterator _constiterator)//代入する
{
	mp_Node = _constiterator.mp_Node;
	return *this;
}

bool DoubleLinkedList::ConstIterator::operator==(const ConstIterator _constiterator)//イテレータが同じか比較する
{
	if (mp_Node == _constiterator.mp_Node)
	{
		return true;
	}
	return false;
}

bool DoubleLinkedList::ConstIterator::operator!=(const ConstIterator _constiterator)//イテレータが異なるか比較する
{
	if (mp_Node != _constiterator.mp_Node)
	{
		return true;
	}
	return false;
}
