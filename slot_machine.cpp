#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>

using namespace std;
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
int main() {
    system("chcp 65001 > nul");
    system("mode con: cols=60 lines=30");

    const char* symbols[] = { "♥", "♦", "♣", "♠", "•", "◘", "#", "%", "@", "7"};
    int credits = 20;

    cout << "=== КРИПТО-СЛОТЫ 'САТОШИ МАЙНЕР' ===" << endl;
    cout << "Нажми Enter для вращения, Esc для выхода" << endl;

    int cooldown = 0;
    while (credits > 0) {
        setColor(11);
        cout << "\nСатоши: " << credits;
        setColor(7);
        cout << " | Вращать? (Enter/Esc): ";
        int key = _getch();
        if (key == 27) exit(0);
        if (key != 13) continue;

        credits--;
        system("cls");
        // Анимация вращения
        cout << "\nВращение:\n";
        for (int i = 0; i < 5; i++) {
            cout << "[" << symbols[rand() % 10] << "|"
                << symbols[rand() % 10] << "|" 
                << symbols[rand() % 10] << "]\r";
            Sleep(150);
        }

        int s1 = rand() % 10, s2 = rand() % 10, s3 = rand() % 10;
        cout << "[" << symbols[s1] << "|" 
            << symbols[s2] << "|" 
            << symbols[s3] << "]" << endl;

        if (s1 == s2 && s2 == s3) {
            int win = (s1 == 9) ? 100 : 20;
            credits += win;
            setColor(12);
            cout << (win == 100 ? "777 ДЖЕКПОТ! +" : "Выигрыш! +") << win << " сатоши!" << endl;
            setColor(7);
        }
        else if ((s1 == s2 || s2 == s3 || s1 == s3)&&cooldown==0) {
            if (rand() % 2 == 0) {
                credits += 5;
                setColor(10);
                cout << "Мини вин +5 сатоши" << endl;
                setColor(7);
                cooldown = 2;
            }
            else if (rand() % 2 == 1) {
                setColor(12);
                cout << "Пофиг что комбинация казино в выигрыше";
                setColor(7);
            }
        }
        else {
            cooldown = max(0, cooldown - 1);  // Уменьшаем счётчик
        }
    }

    cout << "\nGame over! Final сатоши: " << credits << endl;
    cout << "Додеп?\n (y=Да n=Нет): ";
    char dep;
    cin >> dep;
    setColor(14);
    if (dep == 'y') {
        cout << "ДОДЕПА НЕ БУДЕТ СОСАТЬ\n";

    }
    else {
        cout << "ДЕЛАЙ ПАУНС В ОКНО\n";
    }
    system("pause");
    return 0;
}