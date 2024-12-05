#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int SizeEnglishAlphabet = 26; //������ ��������

const char LowercaseEnglishLetters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }; //������ �������� ����
const char UppercaseEnglishLetters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' }; //������ ��������� ����

//������� ������������ ����� ������ �� �������� �� ��������� ��������
string CodeEnglishLanguage(string& text, const int shift)
{
	bool Ok; //��� �� ������ ��������� ��� ����� �������� � ����� ����������
	string output_s(""); //������������� ������, ������� ���������������� ������ �������
	for (unsigned i = 0; i < text.length(); i++)
	{
		Ok = false;
		for (int j = 0; j < SizeEnglishAlphabet; j++)
		{ //���������� ��� ����� �������� �� ����� ������������
			if (text[i] == LowercaseEnglishLetters[j]) //���� ������ �������� �������� ������ ��������
			{
				j += shift;//�������� ����� �� �������� �� ��������� ��������
				while (j >= SizeEnglishAlphabet)
				{
					j -= SizeEnglishAlphabet;//���� �������� ����� �� ��������,
				}
				while (j < 0)
				{
					j += SizeEnglishAlphabet; //������������ ���
				}
				output_s += LowercaseEnglishLetters[j]; //��������� ���������� ������ � �����
														//������������� ������
				Ok = true; //������ ��� ������������ ���������� � �������� � ������
				break; //������� ��� ������� ������� ����� ���������
			}
			else if (text[i] == UppercaseEnglishLetters[j]) //�� �� �����, ���� ������ ��������
			{												//��������� ������ ��������
				j += shift;
				if (j >= SizeEnglishAlphabet) j -= SizeEnglishAlphabet;
				else if (j < 0) j += SizeEnglishAlphabet;
				output_s += UppercaseEnglishLetters[j];
				Ok = true;
				break;
			}
		}
		if (!Ok)
		{
			output_s += text[i]; //���� ������ �� �������� ������ ��������,
		}							//���������� ��� ��� ���������		
	}
	return output_s; //�� ��������� ���������� ������������ ������
}

int SearchPossibleShift(const string& text)
{
	vector<int> freq(26, 0);
	int possibleShift = 0;
	int maxFrequency = 0;
	// ���������� ������ ������ � ������
	for (char ch : text)
	{
		// �������� ������ � ������� ��������
		ch = tolower(ch);
		// ���������, �������� �� ������ ������
		if (ch >= 'a' && ch <= 'z')
		{
			freq[ch - 'a']++; // ����������� ������� ��������������� �����
			if (freq[ch - 'a'] > maxFrequency)
			{
				maxFrequency = freq[ch - 'a'];
				possibleShift = ch - 'a' + 'e';
			}
		}
	}
	return possibleShift;
}

int main()
{
	cout << "Enter the text (the program only works with letters): " << endl;
	cout << "If you want to encrypt string, press 1" << endl;
	cout << "if you want to decode, press 2" << endl;

	bool Ok = false; //��������� �� ������� �������
	string text;
	int shift;
	int numberSelectedAction;
	while (!Ok)
	{
		switch (getchar())
		{
		case '1':
		{
			cout << "Input shift: ";
			cin >> shift;
			cout << "Input the text to encrypt: " << endl;
			while (cin >> text) //������� ����� � ��� �� ������� �� ������ �����
			{
				cout << CodeEnglishLanguage(text, shift) << ' ';
				if (cin.get() == '\n') break; //����������� �� ������� Enter
			}
			Ok = true; //������� ���� ������ ���������
		} break;
		case '2':
		{
			bool Done = false; //�������� �� ������� ����������
			cout << "Input string to decode: ";
			getline(cin, text); //��������� ��� ����������� ������
			shift = -1;
			text = "Alhjolyz jhu puayvkbjl huk hzzlzz huf jbyypjbshy avwpj dpao vby chza spiyhyf vm zahukhykz-hspnulk jvualua huk yhunl vm mslepisl xblzapvu afwlz.";
			while (Done == false)
			{
				shift += SearchPossibleShift(text);//����� ���������� ������ � ������� ���������� �������
				shift++; //���������� �� �������, ���� ����� ����������� �� �����
				cout << CodeEnglishLanguage(text, shift) << endl;
				cout << "If decoding is done, press 1 " << endl;
				int find;
				cin >> find;
				if (find == '1') Done = true; //������ �����������
			}
			Ok = true; //������� ���� ������ ���������
		} break;
		default: std::cout << "Press either 1 or 2!"; //����������� �������
	   //�������
		}
	}
}

/*
Teachers can introduce and assess any curricular topic
with our vast library of standards-aligned content and
range of flexible question types.
shift = 7
Alhjolyz jhu puayvkbjl huk hzzlzz huf jbyypjbshy avwpj
dpao vby chza spiyhyf vm zahukhykz-hspnulk jvualua huk
yhunl vm mslepisl xblzapvu afwlz.
*/