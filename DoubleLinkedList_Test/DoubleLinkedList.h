#pragma once
#include <string>

struct ScoreData			 //成績データ　
{
	int Score;				 //スコア
	std::string UserName;	 //ユーザー名
};

class DoubleLinkedList       //双方向リストクラス
{
public:
	struct Node					 //ノード
	{
		Node* prev;				 //前のノードへのポインタ
		Node* next;				 //次のノードへのポインタ
		ScoreData* scoredata;	 //成績データ　
		Node() :prev(nullptr), next(nullptr), scoredata(nullptr) { } //コンストラクタ
	};
	class ConstIterator      //コンストイテレータクラス(DoubleLinkedListのインナークラス)
	{
	protected:
		Node* mp_Node;
	public:
		ConstIterator();
		~ConstIterator();

		ConstIterator& operator--();									   //リストの先頭に向かって一つ進める(前置)
		void operator--(int);								   //リストの先頭に向かって一つ進める(後置)
		ConstIterator& operator++();									   //リストの末尾に向かって一つ進める(前置)
		void operator++(int);								   //リストの末尾に向かって一つ進める(後置)
		
		Node& operator* ()const;							   //イテレータの指す要素を取得する(const)
		ConstIterator(const ConstIterator& constiterator);	   //コピーコンストラクタ
		ConstIterator* operator= (Node* _node);			   //代入を行う
		bool operator==(ConstIterator* _constiterator);						   //同一か比較する
		bool operator!=(ConstIterator* _constiterator);						   //異なるか比較する

	};

	class Iterator : public ConstIterator   //イテレータクラス(DoubleLinkedListのインナークラス)
	{
	public:
        Node* operator*();            //イテレータの指す要素を取得する(非const)
		void operator=(Node*); //コンストイテレータノードをイテレータに入れる
	};

	DoubleLinkedList();
	~DoubleLinkedList();
    int Count_Data()const;				    //データ数の取得
	void Push_Back(ConstIterator& _iterator,ScoreData* _scoredata);				//データの挿入(イテレータ)
	bool Delete_Data(ConstIterator& _iterator);	//データの削除(イテレータ)正常に削除出来たならtrueを返す

	Iterator* Get_HeadIterator();			//先頭イテレータの取得
	ConstIterator* Get_HeadConstIterator()const;	//先頭コンストイテレータの取得
	Iterator* Get_TailIterator();			//末尾イテレータの取得
	ConstIterator* Get_TailConstIterator()const;	//末尾コンストイテレータ取得

private:
	Node* m_Node;							//現在位置のポインタ
	Node* m_HeadNode;						//先頭要素のポインタ
	Node* m_TailNode;						//末尾要素のポインタ
	Iterator* m_Iterator;					//イテレータ
	Iterator* m_HeadIterator;               //先頭要素を表すイテレータ
	Iterator* m_TailIterator;               //末尾要素を表すイテレータ
	ConstIterator* m_HeadConstIterator;     //先頭要素を表すコンストイテレータ
	ConstIterator* m_TailConstIterator;     //末尾要素を表すコンストイテレータ
	ConstIterator* m_ConstIterator;			//コンストイテレータ
	int data_Count;
};
	
void ScoreData_Init(ScoreData* _scoredata);
bool Check_Data(DoubleLinkedList::ConstIterator* _constiterator,ScoreData* _checker);      //Nodeの中のデータが引数のものと同一が比較する(テスト用関数)
ScoreData* Set_ScoreData(int _score, const char* _username); //成績データを代入する(テスト用)