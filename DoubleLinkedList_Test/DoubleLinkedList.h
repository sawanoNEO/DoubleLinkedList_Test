#pragma once
#include <string>

struct ScoreData			 //���уf�[�^�@
{
	int Score;				 //�X�R�A
	std::string UserName;	 //���[�U�[��
};

class DoubleLinkedList       //�o�������X�g�N���X
{
public:
	struct Node					 //�m�[�h
	{
		Node* prev;				 //�O�̃m�[�h�ւ̃|�C���^
		Node* next;				 //���̃m�[�h�ւ̃|�C���^
		ScoreData* scoredata;	 //���уf�[�^�@
		Node() :prev(nullptr), next(nullptr), scoredata(nullptr) { } //�R���X�g���N�^
	};
	class ConstIterator      //�R���X�g�C�e���[�^�N���X(DoubleLinkedList�̃C���i�[�N���X)
	{
	protected:
		Node* mp_Node;
	public:
		ConstIterator();
		~ConstIterator();

		ConstIterator& operator--();									   //���X�g�̐擪�Ɍ������Ĉ�i�߂�(�O�u)
		void operator--(int);								   //���X�g�̐擪�Ɍ������Ĉ�i�߂�(��u)
		ConstIterator& operator++();									   //���X�g�̖����Ɍ������Ĉ�i�߂�(�O�u)
		void operator++(int);								   //���X�g�̖����Ɍ������Ĉ�i�߂�(��u)
		
		Node& operator* ()const;							   //�C�e���[�^�̎w���v�f���擾����(const)
		ConstIterator(const ConstIterator& constiterator);	   //�R�s�[�R���X�g���N�^
		ConstIterator* operator= (Node* _node);			   //������s��
		bool operator==(ConstIterator* _constiterator);						   //���ꂩ��r����
		bool operator!=(ConstIterator* _constiterator);						   //�قȂ邩��r����

	};

	class Iterator : public ConstIterator   //�C�e���[�^�N���X(DoubleLinkedList�̃C���i�[�N���X)
	{
	public:
        Node* operator*();            //�C�e���[�^�̎w���v�f���擾����(��const)
		void operator=(Node*); //�R���X�g�C�e���[�^�m�[�h���C�e���[�^�ɓ����
	};

	DoubleLinkedList();
	~DoubleLinkedList();
    int Count_Data()const;				    //�f�[�^���̎擾
	void Push_Back(ConstIterator& _iterator,ScoreData* _scoredata);				//�f�[�^�̑}��(�C�e���[�^)
	bool Delete_Data(ConstIterator& _iterator);	//�f�[�^�̍폜(�C�e���[�^)����ɍ폜�o�����Ȃ�true��Ԃ�

	Iterator* Get_HeadIterator();			//�擪�C�e���[�^�̎擾
	ConstIterator* Get_HeadConstIterator()const;	//�擪�R���X�g�C�e���[�^�̎擾
	Iterator* Get_TailIterator();			//�����C�e���[�^�̎擾
	ConstIterator* Get_TailConstIterator()const;	//�����R���X�g�C�e���[�^�擾

private:
	Node* m_Node;							//���݈ʒu�̃|�C���^
	Node* m_HeadNode;						//�擪�v�f�̃|�C���^
	Node* m_TailNode;						//�����v�f�̃|�C���^
	Iterator* m_Iterator;					//�C�e���[�^
	Iterator* m_HeadIterator;               //�擪�v�f��\���C�e���[�^
	Iterator* m_TailIterator;               //�����v�f��\���C�e���[�^
	ConstIterator* m_HeadConstIterator;     //�擪�v�f��\���R���X�g�C�e���[�^
	ConstIterator* m_TailConstIterator;     //�����v�f��\���R���X�g�C�e���[�^
	ConstIterator* m_ConstIterator;			//�R���X�g�C�e���[�^
	int data_Count;
};
	
void ScoreData_Init(ScoreData* _scoredata);
bool Check_Data(DoubleLinkedList::ConstIterator* _constiterator,ScoreData* _checker);      //Node�̒��̃f�[�^�������̂��̂Ɠ��ꂪ��r����(�e�X�g�p�֐�)
ScoreData* Set_ScoreData(int _score, const char* _username); //���уf�[�^��������(�e�X�g�p)