#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

const int SizeEnglishAlphabet = 26; //Размер алфавита

const char LowercaseEnglishLetters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }; //массив строчных букв
const char UppercaseEnglishLetters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' }; //массив заглавных букв

//Ôóíêöèÿ îñóùåñòâëÿåò ñäâèã ñòðîêè ïî àëôàâèòó íà óêàçàííóþ âåëè÷èíó
string CodeEnglishLanguage(string& text, const int shift)
{
	bool Ok; //Áûë ëè ñèìâîë îïðåäåëåí êàê áóêâà àëôàâèòà è çàòåì çàøèôðîâàí
	string output_s(""); //Çàøèôðîâàííàÿ ñòðîêà, âíà÷àëå èíèöèàëèçèðóåòñÿ ïóñòîé ñòðîêîé
	for (unsigned i = 0; i < text.length(); i++)
	{
		Ok = false;
		for (int j = 0; j < SizeEnglishAlphabet; j++)
		{ //Ïåðåáèðàåì âñå áóêâû àëôàâèòà íà ïîèñê ñîîòâåòñòâèÿ
			if (text[i] == LowercaseEnglishLetters[j]) //Åñëè ñèìâîë îêàçàëñÿ ñòðî÷íîé áóêâîé àëôàâèòà
			{
				j += shift; //Ñäâèãàåì áóêâó ïî àëôàâèòó íà óêàçàííîå çíà÷åíèå
				while (j >= SizeEnglishAlphabet) j -= SizeEnglishAlphabet; //Åñëè çíà÷åíèå âûøëî çà äèàïàçîí,
				while (j < 0) j += SizeEnglishAlphabet; //êîððåêòèðóåì åãî
				output_s += LowercaseEnglishLetters[j]; //Äîáàâëÿåì ïîëó÷åííûé ñèìâîë â êîíåö
														//çàøèôðîâàííîé ñòðîêè
				Ok = true; //Ñèìâîë áûë áëàãîïîëó÷íî çàøèôðîâàí è äîáàâëåí â ñòðîêó
				break; //Ïåðåáîð äëÿ äàííîãî ñèìâîëà ìîæíî çàêîí÷èòü
			}
			else if (text[i] == UppercaseEnglishLetters[j]) //Òî æå ñàìîå, åñëè ñèìâîë îêàçàëñÿ
															//çàãëàâíîé áóêâîé àëôàâèòà
			{
				j += shift;
				if (j >= SizeEnglishAlphabet) j -= SizeEnglishAlphabet;
				else if (j < 0) j += SizeEnglishAlphabet;
				output_s += UppercaseEnglishLetters[j];
				Ok = true;
				break;
			}
		}
		if (!Ok) output_s += text[i]; //Åñëè ñèìâîë íå ÿâëÿåòñÿ áóêâîé àëôàâèòà,
										//çàïèñûâàåì åãî áåç èçìåíåíèé
	}
	return output_s; //Ïî îêîí÷àíèè âîçâðàùàåì ïîëó÷èâøóþñÿ ñòðîêó
}

int main()
{
	cout << "Enter the text (the program only works with letters): " << endl;
	cout << "If you want to encrypt string, press 1" << endl;
	cout << "if you want to decode, press 2" << endl;

	bool Ok = false; //Êîððåêòíà ëè íàæàòàÿ êëàâèøà
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
			while (cin >> text) //Øèôðóåì îäíèì è òåì æå ñäâèãîì ïî îäíîìó ñëîâó
			{
				cout << CodeEnglishLanguage(text, shift) << ' ';
				if (cin.get() == '\n') break; //Çàêàí÷èâàåì ïî íàæàòèþ Enter
			}
			Ok = true; //Êëàâèøà áûëà íàæàòà êîððåêòíî
		} break;
		case '2':
		{
			bool Done = false; //Çàâåðøåí ëè ïðîöåññ äåøèôðîâêè
			cout << "Input string to decode: ";
			getline(cin, text); //Ñ÷èòûâàåì âñþ äåøèôðóåìóþ ñòðîêó
			//text = "Alhjolyz jhu puayvkbjl huk hzzlzz huf jbyypjbshy avwpj dpao vby chza spiyhyf vm zahukhykz-hspnulk jvualua huk yhunl vm mslepisl xblzapvu afwlz.";
			for (int i = 0; i < SizeEnglishAlphabet && !Done; i++) //Ïðîáóåì ðàçíûå âåëè÷èíû ñäâèãà
		  //äî òåõ ïîð, ïîêà íå ðàñøèôðóåì èëè íå ïðîâåðèì âñå âîçìîæíûå åãî çíà÷åíèÿ
			{
				cout << endl << "With shift equal " << i << " we have such string:" << endl;
				cout << CodeEnglishLanguage(text, i) << endl;
				cout << "If decoding is done, press 1 " << endl;
				int find;
				cin >> find;
				if (find == '1') Done = true; //Ñòðîêà äåøèôðîâàíà
			}
			Ok = true; //Êëàâèøà áûëà íàæàòà êîððåêòíî
		} break;
		default: std::cout << "Press either 1 or 2!"; //Íåêîððåêòíî íàæàòàÿ
	   //êëàâèøà
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
