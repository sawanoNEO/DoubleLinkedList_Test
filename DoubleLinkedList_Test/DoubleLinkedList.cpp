#include "DoubleLinkedList.h"
#include <assert.h>
#include "pch.h"

DoubleLinkedList::DoubleLinkedList()
{
	//�e�ϐ��𐶐�����
	m_HeadNode = new DoubleLinkedList::Node;
	m_HeadNode->next = new DoubleLinkedList::Node;
	m_HeadNode->prev = new DoubleLinkedList::Node;
	m_TailNode = new DoubleLinkedList::Node;

	m_HeadNode->prev = new DoubleLinkedList::Node;
	m_HeadNode->prev->next = m_HeadNode;
	
	//�e�m�[�h�̏�����
	m_TailNode = m_HeadNode;

	data_Count = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
	DoubleLinkedList::Node* tempNode = m_TailNode;

	//�����v�f���珇�Ԃɍ폜
	while (tempNode != m_HeadNode)
	{
		tempNode = tempNode->prev;
		delete tempNode->next;
	}
	delete tempNode;
}

int DoubleLinkedList::Count()const//�f�[�^����Ԃ�
{
	return data_Count;
}

bool DoubleLinkedList::Insert(DoubleLinkedList::ConstIterator& _iterator,ScoreData _scoredata)
{
	if (!_iterator.mp_Node)
	{
		return false;
	}
	//�}���p�m�[�h����
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

	//�C�e���[�^�̎Q�Ƃ�null�܂��̓_�~�[�������ꍇ�A�����𔲂���
	if (!_iterator.mp_Node||
		(_iterator.mp_Node->scoredata.Score==tempScore.Score&&
		 _iterator.mp_Node->scoredata.UserName==tempScore.UserName))
	{
		return false;
	}

	//�Ώۂ̃C�e���[�^�Ɛ擪�m�[�h�������Ȃ�擪�m�[�h���ړ�������
	if (m_HeadNode == _iterator.mp_Node)
	{
		m_HeadNode = _iterator.mp_Node->next;
	}

	_iterator.mp_Node->prev->next = _iterator.mp_Node->next;//�O�̎������̎��ɂ���
	_iterator.mp_Node = _iterator.mp_Node->prev;//����O�ɂ���
	delete _iterator.mp_Node->next->prev;//�O�ɂȂ������̎��̑O������
	_iterator.mp_Node->next->prev = _iterator.mp_Node->prev;//�O�ɂȂ������̎���O�ɂȂ������ɂ���

	data_Count--;
	return true;
}

DoubleLinkedList::Iterator DoubleLinkedList::Get_HeadIterator()//�擪�C�e���[�^��n��
{
	DoubleLinkedList::Iterator tempIterator(m_HeadNode);
	return tempIterator;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::Get_HeadConstIterator()const//�擪�R���X�g�C�e���[�^��n��
{
	DoubleLinkedList::ConstIterator tempConstIterator(m_HeadNode);
	return tempConstIterator;

}

DoubleLinkedList::Iterator DoubleLinkedList::Get_TailIterator()//�����C�e���[�^��n��
{
	DoubleLinkedList::Iterator tempIterator(m_TailNode);
	return tempIterator;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::Get_TailConstIterator()const//�����R���X�g�C�e���[�^��n��
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

ScoreData DoubleLinkedList::Iterator::operator*()//�C�e���[�^�̎w���v�f���擾(��const)
{
	assert(mp_Node);
	assert(mp_Node->scoredata.UserName != "dummy"||mp_Node->prev->scoredata.UserName!="dummy");
	return mp_Node->scoredata;
}

DoubleLinkedList::ConstIterator::ConstIterator()//�R���X�g���N�^
{
	mp_Node = nullptr;
}

DoubleLinkedList::ConstIterator::ConstIterator(Node *_node)//�R���X�g���N�^(�Q��)
{
	mp_Node = _node;
}

DoubleLinkedList::ConstIterator::~ConstIterator()//�f�X�g���N�^
{
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator--()//�擪�Ɍ������Đi�߂�(�O�u)
{
	assert(mp_Node);
	assert(mp_Node->prev->scoredata.UserName != "dummy");
	if (mp_Node->prev)
	{
		mp_Node = mp_Node->prev;
	}
	return *this;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator--(int)//�擪�Ɍ������Đi�߂�(��u)
{
	DoubleLinkedList::ConstIterator temp;
	temp = *this;
	--(*this);
	return temp;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator++()//�����Ɍ������Đi�߂�(�O�u)
{
	assert(mp_Node);
	if (mp_Node->next)
	{
		mp_Node = mp_Node->next;
	}
	return *this;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator++(int)//�����Ɍ������Đi�߂�(��u)
{
	DoubleLinkedList::ConstIterator temp;
	temp = *this;
	++(*this);
	return temp;
}

const ScoreData DoubleLinkedList::ConstIterator::operator*()const//�C�e���[�^�̎w���v�f���擾(const)
{
	assert(mp_Node);
	assert(mp_Node->scoredata.UserName != "dummy" || mp_Node->prev->scoredata.UserName != "dummy");
	return mp_Node->scoredata;
}

DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator& constiterator)//�R�s�[�R���X�g���N�^
{
	this->mp_Node = constiterator.mp_Node;
}

DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator=(const DoubleLinkedList::ConstIterator _constiterator)//�������
{
	mp_Node = _constiterator.mp_Node;
	return *this;
}

bool DoubleLinkedList::ConstIterator::operator==(const ConstIterator _constiterator)//�C�e���[�^����������r����
{
	if (mp_Node == _constiterator.mp_Node)
	{
		return true;
	}
	return false;
}

bool DoubleLinkedList::ConstIterator::operator!=(const ConstIterator _constiterator)//�C�e���[�^���قȂ邩��r����
{
	if (mp_Node != _constiterator.mp_Node)
	{
		return true;
	}
	return false;
}
