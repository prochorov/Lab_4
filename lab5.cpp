#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;


void taskOne() {
    int inputs[10];
    cout << "--- Задание №1 ---" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Введите число №" << i + 1 << ": ";
        cin >> inputs[i];
    }
    cout << "\nРезультат:\n\n";
    cout << "|---------------------------|" << endl;
    cout << "|    oct |    dec |     hex |" << endl;
    cout << "|---------------------------|" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "|" << oct << setw(7) << inputs[i] << " |";
        cout << dec << setw(7) << inputs[i] << " |";
        cout << hex << setw(7) << inputs[i] << "  |" << endl;
        cout << "|---------------------------|" << endl;
    }
}


void taskTwo(int scale) {
    cout << "--- Задание №2 ---" << endl;
    string type;
    cout << "Результат:\n\n";
    cout << '|' << string(34, '-') << '|' << endl;
    for (int row = 1; row < 8; row++) {
        cout << '|';
        for (int col = 1; col < 8; col++) {
            if (scale == 16) {
                cout << hex << setw(3) << row * col << " |";
            }
            else if (scale == 8) {
                cout << oct << setw(3) << row * col << " |";
            }
            else {
                cout << setw(3) << row * col << " |";
            }
        }
        cout << "\n";
        cout << '|' << string(34, '-') << '|' << endl;
    }
}


void taskThree() {
    cout << "--- Задание №3 ---" << endl;
    string s;
    long double sum = 0;
    int count = 0;
    std::ifstream in;
    in.open("D:/институт/Языки программирования/Lab_5/data_v14.txt");

    for (in >> s; !in.eof(); in >> s) {
        count++;
        sum += stod(s);
    }
    cout << "Cреднее арифметическое равно: " << setprecision(10) << (float)sum / count << endl;
}


void taskFour() {
    cout << "--- Задание №4 ---" << endl;
    string line;

    ifstream in;
    in.open("D:/институт/Языки программирования/Lab_5/4.txt");

    ofstream out;
    out.open("D:/институт/Языки программирования/Lab_5/4_1.txt", ios::app);
    out << endl;
    while (getline(in, line)) {
        out << line << endl;
    }

    out.close();
    in.close();
    cout << "Задание выполнено.";
}


void taskFive() {
    cout << "--- Задание №5 ---" << endl;
    ofstream out;
    out.open("D:/lab5/data_v14_res.bin", ios::binary | ios::out);

    double* data = new double[3 * 224 * 224];
    ifstream inF("D:/lab5/data_v14.bin", ios::binary);
    inF.read((char*)data, sizeof(double) * (3 * 224 * 224));
    inF.close();
    int i = 0;
    float res;
    while (data[i] != 0) {

        if (data[i] != 0) {

            cout << i << ": " << data[i] << endl;
            res = 1 / data[i];
            out.write((char*)&res, sizeof(float));
        }
        i++;
    }
    out.close();
    cout << "Программа выполнена.";
}


int main() {
    setlocale(LC_ALL, "Russian");
    //taskOne();
    //taskTwo(8);
    //taskThree();
    //taskFour();
    taskFive();
    return 0;
}
