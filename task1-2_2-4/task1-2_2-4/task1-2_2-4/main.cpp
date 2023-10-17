#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"

using namespace std;

int main(void)
{
	const char *FileName = "asset\\Scores.txt";//�t�@�C�������w��
	ifstream ScoreFile(FileName);
	
	//�t�@�C�����J���Ȃ���΃G���[
	if (!ScoreFile)
	{
		cout << "�t�@�C�����J���܂���ł���" << endl;
		cin.get();
		return 0;
	}

	//�錾
	DoubleLinkedList ScoreList;   //�X�R�A�f�[�^���i�[����o�������X�g
	DoubleLinkedList::Iterator* Itr = ScoreList.Get_HeadIterator();    //ScoreList�̃C�e���[�^
	string Line;  //�e�L�X�g�t�@�C���̈�s��ۑ�����p

	while (getline(ScoreFile, Line))       //�Ō�̍s�܂ŏ������J��Ԃ�
	{
    	ScoreData* ScoreLine=new ScoreData;//���уf�[�^�𐶐�
		string score;                      //�X�R�A��ۑ�����
		string name = "\t";                //���O��ۑ�����
		for (size_t i = 0; i < Line.size(); i++)
		{
			char ch = Line[i];

			if (score.find("\t") == string::npos)//�X�R�A�Ɩ��O���d����
			{
				score += ch;
			}
			else
			{
				name += ch;
			}
		}
		int num = stoi(score);     //score��int�^�ɕϊ�

		//���уf�[�^�����X�g�Ɋi�[
		ScoreLine->Score = num;
		ScoreLine->UserName = name;
		ScoreList.Push_Back(Itr, ScoreLine);

		--(*Itr);
	}
	Itr = ScoreList.Get_TailIterator();

	//�f�[�^�̕\��(�i�[��)
	while ((*Itr) != ScoreList.Get_HeadIterator())//�擪�܂ŌJ��Ԃ�
	{
		--(*Itr);
		DoubleLinkedList::Node* node = *(*Itr);
		cout << node->scoredata->Score << node->scoredata->UserName << endl;
	}

	cin.get();
	return 0;
}