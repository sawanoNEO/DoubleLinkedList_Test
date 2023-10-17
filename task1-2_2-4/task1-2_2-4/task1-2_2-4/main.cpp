#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"

using namespace std;

int main(void)
{
	const char *FileName = "asset\\Scores.txt";//ファイル名を指定
	ifstream ScoreFile(FileName);
	
	//ファイルが開けなければエラー
	if (!ScoreFile)
	{
		cout << "ファイルが開けませんでした" << endl;
		cin.get();
		return 0;
	}

	//宣言
	DoubleLinkedList ScoreList;   //スコアデータを格納する双方向リスト
	DoubleLinkedList::Iterator* Itr = ScoreList.Get_HeadIterator();    //ScoreListのイテレータ
	string Line;  //テキストファイルの一行を保存する用

	while (getline(ScoreFile, Line))       //最後の行まで処理を繰り返す
	{
    	ScoreData* ScoreLine=new ScoreData;//成績データを生成
		string score;                      //スコアを保存する
		string name = "\t";                //名前を保存する
		for (size_t i = 0; i < Line.size(); i++)
		{
			char ch = Line[i];

			if (score.find("\t") == string::npos)//スコアと名前を仕分け
			{
				score += ch;
			}
			else
			{
				name += ch;
			}
		}
		int num = stoi(score);     //scoreをint型に変換

		//成績データをリストに格納
		ScoreLine->Score = num;
		ScoreLine->UserName = name;
		ScoreList.Push_Back(Itr, ScoreLine);

		--(*Itr);
	}
	Itr = ScoreList.Get_TailIterator();

	//データの表示(格納順)
	while ((*Itr) != ScoreList.Get_HeadIterator())//先頭まで繰り返す
	{
		--(*Itr);
		DoubleLinkedList::Node* node = *(*Itr);
		cout << node->scoredata->Score << node->scoredata->UserName << endl;
	}

	cin.get();
	return 0;
}