#include "pch.h"
#include"DoubleLinkedList.h"

TEST(List, ID_00) {
	DoubleLinkedList testList;
	ASSERT_EQ(testList.Count_Data(), 0)<<"ID:0-00���s";
}

TEST(List, ID_01) {
	DoubleLinkedList testList;         //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	*testIterator = *testList.Get_TailIterator();        //�����C�e���[�^�̎擾
	ScoreData* testScore;

	//testScore�̏�����
	testScore=Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator,testScore);   //�f�[�^��}��


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
	*testIterator = *testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	ScoreData* testScore;                     //����p�X�R�A�f�[�^

	//testScore�̏�����
	testScore = Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator,testScore);         //�f�[�^�̑}��

	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-03���s";   //�f�[�^����1�ł���ΐ���
}
//
//TEST(List, ID_04) {   �������A���P�[�V�����G���[���̋����ł���Ɣ��f�������߃e�X�g���X�L�b�v
//	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	testIterator = testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
//	testList.Push_Data(testIterator);         //�f�[�^�̑}��
//
//	
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-04���s";   //�f�[�^����1�ł���ΐ���
//
//}

TEST(List, ID_05) {
	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	ScoreData* testScore;
	testScore = Set_ScoreData(1, "success");
	*testIterator = *testList.Get_TailIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	testList.Push_Back(*testIterator, testScore);  //�f�[�^�̑}��

	//*testIterator = *testList.Get_HeadIterator();  //�擪�C�e���[�^�擾
	testList.Delete_Data(*testIterator);      //�f�[�^���폜

	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-05���s";   //�f�[�^����0�ł���ΐ���
}

//TEST(List, ID_06) {  �������A���P�[�V�����G���[���̋����ł���Ɣ��f�������߃e�X�g���X�L�b�v
//	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	testIterator = testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
//	testList.Push_Data(testIterator);        //�f�[�^�̑}��
//	testList.Delete_Data(testIterator);      //�f�[�^���폜
//
//	
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-06���s";   //�f�[�^����1�ł���ΐ���
//
//}

TEST(List, ID_07) {
	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	testIterator = testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	testList.Delete_Data(*testIterator);      //�f�[�^���폜

	
	//ASSERT_NE(testList.Count_Data(), -1) << "ID:0-07���s�B�f�[�^����-1�ɂȂ��Ă��܂�";  //�f�[�^����-1�łȂ���ΐ���
	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-07���s";   //�f�[�^����0�ł���ΐ���
}

//�R���p�C���G���[���łȂ���ΐ���
//TEST(List, ID_08) {
//	DoubleLinkedList const testList; //const�Ő錾
//	testList.Count_Data();           //�R���p�C���G���[���łȂ���ΐ���
//}

TEST(List, ID_09_1) {
	DoubleLinkedList testList;            //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�擪�v�f�Ƀf�[�^��}��
	*testIterator = *testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	testScore = Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator,testScore);      //�f�[�^��}��

	dataCheck = Check_Data(testIterator, testScore);

	
	
	ASSERT_TRUE(dataCheck) << "ID:0-09-1���s";
}

TEST(List, ID_09_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore;                     //����p�X�R�A�f�[�^

	//�����v�f�Ƀf�[�^��}��
	*testIterator = *testList.Get_TailIterator();
	testScore = Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator,testScore);
	bool dataCheck = false;


	dataCheck = Check_Data(testIterator, testScore);

	
	ASSERT_TRUE(dataCheck) << "ID:0-09-2���s";
}

TEST(List, ID_10) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData* testScore;                     //����p�X�R�A�f�[�^

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//�擪�v�f�Ƀf�[�^�}��
	*testIterator = *testList.Get_HeadIterator();
	testScore = Set_ScoreData(10000, "success");
	testList.Push_Back(*testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	bool dataCheck = false;
	dataCheck = Check_Data(testIterator, testScore);

	
	ASSERT_TRUE(dataCheck)<<"ID0_10���s";
}

TEST(List, ID_11) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData* testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;


    //�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData((0000) + i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//�����v�f�Ƀf�[�^�}��
	*testIterator = *testList.Get_TailIterator();
	testScore = Set_ScoreData(10000, "success");
	testList.Push_Back(*testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	dataCheck = Check_Data(testIterator, testScore);

	
	ASSERT_TRUE(dataCheck) << "ID0_11���s";
}

TEST(List, 12_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData* testScore;                     //����p�X�R�A�f�[�^

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
	}

	//�����v�f�Ƀf�[�^�}��
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(10, "succes");
	testList.Push_Back(*testIterator, testScore);
    //�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	bool dataCheck = false;

	dataCheck = Check_Data(testIterator, testScore);
	

	ASSERT_TRUE(dataCheck) << "ID0_12_1���s";
}

TEST(List, ID_13_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //�擪�v�f�̃C�e���[�^���擾
	ScoreData* testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//�����v�f�Ƀf�[�^�}��
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(100, "succes");
	testList.Push_Back(*testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	dataCheck = Check_Data(testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_1���s";
}

TEST(List, ID_13_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData* testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//�擪�v�f�Ƀf�[�^�}��
	*testIterator = *testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(00010, "succes");
	testList.Push_Back(*testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	dataCheck = Check_Data(testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_2���s";
}

TEST(List, ID_13_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	*testIterator = *testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData* testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
		testList.Push_Back(*testIterator, testScore);
		
	}

	//�����v�f�Ƀf�[�^�}��
	*testIterator = *testList.Get_TailConstIterator();
	testScore = Set_ScoreData(100, "succes");
	testList.Push_Back(*testIterator, testScore);

	//�`�F�b�N�֐���p���Ēl�������������Ă邩�m�F����
	dataCheck = Check_Data(testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_3���s";
}

TEST(List, ID_14) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(1, "failed");

	//���Q�Ƃ̃C�e���[�^�Ƀf�[�^����
	testList.Push_Back(*testIterator, testScore);
	testIterator = testList.Get_HeadIterator();

	
	ASSERT_EQ(testList.Count_Data(),0)<<"ID0_14���s";
}

//�R���p�C���G���[���o��ΐ���
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
	//��̗v�f���폜
	*testIterator = *testList.Get_HeadIterator();
	++(*testIterator);
	++(*testIterator);
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(*testIterator);

	

	ASSERT_FALSE(destroyCheck) << "ID_0_16_1���s";
}

TEST(List, ID_16_2)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//�擪�v�f���폜
	*testIterator = *testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(*testIterator);

	

	ASSERT_FALSE(destroyCheck) << "ID_0_16_2���s";
}

TEST(List, ID_16_3)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//�����v�f���폜
	*testIterator = *testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete_Data(*testIterator);

	

	ASSERT_FALSE(destroyCheck) << "ID_0_16_3���s";
}

TEST(List, ID_17) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(0, "test");

	//�����̗v�f�Ƀf�[�^����
	*testIterator = *testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(*testIterator, testScore);
	}

	//�擪�v�f���폜
	testIterator = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testIterator);

	

	ASSERT_TRUE(destroyCheck) << "ID_0_17���s";
}

TEST(List, ID_18) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(0, "test");

	//�����̗v�f�Ƀf�[�^����
	*testIterator = *testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(*testIterator, testScore);
	}

	//�����v�f���폜
	*testIterator = *testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testIterator);

	

	ASSERT_FALSE(destroyCheck) << "ID_0_18���s";
}

TEST(List, ID_19) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(0, "test");

	//�����̗v�f�Ƀf�[�^����
	*testIterator = *testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(*testIterator, testScore);
	}

	//�w��̗v�f���폜
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testIterator);

	ASSERT_TRUE(destroyCheck) << "ID_0_19���s";
}

TEST(List, ID_20) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData* testScore; 
	testScore = Set_ScoreData(0, "test");

	//�����̗v�f�Ƀf�[�^����
	*testConstIterator = *testList.Get_HeadConstIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Push_Back(*testConstIterator, testScore);
	}

	//�w��̗v�f���폜
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testConstIterator);

	delete testConstIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_20���s";
}

TEST(List, ID_21) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//���Q�Ƃ̃C�e���[�^�̃f�[�^���폜
	bool destroyCheck = false;
	destroyCheck = testList.Delete_Data(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID0_21���s";
}

////�R���p�C���G���[���o��ΐ���
//TEST(List, ID_22)
//{
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testList.Delete_Data(testIterator);
//
//}

TEST(List, ID_23) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore = new ScoreData;

	//�_�~�[�f�[�^�ŏ�����
	ScoreData_Init(testScore);

	testIterator = testList.Get_HeadIterator();
	

	ASSERT_EQ(testList.Get_HeadIterator(),testIterator) << "ID_0_23���s.�f�[�^����v���Ȃ�";
	ASSERT_TRUE(Check_Data(testIterator, testScore)) << "ID_0_23���s.�f�[�^���_�~�[�łȂ�";
}

TEST(List, ID_24) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 

	//�f�[�^�̑}��
	testScore = Set_ScoreData(1, "succes");
	*testIterator = *testList.Get_HeadIterator();
	testList.Push_Back(*testIterator, testScore);
	testIterator = testList.Get_HeadIterator();

	ASSERT_EQ(testList.Get_HeadIterator(), testIterator)<<"ID_0_24���s";
}

TEST(List, ID_25) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore; 
	*testIterator = *testList.Get_HeadIterator();

	//�����̃f�[�^��}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
		testList.Push_Back(*testIterator, testScore);
	}
	testIterator = testList.Get_HeadIterator();
	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_25���s";
}

TEST(List,ID0_26_1){//�擪�v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore=new ScoreData; 

	*testIterator = *testList.Get_HeadIterator();
	testScore = Set_ScoreData(1, "success");
	testList.Push_Back(*testIterator, testScore);

	testIterator = testList.Get_HeadIterator();

	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_26_1���s";
}

TEST(List,ID0_26_2){//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData* testScore=new ScoreData; 

	*testIterator = *testList.Get_HeadIterator();

	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Push_Back(*testIterator, testScore);
	}

	//�����v�f�Ƀf�[�^��}������
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(10000, "center");
	testList.Push_Back(*testIterator, testScore);
	testIterator = testList.Get_HeadIterator();


	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_26_2���s";
}

//TEST(List,ID0_26_3){//�����v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator=testList.Get_TailIterator();
//	//�����v�f�Ƀf�[�^��}������
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(*testIterator, testScore);
//	testIterator = testList.Get_HeadIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_26_3���s";
//}
//
//TEST(List,ID0_27_1){//�擪�v�f�̃f�[�^���폜�����ꍇ
//    ////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//	testIterator = testList.Get_HeadIterator();
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//		
//	}
//
//
//	//�擪�v�f�̃f�[�^���폜����
//	testIterator = testList.Get_HeadIterator();
//	testList.Delete_Data(testIterator);
//
//	testIterator = testList.Get_HeadIterator();
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_27_1���s";
//}
//
//TEST(List,ID0_27_2){//�����v�f�̃f�[�^���폜�����ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator=testList.Get_HeadIterator();
//	//�����v�f�̃f�[�^���폜����
//	for (int i = 0; i < 5; i++)
//	{
//		testIterator++;
//	}
//	testList.Delete_Data(testIterator);
//	testIterator = testList.Get_HeadIterator();
//
//	testIterator = testList.Get_HeadIterator();
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_27_2���s";
//}
//
//TEST(List,ID0_27_3){//�����v�f�̃f�[�^���폜�����ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//�����v�f�̃f�[�^���폜����
//	testIterator=testList.Get_TailIterator();
//	testList.Delete_Data(testIterator);
//	testIterator = testList.Get_HeadIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_27_3���s";
//}
//
////�R���p�C���G���[���o��ΐ���
////TEST(List, ID_28) {
////	const DoubleLinkedList testList;
////	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
////	testIterator = testList.Get_HeadIterator();
////
////}
//
//TEST(List, ID_29) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_29���s";
//}
//
//TEST(List, ID_30) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//�f�[�^�̑}��
//	testScore = Set_ScoreData(1, "succes");
//	testConstIterator = testList.Get_HeadConstIterator();
//	testList.Push_Back(testConstIterator, testScore);
//
//	testConstIterator = testList.Get_HeadConstIterator();
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_30���s";
//}
//
//TEST(List, ID_31) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//	testConstIterator = testList.Get_HeadConstIterator();
//
//	//�����̃f�[�^��}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "test");
//		testList.Push_Back(testConstIterator, testScore);
//
//	}
//	testConstIterator = testList.Get_HeadConstIterator();
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_31���s";
//}
//
//TEST(List, ID0_32_1) {//�擪�v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
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
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_32_1���s";
//}
//
//TEST(List, ID0_32_2) {//�����v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//�����v�f�Ƀf�[�^��}������
//	for (int i = 0; i < 5; i++)
//	{
//		testConstIterator++;
//	}
//	testScore = Set_ScoreData(10000, "center");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_32_2���s";
//}
//
//TEST(List, ID0_32_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//�����v�f�Ƀf�[�^��}������
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_32_3���s";
//}
//
//TEST(List, ID0_33_1) {//�擪�v�f�̃f�[�^���폜�����ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//	testConstIterator = testList.Get_HeadConstIterator();
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//
//	}
//
//
//	//�擪�v�f�̃f�[�^���폜����
//	testConstIterator = testList.Get_HeadConstIterator();
//	testList.Delete_Data(testConstIterator);
//
//	testConstIterator = testList.Get_HeadConstIterator();
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_33_1���s";
//}
//
//TEST(List, ID0_33_2) {//�����v�f�̃f�[�^���폜�����ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//�����v�f�̃f�[�^���폜����
//	for (int i = 0; i < 5; i++)
//	{
//		testConstIterator++;
//	}
//	testList.Delete_Data(testConstIterator);
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_33_2���s";
//}
//
//TEST(List, ID0_33_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//�����v�f�Ƀf�[�^��}������
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_HeadConstIterator();
//
//
//	ASSERT_EQ(testList.Get_HeadConstIterator(), testConstIterator) << "ID_0_33_3���s";
//}
//
////�R���p�C���G���[�ƂȂ�Ȃ���ΐ���
////TEST(List, ID_34) {
////	const DoubleLinkedList testList;
////	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
////	testConstIterator = testList.Get_HeadConstIterator();
////}
//
//TEST(List, ID_35) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_TailIterator();
//
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_35���s";
//}
//
//TEST(List, ID_36) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//�f�[�^�̑}��
//	testScore = Set_ScoreData(1, "success");
//	testIterator = testList.Get_HeadIterator();
//	testList.Push_Back(*testIterator, testScore);
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_36���s";
//}
//
//TEST(List, ID_37) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//	testIterator = testList.Get_HeadIterator();
//
//	//�����̃f�[�^��}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "test");
//		testList.Push_Back(*testIterator, testScore);
//
//	}
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_37���s";
//}
//
//TEST(List, ID0_38_1) {//�擪�v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
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
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_38_1���s";
//}
//
//TEST(List, ID0_38_2) {//�����v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator = testList.Get_HeadIterator();
//	//�����v�f�Ƀf�[�^��}������
//	for (int i = 0; i < 5; i++)
//	{
//		testIterator++;
//	}
//	testScore = Set_ScoreData(10000, "center");
//	testList.Push_Back(*testIterator, testScore);
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_38_2���s";
//}
//
//TEST(List, ID0_38_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator = testList.Get_TailIterator();
//	//�����v�f�Ƀf�[�^��}������
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(*testIterator, testScore);
//	testIterator = testList.Get_TailIterator();
//
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_38_3���s";
//}
//
//TEST(List, ID0_39_1) {//�擪�v�f�̃f�[�^���폜�����ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//	testIterator = testList.Get_HeadIterator();
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//
//	}
//
//
//	//�擪�v�f�̃f�[�^���폜����
//	testIterator = testList.Get_HeadIterator();
//	testList.Delete_Data(testIterator);
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_39_1���s";
//}
//
//TEST(List, ID0_39_2) {//�����v�f�̃f�[�^���폜�����ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	testIterator = testList.Get_HeadIterator();
//	//�����v�f�̃f�[�^���폜����
//	for (int i = 0; i < 5; i++)
//	{
//		testIterator++;
//	}
//	testList.Delete_Data(testIterator);
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_TailIterator(), testIterator) << "ID_0_39_2���s";
//}
//
//TEST(List, ID0_39_3) {//�����v�f�̃f�[�^���폜�����ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//�����v�f�̃f�[�^���폜����
//	testIterator = testList.Get_TailIterator();
//	testList.Delete_Data(testIterator);
//
//	testIterator = testList.Get_TailIterator();
//
//	ASSERT_EQ(testList.Get_HeadIterator(), testIterator) << "ID_0_39_3���s";
//}
//
////�R���p�C���G���[���o��ΐ���
////TEST(List, ID_40) {
////	const DoubleLinkedList testList;
////	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
////	testIterator = testList.Get_TailIterator();
////
////}
//
//TEST(List, ID_41) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_41���s";
//}
//
//TEST(List, ID_42) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//�f�[�^�̑}��
//	testScore = Set_ScoreData(1, "succes");
//	testConstIterator = testList.Get_TailConstIterator();
//	testList.Push_Back(testConstIterator, testScore);
//
//	testConstIterator = testList.Get_TailConstIterator();
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_42���s";
//}
//
//TEST(List, ID_43) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//	testConstIterator = testList.Get_HeadConstIterator();
//
//	//�����̃f�[�^��}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "test");
//		testList.Push_Back(testConstIterator, testScore);
//
//	}
//	testConstIterator = testList.Get_TailConstIterator();
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_43���s";
//}
//
//TEST(List, ID0_44_1) {//�擪�v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
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
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_44_1���s";
//}
//
//TEST(List, ID0_44_2) {//�����v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//�����v�f�Ƀf�[�^��}������
//	for (int i = 0; i < 5; i++)
//	{
//		testConstIterator++;
//	}
//	testScore = Set_ScoreData(10000, "center");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_44_2���s";
//}
//
//TEST(List, ID0_44_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//�����v�f�Ƀf�[�^��}������
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_44_3���s";
//}
//
//TEST(List, ID0_45_1) {//�擪�v�f�̃f�[�^���폜�����ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//	testConstIterator = testList.Get_HeadConstIterator();
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//
//	}
//
//
//	//�擪�v�f�̃f�[�^���폜����
//	testConstIterator = testList.Get_HeadConstIterator();
//	testList.Delete_Data(testConstIterator);
//
//	testConstIterator = testList.Get_TailConstIterator();
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_45_1���s";
//}
//
//TEST(List, ID0_45_2) {//�����v�f�̃f�[�^���폜�����ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//�����v�f�̃f�[�^���폜����
//	for (int i = 0; i < 5; i++)
//	{
//		testConstIterator++;
//	}
//	testList.Delete_Data(testConstIterator);
//
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_45_2���s";
//}
//
//TEST(List, ID0_45_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData* testScore; 
//
//	//��U�f�[�^��}������
//	for (int i = 0; i < 10; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//�����v�f�Ƀf�[�^��}������
//	testScore = Set_ScoreData(10000, "tail");
//	testList.Push_Back(testConstIterator, testScore);
//	testConstIterator = testList.Get_TailConstIterator();
//
//
//	ASSERT_EQ(testList.Get_TailConstIterator(), testConstIterator) << "ID_0_45_3���s";
//}
//
////�R���p�C���G���[�ƂȂ�Ȃ���ΐ���
////TEST(List, ID_46) {
////	const DoubleLinkedList testList;
////	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
////	testConstIterator = testList.Get_TailConstIterator();
////}
//
////�ȉ��A�C�e���[�^�Ɋւ���e�X�g
////��{�I�ɂ�ID��2�Ԗڂ̒l��1�̏ꍇ�̓C�e���[�^�A2�̏ꍇ�̓R���X�g�C�e���[�^�ɑ΂��ăe�X�g���s��
//
//TEST(Iterator, ID_0_1) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//�C�e���[�^�̎w���v�f���擾(���s����)
//	DoubleLinkedList::Node* testNode = testIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_0_1���s";
//}
//
//TEST(Iterator, ID_0_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	//�C�e���[�^�̎w���v�f���擾(���s����)
//	const DoubleLinkedList::Node* testNode = testConstIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_0_2���s";
//}
//
//TEST(Iterator, ID_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Node* testNode;
//	ScoreData* testScore; 
//	testScore = Set_ScoreData(1, "success");
//
//	//�e�X�g�f�[�^��}��
//	testIterator = testList.Get_HeadIterator();
//	testList.Push_Back(*testIterator, testScore);
//	testNode =testIterator->operator*();
//
//	bool dataCheck = false;
//	dataCheck = Check_Data(testIterator, testScore);//��������Node*�̊֐��������������������
//
//	ASSERT_NO_THROW(testNode) << "ID_1_1���s";
//	ASSERT_TRUE(dataCheck) << "ID_1_1�f�[�^�Ȃ�";
//}
//
//TEST(Iterator, ID_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Node* testNode;
//	ScoreData* testScore; 
//	testScore = Set_ScoreData(1, "success");
//
//	//�e�X�g�f�[�^��}��
//	testConstIterator = testList.Get_HeadIterator();
//	testList.Push_Back(testConstIterator, testScore);
//	testNode = testConstIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_2���s";
//}
//
//TEST(Iterator, ID_3_1) {
//
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Node* testNode;
//
//	//�擪�v�f���擾
//	testIterator = testList.Get_HeadIterator();
//	testNode = testIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_3_1���s";
//}
//
//TEST(Iterator, ID_3_2) {
//
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Node* testNode;
//
//	//�擪�v�f���擾
//	testConstIterator = testList.Get_HeadConstIterator();
//	testNode = testConstIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_3_2���s";
//}
//
//TEST(Iterator, ID_4_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Node* testNode;
//
//	//�擪�v�f���擾
//	testIterator = testList.Get_TailIterator();
//	testNode = testIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_4_1���s";
//}
//
//TEST(Iterator, ID_4_2) {
//
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Node* testNode;
//
//	//�擪�v�f���擾
//	testConstIterator = testList.Get_TailConstIterator();
//	testNode = testConstIterator->operator*();
//
//	ASSERT_ANY_THROW(testNode) << "ID_1_4_2���s";
//}
//
//TEST(Iterator, ID_5_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//�������ɐi�߂�
//	testIterator++;
//	ASSERT_ANY_THROW(testIterator)<<"ID_1_5_1���s";
//}
//
//TEST(Iterator, ID_5_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//	//�������ɐi�߂�
//	testConstIterator++;
//	ASSERT_ANY_THROW(testConstIterator)<<"ID_1_5_2���s";
//}
//
//TEST(Iterator, ID_6_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	testIterator = testList.Get_HeadIterator();
//	//�������ɐi�߂�
//	testIterator++;
//
//	ASSERT_ANY_THROW(testIterator) << "ID_1_6_1���s";
//}
//
//TEST(Iterator, ID_6_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//�������ɐi�߂�
//	testConstIterator++;
//
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_6_2���s";
//}
//
//TEST(Iterator, ID_7_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	testIterator = testList.Get_TailIterator();
//	//�������ɐi�߂�
//	testIterator++;
//
//	ASSERT_ANY_THROW(testIterator) << "ID_1_7_1���s";
//}
//
//TEST(Iterator, ID_7_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//�������ɐi�߂�
//	testConstIterator++;
//
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_7_2���s";
//}
//
//TEST(Iterator, ID_8_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//�擪���珇�Ɍ��؂��Ă���
//	testIterator = testList.Get_HeadIterator();
//	int i = 4;
//	while (testIterator||i>0)
//	{
//		testScore = Set_ScoreData(i, "success");
//		dataCheck = Check_Data(testIterator, testScore);
//		testIterator++;
//		i--;
//		ASSERT_TRUE(dataCheck) << "ID_1_8_1���s";
//	}
//}
//
//TEST(Iterator, ID_8_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//�擪���珇�Ɍ��؂��Ă���
//	testConstIterator = testList.Get_HeadConstIterator();
//	int i = 4;
//	while (testConstIterator||i>0)
//	{
//		testScore = Set_ScoreData(i, "success");
//		dataCheck = Check_Data(testConstIterator, testScore);
//		testConstIterator++;
//		i--;
//		ASSERT_TRUE(dataCheck) << "ID_1_8_2���s";
//	}
//}
//
//TEST(Iterator, ID_9_1){
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//�ړ��O�̌���
//	testIterator = testList.Get_HeadIterator();
//	testScore = Set_ScoreData(0, "dummy");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_9_1���s";
//
//	//��i�߂���̌���
//	++testIterator;
//	testScore = Set_ScoreData(4, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_9_1���s";
//
//}
//
//TEST(Iterator, ID_9_2){
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//�ړ��O�̌���
//	testConstIterator = testList.Get_HeadConstIterator();
//	testScore = Set_ScoreData(0, "dummy");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_9_2���s";
//
//	//��i�߂���̌���
//	++testConstIterator;
//	testScore = Set_ScoreData(4, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_9_2���s";
//
//}
//
//TEST(Iterator, ID_10_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//�ړ��O�̌���
//	testIterator = testList.Get_HeadIterator();
//	testScore = Set_ScoreData(0, "dummy");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_10_1���s";
//
//	//��i�߂���̌���
//	testIterator++;
//	testScore = Set_ScoreData(4, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_10_1���s";
//
//}
//
//TEST(Iterator, ID_10_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//�ړ��O�̌���
//	testConstIterator = testList.Get_HeadConstIterator();
//	testScore = Set_ScoreData(0, "dummy");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_10_2���s";
//
//	//��i�߂���̌���
//	testConstIterator++;
//	testScore = Set_ScoreData(4, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_10_2���s";
//
//}
//
//TEST(Iterator, ID_11_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//�擪���ɐi�߂�
//	testIterator--;
//	ASSERT_ANY_THROW(testIterator) << "ID_1_11_1���s";
//}
//
//TEST(Iterator, ID_11_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	//�擪���ɐi�߂�
//	testConstIterator--;
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_11_2���s";
//}
//
//TEST(Iterator, ID_12_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	testIterator = testList.Get_TailIterator();
//	//�擪���ɐi�߂�
//	testIterator--;
//
//	ASSERT_ANY_THROW(testIterator) << "ID_1_12_1���s";
//}
//
//TEST(Iterator, ID_12_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	testConstIterator = testList.Get_TailConstIterator();
//	//�擪���ɐi�߂�
//	testConstIterator++;
//
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_12_2���s";
//}
//
//TEST(Iterator, ID_13_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	testIterator = testList.Get_HeadIterator();
//	//�擪���ɐi�߂�
//	testIterator--;
//
//	ASSERT_ANY_THROW(testIterator) << "ID_1_13_1���s";
//}
//
//TEST(Iterator, ID_13_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	testConstIterator = testList.Get_HeadConstIterator();
//	//�������ɐi�߂�
//	testConstIterator--;
//
//	ASSERT_ANY_THROW(testConstIterator) << "ID_1_13_2���s";
//}
//
//TEST(Iterator, ID_14_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//�擪���珇�Ɍ��؂��Ă���
//	testIterator = testList.Get_HeadIterator();
//	int i = 0;
//	while (testIterator || i < 5)
//	{
//		testScore = Set_ScoreData(i, "success");
//		dataCheck = Check_Data(testIterator, testScore);
//		testIterator--;
//		i++;
//		ASSERT_TRUE(dataCheck) << "ID_1_14_1���s";
//	}
//}
//
//TEST(Iterator, ID_14_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//�擪���珇�Ɍ��؂��Ă���
//	testConstIterator = testList.Get_HeadConstIterator();
//	int i = 0;
//	while (testConstIterator || i < 5)
//	{
//		testScore = Set_ScoreData(i, "success");
//		dataCheck = Check_Data(testConstIterator, testScore);
//		testConstIterator--;
//		i++;
//		ASSERT_TRUE(dataCheck) << "ID_1_14_2���s";
//	}
//}
//
//TEST(Iterator, ID_15_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//�ړ��O�̌���
//	testIterator = testList.Get_TailIterator();
//	testScore = Set_ScoreData(0, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_15_1���s";
//
//	//��߂�����̌���
//	--testIterator;
//	testScore = Set_ScoreData(1, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_15_1���s";
//
//}
//
//TEST(Iterator, ID_15_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//�ړ��O�̌���
//	testConstIterator = testList.Get_TailConstIterator();
//	testScore = Set_ScoreData(0, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_15_2���s";
//
//	//��i�߂���̌���
//	--testConstIterator;
//	testScore = Set_ScoreData(1, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_15_2���s";
//
//}
//
//TEST(Iterator, ID_16_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testIterator = testList.Get_HeadIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(*testIterator, testScore);
//	}
//
//	//�ړ��O�̌���
//	testIterator = testList.Get_TailIterator();
//	testScore = Set_ScoreData(0, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_16_1���s";
//
//	//��i�߂���̌���
//	testIterator--;
//	testScore = Set_ScoreData(1, "success");
//	dataCheck = Check_Data(testIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_16_1���s";
//
//}
//
//TEST(Iterator, ID_16_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	testConstIterator = testList.Get_HeadConstIterator();
//	ScoreData* testScore; 
//	bool dataCheck = false;
//
//	//�Ƃ肠�����f�[�^�̑}��
//	for (int i = 0; i < 5; i++)
//	{
//		testScore = Set_ScoreData(i, "success");
//		testList.Push_Back(testConstIterator, testScore);
//	}
//
//	//�ړ��O�̌���
//	testConstIterator = testList.Get_TailConstIterator();
//	testScore = Set_ScoreData(0, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_16_2���s";
//
//	//��i�߂���̌���
//	testConstIterator--;
//	testScore = Set_ScoreData(1, "success");
//	dataCheck = Check_Data(testConstIterator, testScore);
//	ASSERT_TRUE(dataCheck) << "ID_1_16_2���s";
//
//}
//
////�R���p�C���G���[�ƂȂ�ΐ���
////TEST(Iterator, ID_17) {
////	DoubleLinkedList::ConstIterator* testConstIterator=new DoubleLinkedList::ConstIterator;
////	DoubleLinkedList::Iterator* testIterator = testConstIterator;
////}
//
//TEST(Iterator, ID_18_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	//�R�s�[�R���X�g���N�^
//	DoubleLinkedList::Iterator* testIterator_1 = testIterator_0;
//
//	ASSERT_EQ(testIterator_0, testIterator_1) << "ID_1_18_1���s";
//}
//
//TEST(Iterator, ID_18_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	//�R�s�[�R���X�g���N�^
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = testConstIterator_0;
//
//	ASSERT_EQ(testConstIterator_0, testConstIterator_1) << "ID_1_18_2���s";
//}
//
////�R���p�C���G���[�ƂȂ�ΐ���
////TEST(Iterator, ID_19) {
////	DoubleLinkedList::ConstIterator* testConstIterator=new DoubleLinkedList::ConstIterator;
////	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
////	testIterator=testConstIterator;
////}
//
//TEST(Iterator, ID_20_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//
//	//�C�e���[�^�̃R�s�[
//	testIterator_0 = testIterator_1;
//
//	ASSERT_EQ(testIterator_0, testIterator_1) << "ID_1_20_1���s";
//}
//
//
//TEST(Iterator, ID_20_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//
//	//�R���X�g�C�e���[�^�̃R�s�[
//	testConstIterator_0 = testConstIterator_1;
//
//	ASSERT_EQ(testConstIterator_0, testConstIterator_1) << "ID_1_20_2���s";
//}
//
//TEST(Iterator, ID_21_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator_0 = testList.Get_HeadIterator();
//	DoubleLinkedList::Iterator* testIterator_1 = testList.Get_TailIterator();
//	bool dataCheck=false;
//
//	//�f�[�^�̔�r
//	dataCheck = testIterator_0 == testIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_21_1���s";
//}
//
//TEST(Iterator, ID_21_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = testList.Get_HeadConstIterator();
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = testList.Get_TailConstIterator();
//	bool dataCheck = false;
//
//	//�f�[�^�̔�r
//	dataCheck = testConstIterator_0 == testConstIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_21_2���s";
//}
//
//TEST(Iterator, ID_22_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//	bool dataCheck = false;
//
//	testIterator_0 = testList.Get_HeadIterator();
//
//	//�f�[�^�̔�r
//	testIterator_0 = testIterator_1;
//	dataCheck = testIterator_0 == testIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_22_1���s";
//}
//
//TEST(Iterator, ID_22_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//	bool dataCheck = false;
//
//	//�f�[�^�̔�r
//	testConstIterator_0 = testList.Get_HeadConstIterator();
//	testConstIterator_0 = testConstIterator_1;
//	dataCheck = testConstIterator_0 == testConstIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_22_2���s";
//}
//
//TEST(Iterator, ID_23_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList_0;
//	DoubleLinkedList testList_1;
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//	bool dataCheck = true;
//
//	//�f�[�^�̔�r
//	testIterator_0 = testList_0.Get_HeadIterator();
//	testIterator_1 = testList_1.Get_HeadIterator();
//	dataCheck = testIterator_0 == testIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_23_1���s";
//}
//
//TEST(Iterator, ID_23_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList_0;
//	DoubleLinkedList testList_1;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//	bool dataCheck = true;
//
//	//�f�[�^�̔�r
//	testConstIterator_0 = testList_0.Get_HeadConstIterator();
//	testConstIterator_1 = testList_1.Get_HeadConstIterator();
//	dataCheck = testConstIterator_0 == testConstIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_23_2���s";
//}
//
//TEST(Iterator, ID_24_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator_0 = testList.Get_HeadIterator();
//	DoubleLinkedList::Iterator* testIterator_1 = testList.Get_TailIterator();
//	bool dataCheck = true;
//
//	//�f�[�^�̔�r
//	dataCheck = testIterator_0 != testIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_24_1���s";
//}
//
//TEST(Iterator, ID_24_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = testList.Get_HeadConstIterator();
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = testList.Get_TailConstIterator();
//	bool dataCheck = true;
//
//	//�f�[�^�̔�r
//	dataCheck = testConstIterator_0 != testConstIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_24_2���s";
//}
//
//TEST(Iterator, ID_25_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//	bool dataCheck = true;
//
//	testIterator_0 = testList.Get_HeadIterator();
//
//	//�f�[�^�̔�r
//	testIterator_0 = testIterator_1;
//	dataCheck = testIterator_0 != testIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_25_1���s";
//}
//
//TEST(Iterator, ID_25_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//	bool dataCheck = true;
//
//	//�f�[�^�̔�r
//	testConstIterator_0 = testList.Get_HeadConstIterator();
//	testConstIterator_0 = testConstIterator_1;
//	dataCheck = testConstIterator_0 != testConstIterator_1;
//
//	ASSERT_FALSE(dataCheck) << "ID_1_25_2���s";
//}
//
//TEST(Iterator, ID_26_1) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList_0;
//	DoubleLinkedList testList_1;
//	DoubleLinkedList::Iterator* testIterator_0 = new DoubleLinkedList::Iterator;
//	DoubleLinkedList::Iterator* testIterator_1 = new DoubleLinkedList::Iterator;
//	bool dataCheck =false;
//
//	//�f�[�^�̔�r
//	testIterator_0 = testList_0.Get_HeadIterator();
//	testIterator_1 = testList_1.Get_HeadIterator();
//	dataCheck = testIterator_0 != testIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_26_1���s";
//}
//
//TEST(Iterator, ID_26_2) {
//	//�e�X�g�f�[�^�̐錾
//	DoubleLinkedList testList_0;
//	DoubleLinkedList testList_1;
//	DoubleLinkedList::ConstIterator* testConstIterator_0 = new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::ConstIterator* testConstIterator_1 = new DoubleLinkedList::ConstIterator;
//	bool dataCheck = false;
//
//	//�f�[�^�̔�r
//	testConstIterator_0 = testList_0.Get_HeadConstIterator();
//	testConstIterator_1 = testList_1.Get_HeadConstIterator();
//	dataCheck = testConstIterator_0 == testConstIterator_1;
//
//	ASSERT_TRUE(dataCheck) << "ID_1_26_2���s";
//}
//
//TEST(TestCaseName, TestName) {
//  ASSERT_EQ(1, 1);
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}