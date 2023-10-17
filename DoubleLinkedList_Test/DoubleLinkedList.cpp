#include "DoubleLinkedList.h"
#include "pch.h"

DoubleLinkedList::DoubleLinkedList()
{
	//�e�ϐ��𐶐�����
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
	
	//�e�m�[�h�̏�����
	m_HeadNode = m_Node;
	m_HeadNode->prev = m_Node->prev;
	m_TailNode = m_Node;

	data_Count = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
	m_Node = m_TailNode;

	//�����v�f���珇�Ԃɍ폜
	while (m_Node != m_HeadNode)
	{
		m_Node = m_Node->prev;
		delete m_Node->next;
	}
	delete m_Node;
}

int DoubleLinkedList::Count()const//�f�[�^����Ԃ�
{
	return data_Count;
}

void DoubleLinkedList::Push_Back(DoubleLinkedList::ConstIterator* _iterator,ScoreData* _scoredata)
{
	//�C�e���[�^����Q�Ǝ擾
	DoubleLinkedList::Node* tempNode = new DoubleLinkedList::Node;
	tempNode->scoredata = _scoredata;
	
	m_Node = m_HeadNode;

	while (m_Node != m_TailNode->next||m_TailNode==*(*_iterator))//�擪���疖���܂ŏƍ����J��Ԃ�
	{
		if(m_Node==*(*_iterator))
		{
			//�m�[�h�̑}������
			tempNode->next = m_Node;
			tempNode->prev = m_Node->prev;
			m_Node->prev->next = tempNode;
			m_Node->prev = tempNode;

			if (m_Node == m_HeadNode||data_Count==0)//�擪�v�f�̍X�V
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
		if (m_Node == *_iterator)//*_iterator���L���ȎQ�Ƃł���Βʂ�
		{
			//�w�肳�ꂽ�C�e���[�^�̃f�[�^���_�~�[�ł���Ώ����𔲂��o��
			ScoreData* tempScore = new ScoreData;
			if (m_Node->scoredata->Score == tempScore->Score&&
				m_Node->scoredata->UserName == tempScore->UserName)
			{
				delete tempScore;
				return false;
			}
			//�w�肳�ꂽ�C�e���[�^���擪�܂��͖����ł���Έʒu���X�V���č폜

			if (m_Node == m_TailNode)//�����̓_�~�[�����O�̂���
			{
				m_TailNode = m_Node->prev;
				--_iterator;
			}
			else if (m_Node == m_HeadNode)
			{
				//�擪�v�f�̍X�V���s���A�Ώۂ̃f�[�^���폜
				m_HeadNode = m_Node->next;
				++_iterator;
				delete m_Node;
				m_Node = nullptr;
				data_Count--;
				return true;
			}

			//�O��̃f�[�^�̌q���������āA�Ώۂ̃f�[�^���폜
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

DoubleLinkedList::Iterator* DoubleLinkedList::Get_HeadIterator()//�擪�C�e���[�^��n��
{
	DoubleLinkedList::Iterator* tempIterator=new DoubleLinkedList::Iterator;
	DoubleLinkedList::Node* tempNode = *(*tempIterator);
	tempNode = m_HeadNode;
	(*tempIterator) = tempNode;
	return tempIterator;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_HeadConstIterator()const//�擪�R���X�g�C�e���[�^��n��
{
	DoubleLinkedList::ConstIterator* tempConstIterator = new DoubleLinkedList::ConstIterator(m_HeadNode);
	return tempConstIterator;

}

DoubleLinkedList::Iterator* DoubleLinkedList::Get_TailIterator()//�����C�e���[�^��n��
{
	DoubleLinkedList::Iterator* tempIterator = new DoubleLinkedList::Iterator();
	DoubleLinkedList::Node* tempNode = *(*tempIterator);
	tempNode = m_TailNode;
	(*tempIterator) = tempNode;
	return tempIterator;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::Get_TailConstIterator()const//�����R���X�g�C�e���[�^��n��
{
	DoubleLinkedList::ConstIterator* tempConstIterator = new DoubleLinkedList::ConstIterator(m_TailNode);
	return tempConstIterator;
}


DoubleLinkedList::Node * DoubleLinkedList::Iterator::operator*()//�C�e���[�^�̎w���v�f���擾(��const)
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

void DoubleLinkedList::Iterator::operator=(DoubleLinkedList::Node* _node)//�m�[�h��������
{
	mp_Node = _node;
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

DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator--()//�擪�Ɍ������Đi�߂�(�O�u)
{
	if (mp_Node)
	{
		if (mp_Node->prev)
			mp_Node = mp_Node->prev;
	}
	return *this;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::ConstIterator::operator--(int)//�擪�Ɍ������Đi�߂�(��u)
{
	DoubleLinkedList::ConstIterator* temp = new DoubleLinkedList::ConstIterator;
	*temp = *this;
	--(*this);
	return temp;
}

DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator++()//�����Ɍ������Đi�߂�(�O�u)
{
	if (mp_Node)
	{
		if (mp_Node->next)
			mp_Node = mp_Node->next;
	}
	return *this;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::ConstIterator::operator++(int)//�����Ɍ������Đi�߂�(��u)
{
	DoubleLinkedList::ConstIterator* temp = new DoubleLinkedList::ConstIterator;
	*temp = *this;
	++(*this);
	return temp;
}

const DoubleLinkedList::Node* DoubleLinkedList::ConstIterator::operator*()const//�C�e���[�^�̎w���v�f���擾(const)
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

DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator & constiterator)//�R�s�[�R���X�g���N�^
{
	this->mp_Node = constiterator.mp_Node;
}

DoubleLinkedList::ConstIterator* DoubleLinkedList::ConstIterator::operator=(const DoubleLinkedList::ConstIterator& _constiterator)//�������
{
	mp_Node = _constiterator.mp_Node;
	return this;
}

bool DoubleLinkedList::ConstIterator::operator==(const ConstIterator* _constiterator)//�C�e���[�^����������r����
{
	if (mp_Node == *(*_constiterator))
	{
		return true;
	}
	return false;
}

bool DoubleLinkedList::ConstIterator::operator!=(const ConstIterator* _constiterator)//�C�e���[�^���قȂ邩��r����
{
	if (mp_Node != *(*_constiterator))
	{
		return true;
	}
	return false;
}
