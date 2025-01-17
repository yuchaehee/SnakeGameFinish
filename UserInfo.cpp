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
    bool goalsCompleted[4]; // 각 목표별 달성 여부
    int infoStartX; // 정보 출력 시작 X 좌표
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
    // 현재 길이
    void setCurrentLength(const int current_length) {
        this->current_length = current_length;
    }

    // 최대 길이
    void setMaxLen(const int current_len) {
        if (current_len > max_length) {
            max_length = current_len;
        }
    }

    // 아이템 관련
    void setGrowthItem(const int current_C) {
        this->GrowthItemC = current_C;
    }
    void setPoisonItem(const int current_C) {
        this->PoisonItemC = current_C;
    }

    // 아이템 획득 메서드
    void IncreaseGetGrowthItem() {
        GrowthItemC++;
    }
    void IncreaseGetPoisonItem() {
        PoisonItemC++;
    }

    // 게이트 사용 관련
    void setGateUse(const int current_C) {
        this->GateUseC = current_C;
    }
    void IncreaseGateCount() {
        GateUseC++;
    }

    // 시간 관련
    void setTime(const int current_T) {
        this->current_Time = current_T;
    }

    // 텍스트 색상 설정
    void setColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    // 정보 출력
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

    // 미션 정보 출력
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

    // 미션 정보 출력 보조 함수
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
            setColor(10);  // 임무 완료를 나타내는 녹색으로 표시
            std::cout << "(v)\n";
        }
        else {
            if (current < goal) {
                setColor(12);  // 미완료 항목은 빨간색으로 표시
                std::cout << "( )\n";
            }
            else {
                setColor(10);  // 완료된 경우에는 초록색
                std::cout << "(v)\n";
                goalsCompleted[goalIndex] = true;
            }
        }

        setColor(7);
    }
};