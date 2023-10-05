#pragma once
#include <string>

struct ScoreData			 //���уf�[�^�@
{
	int Score;				 //�X�R�A
	std::string UserName;	 //���[�U�[��
};

struct Node					 //�m�[�h
{
	Node* prev;				 //�O�̃m�[�h�ւ̃|�C���^
	Node* next;				 //���̃m�[�h�ւ̃|�C���^
	ScoreData scoredata;	 //���уf�[�^�@
};

class DoubleLinkedList       //�o�������X�g�N���X
{
public:
	class ConstIterator      //�R���X�g�C�e���[�^�N���X(DoubleLinkedList�̃C���i�[�N���X)
	{
	public:
		ConstIterator();
		~ConstIterator();

		void operator--();									   //���X�g�̐擪�Ɍ������Ĉ�i�߂�
		void operator++();									   //���X�g�̖����Ɍ������Ĉ�i�߂�
		Node* const operator* ();							   //�C�e���[�^�̎w���v�f���擾����(const)
		ConstIterator(const ConstIterator& constiterator);	   //�R�s�[�R���X�g���N�^
		ConstIterator operator= (ConstIterator);			   //������s��
		bool operator==(ConstIterator);						   //���ꂩ��r����
		bool operator!=(ConstIterator);						   //�قȂ邩��r����


	};

	class Iterator : public ConstIterator   //�C�e���[�^�N���X(DoubleLinkedList�̃C���i�[�N���X)
	{
	public:
		Node* operator*();            //�C�e���[�^�̎w���v�f���擾����(��const)
	};

	DoubleLinkedList();
	~DoubleLinkedList();
    int Count_Data()const;				    //�f�[�^���̎擾
	void Push_Back(ConstIterator* _iterator,ScoreData _scoredata);				//�f�[�^�̑}��(�C�e���[�^)
	bool Delete_Data(ConstIterator* _iterator);	//�f�[�^�̍폜(�C�e���[�^)����ɍ폜�o�����Ȃ�true��Ԃ�
	Iterator* Get_Iterator();               //���݈ʒu�̃C�e���[�^�̎擾
	Iterator* Get_HeadIterator();			//�擪�C�e���[�^�̎擾
	ConstIterator* Get_HeadConstIterator();	//�擪�R���X�g�C�e���[�^�̎擾
	Iterator* Get_TailIterator();			//�����C�e���[�^�̎擾
	ConstIterator* Get_TailConstIterator();	//�����R���X�g�C�e���[�^�擾
	Node* Get_Node();                       //���݈ʒu�̗v�f�擾
	Node* Get_HeadNode();                   //�擪�v�f�擾
	Node* Get_TailNode();                   //�����v�f�擾

private:
	Node* m_Node;							//���݈ʒu�̃|�C���^
	Node* m_Head;							//�擪�v�f�̃|�C���^
	Node* m_Tail;							//�����v�f�̃|�C���^
	Iterator* m_Iterator;					//�C�e���[�^
	ConstIterator* m_ConstIterator;			//�R���X�g�C�e���[�^

};
	
bool Check_Data(ScoreData _scoredata,ScoreData _checker);      //Node�̒��̃f�[�^�������̂��̂Ɠ��ꂪ��r����(�e�X�g�p�֐�)
void Set_ScoreData(ScoreData _scoredata, int _score, const char* _username); //���уf�[�^��������(�e�X�g�p)