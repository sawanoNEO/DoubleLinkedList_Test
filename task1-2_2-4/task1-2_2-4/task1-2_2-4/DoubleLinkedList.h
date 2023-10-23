#pragma once
#include <string>

struct ScoreData			 //���уf�[�^�@
{
	int Score;				 //�X�R�A
	std::string UserName;	 //���[�U�[��
	ScoreData() :Score(0), UserName("dummy") {}
};

class DoubleLinkedList       //�o�������X�g�N���X
{
private:
	struct Node					 //�m�[�h
	{
		Node* prev;				 //�O�̃m�[�h�ւ̃|�C���^
		Node* next;				 //���̃m�[�h�ւ̃|�C���^
		ScoreData scoredata;	 //���уf�[�^�@
		Node() :prev(nullptr), next(nullptr) { scoredata.Score = 0; scoredata.UserName = "dummy"; } //�R���X�g���N�^
	};
	Node* m_HeadNode;  //�擪�v�f�̃|�C���^
	Node* m_TailNode;  //�����v�f�̃|�C���^

	int data_Count;    //���݂̃f�[�^��

public:
	class ConstIterator      //�R���X�g�C�e���[�^�N���X(DoubleLinkedList�̃C���i�[�N���X)
	{
	protected:
		Node* mp_Node;
	public:
		friend DoubleLinkedList;

		ConstIterator();
		explicit ConstIterator(Node* _node);//�Q�Ƃ�n���ꂽ���̃R���X�g���N�^
		~ConstIterator();

		ConstIterator operator--();								    //���X�g�̐擪�Ɍ������Ĉ�i�߂�(�O�u)
		ConstIterator operator--(int);								    //���X�g�̐擪�Ɍ������Ĉ�i�߂�(��u)
		ConstIterator operator++();								    //���X�g�̖����Ɍ������Ĉ�i�߂�(�O�u)
		ConstIterator operator++(int);								    //���X�g�̖����Ɍ������Ĉ�i�߂�(��u)
		const ScoreData operator* ()const;						        //�C�e���[�^�̎w���v�f���擾����(const)
		ConstIterator(const ConstIterator& _constiterator);	            //�R�s�[�R���X�g���N�^
		ConstIterator operator= (const ConstIterator _constiterator);	//������s��
		bool operator==(const ConstIterator _constiterator);			//���ꂩ��r����
		bool operator!=(const ConstIterator _constiterator);			//�قȂ邩��r����

	};

	class Iterator : public ConstIterator   //�C�e���[�^�N���X(DoubleLinkedList�̃C���i�[�N���X)
	{
	public:
		Iterator();
		explicit Iterator(Node* _node);
        ScoreData operator*();            //�C�e���[�^�̎w���v�f���擾����(��const)
	};

	DoubleLinkedList();
	~DoubleLinkedList();
    int Count()const;				    //�f�[�^���̎擾
	bool Insert(ConstIterator& _iterator,ScoreData _scoredata);				//�f�[�^�̑}��(�C�e���[�^)
	bool Delete(ConstIterator& _iterator);	        //�f�[�^�̍폜(�C�e���[�^)����ɍ폜�o�����Ȃ�true��Ԃ�

	Iterator Get_HeadIterator();		        	//�擪�C�e���[�^�̎擾
	ConstIterator Get_HeadConstIterator()const;	//�擪�R���X�g�C�e���[�^�̎擾
	Iterator Get_TailIterator();		           	//�����C�e���[�^�̎擾
	ConstIterator Get_TailConstIterator()const;	//�����R���X�g�C�e���[�^�擾

};
	
