#include "pch.h"
#include"DoubleLinkedList.h"

TEST(List, ID_00) {
	DoubleLinkedList testList;
	ASSERT_EQ(testList.Count_Data(), 0)<<"ID:0-00失敗";
}

TEST(List, ID_01) {
	DoubleLinkedList testList;         //テストデータの構築
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	*testIterator = *testList.Get_TailIterator();        //末尾イテレータの取得
	ScoreData* testScore;

	//testScoreの初期化
	testScore=Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator,testScore);   //データを挿入


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
	*testIterator = *testList.Get_HeadIterator();  //テストデータのイテレータを取得
	ScoreData* testScore;                     //代入用スコアデータ

	//testScoreの初期化
	testScore = Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator,testScore);         //データの挿入

	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-03失敗";   //データ数が1であれば成功
}
//
//TEST(List, ID_04) {   メモリアロケーションエラー時の挙動であると判断したためテストをスキップ
//	DoubleLinkedList testList;               //テストデータの構築
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	testIterator = testList.Get_HeadIterator();  //テストデータのイテレータを取得
//	testList.Push_Data(testIterator);         //データの挿入
//
//	
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-04失敗";   //データ数が1であれば成功
//
//}

TEST(List, ID_05) {
	DoubleLinkedList testList;               //テストデータの構築
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	ScoreData* testScore;
	testScore = Set_ScoreData(1, "success");
	*testIterator = *testList.Get_TailIterator();  //テストデータのイテレータを取得
	testList.Push_Back(*testIterator, testScore);  //データの挿入

	//*testIterator = *testList.Get_HeadIterator();  //先頭イテレータ取得
	testList.Delete_Data(*testIterator);      //データを削除

	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-05失敗";   //データ数が0であれば成功
}

//TEST(List, ID_06) {  メモリアロケーションエラー時の挙動であると判断したためテストをスキップ
//	DoubleLinkedList testList;               //テストデータの構築
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	testIterator = testList.Get_HeadIterator();  //テストデータのイテレータを取得
//	testList.Push_Data(testIterator);        //データの挿入
//	testList.Delete_Data(testIterator);      //データを削除
//
//	
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-06失敗";   //データ数が1であれば成功
//
//}

TEST(List, ID_07) {
	DoubleLinkedList testList;               //テストデータの構築
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	testIterator = testList.Get_HeadIterator();  //テストデータのイテレータを取得
	testList.Delete_Data(*testIterator);      //データを削除

	
	//ASSERT_NE(testList.Count_Data(), -1) << "ID:0-07失敗。データ数が-1になっています";  //データ数が-1でなければ成功
	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-07失敗";   //データ数が0であれば成功
}

//コンパイルエラーがでなければ成功
//TEST(List, ID_08) {
//	DoubleLinkedList const testList; //constで宣言
//	testList.Count_Data();           //コンパイルエラーがでなければ成功
//}

TEST(List, ID_09_1) {
	DoubleLinkedList testList;            //テストデータの構築
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//先頭要素にデータを挿入
	*testIterator = *testList.Get_HeadIterator();  //テストデータのイテレータを取得
	testScore = Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator,testScore);      //データを挿入

	dataCheck = Check_Data(testIterator, testScore);

	
	
	ASSERT_TRUE(dataCheck) << "ID:0-09-1失敗";
}

TEST(List, ID_09_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore;                     //代入用スコアデータ

	//末尾要素にデータを挿入
	*testIterator = *testList.Get_TailIterator();
	testScore = Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator,testScore);
	bool dataCheck = false;


	dataCheck = Check_Data(testIterator, testScore);

	
	ASSERT_TRUE(dataCheck) << "ID:0-09-2失敗";
}

TEST(List, ID_10) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData* testScore;                     //代入用スコアデータ

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//先頭要素にデータ挿入
	*testIterator = *testList.Get_HeadIterator();
	testScore = Set_ScoreData(10000, "success");
	testList.Push_Back(*testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	bool dataCheck = false;
	dataCheck = Check_Data(testIterator, testScore);

	
	ASSERT_TRUE(dataCheck)<<"ID0_10失敗";
}

TEST(List, ID_11) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData* testScore;                     //代入用スコアデータ
	bool dataCheck = false;


    //複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData((0000) + i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//末尾要素にデータ挿入
	*testIterator = *testList.Get_TailIterator();
	testScore = Set_ScoreData(10000, "success");
	testList.Push_Back(*testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	dataCheck = Check_Data(testIterator, testScore);

	
	ASSERT_TRUE(dataCheck) << "ID0_11失敗";
}

TEST(List, 12_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData* testScore;                     //代入用スコアデータ

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
	}

	//中央要素にデータ挿入
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(10, "succes");
	testList.Push_Back(*testIterator, testScore);
    //チェック関数を用いて値が正しく入ってるか確認する
	bool dataCheck = false;

	dataCheck = Check_Data(testIterator, testScore);
	

	ASSERT_TRUE(dataCheck) << "ID0_12_1失敗";
}

TEST(List, ID_13_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //先頭要素のイテレータを取得
	ScoreData* testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//中央要素にデータ挿入
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(100, "succes");
	testList.Push_Back(*testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	dataCheck = Check_Data(testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_1失敗";
}

TEST(List, ID_13_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData* testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//先頭要素にデータ挿入
	*testIterator = *testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(00010, "succes");
	testList.Push_Back(*testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	dataCheck = Check_Data(testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_2失敗";
}

TEST(List, ID_13_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData* testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//末尾要素にデータ挿入
	*testIterator = *testList.Get_TailConstIterator();
	testScore = Set_ScoreData(100, "succes");
	testList.Push_Back(*testIterator, testScore);

	//チェック関数を用いて値が正しく入ってるか確認する
	dataCheck = Check_Data(testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_3失敗";
}

TEST(List, ID_14) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(1, "failed");

	//未参照のイテレータにデータを代入
	testList.Push_Back(*testIterator, testScore);
	testIterator = testList.Get_HeadIterator();

	
	ASSERT_EQ(testList.Count_Data(),0)<<"ID0_14失敗";
}

//コンパイルエラーが出れば成功
//TEST(List, ID_15)
//{
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	testList.Push_Back(*testIterator, testScore);
//}

TEST(List, ID_16_1)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	//空の要素を削除
	*testIterator = *testList.Get_HeadIterator();
	++(*testIterator);
	++(*testIterator);
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(*testIterator);

	

	ASSERT_FALSE(destroyCheck) << "ID_0_16_1失敗";
}

TEST(List, ID_16_2)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//先頭要素を削除
	*testIterator = *testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(*testIterator);

	

	ASSERT_FALSE(destroyCheck) << "ID_0_16_2失敗";
}

TEST(List, ID_16_3)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//末尾要素を削除
	*testIterator = *testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(*testIterator);

	

	ASSERT_FALSE(destroyCheck) << "ID_0_16_3失敗";
}

TEST(List, ID_17) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(0, "test");

	//複数の要素にデータを代入
	*testIterator = *testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(*testIterator, testScore);
	}

	//先頭要素を削除
	testIterator = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testIterator);

	

	ASSERT_TRUE(destroyCheck) << "ID_0_17失敗";
}

TEST(List, ID_18) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(0, "test");

	//複数の要素にデータを代入
	*testIterator = *testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(*testIterator, testScore);
	}

	//末尾要素を削除
	*testIterator = *testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testIterator);

	

	ASSERT_FALSE(destroyCheck) << "ID_0_18失敗";
}

TEST(List, ID_19) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(0, "test");

	//複数の要素にデータを代入
	*testIterator = *testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(*testIterator, testScore);
	}

	//指定の要素を削除
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testIterator);

	ASSERT_TRUE(destroyCheck) << "ID_0_19失敗";
}

TEST(List, ID_20) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(0, "test");

	//複数の要素にデータを代入
	*testConstIterator = *testList.Get_HeadConstIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(*testConstIterator, testScore);
	}

	//指定の要素を削除
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testConstIterator);

	delete testConstIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_20失敗";
}

TEST(List, ID_21) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//未参照のイテレータのデータを削除
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID0_21失敗";
}

////コンパイルエラーが出れば成功
//TEST(List, ID_22)
//{
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testList.Delete_Data(testIterator);
//
//}

TEST(List, ID_23) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore = new ScoreData;

	//ダミーデータで初期化
	ScoreData_Init(testScore);

	testIterator = testList.Get_HeadIterator();
	

	ASSERT_EQ(testList.Get_HeadIterator(),testIterator) << "ID_0_23失敗.データが一致しない";
	ASSERT_TRUE(Check_Data(testIterator, testScore)) << "ID_0_23失敗.データがダミーでない";
}

TEST(List, ID_24) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 

	//データの挿入
	testScore = Set_ScoreData(1, "succes");
	*testIterator = *testList.Get_HeadIterator();
	testList.Push_Back(*testIterator, testScore);
	testIterator = testList.Get_HeadIterator();

	ASSERT_EQ(testList.Get_HeadIterator(), testIterator)<<"ID_0_24失敗";
}

TEST(List, ID_25) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	*testIterator = *testList.Get_HeadIterator();

	//複数のデータを挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
		testList.Push_Back(*testIterator, testScore);
	}
	testIterator = testList.Get_HeadIterator();
	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_25失敗";
}

TEST(List,ID0_26_1){//先頭要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore=new ScoreData; 

	*testIterator = *testList.Get_HeadIterator();
	testScore = Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator, testScore);

	testIterator = testList.Get_HeadIterator();

	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_26_1失敗";
}

TEST(List,ID0_26_2){//中央要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore=new ScoreData; 

	*testIterator = *testList.Get_HeadIterator();

	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Push_Back(*testIterator, testScore);
	}

	//中央要素にデータを挿入する
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(10000, "center");
	testList.Push_Back(*testIterator, testScore);
	testIterator = testList.Get_HeadIterator();


	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_26_2失敗";
}

//TEST(List,ID0_26_3){//末尾要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator=testList.Get_TailIterator();
//	//末尾要素にデータを挿入する
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(*testIterator, testScore);
//	testIterator = testList.Get_HeadIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_26_3失敗";
//}
//
//TEST(List,ID0_27_1){//先頭要素のデータを削除した場合
//    ////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//	testIterator = testList.Get_HeadIterator();
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//		
//	}
//
//
//	//先頭要素のデータを削除する
//	testIterator = testList.Get_HeadIterator();
//	testList.Delete_Data(testIterator);
//
//	testIterator = testList.Get_HeadIterator();
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_27_1失敗";
//}
//
//TEST(List,ID0_27_2){//中央要素のデータを削除した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator=testList.Get_HeadIterator();
//	//中央要素のデータを削除する
//	for (int i = 0; i < 5; i++)
//	{
//		testIterator++;
//	}
//	testList.Delete_Data(testIterator);
//	testIterator = testList.Get_HeadIterator();
//
//	testIterator = testList.Get_HeadIterator();
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_27_2失敗";
//}
//
//TEST(List,ID0_27_3){//末尾要素のデータを削除した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//末尾要素のデータを削除する
//	testIterator=testList.Get_TailIterator();
//	testList.Delete_Data(testIterator);
//	testIterator = testList.Get_HeadIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_27_3失敗";
//}
//
////コンパイルエラーが出れば成功
////TEST(List, ID_28) {
////	const DoubleLinkedList testList;
////	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
////	testIterator = testList.Get_HeadIterator();
////
////}
//
//TEST(List, ID_29) {
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_29失敗";
//}
//
//TEST(List, ID_30) {
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//データの挿入
//	testScore = Set_ScoreData(1, "succes");
//	testConstIterator = testList.Get_HeadConstIterator();
//	testList.Push_Back(testConstIterator, testScore);
//
//	testConstIterator = testList.Get_HeadConstIterator();
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_30失敗";
//}
//
//TEST(List, ID_31) {
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//	testConstIterator = testList.Get_HeadConstIterator();
//
//	//複数のデータを挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "test");
//		testList.Push_Back(testConstIterator, testScore);
//
//	}
//	testConstIterator = testList.Get_HeadConstIterator();
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_31失敗";
//}
//
//TEST(List, ID0_32_1) {//先頭要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	testScore = Set_ScoreData(1, "success");
//	testList.Push_Back(testConstIterator, testScore);
//
//	testConstIterator = testList.Get_HeadConstIterator();
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_32_1失敗";
//}
//
//TEST(List, ID0_32_2) {//中央要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//中央要素にデータを挿入する
//	for (int i = 0; i < 5; i++)
//	{
//		testConstIterator++;
//	}
//	testScore = Set_ScoreData(10000, "center");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_32_2失敗";
//}
//
//TEST(List, ID0_32_3) {//末尾要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//末尾要素にデータを挿入する
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_32_3失敗";
//}
//
//TEST(List, ID0_33_1) {//先頭要素のデータを削除した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//	testConstIterator = testList.Get_HeadConstIterator();
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//
//	}
//
//
//	//先頭要素のデータを削除する
//	testConstIterator = testList.Get_HeadConstIterator();
//	testList.Delete_Data(testConstIterator);
//
//	testConstIterator = testList.Get_HeadConstIterator();
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_33_1失敗";
//}
//
//TEST(List, ID0_33_2) {//中央要素のデータを削除した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//中央要素のデータを削除する
//	for (int i = 0; i < 5; i++)
//	{
//		testConstIterator++;
//	}
//	testList.Delete_Data(testConstIterator);
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_33_2失敗";
//}
//
//TEST(List, ID0_33_3) {//末尾要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//末尾要素にデータを挿入する
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_33_3失敗";
//}
//
////コンパイルエラーとならなければ成功
////TEST(List, ID_34) {
////	const DoubleLinkedList testList;
////	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
////	testConstIterator = testList.Get_HeadConstIterator();
////}
//
//TEST(List, ID_35) {
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_TailIterator();
//
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_35失敗";
//}
//
//TEST(List, ID_36) {
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//データの挿入
//	testScore = Set_ScoreData(1, "success");
//	testIterator = testList.Get_HeadIterator();
//	testList.Push_Back(*testIterator, testScore);
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_36失敗";
//}
//
//TEST(List, ID_37) {
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//	testIterator = testList.Get_HeadIterator();
//
//	//複数のデータを挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "test");
//		testList.Push_Back(*testIterator, testScore);
//
//	}
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_37失敗";
//}
//
//TEST(List, ID0_38_1) {//先頭要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	testIterator = testList.Get_HeadIterator();
//	testScore = Set_ScoreData(1, "success");
//	testList.Push_Back(*testIterator, testScore);
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_38_1失敗";
//}
//
//TEST(List, ID0_38_2) {//中央要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator = testList.Get_HeadIterator();
//	//中央要素にデータを挿入する
//	for (int i = 0; i < 5; i++)
//	{
//		testIterator++;
//	}
//	testScore = Set_ScoreData(10000, "center");
//	testList.Push_Back(*testIterator, testScore);
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_38_2失敗";
//}
//
//TEST(List, ID0_38_3) {//末尾要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator = testList.Get_TailIterator();
//	//末尾要素にデータを挿入する
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(*testIterator, testScore);
//	testIterator = testList.Get_TailIterator();
//
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_38_3失敗";
//}
//
//TEST(List, ID0_39_1) {//先頭要素のデータを削除した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//	testIterator = testList.Get_HeadIterator();
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//
//	}
//
//
//	//先頭要素のデータを削除する
//	testIterator = testList.Get_HeadIterator();
//	testList.Delete_Data(testIterator);
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_39_1失敗";
//}
//
//TEST(List, ID0_39_2) {//中央要素のデータを削除した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator = testList.Get_HeadIterator();
//	//中央要素のデータを削除する
//	for (int i = 0; i < 5; i++)
//	{
//		testIterator++;
//	}
//	testList.Delete_Data(testIterator);
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_39_2失敗";
//}
//
//TEST(List, ID0_39_3) {//末尾要素のデータを削除した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//末尾要素のデータを削除する
//	testIterator = testList.Get_TailIterator();
//	testList.Delete_Data(testIterator);
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_39_3失敗";
//}
//
////コンパイルエラーが出れば成功
////TEST(List, ID_40) {
////	const DoubleLinkedList testList;
////	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
////	testIterator = testList.Get_TailIterator();
////
////}
//
//TEST(List, ID_41) {
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_41失敗";
//}
//
//TEST(List, ID_42) {
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//データの挿入
//	testScore = Set_ScoreData(1, "succes");
//	testConstIterator = testList.Get_TailConstIterator();
//	testList.Push_Back(testConstIterator, testScore);
//
//	testConstIterator = testList.Get_TailConstIterator();
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_42失敗";
//}
//
//TEST(List, ID_43) {
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//	testConstIterator = testList.Get_HeadConstIterator();
//
//	//複数のデータを挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "test");
//		testList.Push_Back(testConstIterator, testScore);
//
//	}
//	testConstIterator = testList.Get_TailConstIterator();
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_43失敗";
//}
//
//TEST(List, ID0_44_1) {//先頭要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	testScore = Set_ScoreData(1, "success");
//	testList.Push_Back(testConstIterator, testScore);
//
//	testConstIterator = testList.Get_TailConstIterator();
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_44_1失敗";
//}
//
//TEST(List, ID0_44_2) {//中央要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//中央要素にデータを挿入する
//	for (int i = 0; i < 5; i++)
//	{
//		testConstIterator++;
//	}
//	testScore = Set_ScoreData(10000, "center");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_44_2失敗";
//}
//
//TEST(List, ID0_44_3) {//末尾要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//末尾要素にデータを挿入する
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_44_3失敗";
//}
//
//TEST(List, ID0_45_1) {//先頭要素のデータを削除した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//	testConstIterator = testList.Get_HeadConstIterator();
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//
//	}
//
//
//	//先頭要素のデータを削除する
//	testConstIterator = testList.Get_HeadConstIterator();
//	testList.Delete_Data(testConstIterator);
//
//	testConstIterator = testList.Get_TailConstIterator();
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_45_1失敗";
//}
//
//TEST(List, ID0_45_2) {//中央要素のデータを削除した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//中央要素のデータを削除する
//	for (int i = 0; i < 5; i++)
//	{
//		testConstIterator++;
//	}
//	testList.Delete_Data(testConstIterator);
//
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_45_2失敗";
//}
//
//TEST(List, ID0_45_3) {//末尾要素にデータを挿入した場合
//	////テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//一旦データを挿入する
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//末尾要素にデータを挿入する
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_45_3失敗";
//}
//
////コンパイルエラーとならなければ成功
////TEST(List, ID_46) {
////	const DoubleLinkedList testList;
////	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
////	testConstIterator = testList.Get_TailConstIterator();
////}
//
////以下、イテレータに関するテスト
////基本的にはIDの2番目の値が1の場合はイテレータ、2の場合はコンストイテレータに対してテストを行う
//
//TEST(Iterator, ID_0_1) {
//	////テスト用データの宣言
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//イテレータの指す要素を取得(失敗する)
//	DoubleLinkedList::Node* testNode = testIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_0_1失敗";
//}
//
//TEST(Iterator, ID_0_2) {
//	//テスト用データの宣言
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	//イテレータの指す要素を取得(失敗する)
//	const DoubleLinkedList::Node* testNode = testConstIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_0_2失敗";
//}
//
//TEST(Iterator, ID_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Node* testNode;
//	ScoreData* testScore; 
//	testScore = Set_ScoreData(1, "success");
//
//	//テストデータを挿入
//	testIterator = testList.Get_HeadIterator();
//	testList.Push_Back(*testIterator, testScore);
//	testNode =testIterator->operator*();
//
//	bool dataCheck = false;
//	dataCheck = Check_Data(testIterator, testScore);//第一引数がNode*の関数を作った方がいいかも
//
//	ASSERT_NO_THROW(testNode) << "ID_1_1失敗";
//	ASSERT_TRUE(dataCheck) << "ID_1_1データなし";
//}
//
//TEST(Iterator, ID_2) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Node* testNode;
//	ScoreData* testScore; 
//	testScore = Set_ScoreData(1, "success");
//
//	//テストデータを挿入
//	testConstIterator = testList.Get_HeadIterator();
//	testList.Push_Back(testConstIterator, testScore);
//	testNode = testConstIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_2失敗";
//}
//
//TEST(Iterator, ID_3_1) {
//
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Node* testNode;
//
//	//先頭要素を取得
//	testIterator = testList.Get_HeadIterator();
//	testNode = testIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_3_1失敗";
//}
//
//TEST(Iterator, ID_3_2) {
//
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Node* testNode;
//
//	//先頭要素を取得
//	testConstIterator = testList.Get_HeadConstIterator();
//	testNode = testConstIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_3_2失敗";
//}
//
//TEST(Iterator, ID_4_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Node* testNode;
//
//	//先頭要素を取得
//	testIterator = testList.Get_TailIterator();
//	testNode = testIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_4_1失敗";
//}
//
//TEST(Iterator, ID_4_2) {
//
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Node* testNode;
//
//	//先頭要素を取得
//	testConstIterator = testList.Get_TailConstIterator();
//	testNode = testConstIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_4_2失敗";
//}
//
//TEST(Iterator, ID_5_1) {
//	//テスト用データの宣言
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//末尾側に進める
//	testIterator++;
//	ASSERT_ANY_THROW(testIterator)<<"ID_1_5_1失敗";
//}
//
//TEST(Iterator, ID_5_2) {
//	//テスト用データの宣言
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//	//末尾側に進める
//	testConstIterator++;
//	ASSERT_ANY_THROW(testConstIterator)<<"ID_1_5_2失敗";
//}
//
//TEST(Iterator, ID_6_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	testIterator = testList.Get_HeadIterator();
//	//末尾側に進める
//	testIterator++;
//
//	ASSERT_ANY_THROW(testIterator) << "ID_1_6_1失敗";
//}
//
//TEST(Iterator, ID_6_2) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//末尾側に進める
//	testConstIterator++;
//
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_6_2失敗";
//}
//
//TEST(Iterator, ID_7_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	testIterator = testList.Get_TailIterator();
//	//末尾側に進める
//	testIterator++;
//
//	ASSERT_ANY_THROW(testIterator) << "ID_1_7_1失敗";
//}
//
//TEST(Iterator, ID_7_2) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//末尾側に進める
//	testConstIterator++;
//
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_7_2失敗";
//}
//
//TEST(Iterator, ID_8_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//先頭から順に検証していく
//	testIterator = testList.Get_HeadIterator();
//	int i = 4;
//	while (testIterator||i>0)
//	{
//		testScore = Set_ScoreData(i, "success");
//		dataCheck = Check_Data(testIterator, testScore);
//		testIterator++;
//		i--;
//		ASSERT_TRUE(dataCheck) << "ID_1_8_1失敗";
//	}
//}
//
//TEST(Iterator, ID_8_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//先頭から順に検証していく
//	testConstIterator = testList.Get_HeadConstIterator();
//	int i = 4;
//	while (testConstIterator||i>0)
//	{
//		testScore = Set_ScoreData(i, "success");
//		dataCheck = Check_Data(testConstIterator, testScore);
//		testConstIterator++;
//		i--;
//		ASSERT_TRUE(dataCheck) << "ID_1_8_2失敗";
//	}
//}
//
//TEST(Iterator, ID_9_1){
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//移動前の検証
//	testIterator = testList.Get_HeadIterator();
//	testScore = Set_ScoreData(0, "dummy");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_9_1失敗";
//
//	//一つ進めた後の検証
//	++testIterator;
//	testScore = Set_ScoreData(4, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_9_1失敗";
//
//}
//
//TEST(Iterator, ID_9_2){
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//移動前の検証
//	testConstIterator = testList.Get_HeadConstIterator();
//	testScore = Set_ScoreData(0, "dummy");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_9_2失敗";
//
//	//一つ進めた後の検証
//	++testConstIterator;
//	testScore = Set_ScoreData(4, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_9_2失敗";
//
//}
//
//TEST(Iterator, ID_10_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//移動前の検証
//	testIterator = testList.Get_HeadIterator();
//	testScore = Set_ScoreData(0, "dummy");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_10_1失敗";
//
//	//一つ進めた後の検証
//	testIterator++;
//	testScore = Set_ScoreData(4, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_10_1失敗";
//
//}
//
//TEST(Iterator, ID_10_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//移動前の検証
//	testConstIterator = testList.Get_HeadConstIterator();
//	testScore = Set_ScoreData(0, "dummy");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_10_2失敗";
//
//	//一つ進めた後の検証
//	testConstIterator++;
//	testScore = Set_ScoreData(4, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_10_2失敗";
//
//}
//
//TEST(Iterator, ID_11_1) {
//	//テスト用データの宣言
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//先頭側に進める
//	testIterator--;
//	ASSERT_ANY_THROW(testIterator) << "ID_1_11_1失敗";
//}
//
//TEST(Iterator, ID_11_2) {
//	//テスト用データの宣言
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	//先頭側に進める
//	testConstIterator--;
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_11_2失敗";
//}
//
//TEST(Iterator, ID_12_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	testIterator = testList.Get_TailIterator();
//	//先頭側に進める
//	testIterator--;
//
//	ASSERT_ANY_THROW(testIterator) << "ID_1_12_1失敗";
//}
//
//TEST(Iterator, ID_12_2) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//先頭側に進める
//	testConstIterator++;
//
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_12_2失敗";
//}
//
//TEST(Iterator, ID_13_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	testIterator = testList.Get_HeadIterator();
//	//先頭側に進める
//	testIterator--;
//
//	ASSERT_ANY_THROW(testIterator) << "ID_1_13_1失敗";
//}
//
//TEST(Iterator, ID_13_2) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//末尾側に進める
//	testConstIterator--;
//
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_13_2失敗";
//}
//
//TEST(Iterator, ID_14_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//先頭から順に検証していく
//	testIterator = testList.Get_HeadIterator();
//	int i = 0;
//	while (testIterator || i < 5)
//	{
//		testScore = Set_ScoreData(i, "success");
//		dataCheck = Check_Data(testIterator, testScore);
//		testIterator--;
//		i++;
//		ASSERT_TRUE(dataCheck) << "ID_1_14_1失敗";
//	}
//}
//
//TEST(Iterator, ID_14_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//先頭から順に検証していく
//	testConstIterator = testList.Get_HeadConstIterator();
//	int i = 0;
//	while (testConstIterator || i < 5)
//	{
//		testScore = Set_ScoreData(i, "success");
//		dataCheck = Check_Data(testConstIterator, testScore);
//		testConstIterator--;
//		i++;
//		ASSERT_TRUE(dataCheck) << "ID_1_14_2失敗";
//	}
//}
//
//TEST(Iterator, ID_15_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//移動前の検証
//	testIterator = testList.Get_TailIterator();
//	testScore = Set_ScoreData(0, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_15_1失敗";
//
//	//一つ戻した後の検証
//	--testIterator;
//	testScore = Set_ScoreData(1, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_15_1失敗";
//
//}
//
//TEST(Iterator, ID_15_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//移動前の検証
//	testConstIterator = testList.Get_TailConstIterator();
//	testScore = Set_ScoreData(0, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_15_2失敗";
//
//	//一つ進めた後の検証
//	--testConstIterator;
//	testScore = Set_ScoreData(1, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_15_2失敗";
//
//}
//
//TEST(Iterator, ID_16_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//移動前の検証
//	testIterator = testList.Get_TailIterator();
//	testScore = Set_ScoreData(0, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_16_1失敗";
//
//	//一つ進めた後の検証
//	testIterator--;
//	testScore = Set_ScoreData(1, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_16_1失敗";
//
//}
//
//TEST(Iterator, ID_16_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//とりあえずデータの挿入
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//移動前の検証
//	testConstIterator = testList.Get_TailConstIterator();
//	testScore = Set_ScoreData(0, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_16_2失敗";
//
//	//一つ進めた後の検証
//	testConstIterator--;
//	testScore = Set_ScoreData(1, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_16_2失敗";
//
//}
//
////コンパイルエラーとなれば成功
////TEST(Iterator, ID_17) {
////	DoubleLinkedList::ConstIterator* testConstIterator=new DoubleLinkedList::ConstIterator;
////	DoubleLinkedList::Iterator* testIterator = testConstIterator;
////}
//
//TEST(Iterator, ID_18_1) {
//	//テストデータの宣言
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	//コピーコンストラクタ
//	DoubleLinkedList::Iterator* testIterator_1 = testIterator_0;
//
//	ASSERT_EQ(testIterator_0, testIterator_1) << "ID_1_18_1失敗";
//}
//
//TEST(Iterator, ID_18_2) {
//	//テストデータの宣言
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	//コピーコンストラクタ
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = testConstIterator_0;
//
//	ASSERT_EQ(testConstIterator_0, testConstIterator_1) << "ID_1_18_2失敗";
//}
//
////コンパイルエラーとなれば成功
////TEST(Iterator, ID_19) {
////	DoubleLinkedList::ConstIterator* testConstIterator=new DoubleLinkedList::ConstIterator;
////	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
////	testIterator=testConstIterator;
////}
//
//TEST(Iterator, ID_20_1) {
//	//テストデータの宣言
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//
//	//イテレータのコピー
//	testIterator_0 = testIterator_1;
//
//	ASSERT_EQ(testIterator_0, testIterator_1) << "ID_1_20_1失敗";
//}
//
//
//TEST(Iterator, ID_20_2) {
//	//テストデータの宣言
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//
//	//コンストイテレータのコピー
//	testConstIterator_0 = testConstIterator_1;
//
//	ASSERT_EQ(testConstIterator_0, testConstIterator_1) << "ID_1_20_2失敗";
//}
//
//TEST(Iterator, ID_21_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator_0 = testList.Get_HeadIterator();
//	DoubleLinkedList::Iterator* testIterator_1 = testList.Get_TailIterator();
//	bool dataCheck=false;
//
//	//データの比較
//	dataCheck = testIterator_0 == testIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_21_1失敗";
//}
//
//TEST(Iterator, ID_21_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = testList.Get_HeadConstIterator();
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = testList.Get_TailConstIterator();
//	bool dataCheck = false;
//
//	//データの比較
//	dataCheck = testConstIterator_0 == testConstIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_21_2失敗";
//}
//
//TEST(Iterator, ID_22_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//	bool dataCheck = false;
//
//	testIterator_0 = testList.Get_HeadIterator();
//
//	//データの比較
//	testIterator_0 = testIterator_1;
//	dataCheck = testIterator_0 == testIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_22_1失敗";
//}
//
//TEST(Iterator, ID_22_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//	bool dataCheck = false;
//
//	//データの比較
//	testConstIterator_0 = testList.Get_HeadConstIterator();
//	testConstIterator_0 = testConstIterator_1;
//	dataCheck = testConstIterator_0 == testConstIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_22_2失敗";
//}
//
//TEST(Iterator, ID_23_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList_0;
//	DoubleLinkedList testList_1;
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//	bool dataCheck = true;
//
//	//データの比較
//	testIterator_0 = testList_0.Get_HeadIterator();
//	testIterator_1 = testList_1.Get_HeadIterator();
//	dataCheck = testIterator_0 == testIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_23_1失敗";
//}
//
//TEST(Iterator, ID_23_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList_0;
//	DoubleLinkedList testList_1;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//	bool dataCheck = true;
//
//	//データの比較
//	testConstIterator_0 = testList_0.Get_HeadConstIterator();
//	testConstIterator_1 = testList_1.Get_HeadConstIterator();
//	dataCheck = testConstIterator_0 == testConstIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_23_2失敗";
//}
//
//TEST(Iterator, ID_24_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator_0 = testList.Get_HeadIterator();
//	DoubleLinkedList::Iterator* testIterator_1 = testList.Get_TailIterator();
//	bool dataCheck = true;
//
//	//データの比較
//	dataCheck = testIterator_0 != testIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_24_1失敗";
//}
//
//TEST(Iterator, ID_24_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = testList.Get_HeadConstIterator();
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = testList.Get_TailConstIterator();
//	bool dataCheck = true;
//
//	//データの比較
//	dataCheck = testConstIterator_0 != testConstIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_24_2失敗";
//}
//
//TEST(Iterator, ID_25_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//	bool dataCheck = true;
//
//	testIterator_0 = testList.Get_HeadIterator();
//
//	//データの比較
//	testIterator_0 = testIterator_1;
//	dataCheck = testIterator_0 != testIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_25_1失敗";
//}
//
//TEST(Iterator, ID_25_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//	bool dataCheck = true;
//
//	//データの比較
//	testConstIterator_0 = testList.Get_HeadConstIterator();
//	testConstIterator_0 = testConstIterator_1;
//	dataCheck = testConstIterator_0 != testConstIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_25_2失敗";
//}
//
//TEST(Iterator, ID_26_1) {
//	//テストデータの宣言
//	DoubleLinkedList testList_0;
//	DoubleLinkedList testList_1;
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//	bool dataCheck =false;
//
//	//データの比較
//	testIterator_0 = testList_0.Get_HeadIterator();
//	testIterator_1 = testList_1.Get_HeadIterator();
//	dataCheck = testIterator_0 != testIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_26_1失敗";
//}
//
//TEST(Iterator, ID_26_2) {
//	//テストデータの宣言
//	DoubleLinkedList testList_0;
//	DoubleLinkedList testList_1;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//	bool dataCheck = false;
//
//	//データの比較
//	testConstIterator_0 = testList_0.Get_HeadConstIterator();
//	testConstIterator_1 = testList_1.Get_HeadConstIterator();
//	dataCheck = testConstIterator_0 == testConstIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_26_2失敗";
//}
//
//TEST(TestCaseName, TestName) {
//  ASSERT_EQ(1, 1);
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}