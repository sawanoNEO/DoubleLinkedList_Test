#include "pch.h"
#include"DoubleLinkedList.h"
#include "ListTest.h"

//データ数の取得、リストが空の場合の戻り値
TEST(List, ID_00) {
	DoubleLinkedList testList;
	ASSERT_EQ(testList.Count(), 0)<<"ID:0-00失敗";
}

//データ数の取得、リスト末尾への挿入を行った際の戻り値
TEST(List, ID_01) {
	DoubleLinkedList testList;         //テストデータの構築
	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_TailIterator();        //末尾イテレータの取得
	ScoreData testScore;

	//testScoreの初期化
	testScore=Set_ScoreData(1, "success");
    testList.Insert(*testIterator,testScore);   //データを挿入

	ASSERT_EQ(testList.Count(), 1)<<"ID:0-01失敗";    //データ数が1であれば成功
}

////データ数の取得、リスト末尾への挿入が失敗した際の戻り値
//TEST(List, ID_02) {    メモリアロケーションエラー時の挙動であると判断したためテストをスキップ
//	DoubleLinkedList testList;          //テストデータの構築
//	/*DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();*/
//	testList.Get_TailIterator();         //末尾イテレータの取得
//	testList.Push_Data(testList.Get_TailIterator());   //データを挿入
//
//	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-02失敗";   //データ数が0であれば成功
//
//}

//データ数の取得、データの挿入を行った際の戻り値
TEST(List, ID_03) {
	DoubleLinkedList testList;               //テストデータの構築
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //テストデータのイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ

	//testScoreの初期化
	testScore = Set_ScoreData(1, "success");
    testList.Insert(*testIterator,testScore);         //データの挿入

	ASSERT_EQ(testList.Count(), 1) << "ID:0-03失敗";   //データ数が1であれば成功
}

//データ数の取得、データの挿入に失敗した際の戻り値
////TEST(List, ID_04) {   メモリアロケーションエラー時の挙動であると判断したためテストをスキップ
////	DoubleLinkedList testList;               //テストデータの構築
////	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
////	(*testIterator) = testList.Get_HeadIterator();  //テストデータのイテレータを取得
////	testList.Push_Data(testIterator);         //データの挿入
////
////	
////	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-04失敗";   //データ数が1であれば成功
////
////}

//データ数の取得、データの削除を行った際の戻り値
TEST(List, ID_05) {
	DoubleLinkedList testList;               //テストデータの構築
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator; 
	ScoreData testScore;
	testScore = Set_ScoreData(1, "success");
	(*testIterator) = testList.Get_TailIterator();  //テストデータのイテレータを取得
    testList.Insert(*testIterator, testScore);  //データの挿入
	--(*testIterator);
	testList.Delete(*testIterator);      //データを削除

	ASSERT_EQ(testList.Count(), 0) << "ID:0-05失敗";   //データ数が0であれば成功
}

//データ数の取得、データの削除が失敗した際の戻り値
//TEST(List, ID_06) {  メモリアロケーションエラー時の挙動であると判断したためテストをスキップ
//	DoubleLinkedList testList;               //テストデータの構築
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	(*testIterator) = testList.Get_HeadIterator();  //テストデータのイテレータを取得
//	testList.Push_Data(testIterator);        //データの挿入
//	testList.Delete(testIterator);      //データを削除
//
//	
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-06失敗";   //データ数が1であれば成功
//
//}

//データ数の取得、リストが空である場合にデータの削除を行った際の戻り値
TEST(List, ID_07) {
	DoubleLinkedList testList;               //テストデータの構築
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	(*testIterator) = testList.Get_HeadIterator();  //テストデータのイテレータを取得
	testList.Delete(*testIterator);      //データを削除

	ASSERT_EQ(testList.Count(), 0) << "ID:0-07失敗";   //データ数が0であれば成功
}
//
////データ数の取得、constのメソッドであるか
////コンパイルエラーがでなければ成功
////TEST(List, ID_08) {
////	DoubleLinkedList const testList; //constで宣言
////	testList.Count_Data();           //コンパイルエラーがでなければ成功
////}
//
//データ挿入関数:リストが空である場合に、挿入した際の挙動(先頭イテレータで検証)
TEST(List, ID_09_1) {
	DoubleLinkedList testList;            //テストデータの構築
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//先頭要素にデータを挿入
	(*testIterator) = testList.Get_HeadIterator();  //テストデータのイテレータを取得
	testScore = Set_ScoreData(1, "success");
    
	dataCheck = testList.Insert(*testIterator,testScore);      //データを挿入
	
	ASSERT_TRUE(dataCheck) << "ID:0-09-1失敗";
}

//データ挿入関数:リストが空である場合に、挿入した際の挙動(末尾イテレータで検証)
TEST(List, ID_09_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//末尾要素にデータを挿入
	(*testIterator) = testList.Get_TailIterator();
	testScore = Set_ScoreData(1, "success");
	dataCheck = testList.Insert(*testIterator,testScore);

	ASSERT_TRUE(dataCheck) << "ID:0-09-2失敗";
}

//データ挿入関数:リストに複数の要素がある場合に、先頭イテレータを渡して挿入を行った際の戻り値
TEST(List, ID_10) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
   	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
		
	}

	//先頭要素にデータ挿入
	(*testIterator) = testList.Get_HeadIterator();
	testScore = Set_ScoreData(10000, "success");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck)<<"ID0_10失敗";
}

//データ挿入関数:リストに複数の要素がある場合に、末尾イテレータを渡して挿入を行った際の戻り値
TEST(List, ID_11) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //先頭位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

    //複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	 testList.Insert(*testIterator, testScore);
		--(*testIterator);
		
	}

	//末尾要素にデータ挿入
	(*testIterator) = testList.Get_TailIterator();
	testScore = Set_ScoreData(10000, "success");
    dataCheck = testList.Insert(*testIterator, testScore);
	
	ASSERT_TRUE(dataCheck) << "ID0_11失敗";
}

//データ挿入関数:リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入を行った際の戻り値(中央で検証)
TEST(List, 12_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	 testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//中央要素にデータ挿入
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_12_1失敗";
}

//データ挿入関数:リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入を行った際の戻り値(先頭で検証)
TEST(List, 12_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	 testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//先頭にデータ挿入
	*testIterator = testList.Get_HeadIterator();
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_12_2失敗";
}

//データ挿入関数:リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入を行った際の戻り値(末尾で検証)
TEST(List, 12_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	 testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//末尾要素にデータ挿入
	*testIterator = testList.Get_TailIterator();
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_12_2失敗";
}

//データ挿入関数:ConstIteratorを指定して挿入を行った際の挙動(中央で検証)
TEST(List, ID_13_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //先頭要素のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	    testList.Insert(*testIterator, testScore);
	    --(*testIterator);
	}

	//中央要素にデータ挿入
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_1失敗";
}

//データ挿入関数:ConstIteratorを指定して挿入を行った際の挙動(先頭で検証)
TEST(List, ID_13_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//先頭要素にデータ挿入
	(*testIterator) = testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(00010, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_2失敗";
}

//データ挿入関数:ConstIteratorを指定して挿入を行った際の挙動(末尾で検証)
TEST(List, ID_13_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //現在位置のイテレータを取得
	ScoreData testScore;                     //代入用スコアデータ
	bool dataCheck = false;

	//複数のデータを代入
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//末尾要素にデータ挿入
	(*testIterator) = testList.Get_TailConstIterator();
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_3失敗";
}

//不正なイテレータを渡し、挿入した場合の挙動
TEST(List, ID_14) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	testScore = Set_ScoreData(1, "failed");
	bool dataCheck=false;

	//未参照のイテレータにデータを代入
    dataCheck = testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_HeadIterator();

	ASSERT_EQ(testList.Count(),0)<<"ID0_14失敗";
}

////データ挿入関数が非constのメソッドであるか
////コンパイルエラーが出れば成功
////TEST(List, ID_15)
////{
////	const DoubleLinkedList testList;
////	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
////	ScoreData testScore; 
////
//// testList.Push_Back(*testIterator, testScore);
////}
//
////以下、データ削除関数についてのテスト
//リストが空である場合に削除を行った際の挙動(先頭イテレータ検証)
TEST(List, ID_16_1)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//先頭要素を削除
	(*testIterator) = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID_0_16_1失敗";
}


//リストが空である場合に削除を行った際の挙動(末尾イテレータ検証)
TEST(List, ID_16_2)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//末尾要素を削除
	(*testIterator) = testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID_0_16_2失敗";
}

//リストに複数の要素がある場合に、先頭イテレータを渡して、削除を行った際の挙動
TEST(List, ID_17) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	testScore = Set_ScoreData(0, "test");

	//複数の要素にデータを代入
	(*testIterator) = testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
	 testList.Insert(*testIterator, testScore);
	}

	//先頭要素を削除
	(*testIterator) = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete(*testIterator);

	ASSERT_TRUE(destroyCheck) << "ID_0_17失敗";
}

//リストに複数の要素がある場合に、末尾イテレータを渡して、削除を行った際の挙動
TEST(List, ID_18) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	testScore = Set_ScoreData(0, "test");
	bool destroyCheck = false;

	//複数の要素にデータを代入
	(*testIterator) = testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
	 testList.Insert(*testIterator, testScore);
	}

	//末尾要素を削除
	(*testIterator) = testList.Get_TailIterator();
	destroyCheck = testList.Delete(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID_0_18失敗";
}

//リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して、削除を行った際の挙動
TEST(List, ID_19) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 

	//複数の要素にデータを代入
	(*testIterator) = testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
	 testScore = Set_ScoreData(i, "test");
	 testList.Insert(*testIterator, testScore);
	}

	//指定の要素を削除
	for (int i = 0; i < 5; i++)
	{
		--(*testIterator);
	}

	//削除関数を実行し、成功したか確認する
	bool destroyCheck = false;
	destroyCheck = testList.Delete(*testIterator);

	ASSERT_TRUE(destroyCheck) << "ID_0_19失敗";
}

//ConstIteratorを指定して削除を行った際の挙動
TEST(List, ID_20) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	testScore = Set_ScoreData(0, "test");

	//複数の要素にデータを代入
	(*testConstIterator) = testList.Get_HeadConstIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Insert(*testConstIterator, testScore);
	}

	//指定の要素を削除
	for (int i = 0; i < 5; i++)
	{
		--(*testConstIterator);
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete(*testConstIterator);

	delete testConstIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_20失敗";
}

//不正なイテレータを渡して、削除した場合の挙動
TEST(List, ID_21) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//未参照のイテレータのデータを削除
	bool destroyCheck = false;
	destroyCheck = testList.Delete(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID0_21失敗";
}

//非constのメソッドであるか
////コンパイルエラーが出れば成功
//TEST(List, ID_22)
//{
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testList.Delete(*testIterator);
//
//}

//////以下、先頭イテレータ取得関数についてのテスト
////リストが空である場合に、呼び出した際の挙動
TEST(List, ID_23) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator1 = new DoubleLinkedList::Iterator;
	DoubleLinkedList::Iterator* testIterator2= new DoubleLinkedList::Iterator;

	(*testIterator1) = testList.Get_HeadIterator();
	(*testIterator2) = testList.Get_TailIterator();

	ASSERT_NE(testIterator1, testIterator2) << "ID_0_23失敗.データがダミーでない";
}

//リストに要素が一つ以上ある場合に、呼び出した際の挙動
TEST(List, ID_24) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;

	//データの挿入
	testScore = Set_ScoreData(1, "succes");
	(*testIterator) = testList.Get_HeadIterator();
    testList.Insert(*testIterator, testScore);

	//先頭イテレータを取得し、検証
	(*testIterator) = testList.Get_HeadIterator();

	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck)<<"ID_0_24失敗";
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(List, ID_25) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	
	(*testIterator) = testList.Get_HeadIterator();

	//複数のデータを挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
    	testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_25失敗";
}

//データの挿入を行った際に、呼び出した際の挙動
TEST(List,ID0_26_1){//先頭要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 

	//先頭にデータ挿入
	(*testIterator) = testList.Get_HeadIterator();
	testScore = Set_ScoreData(1, "success");
    testList.Insert(*testIterator, testScore);

	//先頭イテレータ取得
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_26_1失敗";
}

//データの挿入を行った際に、呼び出した際の挙動
TEST(List,ID0_26_2){//中央要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	
	(*testIterator) = testList.Get_HeadIterator();

	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//中央要素にデータを挿入する
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(10000, "center");
    testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_26_2失敗";
}

//データの挿入を行った際に、呼び出した際の挙動
TEST(List,ID0_26_3){//末尾要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;

	(*testIterator) = testList.Get_HeadIterator();

	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_TailIterator();
	//末尾要素にデータを挿入する
	testScore = Set_ScoreData(10000, "tail");
    testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_26_3失敗";
}

//データの削除を行った際に、呼び出した際の挙動
TEST(List,ID0_27_1){//先頭要素のデータを削除した場合
    ////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;

	(*testIterator) = testList.Get_HeadIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	 testList.Insert(*testIterator, testScore);
		
	}

	//先頭要素のデータを削除する
	(*testIterator) = testList.Get_HeadIterator();
	testList.Delete(*testIterator);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_27_1失敗";
}

//データの削除を行った際に、呼び出した際の挙動
TEST(List,ID0_27_2){//中央要素のデータを削除した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;

	(*testIterator) = testList.Get_HeadIterator();

	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_HeadIterator();
	//中央要素のデータを削除する
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testList.Delete(*testIterator);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_27_2失敗";
}

//データの削除を行った際に、呼び出した際の挙動
TEST(List,ID0_27_3){//末尾要素のデータを削除した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	
	(*testIterator) = testList.Get_HeadIterator();

	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//末尾要素のデータを削除する
	(*testIterator)=testList.Get_TailIterator();
	testList.Delete(*testIterator);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_27_3失敗";
}

//constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
//コンパイルエラーが出れば成功
//TEST(List, ID_28) {
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	(*testIterator) = testList.Get_HeadIterator();
//
//}

////以下、先頭コンストイテレータについてのテスト
//リストが空である場合に、呼び出した際の挙動
TEST(List, ID_29) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;

	//呼び出し
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_29失敗";
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(List, ID_30) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	//データの挿入
	testScore = Set_ScoreData(1, "succes");
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testList.Insert(*testConstIterator, testScore);

	//呼び出し
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_30失敗";
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(List, ID_31) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();

	//複数のデータを挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_31失敗";
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(List, ID0_32_1) {//先頭要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(1, "success");
	testList.Insert(*testConstIterator, testScore);

	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_32_1失敗";
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(List, ID0_32_2) {//中央要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();

	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//中央要素にデータを挿入する
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	testScore = Set_ScoreData(10000, "center");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_32_2失敗";
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(List, ID0_32_3) {//末尾要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();

	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_TailConstIterator();
	//末尾要素にデータを挿入する
	testScore = Set_ScoreData(10000, "tail");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_32_3失敗";
}

//データの削除を行った後に、呼び出した際の挙動
TEST(List, ID0_33_1) {//先頭要素のデータを削除した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//先頭要素のデータを削除する
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testList.Delete(*testConstIterator);

	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_33_1失敗";
}

//データの削除を行った後に、呼び出した際の挙動
TEST(List, ID0_33_2) {//中央要素のデータを削除した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//中央要素のデータを削除する
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	testList.Delete(*testConstIterator);
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_33_2失敗";
}

//データの削除を行った後に、呼び出した際の挙動
TEST(List, ID0_33_3) {//末尾要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_TailConstIterator();
	//末尾要素にデータを挿入する
	testScore = Set_ScoreData(10000, "tail");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_33_3失敗";
}

//constのメソッドであるか
//コンパイルエラーとならなければ成功
//TEST(List, ID_34) {
//	const DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	(*testConstIterator) = testList.Get_HeadConstIterator();
//}

////以下、末尾イテレータ取得関数についてのテスト
//リストが空である場合に、呼び出した際の挙動
TEST(List, ID_35) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData checkScore;

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_35失敗";
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(List, ID_36) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	//データの挿入
	testScore = Set_ScoreData(1, "success");
	(*testIterator) = testList.Get_HeadIterator();
    testList.Insert(*testIterator, testScore);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_36失敗";
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(List, ID_37) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();

	//複数のデータを挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_37失敗";
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(List, ID0_38_1) {//先頭要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	//先頭にデータ挿入
	(*testIterator) = testList.Get_HeadIterator();
	testScore = Set_ScoreData(1, "success");
    testList.Insert(*testIterator, testScore);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_38_1失敗";
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(List, ID0_38_2) {//中央要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();

	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_HeadIterator();
	//中央要素にデータを挿入する
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(10000, "center");
    testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_38_2失敗";
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(List, ID0_38_3) {//末尾要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_TailIterator();
	//末尾要素にデータを挿入する
	testScore = Set_ScoreData(10000, "tail");
    testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_38_3失敗";
}

//データの削除を行った後に、呼び出した際の挙動
TEST(List, ID0_39_1) {//先頭要素のデータを削除した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
     	testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//先頭要素のデータを削除する
	(*testIterator) = testList.Get_HeadIterator();
	testList.Delete(*testIterator);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_39_1失敗";
}

//データの削除を行った後に、呼び出した際の挙動
TEST(List, ID0_39_2) {//中央要素のデータを削除した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
 	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_HeadIterator();
	//中央要素のデータを削除する
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testList.Delete(*testIterator);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_39_2失敗";
}

//データの削除を行った後に、呼び出した際の挙動
TEST(List, ID0_39_3) {//末尾要素のデータを削除した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//末尾要素のデータを削除する
	(*testIterator) = testList.Get_TailIterator();
	testList.Delete(*testIterator);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_39_3失敗";
}

//constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
//コンパイルエラーが出れば成功
//TEST(List, ID_40) {
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	(*testIterator) = testList.Get_TailIterator();
//
//}

////以下、末尾コンストイテレータ取得関数についてのテスト
//リストが空である場合に、呼び出した際の挙動
TEST(List, ID_41) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_41失敗";
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(List, ID_42) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	//データの挿入
	testScore = Set_ScoreData(1, "succes");
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testList.Insert(*testConstIterator, testScore);

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_42失敗";
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(List, ID_43) {
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore;
	

	(*testConstIterator) = testList.Get_HeadConstIterator();

	//複数のデータを挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}
	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_43失敗";
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(List, ID0_44_1) {//先頭要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(1, "success");
	testList.Insert(*testConstIterator, testScore);

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_44_1失敗";
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(List, ID0_44_2) {//中央要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//中央要素にデータを挿入する
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	testScore = Set_ScoreData(10000, "center");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_44_2失敗";
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(List, ID0_44_3) {//末尾要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_TailConstIterator();
	//末尾要素にデータを挿入する
	testScore = Set_ScoreData(10000, "tail");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_44_3失敗";
}

//データの削除を行った後に、呼び出した際の挙動
TEST(List, ID0_45_1) {//先頭要素のデータを削除した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//先頭要素のデータを削除する
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testList.Delete(*testConstIterator);

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_45_1失敗";
}

//データの削除を行った後に、呼び出した際の挙動
TEST(List, ID0_45_2) {//中央要素のデータを削除した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//中央要素のデータを削除する
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	testList.Delete(*testConstIterator);

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_45_2失敗";
}

//データの削除を行った後に、呼び出した際の挙動
TEST(List, ID0_45_3) {//末尾要素にデータを挿入した場合
	////テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//一旦データを挿入する
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_TailConstIterator();
	//末尾要素にデータを挿入する
	testScore = Set_ScoreData(10000, "tail");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_45_3失敗";
}

//constのメソッドであるか
//コンパイルエラーとならなければ成功
//TEST(List, ID_46) {
//	const DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	(*testConstIterator) = testList.Get_TailConstIterator();
//}

////以下、イテレータに関するテスト
////基本的にはIDの2番目の値が1の場合はイテレータ、2の場合はコンストイテレータに対してテストを行う

////イテレータの指す要素を取得する(operator*)についてのテスト
//リストの参照がない状態で呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_0_1) {
//	////テスト用データの宣言
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//イテレータの指す要素を取得(失敗する)
//	ScoreData testScore = *(*testIterator);
//}

//リストの参照がない状態で呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_0_2) {
//	//テスト用データの宣言
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	//イテレータの指す要素を取得(失敗する)
//	ScoreData testScore = *(*testIterator);
//}

//Iteratorから取得した要素に対して、値の代入が行えるかをチェック
TEST(Iterator, ID_1) {
	//テスト用データの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	testScore.Score = 100;
	testScore.UserName = "test";

	//テストデータを挿入
	(*testIterator) = testList.Get_HeadIterator();
	testList.Insert(*testIterator, testScore);
	--(*testIterator);

	testScore = *(*testIterator);

	testScore.Score = 1;
	testScore.UserName = "success";

	ASSERT_EQ(testScore.Score, 1);
	ASSERT_EQ(testScore.UserName, "success");
}

////コンパイルエラーになれば成功
////ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック
////TEST(Iterator, ID_2) {
//	////テスト用データの宣言
//	//DoubleLinkedList testList;
//	//DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	//const ScoreData testScore = *(*testConstIterator);
//	//
//	//testScore.Score = 1;
//	//testScore.UserName = "success";
////}
//
//リストが空の際の、先頭イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_3_1) {
//
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData testScore;
//	ScoreData checkScore;//ダミーデータ
//	
//	//先頭要素を取得
//	(*testIterator) = testList.Get_HeadIterator();
//	testScore = *(*testIterator);
//
//	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_3_1失敗";
//	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_3_1失敗";
//}

////リストが空の際の、先頭イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_3_2) {
//
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData checkScore;//ダミーデータ
//
//	//先頭要素を取得
//	(*testConstIterator) = testList.Get_HeadConstIterator();
//	const ScoreData testScore = *(*testConstIterator);
//}

////末尾イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_4_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData testScore;
//	ScoreData checkScore;//ダミーデータ
//
//	//末尾要素を取得
//	(*testIterator) = testList.Get_TailIterator();
//	testScore = *(*testIterator);
//}

//末尾イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_4_2) {
//
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData checkScore;//ダミーデータ
//
//	//先頭要素を取得
//	(*testConstIterator) = testList.Get_TailConstIterator();
//	const ScoreData testScore = *(*testConstIterator);
//}

////イテレータをリストの末尾に向かって一つ進める(operator++)についてのテスト
////リストの参照がない状態で呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_5_1) {
//	//テスト用データの宣言
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//末尾側に進める
//	++(*testIterator);
//}

//リストの参照がない状態で呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_5_2) {
//	//テスト用データの宣言
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//	//末尾側に進める
//	++(*testConstIterator);
//}

////リストが空の際の、先頭イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_6_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData checkScore;
//
//	(*testIterator) = testList.Get_HeadIterator();
//	checkScore = *(*testIterator);
//	//末尾側に進める
//	++(*testIterator);
//}

////リストが空の際の、先頭イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_6_2) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//
//	(*testConstIterator) = testList.Get_HeadConstIterator();
//	const ScoreData checkScore=*(*testConstIterator);
//	//末尾側に進める
//	++(*testConstIterator);
//}

//末尾イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_7_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData checkScore;
//
//	(*testIterator) = testList.Get_TailIterator();
//	checkScore = *(*testIterator);
//	//末尾側に進める
//	++(*testIterator);
//}

//末尾イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_7_2) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//
//	(*testConstIterator) = testList.Get_TailConstIterator();
//	const ScoreData checkScore=*(*testConstIterator);
//	//末尾側に進める
//	++(*testConstIterator);
//}

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(Iterator, ID_8_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore; 
	ScoreData checkScore;

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//先頭から順に検証していく
	(*testIterator) = testList.Get_HeadIterator();
	int i = 4;
	while (testIterator&&i>0)
	{
		testScore = Set_ScoreData(i, "success");
		checkScore = *(*testIterator);
		++(*testIterator);
		i--;
		ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_8_1失敗";
		ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_8_1失敗";
	}
	//末尾の検証
	(*testIterator) = testList.Get_TailIterator();
	checkScore = *(*testIterator);
	testScore = Set_ScoreData(0, "dummy");

	ASSERT_EQ(testScore.Score,checkScore.Score)<<"ID_1_8_1失敗、末尾に異常";
	ASSERT_EQ(testScore.UserName,checkScore.UserName)<<"ID_1_8_1失敗、末尾に異常";
}

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(Iterator, ID_8_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore; 
	

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//先頭から順に検証していく
	(*testConstIterator) = testList.Get_HeadConstIterator();
	int i = 4;
	while (testConstIterator&&i>0)
	{
		testScore = Set_ScoreData(i, "success");
		const ScoreData checkScore=*(*testConstIterator);
		++(*testConstIterator);
		i--;
		ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_8_2失敗";
		ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_8_2失敗";
	}
	//末尾の検証
	(*testConstIterator) = testList.Get_TailConstIterator();
	const ScoreData checkScore=*(*testConstIterator);
	testScore = Set_ScoreData(0, "dummy");

	ASSERT_EQ(testScore.Score,checkScore.Score)<<"ID_1_8_2失敗、末尾に異常";
	ASSERT_EQ(testScore.UserName,checkScore.UserName)<<"ID_1_8_2失敗、末尾に異常";
}

//前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(Iterator, ID_9_1){
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore; 
	

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//移動前の検証
	(*testIterator) = testList.Get_HeadIterator();
	testScore = Set_ScoreData(4, "success");
	ScoreData checkScore=*(*testIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_9_1失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_9_1失敗";

	//一つ進めた後の検証
	DoubleLinkedList::ConstIterator* tempIterator = new DoubleLinkedList::ConstIterator;
	*tempIterator = ++(*testIterator);
	testScore = Set_ScoreData(3, "success");
	checkScore = *(*tempIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_9_1失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_9_1失敗";

}

//前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(Iterator, ID_9_2){
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore; 
	

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//移動前の検証
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(4, "success");
	ScoreData checkScore=*(*testConstIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_9_2失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_9_2失敗";

	//一つ進めた後の検証
	DoubleLinkedList::ConstIterator* tempIterator = new DoubleLinkedList::ConstIterator;
	*tempIterator = ++(*testConstIterator);
	testScore = Set_ScoreData(3, "success");
	checkScore = *(*tempIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_9_2失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_9_2失敗";

}

//後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(Iterator, ID_10_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore; 
	

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//移動前の検証
	(*testIterator) = testList.Get_HeadIterator();
	//移動前の値を保存
	DoubleLinkedList::ConstIterator* tempIterator=new DoubleLinkedList::ConstIterator;
	*tempIterator = (*testIterator)++;
	testScore = Set_ScoreData(4, "success");
	ScoreData checkScore = *(*tempIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_10_1失敗,1";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_10_1失敗,2";

	//一つ進めた後の検証
	testScore = Set_ScoreData(3, "success");
	checkScore = *(*testIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_10_1失敗,3";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_10_1失敗,4";
}

//後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(Iterator, ID_10_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore; 
    

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//移動前の検証
	(*testConstIterator) = testList.Get_HeadConstIterator();
	//移動前を保存
	DoubleLinkedList::ConstIterator* tempConstIterator = new DoubleLinkedList::ConstIterator;
	*tempConstIterator = (*testConstIterator)++;

	testScore = Set_ScoreData(4, "success");
	ScoreData checkScore = *(*tempConstIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_10_2失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_10_2失敗";

	//一つ進めた後の検証
	testScore = Set_ScoreData(3, "success");
	checkScore = *(*testConstIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_10_2失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_10_2失敗";

}

////イテレータをリストの先頭に向かって一つ進める(operator--)についてのテスト
////リストの参照がない状態で呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_11_1) {
//	//テスト用データの宣言
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//先頭側に進める
//	--(*testIterator);
//}

////リストの参照がない状態で呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_11_2) {
//	//テスト用データの宣言
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	//先頭側に進める
//	--(*testConstIterator);
//}

////リストが空の際の、末尾イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_12_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	
//	ScoreData testScore;
//	ScoreData checkScore;
//
//	(*testIterator) = testList.Get_TailIterator();
//	//先頭側に進める
//	--(*testIterator);
//}

////リストが空の際の、末尾イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_12_2) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//	ScoreData checkScore;
//
//	(*testConstIterator) = testList.Get_TailConstIterator();
//	//末尾側に進める
//	--(*testConstIterator);
//}

////先頭イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_13_1) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	
//	ScoreData testScore;
//	ScoreData checkScore;
//
//
//	(*testIterator) = testList.Get_HeadIterator();
//	//末尾側に進める
//	--(*testIterator);
//}

////先頭イテレータに対して呼び出した際の挙動(Assert発生すると中断されるのでコメント化)
//TEST(Iterator, ID_13_2) {
//	//テスト用データの宣言
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//	ScoreData checkScore;
//
//	(*testConstIterator) = testList.Get_HeadConstIterator();
//	//末尾側に進める
//	--(*testConstIterator);
//}

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(Iterator, ID_14_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore;
	ScoreData checkScore;

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//末尾から順に検証していく
	(*testIterator) = testList.Get_TailIterator();
	testScore = Set_ScoreData(0, "dummy");
	checkScore = *(*testIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_14_1失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_14_1失敗";

	for (int i = 0; i < testList.Count(); i++)
	{
		--(*testIterator);
		testScore = Set_ScoreData(i, "success");
		const ScoreData checkScore=*(*testIterator);
		
		ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_14_1失敗";
		ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_14_1失敗";
	}
}

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(Iterator, ID_14_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore;
	

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//末尾から順に検証していく
	(*testConstIterator) = testList.Get_TailConstIterator();
	testScore = Set_ScoreData(0, "dummy");
	const ScoreData checkScore=*(*testConstIterator);
	
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_14_2失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_14_2失敗";
    for(int i=0;i<testList.Count();i++)
	{
		--(*testConstIterator);
		testScore = Set_ScoreData(i, "success");
		const ScoreData checkScore=*(*testConstIterator);
		
		ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_14_2失敗";
		ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_14_2失敗";
	}
}

//前置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
TEST(Iterator, ID_15_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore;
	

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//移動前の検証
	(*testIterator) = testList.Get_TailIterator();
	testScore = Set_ScoreData(0, "dummy");
	ScoreData checkScore=*(*testIterator);
	
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_15_1失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_15_1失敗";

	//一つ進めた後の検証
	DoubleLinkedList::ConstIterator tempIterator = --(*testIterator);
	testScore = Set_ScoreData(0, "success");
	checkScore = *tempIterator;
	
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_15_1失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_15_1失敗";

}

//前置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
TEST(Iterator, ID_15_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore;
	

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//移動前の検証
	(*testConstIterator) = testList.Get_TailConstIterator();
	testScore = Set_ScoreData(0, "dummy");
	ScoreData checkScore=*(*testConstIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_15_2失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_15_2失敗";

	//一つ進めた後の検証
	DoubleLinkedList::ConstIterator tempIterator = --(*testConstIterator);
	testScore = Set_ScoreData(0, "success");
	checkScore = *tempIterator;

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_15_2失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_15_2失敗";

}

//後置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
TEST(Iterator, ID_16_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore;
	

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//移動前の検証
	(*testIterator) = testList.Get_TailIterator();
	//移動前の値を保存
	DoubleLinkedList::ConstIterator tempConstIterator = (*testIterator)--;

	testScore = Set_ScoreData(0, "dummy");
	ScoreData checkScore = *tempConstIterator;
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_16_1失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_16_1失敗";

	//一つ進めた後の検証
	testScore = Set_ScoreData(0, "success");
    checkScore=*(*testIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_16_1失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_16_1失敗";

}

//後置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
TEST(Iterator, ID_16_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore;
	

	//とりあえずデータの挿入
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//移動前の検証
	(*testConstIterator) = testList.Get_TailConstIterator();
	//移動前を保存
	DoubleLinkedList::ConstIterator tempConstIterator = (*testConstIterator)--;

	testScore = Set_ScoreData(0, "dummy");
	ScoreData checkScore = *tempConstIterator;
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_16_2失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_16_2失敗";

	//一つ進めた後の検証
	testScore = Set_ScoreData(0, "success");
	checkScore=*(*testConstIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_16_2失敗";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_16_2失敗";

}

////以下、イテレータのコピーを行う(コピーコンストラクタ)についてのテスト

//ConstIteratorから、Iteratorのコピーが作成されないかをチェック
//コンパイルエラーとなれば成功
//TEST(Iterator, ID_17) {
//	DoubleLinkedList::ConstIterator* testConstIterator=new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Iterator* testIterator = testConstIterator;
//}

//コピーコンストラクト後の値がコピー元と等しいことをチェック
TEST(Iterator, ID_18_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0=testList.Get_HeadIterator();
	ScoreData testScore;
	testScore.Score = 1;
	testScore.UserName = "success";
	testList.Insert(testIterator_0, testScore);
	--testIterator_0;
	//データ挿入

	//コピーコンストラクタ
	DoubleLinkedList::Iterator testIterator_1 = testIterator_0;

	ScoreData checkScore0 = *testIterator_0;
	ScoreData checkScore1 = *testIterator_1;
	
	ASSERT_EQ(checkScore0.Score, checkScore1.Score) << "ID_1_18_1失敗";
	ASSERT_EQ(checkScore0.UserName, checkScore1.UserName) << "ID_1_18_1失敗";
}

//コピーコンストラクト後の値がコピー元と等しいことをチェック
TEST(Iterator, ID_18_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0=testList.Get_HeadConstIterator();
	ScoreData testScore;
	testScore.Score = 1;
	testScore.UserName = "success";
	testList.Insert(testConstIterator_0, testScore);
	--testConstIterator_0;
	//コピーコンストラクタ
	DoubleLinkedList::ConstIterator testConstIterator_1 = testConstIterator_0;

	ScoreData checkScore0 = *testConstIterator_0;
	ScoreData checkScore1 = *testConstIterator_1;

	ASSERT_EQ(checkScore0.Score, checkScore1.Score) << "ID_1_18_2失敗";
	ASSERT_EQ(checkScore0.UserName, checkScore1.UserName) << "ID_1_18_2失敗";
}

////以下、イテレータの代入を行う(operator=)についてのテスト
//IteratorにConstIteratorを代入できない事をチェック
//コンパイルエラーとなれば成功
//TEST(Iterator, ID_19) {
//	DoubleLinkedList::ConstIterator* testConstIterator=new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	(*testIterator)=*testConstIterator;
//}

//代入後の値がコピー元と等しいことをチェック
TEST(Iterator, ID_20_1) {
	//テストデータの宣言
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;

	//イテレータのコピー

	testIterator_0 = testIterator_1;

	bool dataCheck = false;
	dataCheck = testIterator_0 == testIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_20_1失敗";
}


//代入後の値がコピー元と等しいことをチェック
TEST(Iterator, ID_20_2) {
	//テストデータの宣言
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;

	//コンストイテレータのコピー
	testConstIterator_0 = testConstIterator_1;

	bool dataCheck = false;
	dataCheck = testConstIterator_0 == testConstIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_20_2失敗";
}

////以下、二つのイテレータが同じか比較する(operator==)についてのテスト
//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(Iterator, ID_21_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0;
	testIterator_0 = testList.Get_HeadIterator();
	DoubleLinkedList::Iterator testIterator_1;
	testIterator_1 = testList.Get_TailIterator();
	bool dataCheck = false;

	//データの比較
	dataCheck = testIterator_0 == testIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_21_1失敗";
}

//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(Iterator, ID_21_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	testConstIterator_0 = testList.Get_HeadConstIterator();
	DoubleLinkedList::ConstIterator testConstIterator_1;
	testConstIterator_1 = testList.Get_TailConstIterator();
	bool dataCheck = false;

	//データの比較
	dataCheck = testConstIterator_0 == testConstIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_21_2失敗";
}

//同一のイテレータを比較した際の挙動
TEST(Iterator, ID_22_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;
	bool dataCheck = false;

	testIterator_0 = testList.Get_HeadIterator();
	testIterator_1 = testList.Get_HeadIterator();
	//データの比較
	testIterator_1 = testIterator_0;
	dataCheck = testIterator_0 == testIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_22_1失敗";
}

//同一のイテレータを比較した際の挙動
TEST(Iterator, ID_22_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	bool dataCheck = false;

	//データの比較
	testConstIterator_0 = testList.Get_HeadConstIterator();
	testConstIterator_1 = testConstIterator_0;
	dataCheck = testConstIterator_0 == testConstIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_22_2失敗";
}

//異なるイテレータを比較した際の挙動
TEST(Iterator, ID_23_1) {
	//テストデータの宣言
	DoubleLinkedList testList_0;
	DoubleLinkedList testList_1;
	DoubleLinkedList::Iterator testIterator_0;;
	DoubleLinkedList::Iterator testIterator_1;;
	bool dataCheck = true;

	//データの比較
    testIterator_0 = testList_0.Get_HeadIterator();
	testIterator_1 = testList_1.Get_HeadIterator();
	dataCheck = testIterator_0 == testIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_23_1失敗";
}

//異なるイテレータを比較した際の挙動
TEST(Iterator, ID_23_2) {
	//テストデータの宣言
	DoubleLinkedList testList_0;
	DoubleLinkedList testList_1;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	bool dataCheck = true;

	//データの比較
	testConstIterator_0 = testList_0.Get_HeadConstIterator();
	testConstIterator_1 = testList_1.Get_HeadConstIterator();
	dataCheck = testConstIterator_0 == testConstIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_23_2失敗";
}

////以下、二つのイテレータが異なるか比較する(operator!=)についてのテスト
//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(Iterator, ID_24_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;
	testIterator_0 = testList.Get_HeadIterator();
	testIterator_1 = testList.Get_TailIterator();
	bool dataCheck = true;

	//データの比較
	dataCheck = testIterator_0 != testIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_24_1失敗";
}

//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(Iterator, ID_24_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	testConstIterator_0 = testList.Get_HeadConstIterator();
	testConstIterator_1 = testList.Get_TailConstIterator();

	bool dataCheck = true;

	//データの比較
	dataCheck = testConstIterator_0 != testConstIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_24_2失敗";
}

//同一のイテレータを比較した際の挙動
TEST(Iterator, ID_25_1) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;
	bool dataCheck = true;

	testIterator_0 = testList.Get_HeadIterator();

	//データの比較
	testIterator_0 = testIterator_1;
	dataCheck = testIterator_0 != testIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_25_1失敗";
}

//同一のイテレータを比較した際の挙動
TEST(Iterator, ID_25_2) {
	//テストデータの宣言
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	bool dataCheck = true;

	//データの比較
	testConstIterator_0 = testList.Get_HeadConstIterator();
	testConstIterator_0 = testConstIterator_1;
	dataCheck = testConstIterator_0 != testConstIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_25_2失敗";
}

//異なるイテレータを比較した際の挙動
TEST(Iterator, ID_26_1) {
	//テストデータの宣言
	DoubleLinkedList testList_0;
	DoubleLinkedList testList_1;
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;
	bool dataCheck =false;

	//データの比較
	testIterator_0 = testList_0.Get_HeadIterator();
	testIterator_1 = testList_1.Get_HeadIterator();
	dataCheck = testIterator_0 != testIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_26_1失敗";
}

//異なるイテレータを比較した際の挙動
TEST(Iterator, ID_26_2) {
	//テストデータの宣言
	DoubleLinkedList testList_0;
	DoubleLinkedList testList_1;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	bool dataCheck = false;

	//データの比較
	testConstIterator_0 = testList_0.Get_HeadConstIterator();
	testConstIterator_1 = testList_1.Get_HeadConstIterator();
	dataCheck = testConstIterator_0 != testConstIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_26_2失敗";
}

////TEST(TestCaseName, TestName) {
////  ASSERT_EQ(1, 1);
////  EXPECT_EQ(1, 1);
////  EXPECT_TRUE(true);
////}