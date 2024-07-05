#include <iostream>
#include <windows.h>
#define MAPWIDTH 21
using namespace std;


class UserInfo {
private:
    int current_length;
    int max_length;
    int GrowthItemC;
    int PoisonItemC;
    int GateUseC;
    int current_Time;
    bool goalsCompleted[4]; // �� ��ǥ�� �޼� ����
    int infoStartX; // ���� ��� ���� X ��ǥ
    bool IsCompelet;

public:
    void gotoxy(int x, int y) {
        COORD pos = { x, y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    }

    UserInfo() {
        current_length = 3;
        max_length = 3;
        GrowthItemC = 0;
        PoisonItemC = 0;
        GateUseC = 0;
        current_Time = 0;
        infoStartX = MAPWIDTH * 2 + 8;
        IsCompelet = false;
        for (int i = 0; i < 4; ++i) {
            goalsCompleted[i] = false;
        }
    }
    void ReSetInfo() {
        current_length = 3;
        max_length = 3;
        GrowthItemC = 0;
        PoisonItemC = 0;
        GateUseC = 0;
        current_Time = 0;
        infoStartX = MAPWIDTH * 2 + 8;
        IsCompelet = false;
        for (int i = 0; i < 4; ++i) {
            goalsCompleted[i] = false;
        }
    }

    bool IsGoal() {
        return IsCompelet;
    }
    // ���� ����
    void setCurrentLength(const int current_length) {
        this->current_length = current_length;
    }

    // �ִ� ����
    void setMaxLen(const int current_len) {
        if (current_len > max_length) {
            max_length = current_len;
        }
    }

    // ������ ����
    void setGrowthItem(const int current_C) {
        this->GrowthItemC = current_C;
    }
    void setPoisonItem(const int current_C) {
        this->PoisonItemC = current_C;
    }

    // ������ ȹ�� �޼���
    void IncreaseGetGrowthItem() {
        GrowthItemC++;
    }
    void IncreaseGetPoisonItem() {
        PoisonItemC++;
    }

    // ����Ʈ ��� ����
    void setGateUse(const int current_C) {
        this->GateUseC = current_C;
    }
    void IncreaseGateCount() {
        GateUseC++;
    }

    // �ð� ����
    void setTime(const int current_T) {
        this->current_Time = current_T;
    }

    // �ؽ�Ʈ ���� ����
    void setColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    // ���� ���
    void ShowInfo() {
        gotoxy(infoStartX, 0);
        setColor(10);
        cout << "Score Board" << "\n";

        gotoxy(infoStartX, 1);
        setColor(10);
        cout << "B: ";
        setColor(5);
        std::cout << current_length << " / " << max_length << "\n";

        gotoxy(infoStartX, 2);
        setColor(10);
        cout << "+: ";
        setColor(5); 
        std::cout << GrowthItemC << "\n";

        gotoxy(infoStartX, 3);
        setColor(10);
        cout << "-: ";
        setColor(5);
        std::cout << PoisonItemC << "\n";

        gotoxy(infoStartX, 4);
        setColor(10);
        cout << "G: ";
        setColor(5); 
        std:cout << GateUseC << "\n";

        gotoxy(infoStartX, 5);
        setColor(10);
        cout << "Time: ";
        setColor(5); 
        std::cout << current_Time << "\n";

        setColor(7);
    }

    // �̼� ���� ���
    void Mission(int Bgoal, int Pgoal, int MinGoal, int Ggoal) {
        gotoxy(infoStartX, 9);
        setColor(6);
        cout << "Mission" << "\n";

        setColor(6);
        PrintMissionInfo("B", max_length, Bgoal, 0);
        PrintMissionInfo("+", GrowthItemC, Pgoal, 1);
        PrintMissionInfo("-", PoisonItemC, MinGoal, 2);
        PrintMissionInfo("G", GateUseC, Ggoal, 3);

        IsCompelet = true;
        for (int i = 0; i < 4; ++i) {
            if (!goalsCompleted[i]) {
                IsCompelet = false;
                break;
            }
        }

        setColor(7);
    }

private:

    // �̼� ���� ��� ���� �Լ�
    int GetYPosition(const string& label) {
        if (label == "B") return 10;
        else if (label == "+") return 11;
        else if (label == "-") return 12;
        else if (label == "G") return 13;
        else return -1;
    }

    void PrintMissionInfo(const string& label, int current, int goal, int goalIndex) {
        gotoxy(MAPWIDTH * 2 + 8, GetYPosition(label));

        setColor(6);
        cout << label << ": " << goal << " ";

        if (goalsCompleted[goalIndex]) {
            setColor(10);  // �ӹ� �ϷḦ ��Ÿ���� ������� ǥ��
            std::cout << "(v)\n";
        }
        else {
            if (current < goal) {
                setColor(12);  // �̿Ϸ� �׸��� ���������� ǥ��
                std::cout << "( )\n";
            }
            else {
                setColor(10);  // �Ϸ�� ��쿡�� �ʷϻ�
                std::cout << "(v)\n";
                goalsCompleted[goalIndex] = true;
            }
        }

        setColor(7);
    }
};