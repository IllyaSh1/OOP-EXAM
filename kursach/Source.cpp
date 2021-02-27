#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

ifstream file("C://Users//38098//Desktop//kursach//words.txt");

class Gallows {
protected:
	const short game_over = 7;
	unsigned short game_end = 0;
	unsigned short lose = 0;
	bool correct = false;
	string line = " ";
	char* word = new char[15];
	char* underfiend = new char[15];
	short index = 0;
	unsigned short length = 0;
	char temp = ' ';
	char* entered_letters = new char[30];
	unsigned short tries = 0;
public:
	//Вибирання слова з текстового файла
	void random() {
		unsigned short ran_word = rand() % (20 - 1);
		char open_file[400];
		do {
			index++;
			if (index == ran_word) {
				line = open_file;
				length = line.length();
			}
			file.getline(open_file, 400);
		} while (!file.eof());
		reverse(line.begin(), line.end());//повернення слова в початковий вигляд
		for (int i = 0; i < length; i++) {
			if (i == 0) {
				word[i] = line[i];
				underfiend[i] = line[i];
			}
			else if (i == length - 1 && length > 4) {
				word[i] = line[i];
				underfiend[i] = line[i];
			}
			else {
				word[i] = line[i];
				underfiend[i] = '_';
			}
		}
	}
	//Очищення консолі, що б гра не виводилася списком
	void clean() {
		system("cls");//чистка консолі
	}
	//Гра проти комп'ютера
	void player_vs_computer() {
		for (int i = 0; i < length; i++) {
			cout << underfiend[i] << " ";
		}
		//Частина коду яка відповідає за час
		cout << endl;
		clock_t start;
		double duration;
		start = clock();
		//====================
		while (game_end == 0) {

			draw();
			correct = false;
			if (lose == game_over) {
				clean();
				for (int i = 0; i < length; i++) {
					cout << word[i] << " ";
				}
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;//time
				cout << "\nYou lose!\n";
				cout << "\nTime " << duration << " S";
				cout << "\nLetters used: ";
				for (int i = 0; i < tries; i++) {
					cout << entered_letters[i] << " ";
				}
				cout << "\nTries: " << tries << endl;
				break;
			}
			cin >> temp;
			caps();
			entered_letters[tries] = temp;
			cin.ignore(cin.rdbuf()->in_avail());//можливість введеня лише одного символа
			clean();
			for (int i = 0; i < length; i++) {
				if (temp == word[i]) {
					underfiend[i] = temp;
					correct = true;
				}
				cout << underfiend[i] << " ";
			}
			unsigned short good = 0;
			for (int i = 0; i < length; i++) {
				if (underfiend[i] != '_') {
					good++;
				}
			}
			if (good == length) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;//time
				cout << "\nYou win!";
				cout << "\nTime " << duration << " S";
				cout << "\nLetters used: ";
				for (int i = 0; i < tries + 1; i++) {
					cout << entered_letters[i] << " ";
				}
				cout << "\nTries: " << tries << endl;
				game_end = 1;
			}
			if (correct == false) {
				lose++;
			}
			cout << endl;
			tries++;
		}
	}
	//Гра проти іншого гравця
	void duel() {
		cout << "Player's 1 word --> ";
		cin >> line;
		length = line.length();
		for (int i = 0; i < length; i++) {
			line[i] = putchar(toupper(line[i]));
		}
		for (int i = 0; i < length; i++) {
			if (i == 0) {
				word[i] = line[i];
				underfiend[i] = line[i];
			}
			else if (i == length - 1 && length > 4) {
				word[i] = line[i];
				underfiend[i] = line[i];
			}
			else {
				word[i] = line[i];
				underfiend[i] = '_';
			}
		}
		clean();
		for (int i = 0; i < length; i++) {
			cout << underfiend[i] << " ";
		}
		cout << endl;
		//Частина коду яка відповідає за час
		cout << endl;
		clock_t start;
		double duration;
		start = clock();
		//====================
		while (game_end == 0) {
			draw();
			correct = false;
			if (lose == game_over) {
				clean();
				for (int i = 0; i < length; i++) {
					cout << word[i] << " ";
				}
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;//time
				cout << "\nYou lose!\n";
				cout << "\nTime " << duration << " S";
				cout << "\nLetters used: ";
				for (int i = 0; i < tries; i++) {
					cout << entered_letters[i] << " ";
				}
				cout << "\nTries: " << tries << endl;
				break;
			}
			cin >> temp;
			caps();
			entered_letters[tries] = temp;
			cin.ignore(cin.rdbuf()->in_avail());//можливість введеня лише одного символа
			clean();
			for (int i = 0; i < length; i++) {
				if (temp == word[i]) {
					underfiend[i] = temp;
					correct = true;
				}
				cout << underfiend[i] << " ";
			}
			unsigned short good = 0;
			for (int i = 0; i < length; i++) {
				if (underfiend[i] != '_') {
					good++;
				}
			}
			if (good == length) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;//time
				cout << "\nYou win!";
				cout << "\nTime " << duration << " S";
				cout << "\nLetters used: ";
				for (int i = 0; i < tries + 1; i++) {
					cout << entered_letters[i] << " ";
				}
				cout << "\nTries: " << tries << endl;
				game_end = 1;
			}
			if (correct == false) {
				lose++;
			}
			cout << endl;
			tries++;
		}
	}
	//Виведення віселиці на екран
	void draw() {

		if (lose == 1) {
			cout << "\n\n\n\n\n\n\n\n\n\n################\n";
		}
		else if (lose == 2) {
			cout << "################\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n################\n";
		}
		else if (lose == 3) {
			cout << "################\n#             |\n#             |\n#             |\n#\n#\n#\n#\n#\n#\n################\n";
		}
		else if (lose == 4) {
			cout << "################\n#             |\n#             |\n#             |\n#             0\n#\n#\n#\n#\n#\n################\n";
		}
		else if (lose == 5) {
			cout << "################\n#             |\n#             |\n#             |\n#             0\n#            / \\\n#\n#\n#\n#\n################\n";
		}
		else if (lose == 6) {
			cout << "################\n#             |\n#             |\n#             |\n#             0\n#            /|\\\n#             |\n#\n#\n#\n################\n";
		}
		else if (lose == 7) {
			cout << "################\n#             |\n#             |\n#             |\n#             0\n#            /|\\\n#             |\n#            / \\\n#\n#\n################\n";
		}
	}
	//Коніертація маленьких букв у великі
	void caps() {
		if (temp >= 97 && temp <= 122) {
			temp = temp - 32;
		}
	}
	//Очистка пам'яті
	void delete_memory() {
		delete[] word;
		delete[] underfiend;
		delete[] entered_letters;
	};
};

int main() {
	srand(unsigned(time(NULL)));


	unsigned short option = 9;
	Gallows gallows;
	cout << "=========================-GALLOWS-=========================\n";
	cout << "1. Computer vs Player\n";
	cout << "2. Player vs Player\n";
	cin >> option;
	cout << "===========================================================\n";
	if (option == 1) {
		gallows.random();
		gallows.player_vs_computer();
		gallows.draw();
		gallows.delete_memory();
	}
	else if (option == 2) {
		gallows.duel();
		gallows.draw();
		gallows.delete_memory();
	}
	else {
		cout << "Incorrect option\n";
	}
	file.close();
	return 0;
}