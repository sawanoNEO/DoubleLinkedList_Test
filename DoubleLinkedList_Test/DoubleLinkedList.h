#pragma once
#include <string>

struct ScoreData			 //成績データ　
{
	int Score;				 //スコア
	std::string UserName;	 //ユーザー名
};

struct Node					 //ノード
{
	Node* prev;				 //前のノードへのポインタ
	Node* next;				 //次のノードへのポインタ
	ScoreData scoredata;	 //成績データ　
};

class DoubleLinkedList       //双方向リストクラス
{
public:
	class ConstIterator      //コンストイテレータクラス(DoubleLinkedListのインナークラス)
	{
	public:
		ConstIterator();
		~ConstIterator();

		void operator--();									   //リストの先頭に向かって一つ進める
		void operator++();									   //リストの末尾に向かって一つ進める
		Node* const operator* ();							   //イテレータの指す要素を取得する(const)
		ConstIterator(const ConstIterator& constiterator);	   //コピーコンストラクタ
		ConstIterator operator= (ConstIterator);			   //代入を行う
		bool operator==(ConstIterator);						   //同一か比較する
		bool operator!=(ConstIterator);						   //異なるか比較する


	};

	class Iterator : public ConstIterator   //イテレータクラス(DoubleLinkedListのインナークラス)
	{
	public:
		Node* operator*();            //イテレータの指す要素を取得する(非const)
	};

	DoubleLinkedList();
	~DoubleLinkedList();
    int Count_Data()const;				    //データ数の取得
	void Push_Back(ConstIterator* _iterator,ScoreData _scoredata);				//データの挿入(イテレータ)
	bool Delete_Data(ConstIterator* _iterator);	//データの削除(イテレータ)正常に削除出来たならtrueを返す
	Iterator* Get_Iterator();               //現在位置のイテレータの取得
	Iterator* Get_HeadIterator();			//先頭イテレータの取得
	ConstIterator* Get_HeadConstIterator();	//先頭コンストイテレータの取得
	Iterator* Get_TailIterator();			//末尾イテレータの取得
	ConstIterator* Get_TailConstIterator();	//末尾コンストイテレータ取得
	Node* Get_Node();                       //現在位置の要素取得
	Node* Get_HeadNode();                   //先頭要素取得
	Node* Get_TailNode();                   //末尾要素取得

private:
	Node* m_Node;							//現在位置のポインタ
	Node* m_Head;							//先頭要素のポインタ
	Node* m_Tail;							//末尾要素のポインタ
	Iterator* m_Iterator;					//イテレータ
	ConstIterator* m_ConstIterator;			//コンストイテレータ

};
	
bool Check_Data(ScoreData _scoredata,ScoreData _checker);      //Nodeの中のデータが引数のものと同一が比較する(テスト用関数)
void Set_ScoreData(ScoreData _scoredata, int _score, const char* _username); //成績データを代入する(テスト用)