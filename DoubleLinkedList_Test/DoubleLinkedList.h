#pragma once
#include <string>

struct ScoreData			 //成績データ　
{
	int Score;				 //スコア
	std::string UserName;	 //ユーザー名
	ScoreData() :Score(0), UserName("dummy") {}
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
		ConstIterator(Node* _node);//参照を渡された時のコンストラクタ
		~ConstIterator();

		ConstIterator& operator--();									   //リストの先頭に向かって一つ進める(前置)
		ConstIterator* operator--(int);								   //リストの先頭に向かって一つ進める(後置)
		ConstIterator& operator++();									   //リストの末尾に向かって一つ進める(前置)
		ConstIterator* operator++(int);								   //リストの末尾に向かって一つ進める(後置)
		
		const Node* operator* ()const;						   //イテレータの指す要素を取得する(const)
		ConstIterator(const ConstIterator& _constiterator);	   //コピーコンストラクタ
		ConstIterator* operator= (const ConstIterator& _constiterator);			   //代入を行う
		bool operator==(const ConstIterator* _constiterator);						   //同一か比較する
		bool operator!=(const ConstIterator* _constiterator);						   //異なるか比較する

	};

	class Iterator : public ConstIterator   //イテレータクラス(DoubleLinkedListのインナークラス)
	{
	public:
        Node* operator*();            //イテレータの指す要素を取得する(非const)
		void operator=(Node*); //コンストイテレータノードをイテレータに入れる
	};

	DoubleLinkedList();
	~DoubleLinkedList();
    int Count()const;				    //データ数の取得
	void Push_Back(ConstIterator* _iterator,ScoreData* _scoredata);				//データの挿入(イテレータ)
	bool Delete(ConstIterator& _iterator);	//データの削除(イテレータ)正常に削除出来たならtrueを返す

	Iterator* Get_HeadIterator();			//先頭イテレータの取得
	ConstIterator* Get_HeadConstIterator()const;	//先頭コンストイテレータの取得
	Iterator* Get_TailIterator();			//末尾イテレータの取得
	ConstIterator* Get_TailConstIterator()const;	//末尾コンストイテレータ取得

private:
	Node* m_Node;							//現在位置のポインタ
	Node* m_HeadNode;						//先頭要素のポインタ
	Node* m_TailNode;						//末尾要素のポインタ

	int data_Count;
};
	
