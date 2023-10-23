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

	//各変数の宣言
	DoubleLinkedList ScoreList;   //スコアデータを格納する双方向リスト
	DoubleLinkedList::Iterator Itr = ScoreList.Get_HeadIterator();    //ScoreListのイテレータ
	string Line;  //テキストファイルの一行を保存する用

	while (getline(ScoreFile, Line))       //最後の行まで処理を繰り返す
	{
    	ScoreData ScoreLine;//成績データを生成
		string score;                      //スコアを保存する
		string name = "\t";                //名前を保存する
		for (size_t i = 0; i < Line.size(); i++)
		{
			char ch = Line[i];

			if (score.find("\t") == string::npos)//スコアと名前を仕分けして対応する変数に一文字ずつ格納
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
		ScoreLine.Score = num;
		ScoreLine.UserName = name;
		ScoreList.Insert(Itr, ScoreLine);

		--Itr;
	}
	Itr = ScoreList.Get_TailIterator();

	//格納したデータを表示させる
	ScoreData displayScore = *Itr; //表示させるデータ
	ScoreData headScore = *ScoreList.Get_HeadIterator();//繰り返し処理の判定用

	//データの表示(格納順)
	while (displayScore.Score != headScore.Score&&
		   displayScore.UserName!=headScore.UserName)//先頭まで繰り返す
	{
		--Itr;//一つ前のデータを格納する
		displayScore = *Itr;
		cout << displayScore.Score << displayScore.UserName << endl;
	}

	cin.get();
	return 0;
}