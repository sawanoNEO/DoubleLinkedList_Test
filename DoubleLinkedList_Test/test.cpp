#include "pch.h"
#include"DoubleLinkedList.h"

TEST(List, ID_00) {
	DoubleLinkedList testList;
	ASSERT_EQ(testList.Count_Data(), 0)<<"ID:0-00���s";
}

TEST(List, ID_01) {
	DoubleLinkedList testList;         //�e�X�g�f�[�^�̍\�z
	/*DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();*/
	testList.Get_TailIterator();        //�����C�e���[�^�̎擾
	ScoreData testScore;

	//������testScore�̏�����

	testList.Push_Back(testList.Get_TailIterator(),testScore);   //�f�[�^��}��

	/*Node* testnode = new Node;
	testnode = testIterator->operator*;
	*testnode*/

	ASSERT_EQ(testList.Count_Data(), 1)<<"ID:0-01���s";    //�f�[�^����1�ł���ΐ���
}
//
//TEST(List, ID_02) {    �������A���P�[�V�����G���[���̋����ł���Ɣ��f�������߃e�X�g���X�L�b�v
//	DoubleLinkedList testList;          //�e�X�g�f�[�^�̍\�z
//	/*DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();*/
//	testList.Get_TailIterator();         //�����C�e���[�^�̎擾
//	testList.Push_Data(testList.Get_TailIterator());   //�f�[�^��}��
//
//	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-02���s";   //�f�[�^����0�ł���ΐ���
//
//}

TEST(List, ID_03) {
	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	testIterator = testList.Get_Iterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^

	//������testScore�̏�����

	testList.Push_Back(testIterator,testScore);         //�f�[�^�̑}��

	delete testIterator;
	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-03���s";   //�f�[�^����0�ł���ΐ���
}
//
//TEST(List, ID_04) {   �������A���P�[�V�����G���[���̋����ł���Ɣ��f�������߃e�X�g���X�L�b�v
//	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	testIterator = testList.Get_Iterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
//	testList.Push_Data(testIterator);         //�f�[�^�̑}��
//
//	delete testIterator;
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-04���s";   //�f�[�^����1�ł���ΐ���
//
//}

TEST(List, ID_05) {
	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	testIterator = testList.Get_Iterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	testList.Delete_Data(testIterator);      //�f�[�^���폜

	delete testIterator;
	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-05���s";   //�f�[�^����0�ł���ΐ���

}

//TEST(List, ID_06) {  �������A���P�[�V�����G���[���̋����ł���Ɣ��f�������߃e�X�g���X�L�b�v
//	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	testIterator = testList.Get_Iterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
//	testList.Push_Data(testIterator);        //�f�[�^�̑}��
//	testList.Delete_Data(testIterator);      //�f�[�^���폜
//
//	delete testIterator;
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-06���s";   //�f�[�^����1�ł���ΐ���
//
//}

TEST(List, ID_07) {
	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	testIterator = testList.Get_Iterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	testList.Delete_Data(testIterator);      //�f�[�^���폜

	delete testIterator;
	ASSERT_NE(testList.Count_Data(), -1) << "ID:0-07���s�B�f�[�^����-1�ɂȂ��Ă��܂�";  //�f�[�^����-1�łȂ���ΐ���
	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-07���s";   //�f�[�^����0�ł���ΐ���

}

TEST(List, ID_08) {
	DoubleLinkedList const testList; //const�Ő錾
	testList.Count_Data();           //�R���p�C���G���[���łȂ���ΐ���
}

TEST(List, ID_09_1) {
	DoubleLinkedList testList;            //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^

//������testScore�̏�����

	testList.Push_Back(testIterator,testScore);      //�f�[�^��}��
	bool dataCheck = false;
	Node* testNode = new Node;
	testNode = testList.Get_Node();

	dataCheck = Check_Data(testNode->scoredata, testScore);
	/*if(&testNode->prev->scoredata)
	{
		dataCheck = true;
	}*/
	
	delete testIterator;
	ASSERT_EQ(dataCheck, true ) << "ID:0-09-1���s";
}

TEST(List, ID_09_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_HeadIterator();
	ScoreData testScore;                     //����p�X�R�A�f�[�^

//������testScore�̏�����

	testList.Push_Back(testIterator,testScore);
	bool dataCheck = false;
	Node* testNode = new Node;
	testNode = testList.Get_HeadNode();

	if(&testNode->scoredata)
	{
		dataCheck = true;
	}

	delete testIterator;
	ASSERT_NE(dataCheck, true ) << "ID:0-09-2���s";
}

TEST(List, ID_09_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_TailIterator();
	ScoreData testScore;                     //����p�X�R�A�f�[�^

//������testScore�̏�����

	testList.Push_Back(testIterator,testScore);
	bool dataCheck = false;
	Node* testNode = new Node;
	testNode = testList.Get_TailNode();

	if(&testNode->scoredata)
	{
		dataCheck = true;
	}

	delete testIterator;
	ASSERT_NE(dataCheck, true ) << "ID:0-09-3���s";
}

TEST(List, ID_10) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//�擪�v�f�Ƀf�[�^�}��
	testIterator = testList.Get_HeadIterator();
	Set_ScoreData(testScore, 00003, "test3");
	testList.Push_Back(testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	bool dataCheck = false;
	dataCheck = Check_Data(testList.Get_HeadNode()->scoredata, testScore);

	delete testIterator;
	ASSERT_TRUE(dataCheck)<<"ID0_10���s";
}

TEST(List, ID_11) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^


    //�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//�����v�f�Ƀf�[�^�}��
	testIterator = testList.Get_TailIterator();
	Set_ScoreData(testScore, 00003, "test3");
	testList.Push_Back(testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	bool dataCheck = false;
	dataCheck = Check_Data(testList.Get_HeadNode()->scoredata, testScore);

	delete testIterator;
	ASSERT_TRUE(dataCheck) << "ID0_11���s";
}

TEST(List, 12_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//�����v�f�Ƀf�[�^�}��
	for (int i = 0; i < 5; i++)
	{
		testIterator--;
	}
	Set_ScoreData(testScore, 00010, "succes");
	testList.Push_Back(testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	bool dataCheck = false;
	//���b��I�ɃR�����g�A�E�g
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_TRUE(dataCheck) << "ID0_12_1���s";
}

TEST(List, ID_13_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//�����v�f�Ƀf�[�^�}��
	for (int i = 0; i < 5; i++)
	{
		testIterator--;
	}
	Set_ScoreData(testScore, 00010, "succes");
	testList.Push_Back(testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	bool dataCheck = false;
	//�b��I�ɃR�����g�A�E�g
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_TRUE(dataCheck) << "ID0_13_1���s";
}

TEST(List, ID_13_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//�擪�v�f�Ƀf�[�^�}��
	testIterator = testList.Get_HeadConstIterator();
	Set_ScoreData(testScore, 00010, "succes");
	testList.Push_Back(testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	bool dataCheck = false;
	//�b��I�ɃR�����g�A�E�g
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_TRUE(dataCheck) << "ID0_13_2���s";
}

TEST(List, ID_13_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	testIterator = testList.Get_Iterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		Set_ScoreData(testScore, (0000) + i + 1, "test0");
		testList.Push_Back(testIterator, testScore);
		testIterator++;
	}

	//�����v�f�Ƀf�[�^�}��
	testIterator = testList.Get_TailConstIterator();
	Set_ScoreData(testScore, 00010, "succes");
	testList.Push_Back(testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	bool dataCheck = false;
	//�b��I�ɃR�����g�A�E�g
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_TRUE(dataCheck) << "ID0_13_3���s";
}

TEST(List, ID_14) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 1, "failed");

	//���Q�Ƃ̃C�e���[�^�Ƀf�[�^����
	testList.Push_Back(testIterator, testScore);
	testIterator = testList.Get_Iterator();


	bool dataCheck=false;
	//�b��I�ɃR�����g�A�E�g
	//dataCheck = Check_Data(testIterator->operator*()->scoredata, testScore);
	//delete testIterator;

	ASSERT_FALSE(dataCheck)<<"ID0_14���s";
}

//�R���p�C���G���[���o��ΐ���
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
	//���݈ʒu�̗v�f���폜
	testIterator = testList.Get_Iterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_FALSE(destroyCheck) << "ID_0_16_1���s";
}

TEST(List, ID_16_2)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//�擪�v�f���폜
	testIterator = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_FALSE(destroyCheck) << "ID_0_16_2���s";
}

TEST(List, ID_16_3)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//�����v�f���폜
	testIterator = testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_FALSE(destroyCheck) << "ID_0_16_3���s";
}

TEST(List, ID_17) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 0, "test");

	//�����̗v�f�Ƀf�[�^����
	testIterator = testList.Get_Iterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(testIterator, testScore);
	}

	//�擪�v�f���폜
	testIterator = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_17���s";
}

TEST(List, ID_18) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 0, "test");

	//�����̗v�f�Ƀf�[�^����
	testIterator = testList.Get_Iterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(testIterator, testScore);
	}

	//�����v�f���폜
	testIterator = testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testIterator);

	delete testIterator;

	ASSERT_FALSE(destroyCheck) << "ID_0_18���s";
}

TEST(List, ID_19) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 0, "test");

	//�����̗v�f�Ƀf�[�^����
	testIterator = testList.Get_Iterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(testIterator, testScore);
	}

	//�w��̗v�f���폜
	testIterator = testList.Get_HeadIterator();
	for (int i = 0; i < 5; i++)
	{
		testIterator++;
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testIterator);

	testIterator = testList.Get_TailIterator();//���炭�{�Ԃł͍폜
	delete testIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_19���s";
}

TEST(List, ID_20) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 0, "test");

	//�����̗v�f�Ƀf�[�^����
	testConstIterator = testList.Get_HeadConstIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(testConstIterator, testScore);
	}

	//�w��̗v�f���폜
	testConstIterator = testList.Get_HeadConstIterator();
	for (int i = 0; i < 5; i++)
	{
		testConstIterator++;
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testConstIterator);

	testConstIterator = testList.Get_TailIterator();//���炭�{�Ԃł͍폜
	delete testConstIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_20���s";
}

TEST(List, ID_21) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	Set_ScoreData(testScore, 1, "failed");

	//���Q�Ƃ̃C�e���[�^�Ƀf�[�^����
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(testIterator);


	delete testIterator;//������͋��炭�G���[�ɂȂ�

	ASSERT_FALSE(destroyCheck) << "ID0_20���s";
}

//�R���p�C���G���[���o��ΐ���
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