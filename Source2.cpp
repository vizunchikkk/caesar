#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

const int SizeEnglishAlphabet = 26; //Размер алфавита

const char LowercaseEnglishLetters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }; //массив строчных букв
const char UppercaseEnglishLetters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' }; //массив заглавных букв

//Функция осуществляет сдвиг строки по алфавиту на указанную величину
string CodeEnglishLanguage(string& text, const int shift)
{
	bool Ok; //Был ли символ определен как буква алфавита и затем зашифрован
	string output_s(""); //Зашифрованная строка, вначале инициализируется пустой строкой
	for (unsigned i = 0; i < text.length(); i++)
	{
		Ok = false;
		//Перебираем все буквы алфавита на поиск соответствия
		for (int j = 0; j < SizeEnglishAlphabet; j++)
		{
			if (text[i] == LowercaseEnglishLetters[j]) //Если символ оказался строчной буквой алфавита
			{
				j += shift; //Сдвигаем букву по алфавиту на указанное значение
				while (j >= SizeEnglishAlphabet) 
					j -= SizeEnglishAlphabet; //Если значение вышло за диапазон,
				while (j < 0) 
					j += SizeEnglishAlphabet; //корректируем его
				output_s += LowercaseEnglishLetters[j]; //Добавляем полученный символ в конец
														//зашифрованной строки
				Ok = true; //Символ был благополучно зашифрован и добавлен в строку
				break; //Перебор для данного символа можно закончить
			}
			else if (text[i] == UppercaseEnglishLetters[j]) //То же самое, если символ оказался
															//çàãëàâíîé áóêâîé àëôàâèòà
			{
				j += shift;
				if (j >= SizeEnglishAlphabet) 
					j -= SizeEnglishAlphabet;
				else if (j < 0) 
					j += SizeEnglishAlphabet;
				output_s += UppercaseEnglishLetters[j];
				Ok = true;
				break;
			}
		}
		if (!Ok) output_s += text[i]; //Если символ не является буквой алфавита,
										//записываем его без изменений
	}
	return output_s; //По окончании возвращаем получившуюся строку
}

int main()
{
	cout << "Enter the text (the program only works with letters): " << endl;
	cout << "If you want to encrypt string, press 1" << endl;
	cout << "if you want to decode, press 2" << endl;

	bool Ok = false; //Корректно ли нажатая клавиша
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
			while (cin >> text) //Шифруем одним и тем же сдвигом по одному слову
			{
				cout << CodeEnglishLanguage(text, shift) << ' ';
				if (cin.get() == '\n') 
					break;//Заканчиваем по нажатию Enter
			}
			Ok = true; //Клавиша была нажата корректно
		} break;
		case '2':
		{
			bool Done = false; //Завершен ли процесс дешифровки
			cout << "Input string to decode: ";
			getline(cin, text); //Считываем всю дешифруемую строку
			//строка внизу для проверки декодирования(почему-то getline не хочет принимать строку)
			//text = "Alhjolyz jhu puayvkbjl huk hzzlzz huf jbyypjbshy avwpj dpao vby chza spiyhyf vm zahukhykz-hspnulk jvualua huk yhunl vm mslepisl xblzapvu afwlz.";
			for (int i = 0; i < SizeEnglishAlphabet && !Done; i++) //Пробуем разные величины сдвига
		  //до тех пор, пока не расшифруем или не проверим все возможные его значения
			{
				cout << endl << "With shift equal " << i << " we have such string:" << endl;
				cout << CodeEnglishLanguage(text, i) << endl;
				cout << "If decoding is done, press 1 " << endl;
				int find;
				cin >> find;
				if (find == '1')
					Done = true; //Строка дешифрована
			}
			Ok = true;//Клавиша была нажата корректно
		} break;
		default:
			cout << "Press either 1 or 2!"; //Некорректно нажатая
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
