#include "pch.h"
#include"DoubleLinkedList.h"
#include "ListTest.h"

//�f�[�^���̎擾�A���X�g����̏ꍇ�̖߂�l
TEST(List, ID_00) {
	DoubleLinkedList testList;
	ASSERT_EQ(testList.Count(), 0)<<"ID:0-00���s";
}

//�f�[�^���̎擾�A���X�g�����ւ̑}�����s�����ۂ̖߂�l
TEST(List, ID_01) {
	DoubleLinkedList testList;         //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_TailIterator();        //�����C�e���[�^�̎擾
	ScoreData testScore;

	//testScore�̏�����
	testScore=Set_ScoreData(1, "success");
    testList.Insert(*testIterator,testScore);   //�f�[�^��}��

	ASSERT_EQ(testList.Count(), 1)<<"ID:0-01���s";    //�f�[�^����1�ł���ΐ���
}

////�f�[�^���̎擾�A���X�g�����ւ̑}�������s�����ۂ̖߂�l
//TEST(List, ID_02) {    �������A���P�[�V�����G���[���̋����ł���Ɣ��f�������߃e�X�g���X�L�b�v
//	DoubleLinkedList testList;          //�e�X�g�f�[�^�̍\�z
//	/*DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();*/
//	testList.Get_TailIterator();         //�����C�e���[�^�̎擾
//	testList.Push_Data(testList.Get_TailIterator());   //�f�[�^��}��
//
//	ASSERT_EQ(testList.Count_Data(), 0) << "ID:0-02���s";   //�f�[�^����0�ł���ΐ���
//
//}

//�f�[�^���̎擾�A�f�[�^�̑}�����s�����ۂ̖߂�l
TEST(List, ID_03) {
	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^

	//testScore�̏�����
	testScore = Set_ScoreData(1, "success");
    testList.Insert(*testIterator,testScore);         //�f�[�^�̑}��

	ASSERT_EQ(testList.Count(), 1) << "ID:0-03���s";   //�f�[�^����1�ł���ΐ���
}

//�f�[�^���̎擾�A�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l
////TEST(List, ID_04) {   �������A���P�[�V�����G���[���̋����ł���Ɣ��f�������߃e�X�g���X�L�b�v
////	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
////	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
////	(*testIterator) = testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
////	testList.Push_Data(testIterator);         //�f�[�^�̑}��
////
////	
////	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-04���s";   //�f�[�^����1�ł���ΐ���
////
////}

//�f�[�^���̎擾�A�f�[�^�̍폜���s�����ۂ̖߂�l
TEST(List, ID_05) {
	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator; 
	ScoreData testScore;
	testScore = Set_ScoreData(1, "success");
	(*testIterator) = testList.Get_TailIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
    testList.Insert(*testIterator, testScore);  //�f�[�^�̑}��
	--(*testIterator);
	testList.Delete(*testIterator);      //�f�[�^���폜

	ASSERT_EQ(testList.Count(), 0) << "ID:0-05���s";   //�f�[�^����0�ł���ΐ���
}

//�f�[�^���̎擾�A�f�[�^�̍폜�����s�����ۂ̖߂�l
//TEST(List, ID_06) {  �������A���P�[�V�����G���[���̋����ł���Ɣ��f�������߃e�X�g���X�L�b�v
//	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
//	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
//	(*testIterator) = testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
//	testList.Push_Data(testIterator);        //�f�[�^�̑}��
//	testList.Delete(testIterator);      //�f�[�^���폜
//
//	
//	ASSERT_EQ(testList.Count_Data(), 1) << "ID:0-06���s";   //�f�[�^����1�ł���ΐ���
//
//}

//�f�[�^���̎擾�A���X�g����ł���ꍇ�Ƀf�[�^�̍폜���s�����ۂ̖߂�l
TEST(List, ID_07) {
	DoubleLinkedList testList;               //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator *testIterator = new DoubleLinkedList::Iterator();
	(*testIterator) = testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	testList.Delete(*testIterator);      //�f�[�^���폜

	ASSERT_EQ(testList.Count(), 0) << "ID:0-07���s";   //�f�[�^����0�ł���ΐ���
}
//
////�f�[�^���̎擾�Aconst�̃��\�b�h�ł��邩
////�R���p�C���G���[���łȂ���ΐ���
////TEST(List, ID_08) {
////	DoubleLinkedList const testList; //const�Ő錾
////	testList.Count_Data();           //�R���p�C���G���[���łȂ���ΐ���
////}
//
//�f�[�^�}���֐�:���X�g����ł���ꍇ�ɁA�}�������ۂ̋���(�擪�C�e���[�^�Ō���)
TEST(List, ID_09_1) {
	DoubleLinkedList testList;            //�e�X�g�f�[�^�̍\�z
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�擪�v�f�Ƀf�[�^��}��
	(*testIterator) = testList.Get_HeadIterator();  //�e�X�g�f�[�^�̃C�e���[�^���擾
	testScore = Set_ScoreData(1, "success");
    
	dataCheck = testList.Insert(*testIterator,testScore);      //�f�[�^��}��
	
	ASSERT_TRUE(dataCheck) << "ID:0-09-1���s";
}

//�f�[�^�}���֐�:���X�g����ł���ꍇ�ɁA�}�������ۂ̋���(�����C�e���[�^�Ō���)
TEST(List, ID_09_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����v�f�Ƀf�[�^��}��
	(*testIterator) = testList.Get_TailIterator();
	testScore = Set_ScoreData(1, "success");
	dataCheck = testList.Insert(*testIterator,testScore);

	ASSERT_TRUE(dataCheck) << "ID:0-09-2���s";
}

//�f�[�^�}���֐�:���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���đ}�����s�����ۂ̖߂�l
TEST(List, ID_10) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
   	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
		
	}

	//�擪�v�f�Ƀf�[�^�}��
	(*testIterator) = testList.Get_HeadIterator();
	testScore = Set_ScoreData(10000, "success");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck)<<"ID0_10���s";
}

//�f�[�^�}���֐�:���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���đ}�����s�����ۂ̖߂�l
TEST(List, ID_11) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //�擪�ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

    //�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	 testList.Insert(*testIterator, testScore);
		--(*testIterator);
		
	}

	//�����v�f�Ƀf�[�^�}��
	(*testIterator) = testList.Get_TailIterator();
	testScore = Set_ScoreData(10000, "success");
    dataCheck = testList.Insert(*testIterator, testScore);
	
	ASSERT_TRUE(dataCheck) << "ID0_11���s";
}

//�f�[�^�}���֐�:���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�����s�����ۂ̖߂�l(�����Ō���)
TEST(List, 12_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	 testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�����v�f�Ƀf�[�^�}��
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_12_1���s";
}

//�f�[�^�}���֐�:���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�����s�����ۂ̖߂�l(�擪�Ō���)
TEST(List, 12_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	 testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�擪�Ƀf�[�^�}��
	*testIterator = testList.Get_HeadIterator();
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_12_2���s";
}

//�f�[�^�}���֐�:���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�����s�����ۂ̖߂�l(�����Ō���)
TEST(List, 12_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	 testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�����v�f�Ƀf�[�^�}��
	*testIterator = testList.Get_TailIterator();
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_12_2���s";
}

//�f�[�^�}���֐�:ConstIterator���w�肵�đ}�����s�����ۂ̋���(�����Ō���)
TEST(List, ID_13_1) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //�擪�v�f�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	    testList.Insert(*testIterator, testScore);
	    --(*testIterator);
	}

	//�����v�f�Ƀf�[�^�}��
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_1���s";
}

//�f�[�^�}���֐�:ConstIterator���w�肵�đ}�����s�����ۂ̋���(�擪�Ō���)
TEST(List, ID_13_2) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�擪�v�f�Ƀf�[�^�}��
	(*testIterator) = testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(00010, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_2���s";
}

//�f�[�^�}���֐�:ConstIterator���w�肵�đ}�����s�����ۂ̋���(�����Ō���)
TEST(List, ID_13_3) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();  //���݈ʒu�̃C�e���[�^���擾
	ScoreData testScore;                     //����p�X�R�A�f�[�^
	bool dataCheck = false;

	//�����̃f�[�^����
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i + 1, "test0");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�����v�f�Ƀf�[�^�}��
	(*testIterator) = testList.Get_TailConstIterator();
	testScore = Set_ScoreData(100, "succes");
	dataCheck = testList.Insert(*testIterator, testScore);

	ASSERT_TRUE(dataCheck) << "ID0_13_3���s";
}

//�s���ȃC�e���[�^��n���A�}�������ꍇ�̋���
TEST(List, ID_14) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	testScore = Set_ScoreData(1, "failed");
	bool dataCheck=false;

	//���Q�Ƃ̃C�e���[�^�Ƀf�[�^����
    dataCheck = testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_HeadIterator();

	ASSERT_EQ(testList.Count(),0)<<"ID0_14���s";
}

////�f�[�^�}���֐�����const�̃��\�b�h�ł��邩
////�R���p�C���G���[���o��ΐ���
////TEST(List, ID_15)
////{
////	const DoubleLinkedList testList;
////	DoubleLinkedList::Iterator* testIterator=new DoubleLinkedList::Iterator;
////	ScoreData testScore; 
////
//// testList.Push_Back(*testIterator, testScore);
////}
//
////�ȉ��A�f�[�^�폜�֐��ɂ��Ẵe�X�g
//���X�g����ł���ꍇ�ɍ폜���s�����ۂ̋���(�擪�C�e���[�^����)
TEST(List, ID_16_1)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//�擪�v�f���폜
	(*testIterator) = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID_0_16_1���s";
}


//���X�g����ł���ꍇ�ɍ폜���s�����ۂ̋���(�����C�e���[�^����)
TEST(List, ID_16_2)
{
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//�����v�f���폜
	(*testIterator) = testList.Get_TailIterator();
	bool destroyCheck = false;
	destroyCheck=testList.Delete(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID_0_16_2���s";
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜���s�����ۂ̋���
TEST(List, ID_17) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	testScore = Set_ScoreData(0, "test");

	//�����̗v�f�Ƀf�[�^����
	(*testIterator) = testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
	 testList.Insert(*testIterator, testScore);
	}

	//�擪�v�f���폜
	(*testIterator) = testList.Get_HeadIterator();
	bool destroyCheck = false;
	destroyCheck = testList.Delete(*testIterator);

	ASSERT_TRUE(destroyCheck) << "ID_0_17���s";
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜���s�����ۂ̋���
TEST(List, ID_18) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	testScore = Set_ScoreData(0, "test");
	bool destroyCheck = false;

	//�����̗v�f�Ƀf�[�^����
	(*testIterator) = testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
	 testList.Insert(*testIterator, testScore);
	}

	//�����v�f���폜
	(*testIterator) = testList.Get_TailIterator();
	destroyCheck = testList.Delete(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID_0_18���s";
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���āA�폜���s�����ۂ̋���
TEST(List, ID_19) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 

	//�����̗v�f�Ƀf�[�^����
	(*testIterator) = testList.Get_HeadIterator();
	for (int i = 0; i < 10; i++)
	{
	 testScore = Set_ScoreData(i, "test");
	 testList.Insert(*testIterator, testScore);
	}

	//�w��̗v�f���폜
	for (int i = 0; i < 5; i++)
	{
		--(*testIterator);
	}

	//�폜�֐������s���A�����������m�F����
	bool destroyCheck = false;
	destroyCheck = testList.Delete(*testIterator);

	ASSERT_TRUE(destroyCheck) << "ID_0_19���s";
}

//ConstIterator���w�肵�č폜���s�����ۂ̋���
TEST(List, ID_20) {
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	testScore = Set_ScoreData(0, "test");

	//�����̗v�f�Ƀf�[�^����
	(*testConstIterator) = testList.Get_HeadConstIterator();
	for (int i = 0; i < 10; i++)
	{
		testList.Insert(*testConstIterator, testScore);
	}

	//�w��̗v�f���폜
	for (int i = 0; i < 5; i++)
	{
		--(*testConstIterator);
	}
	bool destroyCheck = false;
	destroyCheck = testList.Delete(*testConstIterator);

	delete testConstIterator;

	ASSERT_TRUE(destroyCheck) << "ID_0_20���s";
}

//�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
TEST(List, ID_21) {
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;

	//���Q�Ƃ̃C�e���[�^�̃f�[�^���폜
	bool destroyCheck = false;
	destroyCheck = testList.Delete(*testIterator);

	ASSERT_FALSE(destroyCheck) << "ID0_21���s";
}

//��const�̃��\�b�h�ł��邩
////�R���p�C���G���[���o��ΐ���
//TEST(List, ID_22)
//{
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	testList.Delete(*testIterator);
//
//}

//////�ȉ��A�擪�C�e���[�^�擾�֐��ɂ��Ẵe�X�g
////���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_23) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator1 = new DoubleLinkedList::Iterator;
	DoubleLinkedList::Iterator* testIterator2= new DoubleLinkedList::Iterator;

	(*testIterator1) = testList.Get_HeadIterator();
	(*testIterator2) = testList.Get_TailIterator();

	ASSERT_NE(testIterator1, testIterator2) << "ID_0_23���s.�f�[�^���_�~�[�łȂ�";
}

//���X�g�ɗv�f����ȏ゠��ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_24) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;

	//�f�[�^�̑}��
	testScore = Set_ScoreData(1, "succes");
	(*testIterator) = testList.Get_HeadIterator();
    testList.Insert(*testIterator, testScore);

	//�擪�C�e���[�^���擾���A����
	(*testIterator) = testList.Get_HeadIterator();

	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck)<<"ID_0_24���s";
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_25) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	
	(*testIterator) = testList.Get_HeadIterator();

	//�����̃f�[�^��}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
    	testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_25���s";
}

//�f�[�^�̑}�����s�����ۂɁA�Ăяo�����ۂ̋���
TEST(List,ID0_26_1){//�擪�v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 

	//�擪�Ƀf�[�^�}��
	(*testIterator) = testList.Get_HeadIterator();
	testScore = Set_ScoreData(1, "success");
    testList.Insert(*testIterator, testScore);

	//�擪�C�e���[�^�擾
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_26_1���s";
}

//�f�[�^�̑}�����s�����ۂɁA�Ăяo�����ۂ̋���
TEST(List,ID0_26_2){//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	
	(*testIterator) = testList.Get_HeadIterator();

	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�����v�f�Ƀf�[�^��}������
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(10000, "center");
    testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_26_2���s";
}

//�f�[�^�̑}�����s�����ۂɁA�Ăяo�����ۂ̋���
TEST(List,ID0_26_3){//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;

	(*testIterator) = testList.Get_HeadIterator();

	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_TailIterator();
	//�����v�f�Ƀf�[�^��}������
	testScore = Set_ScoreData(10000, "tail");
    testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_26_3���s";
}

//�f�[�^�̍폜���s�����ۂɁA�Ăяo�����ۂ̋���
TEST(List,ID0_27_1){//�擪�v�f�̃f�[�^���폜�����ꍇ
    ////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;

	(*testIterator) = testList.Get_HeadIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	 testList.Insert(*testIterator, testScore);
		
	}

	//�擪�v�f�̃f�[�^���폜����
	(*testIterator) = testList.Get_HeadIterator();
	testList.Delete(*testIterator);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_27_1���s";
}

//�f�[�^�̍폜���s�����ۂɁA�Ăяo�����ۂ̋���
TEST(List,ID0_27_2){//�����v�f�̃f�[�^���폜�����ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;

	(*testIterator) = testList.Get_HeadIterator();

	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_HeadIterator();
	//�����v�f�̃f�[�^���폜����
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testList.Delete(*testIterator);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_27_2���s";
}

//�f�[�^�̍폜���s�����ۂɁA�Ăяo�����ۂ̋���
TEST(List,ID0_27_3){//�����v�f�̃f�[�^���폜�����ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	
	(*testIterator) = testList.Get_HeadIterator();

	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�����v�f�̃f�[�^���폜����
	(*testIterator)=testList.Get_TailIterator();
	testList.Delete(*testIterator);
	(*testIterator) = testList.Get_HeadIterator();
	bool dataCheck = (*testIterator) == testList.Get_HeadIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_27_3���s";
}

//const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
//�R���p�C���G���[���o��ΐ���
//TEST(List, ID_28) {
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	(*testIterator) = testList.Get_HeadIterator();
//
//}

////�ȉ��A�擪�R���X�g�C�e���[�^�ɂ��Ẵe�X�g
//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_29) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;

	//�Ăяo��
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_29���s";
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_30) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	//�f�[�^�̑}��
	testScore = Set_ScoreData(1, "succes");
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testList.Insert(*testConstIterator, testScore);

	//�Ăяo��
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_30���s";
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_31) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();

	//�����̃f�[�^��}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_31���s";
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_32_1) {//�擪�v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(1, "success");
	testList.Insert(*testConstIterator, testScore);

	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_32_1���s";
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_32_2) {//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();

	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//�����v�f�Ƀf�[�^��}������
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	testScore = Set_ScoreData(10000, "center");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_32_2���s";
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_32_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();

	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_TailConstIterator();
	//�����v�f�Ƀf�[�^��}������
	testScore = Set_ScoreData(10000, "tail");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_32_3���s";
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_33_1) {//�擪�v�f�̃f�[�^���폜�����ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//�擪�v�f�̃f�[�^���폜����
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testList.Delete(*testConstIterator);

	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_33_1���s";
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_33_2) {//�����v�f�̃f�[�^���폜�����ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//�����v�f�̃f�[�^���폜����
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	testList.Delete(*testConstIterator);
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_33_2���s";
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_33_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_TailConstIterator();
	//�����v�f�Ƀf�[�^��}������
	testScore = Set_ScoreData(10000, "tail");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_HeadConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_HeadConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_33_3���s";
}

//const�̃��\�b�h�ł��邩
//�R���p�C���G���[�ƂȂ�Ȃ���ΐ���
//TEST(List, ID_34) {
//	const DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	(*testConstIterator) = testList.Get_HeadConstIterator();
//}

////�ȉ��A�����C�e���[�^�擾�֐��ɂ��Ẵe�X�g
//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_35) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData checkScore;

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_35���s";
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_36) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	//�f�[�^�̑}��
	testScore = Set_ScoreData(1, "success");
	(*testIterator) = testList.Get_HeadIterator();
    testList.Insert(*testIterator, testScore);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_36���s";
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_37) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();

	//�����̃f�[�^��}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_37���s";
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_38_1) {//�擪�v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	//�擪�Ƀf�[�^�}��
	(*testIterator) = testList.Get_HeadIterator();
	testScore = Set_ScoreData(1, "success");
    testList.Insert(*testIterator, testScore);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_38_1���s";
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_38_2) {//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();

	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_HeadIterator();
	//�����v�f�Ƀf�[�^��}������
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testScore = Set_ScoreData(10000, "center");
    testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_38_2���s";
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_38_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_TailIterator();
	//�����v�f�Ƀf�[�^��}������
	testScore = Set_ScoreData(10000, "tail");
    testList.Insert(*testIterator, testScore);
	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_38_3���s";
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_39_1) {//�擪�v�f�̃f�[�^���폜�����ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore;
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
     	testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�擪�v�f�̃f�[�^���폜����
	(*testIterator) = testList.Get_HeadIterator();
	testList.Delete(*testIterator);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_39_1���s";
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_39_2) {//�����v�f�̃f�[�^���폜�����ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
 	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	(*testIterator) = testList.Get_HeadIterator();
	//�����v�f�̃f�[�^���폜����
	for (int i = 0; i < 5; i++)
	{
		++(*testIterator);
	}
	testList.Delete(*testIterator);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_39_2���s";
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_39_3) {//�����v�f�̃f�[�^���폜�����ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	ScoreData checkScore;

	(*testIterator) = testList.Get_HeadIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�����v�f�̃f�[�^���폜����
	(*testIterator) = testList.Get_TailIterator();
	testList.Delete(*testIterator);

	(*testIterator) = testList.Get_TailIterator();
	bool dataCheck = (*testIterator) == testList.Get_TailIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_39_3���s";
}

//const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
//�R���p�C���G���[���o��ΐ���
//TEST(List, ID_40) {
//	const DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	(*testIterator) = testList.Get_TailIterator();
//
//}

////�ȉ��A�����R���X�g�C�e���[�^�擾�֐��ɂ��Ẵe�X�g
//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_41) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_41���s";
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_42) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	//�f�[�^�̑}��
	testScore = Set_ScoreData(1, "succes");
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testList.Insert(*testConstIterator, testScore);

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_42���s";
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(List, ID_43) {
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore;
	

	(*testConstIterator) = testList.Get_HeadConstIterator();

	//�����̃f�[�^��}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "test");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}
	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_43���s";
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_44_1) {//�擪�v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(1, "success");
	testList.Insert(*testConstIterator, testScore);

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_44_1���s";
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_44_2) {//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//�����v�f�Ƀf�[�^��}������
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	testScore = Set_ScoreData(10000, "center");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_44_2���s";
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_44_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_TailConstIterator();
	//�����v�f�Ƀf�[�^��}������
	testScore = Set_ScoreData(10000, "tail");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_44_3���s";
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_45_1) {//�擪�v�f�̃f�[�^���폜�����ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//�擪�v�f�̃f�[�^���폜����
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testList.Delete(*testConstIterator);

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_45_1���s";
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_45_2) {//�����v�f�̃f�[�^���폜�����ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//�����v�f�̃f�[�^���폜����
	for (int i = 0; i < 5; i++)
	{
		++(*testConstIterator);
	}
	testList.Delete(*testConstIterator);

	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_45_2���s";
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(List, ID0_45_3) {//�����v�f�Ƀf�[�^��}�������ꍇ
	////�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	ScoreData testScore; 
	

	(*testConstIterator) = testList.Get_HeadConstIterator();
	//��U�f�[�^��}������
	for (int i = 0; i < 10; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	(*testConstIterator) = testList.Get_TailConstIterator();
	//�����v�f�Ƀf�[�^��}������
	testScore = Set_ScoreData(10000, "tail");
	testList.Insert(*testConstIterator, testScore);
	(*testConstIterator) = testList.Get_TailConstIterator();
	bool dataCheck = (*testConstIterator) == testList.Get_TailConstIterator();

	ASSERT_TRUE(dataCheck) << "ID_0_45_3���s";
}

//const�̃��\�b�h�ł��邩
//�R���p�C���G���[�ƂȂ�Ȃ���ΐ���
//TEST(List, ID_46) {
//	const DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	(*testConstIterator) = testList.Get_TailConstIterator();
//}

////�ȉ��A�C�e���[�^�Ɋւ���e�X�g
////��{�I�ɂ�ID��2�Ԗڂ̒l��1�̏ꍇ�̓C�e���[�^�A2�̏ꍇ�̓R���X�g�C�e���[�^�ɑ΂��ăe�X�g���s��

////�C�e���[�^�̎w���v�f���擾����(operator*)�ɂ��Ẵe�X�g
//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_0_1) {
//	////�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//�C�e���[�^�̎w���v�f���擾(���s����)
//	ScoreData testScore = *(*testIterator);
//}

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_0_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	//�C�e���[�^�̎w���v�f���擾(���s����)
//	ScoreData testScore = *(*testIterator);
//}

//Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
TEST(Iterator, ID_1) {
	//�e�X�g�p�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	ScoreData testScore; 
	testScore.Score = 100;
	testScore.UserName = "test";

	//�e�X�g�f�[�^��}��
	(*testIterator) = testList.Get_HeadIterator();
	testList.Insert(*testIterator, testScore);
	--(*testIterator);

	testScore = *(*testIterator);

	testScore.Score = 1;
	testScore.UserName = "success";

	ASSERT_EQ(testScore.Score, 1);
	ASSERT_EQ(testScore.UserName, "success");
}

////�R���p�C���G���[�ɂȂ�ΐ���
////ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N
////TEST(Iterator, ID_2) {
//	////�e�X�g�p�f�[�^�̐錾
//	//DoubleLinkedList testList;
//	//DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	//const ScoreData testScore = *(*testConstIterator);
//	//
//	//testScore.Score = 1;
//	//testScore.UserName = "success";
////}
//
//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_3_1) {
//
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData testScore;
//	ScoreData checkScore;//�_�~�[�f�[�^
//	
//	//�擪�v�f���擾
//	(*testIterator) = testList.Get_HeadIterator();
//	testScore = *(*testIterator);
//
//	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_3_1���s";
//	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_3_1���s";
//}

////���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_3_2) {
//
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData checkScore;//�_�~�[�f�[�^
//
//	//�擪�v�f���擾
//	(*testConstIterator) = testList.Get_HeadConstIterator();
//	const ScoreData testScore = *(*testConstIterator);
//}

////�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_4_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData testScore;
//	ScoreData checkScore;//�_�~�[�f�[�^
//
//	//�����v�f���擾
//	(*testIterator) = testList.Get_TailIterator();
//	testScore = *(*testIterator);
//}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_4_2) {
//
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	ScoreData checkScore;//�_�~�[�f�[�^
//
//	//�擪�v�f���擾
//	(*testConstIterator) = testList.Get_TailConstIterator();
//	const ScoreData testScore = *(*testConstIterator);
//}

////�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�(operator++)�ɂ��Ẵe�X�g
////���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_5_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//�������ɐi�߂�
//	++(*testIterator);
//}

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_5_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//	//�������ɐi�߂�
//	++(*testConstIterator);
//}

////���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_6_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData checkScore;
//
//	(*testIterator) = testList.Get_HeadIterator();
//	checkScore = *(*testIterator);
//	//�������ɐi�߂�
//	++(*testIterator);
//}

////���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_6_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//
//	(*testConstIterator) = testList.Get_HeadConstIterator();
//	const ScoreData checkScore=*(*testConstIterator);
//	//�������ɐi�߂�
//	++(*testConstIterator);
//}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_7_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	ScoreData checkScore;
//
//	(*testIterator) = testList.Get_TailIterator();
//	checkScore = *(*testIterator);
//	//�������ɐi�߂�
//	++(*testIterator);
//}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_7_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//
//	(*testConstIterator) = testList.Get_TailConstIterator();
//	const ScoreData checkScore=*(*testConstIterator);
//	//�������ɐi�߂�
//	++(*testConstIterator);
//}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(Iterator, ID_8_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore; 
	ScoreData checkScore;

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�擪���珇�Ɍ��؂��Ă���
	(*testIterator) = testList.Get_HeadIterator();
	int i = 4;
	while (testIterator&&i>0)
	{
		testScore = Set_ScoreData(i, "success");
		checkScore = *(*testIterator);
		++(*testIterator);
		i--;
		ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_8_1���s";
		ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_8_1���s";
	}
	//�����̌���
	(*testIterator) = testList.Get_TailIterator();
	checkScore = *(*testIterator);
	testScore = Set_ScoreData(0, "dummy");

	ASSERT_EQ(testScore.Score,checkScore.Score)<<"ID_1_8_1���s�A�����Ɉُ�";
	ASSERT_EQ(testScore.UserName,checkScore.UserName)<<"ID_1_8_1���s�A�����Ɉُ�";
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(Iterator, ID_8_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore; 
	

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//�擪���珇�Ɍ��؂��Ă���
	(*testConstIterator) = testList.Get_HeadConstIterator();
	int i = 4;
	while (testConstIterator&&i>0)
	{
		testScore = Set_ScoreData(i, "success");
		const ScoreData checkScore=*(*testConstIterator);
		++(*testConstIterator);
		i--;
		ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_8_2���s";
		ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_8_2���s";
	}
	//�����̌���
	(*testConstIterator) = testList.Get_TailConstIterator();
	const ScoreData checkScore=*(*testConstIterator);
	testScore = Set_ScoreData(0, "dummy");

	ASSERT_EQ(testScore.Score,checkScore.Score)<<"ID_1_8_2���s�A�����Ɉُ�";
	ASSERT_EQ(testScore.UserName,checkScore.UserName)<<"ID_1_8_2���s�A�����Ɉُ�";
}

//�O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(Iterator, ID_9_1){
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore; 
	

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�ړ��O�̌���
	(*testIterator) = testList.Get_HeadIterator();
	testScore = Set_ScoreData(4, "success");
	ScoreData checkScore=*(*testIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_9_1���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_9_1���s";

	//��i�߂���̌���
	DoubleLinkedList::ConstIterator* tempIterator = new DoubleLinkedList::ConstIterator;
	*tempIterator = ++(*testIterator);
	testScore = Set_ScoreData(3, "success");
	checkScore = *(*tempIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_9_1���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_9_1���s";

}

//�O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(Iterator, ID_9_2){
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore; 
	

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//�ړ��O�̌���
	(*testConstIterator) = testList.Get_HeadConstIterator();
	testScore = Set_ScoreData(4, "success");
	ScoreData checkScore=*(*testConstIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_9_2���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_9_2���s";

	//��i�߂���̌���
	DoubleLinkedList::ConstIterator* tempIterator = new DoubleLinkedList::ConstIterator;
	*tempIterator = ++(*testConstIterator);
	testScore = Set_ScoreData(3, "success");
	checkScore = *(*tempIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_9_2���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_9_2���s";

}

//��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(Iterator, ID_10_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore; 
	

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
	    testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�ړ��O�̌���
	(*testIterator) = testList.Get_HeadIterator();
	//�ړ��O�̒l��ۑ�
	DoubleLinkedList::ConstIterator* tempIterator=new DoubleLinkedList::ConstIterator;
	*tempIterator = (*testIterator)++;
	testScore = Set_ScoreData(4, "success");
	ScoreData checkScore = *(*tempIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_10_1���s,1";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_10_1���s,2";

	//��i�߂���̌���
	testScore = Set_ScoreData(3, "success");
	checkScore = *(*testIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_10_1���s,3";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_10_1���s,4";
}

//��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(Iterator, ID_10_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore; 
    

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//�ړ��O�̌���
	(*testConstIterator) = testList.Get_HeadConstIterator();
	//�ړ��O��ۑ�
	DoubleLinkedList::ConstIterator* tempConstIterator = new DoubleLinkedList::ConstIterator;
	*tempConstIterator = (*testConstIterator)++;

	testScore = Set_ScoreData(4, "success");
	ScoreData checkScore = *(*tempConstIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_10_2���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_10_2���s";

	//��i�߂���̌���
	testScore = Set_ScoreData(3, "success");
	checkScore = *(*testConstIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_10_2���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_10_2���s";

}

////�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�(operator--)�ɂ��Ẵe�X�g
////���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_11_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//
//	//�擪���ɐi�߂�
//	--(*testIterator);
//}

////���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_11_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//
//	//�擪���ɐi�߂�
//	--(*testConstIterator);
//}

////���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_12_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	
//	ScoreData testScore;
//	ScoreData checkScore;
//
//	(*testIterator) = testList.Get_TailIterator();
//	//�擪���ɐi�߂�
//	--(*testIterator);
//}

////���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_12_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//	ScoreData checkScore;
//
//	(*testConstIterator) = testList.Get_TailConstIterator();
//	//�������ɐi�߂�
//	--(*testConstIterator);
//}

////�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_13_1) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	
//	ScoreData testScore;
//	ScoreData checkScore;
//
//
//	(*testIterator) = testList.Get_HeadIterator();
//	//�������ɐi�߂�
//	--(*testIterator);
//}

////�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���(Assert��������ƒ��f�����̂ŃR�����g��)
//TEST(Iterator, ID_13_2) {
//	//�e�X�g�p�f�[�^�̐錾
//	DoubleLinkedList testList;
//	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
//	
//	ScoreData checkScore;
//
//	(*testConstIterator) = testList.Get_HeadConstIterator();
//	//�������ɐi�߂�
//	--(*testConstIterator);
//}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(Iterator, ID_14_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore;
	ScoreData checkScore;

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�������珇�Ɍ��؂��Ă���
	(*testIterator) = testList.Get_TailIterator();
	testScore = Set_ScoreData(0, "dummy");
	checkScore = *(*testIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_14_1���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_14_1���s";

	for (int i = 0; i < testList.Count(); i++)
	{
		--(*testIterator);
		testScore = Set_ScoreData(i, "success");
		const ScoreData checkScore=*(*testIterator);
		
		ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_14_1���s";
		ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_14_1���s";
	}
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(Iterator, ID_14_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore;
	

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//�������珇�Ɍ��؂��Ă���
	(*testConstIterator) = testList.Get_TailConstIterator();
	testScore = Set_ScoreData(0, "dummy");
	const ScoreData checkScore=*(*testConstIterator);
	
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_14_2���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_14_2���s";
    for(int i=0;i<testList.Count();i++)
	{
		--(*testConstIterator);
		testScore = Set_ScoreData(i, "success");
		const ScoreData checkScore=*(*testConstIterator);
		
		ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_14_2���s";
		ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_14_2���s";
	}
}

//�O�u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(Iterator, ID_15_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore;
	

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�ړ��O�̌���
	(*testIterator) = testList.Get_TailIterator();
	testScore = Set_ScoreData(0, "dummy");
	ScoreData checkScore=*(*testIterator);
	
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_15_1���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_15_1���s";

	//��i�߂���̌���
	DoubleLinkedList::ConstIterator tempIterator = --(*testIterator);
	testScore = Set_ScoreData(0, "success");
	checkScore = *tempIterator;
	
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_15_1���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_15_1���s";

}

//�O�u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(Iterator, ID_15_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore;
	

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//�ړ��O�̌���
	(*testConstIterator) = testList.Get_TailConstIterator();
	testScore = Set_ScoreData(0, "dummy");
	ScoreData checkScore=*(*testConstIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_15_2���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_15_2���s";

	//��i�߂���̌���
	DoubleLinkedList::ConstIterator tempIterator = --(*testConstIterator);
	testScore = Set_ScoreData(0, "success");
	checkScore = *tempIterator;

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_15_2���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_15_2���s";

}

//��u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(Iterator, ID_16_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
	(*testIterator) = testList.Get_HeadIterator();
	ScoreData testScore;
	

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testIterator, testScore);
		--(*testIterator);
	}

	//�ړ��O�̌���
	(*testIterator) = testList.Get_TailIterator();
	//�ړ��O�̒l��ۑ�
	DoubleLinkedList::ConstIterator tempConstIterator = (*testIterator)--;

	testScore = Set_ScoreData(0, "dummy");
	ScoreData checkScore = *tempConstIterator;
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_16_1���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_16_1���s";

	//��i�߂���̌���
	testScore = Set_ScoreData(0, "success");
    checkScore=*(*testIterator);

	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_16_1���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_16_1���s";

}

//��u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(Iterator, ID_16_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator* testConstIterator = new DoubleLinkedList::ConstIterator;
	(*testConstIterator) = testList.Get_HeadConstIterator();
	ScoreData testScore;
	

	//�Ƃ肠�����f�[�^�̑}��
	for (int i = 0; i < 5; i++)
	{
		testScore = Set_ScoreData(i, "success");
		testList.Insert(*testConstIterator, testScore);
		--(*testConstIterator);
	}

	//�ړ��O�̌���
	(*testConstIterator) = testList.Get_TailConstIterator();
	//�ړ��O��ۑ�
	DoubleLinkedList::ConstIterator tempConstIterator = (*testConstIterator)--;

	testScore = Set_ScoreData(0, "dummy");
	ScoreData checkScore = *tempConstIterator;
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_16_2���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_16_2���s";

	//��i�߂���̌���
	testScore = Set_ScoreData(0, "success");
	checkScore=*(*testConstIterator);
	ASSERT_EQ(testScore.Score,checkScore.Score) << "ID_1_16_2���s";
	ASSERT_EQ(testScore.UserName,checkScore.UserName) << "ID_1_16_2���s";

}

////�ȉ��A�C�e���[�^�̃R�s�[���s��(�R�s�[�R���X�g���N�^)�ɂ��Ẵe�X�g

//ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
//�R���p�C���G���[�ƂȂ�ΐ���
//TEST(Iterator, ID_17) {
//	DoubleLinkedList::ConstIterator* testConstIterator=new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Iterator* testIterator = testConstIterator;
//}

//�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(Iterator, ID_18_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0=testList.Get_HeadIterator();
	ScoreData testScore;
	testScore.Score = 1;
	testScore.UserName = "success";
	testList.Insert(testIterator_0, testScore);
	--testIterator_0;
	//�f�[�^�}��

	//�R�s�[�R���X�g���N�^
	DoubleLinkedList::Iterator testIterator_1 = testIterator_0;

	ScoreData checkScore0 = *testIterator_0;
	ScoreData checkScore1 = *testIterator_1;
	
	ASSERT_EQ(checkScore0.Score, checkScore1.Score) << "ID_1_18_1���s";
	ASSERT_EQ(checkScore0.UserName, checkScore1.UserName) << "ID_1_18_1���s";
}

//�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(Iterator, ID_18_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0=testList.Get_HeadConstIterator();
	ScoreData testScore;
	testScore.Score = 1;
	testScore.UserName = "success";
	testList.Insert(testConstIterator_0, testScore);
	--testConstIterator_0;
	//�R�s�[�R���X�g���N�^
	DoubleLinkedList::ConstIterator testConstIterator_1 = testConstIterator_0;

	ScoreData checkScore0 = *testConstIterator_0;
	ScoreData checkScore1 = *testConstIterator_1;

	ASSERT_EQ(checkScore0.Score, checkScore1.Score) << "ID_1_18_2���s";
	ASSERT_EQ(checkScore0.UserName, checkScore1.UserName) << "ID_1_18_2���s";
}

////�ȉ��A�C�e���[�^�̑�����s��(operator=)�ɂ��Ẵe�X�g
//Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
//�R���p�C���G���[�ƂȂ�ΐ���
//TEST(Iterator, ID_19) {
//	DoubleLinkedList::ConstIterator* testConstIterator=new DoubleLinkedList::ConstIterator;
//	DoubleLinkedList::Iterator* testIterator = new DoubleLinkedList::Iterator;
//	(*testIterator)=*testConstIterator;
//}

//�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(Iterator, ID_20_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;

	//�C�e���[�^�̃R�s�[

	testIterator_0 = testIterator_1;

	bool dataCheck = false;
	dataCheck = testIterator_0 == testIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_20_1���s";
}


//�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(Iterator, ID_20_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;

	//�R���X�g�C�e���[�^�̃R�s�[
	testConstIterator_0 = testConstIterator_1;

	bool dataCheck = false;
	dataCheck = testConstIterator_0 == testConstIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_20_2���s";
}

////�ȉ��A��̃C�e���[�^����������r����(operator==)�ɂ��Ẵe�X�g
//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(Iterator, ID_21_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0;
	testIterator_0 = testList.Get_HeadIterator();
	DoubleLinkedList::Iterator testIterator_1;
	testIterator_1 = testList.Get_TailIterator();
	bool dataCheck = false;

	//�f�[�^�̔�r
	dataCheck = testIterator_0 == testIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_21_1���s";
}

//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(Iterator, ID_21_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	testConstIterator_0 = testList.Get_HeadConstIterator();
	DoubleLinkedList::ConstIterator testConstIterator_1;
	testConstIterator_1 = testList.Get_TailConstIterator();
	bool dataCheck = false;

	//�f�[�^�̔�r
	dataCheck = testConstIterator_0 == testConstIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_21_2���s";
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(Iterator, ID_22_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;
	bool dataCheck = false;

	testIterator_0 = testList.Get_HeadIterator();
	testIterator_1 = testList.Get_HeadIterator();
	//�f�[�^�̔�r
	testIterator_1 = testIterator_0;
	dataCheck = testIterator_0 == testIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_22_1���s";
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(Iterator, ID_22_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	bool dataCheck = false;

	//�f�[�^�̔�r
	testConstIterator_0 = testList.Get_HeadConstIterator();
	testConstIterator_1 = testConstIterator_0;
	dataCheck = testConstIterator_0 == testConstIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_22_2���s";
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(Iterator, ID_23_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList_0;
	DoubleLinkedList testList_1;
	DoubleLinkedList::Iterator testIterator_0;;
	DoubleLinkedList::Iterator testIterator_1;;
	bool dataCheck = true;

	//�f�[�^�̔�r
    testIterator_0 = testList_0.Get_HeadIterator();
	testIterator_1 = testList_1.Get_HeadIterator();
	dataCheck = testIterator_0 == testIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_23_1���s";
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(Iterator, ID_23_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList_0;
	DoubleLinkedList testList_1;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	bool dataCheck = true;

	//�f�[�^�̔�r
	testConstIterator_0 = testList_0.Get_HeadConstIterator();
	testConstIterator_1 = testList_1.Get_HeadConstIterator();
	dataCheck = testConstIterator_0 == testConstIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_23_2���s";
}

////�ȉ��A��̃C�e���[�^���قȂ邩��r����(operator!=)�ɂ��Ẵe�X�g
//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(Iterator, ID_24_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;
	testIterator_0 = testList.Get_HeadIterator();
	testIterator_1 = testList.Get_TailIterator();
	bool dataCheck = true;

	//�f�[�^�̔�r
	dataCheck = testIterator_0 != testIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_24_1���s";
}

//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(Iterator, ID_24_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	testConstIterator_0 = testList.Get_HeadConstIterator();
	testConstIterator_1 = testList.Get_TailConstIterator();

	bool dataCheck = true;

	//�f�[�^�̔�r
	dataCheck = testConstIterator_0 != testConstIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_24_2���s";
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(Iterator, ID_25_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;
	bool dataCheck = true;

	testIterator_0 = testList.Get_HeadIterator();

	//�f�[�^�̔�r
	testIterator_0 = testIterator_1;
	dataCheck = testIterator_0 != testIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_25_1���s";
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(Iterator, ID_25_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	bool dataCheck = true;

	//�f�[�^�̔�r
	testConstIterator_0 = testList.Get_HeadConstIterator();
	testConstIterator_0 = testConstIterator_1;
	dataCheck = testConstIterator_0 != testConstIterator_1;

	ASSERT_FALSE(dataCheck) << "ID_1_25_2���s";
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(Iterator, ID_26_1) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList_0;
	DoubleLinkedList testList_1;
	DoubleLinkedList::Iterator testIterator_0;
	DoubleLinkedList::Iterator testIterator_1;
	bool dataCheck =false;

	//�f�[�^�̔�r
	testIterator_0 = testList_0.Get_HeadIterator();
	testIterator_1 = testList_1.Get_HeadIterator();
	dataCheck = testIterator_0 != testIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_26_1���s";
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(Iterator, ID_26_2) {
	//�e�X�g�f�[�^�̐錾
	DoubleLinkedList testList_0;
	DoubleLinkedList testList_1;
	DoubleLinkedList::ConstIterator testConstIterator_0;
	DoubleLinkedList::ConstIterator testConstIterator_1;
	bool dataCheck = false;

	//�f�[�^�̔�r
	testConstIterator_0 = testList_0.Get_HeadConstIterator();
	testConstIterator_1 = testList_1.Get_HeadConstIterator();
	dataCheck = testConstIterator_0 != testConstIterator_1;

	ASSERT_TRUE(dataCheck) << "ID_1_26_2���s";
}

////TEST(TestCaseName, TestName) {
////  ASSERT_EQ(1, 1);
////  EXPECT_EQ(1, 1);
////  EXPECT_TRUE(true);
////}