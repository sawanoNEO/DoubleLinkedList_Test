#include "pch.h"
#include"DoubleLinkedList.h"

TEST(List, ID_00) {
	DoubleLinkedList testList;
	ASSERT_EQ(testList.Count_Data(), 0)<<"ID:0-00失敗";
}

TEST(List, ID_01) {
	DoubleLinkedList testList;         //テストデータの構築
	/*DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();*/
	testList.Get_TailIterator();        //末尾イテレータの取得
	ScoreData testScore;

	//ここにtestScoreの初期化

	testList.Push_Back(testList.Get_TailIterator(),testScore);   //データを挿入

	/*Node* testnode = new Node;
	testnode = testIterator->operator*;
	*testnode*/

	ASSERT_EQ(testList.Count_Data(), 1)<<"ID:0-01失敗";    //データ数が1であれば成功
}
//
//TEST(List, ID_02) {    メモリアロケーションエラー時の挙動であると判断したためテストをスキップ
//	DoubleLinkedList testList;          //テストデータの構築
//	/*DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();*/
//	testList.Get_TailIterator();         //末尾イテレータの取得
//	testList.Push_Data(testList.Get_TailIterator());   //データを挿入
//
//	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-02失敗";   //データ数が0であれば成功
//
//}

TEST(List, ID_03) {
	DoubleLinkedList testList;               //テストデータの構築
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	testIterator = testList.Get_Iterator();  //テストデータのイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ

	//ここにtestScoreの初期化

	testList.Push_Back(testIterator,testScore);         //データの挿入

	delete testIterator;
	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-03失敗";   //データ数が0であれば成功
}
//
//TEST(List, ID_04) {   メモリアロケーションエラー時の挙動であると判断したためテストをスキップ
//	DoubleLinkedList testList;               //テストデータの構築
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	testIterator = testList.Get_Iterator();  //テストデータのイテレータを取得
//	testList.Push_Data(testIterator);         //データの挿入
//
//	delete testIterator;
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-04失敗";   //データ数が1であれば成功
//
//}

TEST(List, ID_05) {
	DoubleLinkedList testList;               //テストデータの構築
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	testIterator = testList.Get_Iterator();  //テストデータのイテレータを取得
	testList.Delete_Data(testIterator);      //データを削除

	delete testIterator;
	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-05失敗";   //データ数が0であれば成功

}

//TEST(List, ID_06) {  メモリアロケーションエラー時の挙動であると判断したためテストをスキップ
//	DoubleLinkedList testList;               //テストデータの構築
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	testIterator = testList.Get_Iterator();  //テストデータのイテレータを取得
//	testList.Push_Data(testIterator);        //データの挿入
//	testList.Delete_Data(testIterator);      //データを削除
//
//	delete testIterator;
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-06失敗";   //データ数が1であれば成功
//
//}

TEST(List, ID_07) {
	DoubleLinkedList testList;               //テストデータの構築
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	testIterator = testList.Get_Iterator();  //テストデータのイテレータを取得
	testList.Delete_Data(testIterator);      //データを削除

	delete testIterator;
	ASSERT_NE(testList.Count_Data(), -1) << "ID:0-07失敗。データ数が-1になっています";  //データ数が-1でなければ成功
	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-07失敗";   //データ数が0であれば成功

}

TEST(List, ID_08) {
	DoubleLinkedList const testList; //constで宣言
	testList.Count_Data();           //コンパイルエラーがでなければ成功
}

TEST(List, ID_09_1) {
	DoubleLinkedList testList;            //テストデータの構築
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //テストデータのイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ

//ここにtestScoreの初期化

	testList.Push_Back(testIterator,testScore);      //データを挿入
	bool dataCheck = false;
	Node* testNode = new Node;
	testNode = testList.Get_Node();

	dataCheck = Check_Data(testNode->scoredata, testScore);
	/*if(&testNode->prev->scoredata)
	{
		dataCheck = true;
	}*/
	
	delete testIterator;
	ASSERT_EQ(dataCheck, true ) << "ID:0-09-1失敗";
}

TEST(List, ID_09_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_HeadIterator();
	ScoreData testScore;                     //代入用スコアデータ

//ここにtestScoreの初期化

	testList.Push_Back(testIterator,testScore);
	bool dataCheck = false;
	Node* testNode = new Node;
	testNode = testList.Get_HeadNode();

	if(&testNode->scoredata)
	{
		dataCheck = true;
	}

	delete testIterator;
	ASSERT_NE(dataCheck, true ) << "ID:0-09-2失敗";
}

TEST(List, ID_09_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_TailIterator();
	ScoreData testScore;                     //代入用スコアデータ

//ここにtestScoreの初期化

	testList.Push_Back(testIterator,testScore);
	bool dataCheck = false;
	Node* testNode = new Node;
	testNode = testList.Get_TailNode();

	if(&testNode->scoredata)
	{
		dataCheck = true;
	}

	delete testIterator;
	ASSERT_NE(dataCheck, true ) << "ID:0-09-3失敗";
}

TEST(List, ID_10) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//先頭要素にデータ挿入
	testIterator = testList.Get_HeadIterator();
	Set_ScoreData(testScore, 00003, "test3");
	testList.Push_Back(testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	bool dataCheck = false;
	dataCheck = Check_Data(testList.Get_HeadNode()->scoredata, testScore);

	delete testIterator;
	ASSERT_TRUE(dataCheck)<<"ID0_10失敗";
}

TEST(List, ID_11) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ


    //複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//末尾要素にデータ挿入
	testIterator = testList.Get_TailIterator();
	Set_ScoreData(testScore, 00003, "test3");
	testList.Push_Back(testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	bool dataCheck = false;
	dataCheck = Check_Data(testList.Get_HeadNode()->scoredata, testScore);

	delete testIterator;
	ASSERT_TRUE(dataCheck) << "ID0_11失敗";
}

TEST(List, 12_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//中央要素にデータ挿入
	for (int i = 0; i < 5; i++)
	{
		testIterator--;
	}
	Set_ScoreData(testScore, 00010, "succes");
	testList.Push_Back(testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	bool dataCheck = false;
	//↓暫定的にコメントアウト
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_TRUE(dataCheck) << "ID0_12_1失敗";
}

TEST(List, ID_13_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//中央要素にデータ挿入
	for (int i = 0; i < 5; i++)
	{
		testIterator--;
	}
	Set_ScoreData(testScore, 00010, "succes");
	testList.Push_Back(testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	bool dataCheck = false;
	//暫定的にコメントアウト
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_TRUE(dataCheck) << "ID0_13_1失敗";
}

TEST(List, ID_13_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//先頭要素にデータ挿入
	testIterator = testList.Get_HeadConstIterator();
	Set_ScoreData(testScore, 00010, "succes");
	testList.Push_Back(testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	bool dataCheck = false;
	//暫定的にコメントアウト
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_TRUE(dataCheck) << "ID0_13_2失敗";
}

TEST(List, ID_13_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//末尾要素にデータ挿入
	testIterator = testList.Get_TailConstIterator();
	Set_ScoreData(testScore, 00010, "succes");
	testList.Push_Back(testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	bool dataCheck = false;
	//暫定的にコメントアウト
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_TRUE(dataCheck) << "ID0_13_3失敗";
}

TEST(List, ID_14) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 1, "failed");

	//未参照のイテレータにデータを代入
	testList.Push_Back(testIterator, testScore);
	testIterator = testList.Get_Iterator();


	bool dataCheck=false;
	//暫定的にコメントアウト
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_FALSE(dataCheck)<<"ID0_14失敗";
}

//コンパイルエラーが出れば成功
//TEST(List, ID_15)
//{
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
//	ScoreData testScore;
//
//	testList.Push_Back(testIterator, testScore);
//}

TEST(List, ID_16_1)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	//現在位置の要素を削除
	testIterator = testList.Get_Iterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_FALSE(destroyCheck) << "ID_0_16_1失敗";
}

TEST(List, ID_16_2)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//先頭要素を削除
	testIterator = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_FALSE(destroyCheck) << "ID_0_16_2失敗";
}

TEST(List, ID_16_3)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//末尾要素を削除
	testIterator = testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_FALSE(destroyCheck) << "ID_0_16_3失敗";
}

TEST(List, ID_17) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 0, "test");

	//複数の要素にデータを代入
	testIterator = testList.Get_Iterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(testIterator, testScore);
	}

	//先頭要素を削除
	testIterator = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_17失敗";
}

TEST(List, ID_18) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 0, "test");

	//複数の要素にデータを代入
	testIterator = testList.Get_Iterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(testIterator, testScore);
	}

	//末尾要素を削除
	testIterator = testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_FALSE(destroyCheck) << "ID_0_18失敗";
}

TEST(List, ID_19) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 0, "test");

	//複数の要素にデータを代入
	testIterator = testList.Get_Iterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(testIterator, testScore);
	}

	//指定の要素を削除
	testIterator = testList.Get_HeadIterator();
	for (int i = 0; i < 5; i++)
	{
		testIterator++;
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testIterator);

	testIterator = testList.Get_TailIterator();//恐らく本番では削除
	delete testIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_19失敗";
}

TEST(List, ID_20) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 0, "test");

	//複数の要素にデータを代入
	testConstIterator = testList.Get_HeadConstIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(testConstIterator, testScore);
	}

	//指定の要素を削除
	testConstIterator = testList.Get_HeadConstIterator();
	for (int i = 0; i < 5; i++)
	{
		testConstIterator++;
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testConstIterator);

	testConstIterator = testList.Get_TailIterator();//恐らく本番では削除
	delete testConstIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_20失敗";
}

TEST(List, ID_21) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 1, "failed");

	//未参照のイテレータにデータを代入
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testIterator);


	delete testIterator;//実装後は恐らくエラーになる

	ASSERT_FALSE(destroyCheck) << "ID0_20失敗";
}

//コンパイルエラーが出れば成功
//TEST(List, ID_22)
//{
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testList.Delete_Data(testIterator);
//
//}

TEST(TestCaseName, TestName) {
  ASSERT_EQ(1, 1);
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}