#include "HistoryMatch.h"
#include <iostream>
#include <iomanip>
using namespace std;

HistoryMatch::HistoryMatch()
{
}
HistoryMatch::HistoryMatch(Match m, int g1, int g2)
    : Match(m)
{
    this->numGoalTeam1 = g1;
    this->numGoalTeam2 = g2;
}
HistoryMatch::~HistoryMatch()
{
}

void HistoryMatch::showHistoryMatch()
{
    ifstream file("HistoryMatch.txt");
    String tmp;
    String::getline(file, tmp);
    cout << left << setw(7) << "Vong" << setw(10) << "ID doi 1" << setw(17) << "Ten doi 1" << setw(17) << "Ban thang doi 1" << setw(12) << "ID doi 2" << setw(17) << "Ten doi 2" << setw(17) << "Ban thang doi 2" << setw(17) << "Thoi gian" << setw(20) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
        {
            break;
        }
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        Team t;
        String n1, n2;
        n1 = t.nameTeambyId(id1);
        n2 = t.nameTeambyId(id2);
        cout << left << setw(7) << idr << setw(10) << id1 << setw(17) << n1 << setw(17) << goal1 << setw(12) << id2 << setw(17) << n2 << setw(17) << goal2 << setw(17) << time << setw(20) << date << setw(20) << address << endl;
        // cout << idr << ", " << id1 << ", " << goal1 << ", " << id2 << "," << goal2 << "," << time << ", " << date << ", " << address << endl;
    }
    // system("cls");
    // Team t, t1, t2;
    // t1 = t.getTeamById(this->getIdTeam1());
    // t2 = t.getTeamById(this->getIdTeam2());
    // cout << "QUAN LY GIAI DAU/Truy van thong tin lich su tran dau" << endl
    //      << endl;
    // cout << "Vong dau so: " << this->getIdRound() << endl;
    // cout << left << setw(30) << t1.getNameFootballTeam() << setw(15) << this->numGoalTeam1 << setw(15) << "-" << setw(50) << this->numGoalTeam2 << t2.getNameFootballTeam() << endl;
    // cout << "Ngay thi dau: " << this->getDate() << endl;
    // cout << "Dia chi thi dau: " << this->getAddress() << endl;
    // getchar();
}

void HistoryMatch::saveHistoryMatchToFile(ofstream &o)
{
    ifstream f("HistoryMatch.txt");
    f.seekg(0, ios::end);
    if (f.tellg() == 0)
    {
        o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem";
        f.close();
    }
    if (o.is_open())
    {
        o << endl
          << left << setw(15) << this->getIdRound() + "," << setw(20) << this->getIdTeam1() + "," << setw(20) << String::tostring(this->numGoalTeam1) + "," << setw(20) << this->getIdTeam2() + "," << setw(20) << String::tostring(this->numGoalTeam2) + "," << setw(20) << this->getTime() + "," << setw(25) << this->getDate() + "," << setw(20) << this->getAddress();
    }
}

void HistoryMatch::updateGoalandLostGoalandDiffofTeam(String ma, String goal, String lostgoal, String diff)
{
    system("cls");
    fstream file("Team.txt", ios::in);
    fstream tempFile("tempTeam.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String id, nameTeam, numMember, nameCoach, numberGoal, numberLoseGoal, difference, point, rank;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    nameTeam = nameTeam + tmp[i];
                else if (check == 3 && status)
                    numMember = numMember + tmp[i];
                else if (check == 4 && status)
                    nameCoach = nameCoach + tmp[i];
                else if (check == 5 && status)
                    numberGoal = numberGoal + tmp[i];
                else if (check == 6 && status)
                    numberLoseGoal = numberLoseGoal + tmp[i];
                else if (check == 7 && status)
                    difference = difference + tmp[i];
                else if (check == 8 && status)
                    point = point + tmp[i];
                else if (check == 9 && status && tmp[i] != '\n')
                {
                    rank = rank + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (ma == id)
            {
                numberGoal = goal;
                numberLoseGoal = lostgoal;
                difference = diff;
                tempFile << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(15) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
            }
            else
            {
                tempFile << tmp << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("Team.txt");
        rename("tempTeam.txt", "Team.txt");
    }
    else
        cout << "Khong mo dc file";
}

String HistoryMatch::getGoal(String ma)
{
    ifstream file("Team.txt");
    String tmp;
    String notf = "Khong tim thay";
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String id, nameTeam, numMember, nameCoach, numberGoal, numberLoseGoal, difference, point, rank;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                id = id + tmp[i];
            else if (check == 2 && status)
                nameTeam = nameTeam + tmp[i];
            else if (check == 3 && status)
                numMember = numMember + tmp[i];
            else if (check == 4 && status)
                nameCoach = nameCoach + tmp[i];
            else if (check == 5 && status)
                numberGoal = numberGoal + tmp[i];
            else if (check == 6 && status)
                numberLoseGoal = numberLoseGoal + tmp[i];
            else if (check == 7 && status)
                difference = difference + tmp[i];
            else if (check == 8 && status)
                point = point + tmp[i];
            else if (check == 9 && status && tmp[i] != '\n')
            {
                rank = rank + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (ma == id)
        {
            file.close();
            return numberGoal;
        }
    }
    file.close();
    return notf;
}

String HistoryMatch::getLostGoal(String ma)
{
    ifstream file("Team.txt");
    String tmp;
    String notf = "Khong tim thay";
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String id, nameTeam, numMember, nameCoach, numberGoal, numberLoseGoal, difference, point, rank;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                id = id + tmp[i];
            else if (check == 2 && status)
                nameTeam = nameTeam + tmp[i];
            else if (check == 3 && status)
                numMember = numMember + tmp[i];
            else if (check == 4 && status)
                nameCoach = nameCoach + tmp[i];
            else if (check == 5 && status)
                numberGoal = numberGoal + tmp[i];
            else if (check == 6 && status)
                numberLoseGoal = numberLoseGoal + tmp[i];
            else if (check == 7 && status)
                difference = difference + tmp[i];
            else if (check == 8 && status)
                point = point + tmp[i];
            else if (check == 9 && status && tmp[i] != '\n')
            {
                rank = rank + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (ma == id)
        {
            file.close();
            return numberLoseGoal;
        }
    }
    file.close();
    return notf;
}

void HistoryMatch::updatePoint(String ma, String diem)
{
    system("cls");
    fstream file("Team.txt", ios::in);
    fstream tempFile("tempTeam.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String id, nameTeam, numMember, nameCoach, numberGoal, numberLoseGoal, difference, point, rank;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    nameTeam = nameTeam + tmp[i];
                else if (check == 3 && status)
                    numMember = numMember + tmp[i];
                else if (check == 4 && status)
                    nameCoach = nameCoach + tmp[i];
                else if (check == 5 && status)
                    numberGoal = numberGoal + tmp[i];
                else if (check == 6 && status)
                    numberLoseGoal = numberLoseGoal + tmp[i];
                else if (check == 7 && status)
                    difference = difference + tmp[i];
                else if (check == 8 && status)
                    point = point + tmp[i];
                else if (check == 9 && status && tmp[i] != '\n')
                {
                    rank = rank + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (ma == id)
            {
                point = diem;
                tempFile << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(15) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
            }
            else
            {
                tempFile << tmp << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("Team.txt");
        rename("tempTeam.txt", "Team.txt");
    }
    else
        cout << "Khong mo dc file";
}

String HistoryMatch::getPoint(String ma)
{
    ifstream file("Team.txt");
    String tmp;
    String notf = "Khong tim thay";
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String id, nameTeam, numMember, nameCoach, numberGoal, numberLoseGoal, difference, point, rank;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                id = id + tmp[i];
            else if (check == 2 && status)
                nameTeam = nameTeam + tmp[i];
            else if (check == 3 && status)
                numMember = numMember + tmp[i];
            else if (check == 4 && status)
                nameCoach = nameCoach + tmp[i];
            else if (check == 5 && status)
                numberGoal = numberGoal + tmp[i];
            else if (check == 6 && status)
                numberLoseGoal = numberLoseGoal + tmp[i];
            else if (check == 7 && status)
                difference = difference + tmp[i];
            else if (check == 8 && status)
                point = point + tmp[i];
            else if (check == 9 && status && tmp[i] != '\n')
            {
                rank = rank + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (ma == id)
        {
            file.close();
            return point;
        }
    }
    file.close();
    return notf;
}

String HistoryMatch::getbanthangbyPlayertxt(String ma)
{
    ifstream i("Player.txt");
    String notf = "Khong tim thay";
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }

            if (ma == id)
            {
                i.close();
                return goal;
            }
        }
    }
    i.close();
    return notf;
}

String HistoryMatch::getgoalSavePlayer(String idv, String idct)
{
    ifstream sp("SavePlayer.txt");
    String notf = "Khong tim thay";
    if (sp.is_open())
    {
        String tmp;
        String::getline(sp, tmp);
        while (!sp.eof())
        {
            String::getline(sp, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String idround, idteam, tenteam, idplayer, banthangg;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    idround = idround + tmp[i];
                else if (check == 2 && status)
                    idteam = idteam + tmp[i];
                else if (check == 3 && status)
                    tenteam = tenteam + tmp[i];
                else if (check == 4 && status)
                    idplayer = idplayer + tmp[i];
                else if (check == 5 && status && tmp[i] != '\n')
                {
                    banthangg = banthangg + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idv == idround && idct == idplayer)
            {
                sp.close();
                return banthangg;
            }
        }
    }
    sp.close();
    return notf;
}

void HistoryMatch::editSavePlayer(String idv, String idct, String Goal)
{
    fstream file("SavePlayer.txt", ios::in);
    fstream tempFile("tempSavePlayer.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "IDV," << setw(10) << "ID Doi," << setw(15) << "Ten doi," << setw(10) << "ID CT," << setw(10) << "Goal" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String idround, idteam, tenteam, idplayer, banthangg;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    idround = idround + tmp[i];
                else if (check == 2 && status)
                    idteam = idteam + tmp[i];
                else if (check == 3 && status)
                    tenteam = tenteam + tmp[i];
                else if (check == 4 && status)
                    idplayer = idplayer + tmp[i];
                else if (check == 5 && status && tmp[i] != '\n')
                {
                    banthangg = banthangg + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idv == idround && idct == idplayer)
            {
                banthangg = Goal;
                tempFile << left << setw(10) << idround + "," << setw(10) << idteam + "," << setw(15) << tenteam + "," << setw(10) << idplayer + "," << setw(10) << banthangg << endl;
            }
            else
                tempFile << tmp << endl;
        }
        file.close();
        tempFile.close();
        remove("SavePlayer.txt");
        rename("tempSavePlayer.txt", "SavePlayer.txt");
    }
    else
        cout << "Khong mo dc file";
}

void HistoryMatch::editGoalPlayertxt(String idct, String Goal)
{
    fstream file("Player.txt", ios::in);
    fstream tempFile("tempPlayer.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idct == id)
            {
                goal = Goal;
                tempFile << left << setw(10) << id + "," << setw(15) << name + "," << setw(15) << date + "," << setw(20) << address + "," << setw(10) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(10) << redCard + "," << setw(10) << goal + "," << setw(20) << nameTeam << endl;
            }
            else
                tempFile << tmp << endl;
        }
        file.close();
        tempFile.close();
        remove("Player.txt");
        rename("tempPlayer.txt", "Player.txt");
    }
    else
        cout << "Khong mo dc file";
}

void HistoryMatch::entergoal(String idvong, String id1, String id2, int g1, int g2)
{
    const int maxplayer = 100;
    int goalsByPlayer[maxplayer][2];
    for (int i = 0; i < maxplayer; ++i)
    {
        goalsByPlayer[i][0] = 0;
        goalsByPlayer[i][1] = 0;
    }
    String name1 = returnNameTeamByID(id1);
    String name2 = returnNameTeamByID(id2);
    String idm, idh, goal1, goal2;
    cout << "Danh sach cau thu cua doi bong co ID la " << id1 << " (" << name1 << ")" << endl;
    showPlayerofTeam(name1);
    cout << endl;
    cout << "Danh sach cau thu cua doi bong co ID la " << id2 << " (" << name2 << ")" << endl;
    showPlayerofTeam(name2);
    int kiemtra = 0;
    int sum = g1 + g2;
    int dem1 = 0, dem2 = 0;
    cout << "Luu y: So ban thang cho tung cau thu phai bang tong so ban thang cua 2 doi da ghi ban trong tran dau!" << endl;
    int goal1Int, goal2Int;
    ofstream f("SavePlayer.txt", std::ios::app);
    do
    {
        if (g1 > 0 && dem1 < g1)
        {
            do
            {
                cout << "Nhap ID cau thu ghi ban cho doi " << name1 << ": ";
                String::getline(cin, idm);
                if (checkidPlayerofTeam(id1, idm))
                {
                    cout << "Nhap lai so ban thang (toi da " << g1 - dem1 << " ban): ";
                    String::getline(cin, goal1);
                    goal1Int = String::toint(goal1);

                    if (goal1Int <= g1 - dem1 && goal1Int >= 0)
                    {
                        dem1 += goal1Int;
                        kiemtra += goal1Int;
                        goalsByPlayer[String::toint(idm)][0] += goal1Int;
                        // goalsByPlayer[{id1, idm}] += goal1Int;
                    }
                    else
                    {
                        cout << "So ban thang nhap vao khong hop le. Vui long nhap lai." << endl;
                    }
                }
                else
                {
                    cout << "Cau thu co ID " << idm << " khong ton tai trong doi bong " << name1 << ". Vui long nhap lai." << endl;
                }
            } while (!checkidPlayerofTeam(id1, idm));
        }

        if (g2 > 0 && dem2 < g2)
        {
            do
            {
                cout << "Nhap ID cau thu ghi ban cho doi " << name2 << ": ";
                String::getline(cin, idh);
                if (checkidPlayerofTeam(id2, idh))
                {
                    cout << "Nhap lai so ban thang (toi da " << g2 - dem2 << " ban): ";
                    String::getline(cin, goal2);
                    goal2Int = String::toint(goal2);

                    if (goal2Int <= g2 - dem2 && goal2Int >= 0)
                    {
                        dem2 += goal2Int;
                        kiemtra += goal2Int;
                        goalsByPlayer[String::toint(idh)][1] += goal2Int;
                        // goalsByPlayer[{id2, idh}] += goal2Int;
                    }
                    else
                    {
                        cout << "So ban thang nhap vao khong hop le. Vui long nhap lai." << endl;
                    }
                }
                else
                {
                    cout << "Cau thu co ID " << idh << " khong ton tai trong doi bong " << name2 << ". Vui long nhap lai." << endl;
                }
            } while (!checkidPlayerofTeam(id2, idh));
        }
    } while (kiemtra != sum);
    for (int i = 0; i < maxplayer; ++i)
    {
        if (goalsByPlayer[i][0] > 0 || goalsByPlayer[i][1] > 0)
        {
            int m = max(goalsByPlayer[i][0], goalsByPlayer[i][1]);
            int result = String::toint(getbanthangbyPlayertxt(String::tostring(i))) - String::toint(getgoalSavePlayer(idvong, String::tostring(i))) + m;
            // cout << String::toint(getbanthangbyPlayertxt(String::tostring(i))) << " " << String::toint(getgoalSavePlayer(idvong, String::tostring(i))) << " " << m  << " " << result << endl;
            // editGoalPlayertxt(String::tostring(i), String::tostring(m));
            Player::updatePlayerAfterMatch(String::tostring(i), 0, 0, result - String::toint(getbanthangbyPlayertxt(String::tostring(i))));
            // cout << i << " " << m << endl;
            editSavePlayer(idvong, String::tostring(i), String::tostring(m)); // loi khi bo trong for
        }
    }
    Player::sortAllPlayer();
}

void HistoryMatch::updateHistoryMatch()
{
    bool kt = true;
    String idvong, idm, idh;
    showHistoryMatch();
    cout << "Nhap ID vong dau: ";
    String::getline(cin, idvong);
    cout << "Nhap ID doi thu nhat: ";
    String::getline(cin, idm);
    cout << "Nhap ID doi thu hai: ";
    String::getline(cin, idh);
    fstream file("HistoryMatch.txt", ios::in);
    fstream tempFile("tempHistoryMatch.txt", ios::out | ios::app);
    tempFile << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String idr, id1, goal1, id2, goal2, time, date, address;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    idr = idr + tmp[i];
                else if (check == 2 && status)
                    id1 = id1 + tmp[i];
                else if (check == 3 && status)
                    goal1 = goal1 + tmp[i];
                else if (check == 4 && status)
                    id2 = id2 + tmp[i];
                else if (check == 5 && status)
                    goal2 = goal2 + tmp[i];
                else if (check == 6 && status)
                    time = time + tmp[i];
                else if (check == 7 && status)
                    date = date + tmp[i];
                else if (check == 8 && status && tmp[i] != '\n')
                {
                    address = address + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idvong == idr && idm == id1 && idh == id2)
            {
                kt = false;
                int lc;
                do
                {
                    system("cls");
                    String banthang1, banthang2;
                    Team t;
                    int intgoal1 = String::toint(goal1);
                    int intgoal2 = String::toint(goal2);
                    cout << "QUAN LY GIAI DAU/Cap nhat thong tin lich su tran dau" << endl
                         << endl;
                    cout << "1. Chinh sua ti so cua 2 doi." << endl;
                    cout << "0. Thoat." << endl;
                    cout << "Xin moi nhap lua chon: ";
                    cin >> lc;
                    cin.ignore();
                    if (lc == 1)
                    {
                        system("cls");
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin lich su tran dau/Chinh sua ti so cua 2 doi" << endl
                             << endl;
                        cout << "Nhap ban thang doi thu nhat: ";
                        String::getline(cin, banthang1);
                        cout << "Nhap ban thang doi thu hai: ";
                        String::getline(cin, banthang2);
                        // cin.ignore();
                        int intbanthang1 = String::toint(banthang1);
                        int intbanthang2 = String::toint(banthang2);
                        entergoal(idvong, idm, idh, intbanthang1, intbanthang2);
                        if (intgoal1 > intgoal2)
                        {
                            if (intbanthang1 > intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                            }
                            else if (intbanthang1 < intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) - 3;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) + 3;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                            else if (intbanthang1 == intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) - 2;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) + 1;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                        }
                        else if (intgoal1 < intgoal2)
                        {
                            if (intbanthang1 > intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) + 3;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) - 3;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                            else if (intbanthang1 < intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                            }
                            else if (intbanthang1 == intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) + 1;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) - 2;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                        }
                        else if (intgoal1 == intgoal2)
                        {
                            if (intbanthang1 > intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) + 2;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) - 1;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                            else if (intbanthang1 < intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) - 1;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) + 2;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                            else if (intbanthang1 == intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                            }
                        }
                        goal1 = banthang1;
                        goal2 = banthang2;
                    }
                } while (lc != 0);
                tempFile << left << setw(15) << idr + "," << setw(20) << id1 + "," << setw(20) << goal1 + "," << setw(20) << id2 + "," << setw(20) << goal2 + "," << setw(20) << time + "," << setw(25) << date + "," << setw(20) << address << endl;
            }
            else
            {
                tempFile << tmp << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("HistoryMatch.txt");
        rename("tempHistoryMatch.txt", "HistoryMatch.txt");
    }
    else
        cout << "Khong mo duoc file";
    if (kt)
        cout << "Khong tim thay tran dau nao!" << endl;
    else
        cout << "Cap nhat thong tin thanh cong!" << endl;
}

void HistoryMatch::showdateHM()
{
    ifstream file("HistoryMatch.txt");
    String tmp;
    String kt = " ";
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (kt != date)
        {
            cout << date << ", ";
            kt = date;
        }
    }
    file.close();
}

/* void HistoryMatch::showidHM()
{
    const int maxx = 100;
    String uniqueTeamIds[maxx][2];
    ifstream file("HistoryMatch.txt");
    String tmp;
    String kt = " ";
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        bool id1Exists = false;
        bool id2Exists = false;
        for (int i = 0; i < maxx; i++)
        {
            if (uniqueTeamIds[i][0] == id1)
            {
                id1Exists = true;
                break;
            }
            if (uniqueTeamIds[i][1] == id2)
            {
                id2Exists = true;
                break;
            }
            if (uniqueTeamIds[i][0].empty())
            {
                uniqueTeamIds[i][0] = id1;
                break;
            }
            if (uniqueTeamIds[i][1].empty())
            {
                uniqueTeamIds[i][1] = id2;
                break;
            }
        }
        if (!id1Exists)
        {
            cout << id1 << ", ";
        }
        if (!id2Exists)
        {
            cout << id2 << ", ";
        }
    }
    file.close();
} */

void HistoryMatch::showidvongHM()
{
    ifstream file("HistoryMatch.txt");
    String tmp;
    String kt = " ";
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (kt != idr)
        {
            cout << idr << ", ";
            kt = idr;
        }
    }
    file.close();    
}

void HistoryMatch::showHMbydate(String ntn)
{
    bool kq = true;
    ifstream file("HistoryMatch.txt");
    String tmp;
    String::getline(file, tmp);
    int kt = 1;
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (ntn == date)
        {
            if (kt == 1)
            {
                cout << left << setw(10) << "Vong" << setw(15) << "ID doi 1" << setw(20) << "Ten doi 1" << setw(20) << "Ban thang doi 1" << setw(15) << "ID doi 2" << setw(20) << "Ten doi 2" << setw(20) << "Ban thang doi 2" << setw(12) << "Thoi gian" << setw(20) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
                kt++;
            }
            // cout << check;
            kq = false;
            Team t;
            String n1, n2;
            n1 = t.nameTeambyId(id1);
            n2 = t.nameTeambyId(id2);
            cout << left << setw(10) << idr << setw(15) << id1 << setw(20) << n1 << setw(20) << goal1 << setw(15) << id2 << setw(20) << n2 << setw(20) << goal2 << setw(12) << time << setw(20) << date << setw(20) << address << endl;
        }
    }
    if (kq)
        cout << "Khong tim thay!" << endl;
}

void HistoryMatch::showHMbyidoneteam(String ma)
{
    bool kq = true;
    int kt = 1;
    ifstream file("HistoryMatch.txt");
    String tmp;
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (ma == id1 || ma == id2)
        {
            if (kt == 1)
            {
                cout << left << setw(10) << "Vong" << setw(15) << "ID doi 1" << setw(20) << "Ten doi 1" << setw(20) << "Ban thang doi 1" << setw(15) << "ID doi 2" << setw(20) << "Ten doi 2" << setw(20) << "Ban thang doi 2" << setw(12) << "Thoi gian" << setw(20) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
                kt++;
            }
            kq = false;
            Team t;
            String n1, n2;
            n1 = t.nameTeambyId(id1);
            n2 = t.nameTeambyId(id2);
            cout << left << setw(10) << idr << setw(15) << id1 << setw(20) << n1 << setw(20) << goal1 << setw(15) << id2 << setw(20) << n2 << setw(20) << goal2 << setw(12) << time << setw(20) << date << setw(20) << address << endl;
        }
    }
    if (kq)
        cout << "Khong tim thay!" << endl;
}

void HistoryMatch::showHMbyidtwoteam(String ma1, String ma2)
{
    bool kq = true;
    ifstream file("HistoryMatch.txt");
    String tmp;
    int kt = 1;
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if ((ma1 == id1 && ma2 == id2) || (ma2 == id1 && ma1 == id2))
        {
            if (kt == 1)
            {
                cout << left << setw(10) << "Vong" << setw(15) << "ID doi 1" << setw(20) << "Ten doi 1" << setw(20) << "Ban thang doi 1" << setw(15) << "ID doi 2" << setw(20) << "Ten doi 2" << setw(20) << "Ban thang doi 2" << setw(12) << "Thoi gian" << setw(20) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
                kt++;
            }
            kq = false;
            Team t;
            String n1, n2;
            n1 = t.nameTeambyId(id1);
            n2 = t.nameTeambyId(id2);
            cout << left << setw(10) << idr << setw(15) << id1 << setw(20) << n1 << setw(20) << goal1 << setw(15) << id2 << setw(20) << n2 << setw(20) << goal2 << setw(12) << time << setw(20) << date << setw(20) << address << endl;
        }
    }
    if (kq)
        cout << "Khong tim thay!" << endl;
}

void HistoryMatch::showHMbyidround(String idvong)
{
    bool kq = true;
    int kt = 1;
    ifstream file("HistoryMatch.txt");
    String tmp;
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (idvong == idr)
        {
            if (kt == 1)
            {
                cout << left << setw(10) << "Vong" << setw(15) << "ID doi 1" << setw(20) << "Ten doi 1" << setw(20) << "Ban thang doi 1" << setw(15) << "ID doi 2" << setw(20) << "Ten doi 2" << setw(20) << "Ban thang doi 2" << setw(12) << "Thoi gian" << setw(20) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
                kt++;
            }
            kq = false;
            Team t;
            String n1, n2;
            n1 = t.nameTeambyId(id1);
            n2 = t.nameTeambyId(id2);
            cout << left << setw(10) << idr << setw(15) << id1 << setw(20) << n1 << setw(20) << goal1 << setw(15) << id2 << setw(20) << n2 << setw(20) << goal2 << setw(12) << time << setw(20) << date << setw(20) << address << endl;
        }
    }
    if (kq)
        cout << "Khong tim thay!" << endl;
}
