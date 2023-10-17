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
		ConstIterator(Node* _node);//�Q�Ƃ�n���ꂽ���̃R���X�g���N�^
		~ConstIterator();

		ConstIterator& operator--();									   //���X�g�̐擪�Ɍ������Ĉ�i�߂�(�O�u)
		ConstIterator* operator--(int);								   //���X�g�̐擪�Ɍ������Ĉ�i�߂�(��u)
		ConstIterator& operator++();									   //���X�g�̖����Ɍ������Ĉ�i�߂�(�O�u)
		ConstIterator* operator++(int);								   //���X�g�̖����Ɍ������Ĉ�i�߂�(��u)
		
		const Node* operator* ()const;						   //�C�e���[�^�̎w���v�f���擾����(const)
		ConstIterator(const ConstIterator& _constiterator);	   //�R�s�[�R���X�g���N�^
		ConstIterator* operator= (const ConstIterator& _constiterator);			   //������s��
		bool operator==(const ConstIterator* _constiterator);						   //���ꂩ��r����
		bool operator!=(const ConstIterator* _constiterator);						   //�قȂ邩��r����

	};

	class Iterator : public ConstIterator   //�C�e���[�^�N���X(DoubleLinkedList�̃C���i�[�N���X)
	{
	public:
        Node* operator*();            //�C�e���[�^�̎w���v�f���擾����(��const)
		void operator=(Node*); //�R���X�g�C�e���[�^�m�[�h���C�e���[�^�ɓ����
	};

	DoubleLinkedList();
	~DoubleLinkedList();
    int Count()const;				    //�f�[�^���̎擾
	void Push_Back(ConstIterator* _iterator,ScoreData* _scoredata);				//�f�[�^�̑}��(�C�e���[�^)
	bool Delete(ConstIterator& _iterator);	//�f�[�^�̍폜(�C�e���[�^)����ɍ폜�o�����Ȃ�true��Ԃ�

	Iterator* Get_HeadIterator();			//�擪�C�e���[�^�̎擾
	ConstIterator* Get_HeadConstIterator()const;	//�擪�R���X�g�C�e���[�^�̎擾
	Iterator* Get_TailIterator();			//�����C�e���[�^�̎擾
	ConstIterator* Get_TailConstIterator()const;	//�����R���X�g�C�e���[�^�擾

private:
	Node* m_Node;							//���݈ʒu�̃|�C���^
	Node* m_HeadNode;						//�擪�v�f�̃|�C���^
	Node* m_TailNode;						//�����v�f�̃|�C���^

	int data_Count;
};
	
