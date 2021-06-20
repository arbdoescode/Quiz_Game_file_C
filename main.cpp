#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <string>
#include <cctype>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <ctime>

using namespace std;
//pointer to display the users and theire score by who signed up first
float *sortAsc(float *p, int size);
//the function algorithm to compare users rate in admin menu
template <class n1, class n2>
n1 scorealgorithm(n1 a, n2 b)
{
    return a / b;
}
//recursion function to find the best score in page
int findMaxRec(int A[], int n)
{
    if (n == 1)
        return A[0];
    return max(A[n - 1], findMaxRec(A, n - 1));
}
//recursion function to find the worst score in page
int findMinRec(int A[], int n)
{

    if (n == 1)
        return A[0];
    return min(A[n - 1], findMinRec(A, n - 1));
}
//current is to keep track of the user who is logged in
int i, current, testID = 1, checkbox = 1, questionnumber = 20;
float lol[100];
//voids of user menu
void userpage1();
void admin();
//admins username and password,use this info to log in as an admin
string adm = "admin";
string passwo = "godmode";
//enum
enum categories
{
    physics,
    math,
    chemistry,
    other
} cat;
//struct
struct user
{
    int ID;
    string firstname;
    string lastname;
    int age;
    string username;
    string password;
    float score;
    int total;
    int p_co, m_co, c_co, o_co;
    int py, ma, ch, ot;
    int check[100];
    int z[100];
    int que[100];
};
//user array
int const n = 101;
user contester[n];
int m = 1;
//A simple count recursion for intro
void Intro(int counter)
{
    if (counter == 0)
        cout << "Hello LITTLE EINSTEINS!!!" << endl;
    else
    {
        cout << counter << "  ";
        return Intro(--counter);
        ;
    }
}
//function overload tells the number of users everytime u go to the main menu
void UserNumber(int x)
{
    cout << "Users in page : " << x << endl;
}
//adds username but
//it doesn't allow you to use an existing one
void addusername()
{
    string check;
    cin >> check;
    for (i = 1; i < m; i++)
    {
        if (check == contester[i].username || check == adm)
        {
            cout << "This username exists add another one : ";
            cin >> check;
        }
        else
        {
            continue;
        }
    }
    contester[m].username = check;
}
//user register
void signup()
{
    srand(time(0));
    contester[m].ID = 1 + rand() % 9999;
    cout << "\nEnter your firstname : ";
    cin >> contester[m].firstname;
    cout << "\nEnter your lastname : ";
    cin >> contester[m].lastname;
    cout << "\nEnter your age : ";
    cin >> contester[m].age;
    cout << "\nEnter your username (You will use this to log in) : ";
    addusername();
    cout << "\nEnter your password (Required) : ";
    cin >> contester[m].password;
    cout << "Your ID is : " << contester[m].ID << endl;
    cout << "Your account has been created" << endl;
}
//user logs in
void loging()
{
    string us, pas;
    cout << endl
         << "Username : ";
    cin >> us;
    for (i = 1; i <= m; i++)
    {
        if (us == contester[i].username)
        {
            //when u put the right username it asks for the corresponding password
            bool access = false;
            cout << "Password : ";
            do
            {
                cin >> pas;
                current = i;
                if (pas == contester[i].password)
                {
                    access = true;
                }
                if (pas != contester[i].password)
                {
                    cout << "Invalid password.Try again. ";
                }
            } while (!access);
            cout << endl
                 << "You have logged in " << endl;
            userpage1();
        }
        else if (us != contester[i].username)
        {
        }
    }
    //admin logs in
    if (us == adm)
    {
        bool access = false;
        cout << "Password : ";
        do
        {
            cin >> pas;
            if (pas == passwo)
            {
                access = true;
            }
            if (pas != passwo)
            {
                cout << "Invalid password.Try again. ";
            }
        } while (!access);
        admin();
    }
    if (us != adm && us != contester[m].username)
    {
        cout << "This username doesn't exist" << endl;
        loging();
    }
}
//admins voids

//the fuction that adds void
void addquestion()
{
    char input[256];
    ofstream foutput;
    ifstream finput;
    finput.open("questions.txt");
    foutput.open("questions.txt", ios::app);

    cin.ignore();
    cout << "Insert the question \n";
    if (finput.is_open())
        cin.getline(input, 256);
    foutput << input << endl;
    cout << "Insert the answer \n";
    cin.getline(input, 256);
    foutput << input << endl;

    cout << "\n Data has been appended to file";

    finput.close();
    foutput.close();
    questionnumber++;
}
//the function that searches contesters by name
void search()
{
    string s;
    cout << "Enter name of user : ";
    cin >> s;
    for (i = 1; i <= m; i++)
    {
        if (s == contester[i].firstname)
        {
            cout << "ID : " << contester[i].ID << endl;
            cout << "Score : " << contester[i].score << "/" << contester[i].total << endl;
            cout << "Firstname : " << contester[i].firstname << endl;
            cout << "Lastname : " << contester[i].lastname << endl;
            cout << "Age : " << contester[i].age << endl;
            cout << "Username : " << contester[i].username << endl;
            cout << "Password : " << contester[i].password << endl;
        }
        else if (s != contester[i].firstname)
        {
            cout << endl;
            continue;
        }
    }
    admin();
}
//prints out all the users that have been registerd with theire stats
void list()
{
    for (int i = 2; i <= m; i++)
    {
        cout << "ID : " << contester[i].ID << endl;
        cout << "Name : " << contester[i].firstname << " " << contester[i].lastname << endl;
        cout << "AGE : " << contester[i].age << endl;
        cout << "Score : " << contester[i].score << "/" << contester[i].total << endl;
        cout << "_________________________________\n";
    }
    admin();
}
//comparing 2 users
void compare()
{
    string s;
    int x = 0, y = 0;
    if (m >= 3)
    {
        cout << "Compare 2 users,and show ranking\n";
        cout << "1st User : ";
        cin >> s;
        for (i = 1; i <= m; i++)
        {
            if (s == contester[i].firstname)
            {
                x = i;
            }
            else
            {
                continue;
            }
        }
        cout << "2nd User : ";
        cin >> s;
        for (i = 1; i <= m; i++)
        {
            if (s == contester[i].firstname)
            {
                y = i;
            }
            else
            {
                continue;
            }
        }
        if (x == 0 || y == 0)
        {
            cout << "You made a mistage inputing the names,and this result in a exit" << endl;
        }
        else
        {
            float n, q;
            n = scorealgorithm(contester[x].score, contester[x].total);
            q = scorealgorithm(contester[y].score, contester[y].total);
            if (q < n)
            {
                cout << endl
                     << contester[x].firstname << " " << contester[x].lastname << " has better rate." << endl;
            }
            else if (q > n)
            {
                cout << endl
                     << contester[y].firstname << " " << contester[y].lastname << " has better rate." << endl;
            }
            else if (q == n)
            {
                cout << endl
                     << contester[x].firstname << " " << contester[x].lastname << " and " << contester[y].firstname << " " << contester[y].lastname << "have the same rate." << endl;
            }
            if (m >= 3)
            {
                cout << endl
                     << "Ranking(all users):" << endl;
                int r;
                int best, wors;
                r = m - 1;
                int A[r];
                float a;
                for (i = 2; i <= m; i++)
                {
                    a = contester[i].score;
                    A[i - 2] = a;
                }

                int n = sizeof(A) / sizeof(A[0]);
                for (i = 2; i <= m; i++)
                {
                    if (findMaxRec(A, n) == contester[i].score)
                    {
                        best = i;
                    }
                    if (findMinRec(A, n) == contester[i].score)
                    {
                        wors = i;
                    }
                    continue;
                }
                cout << "Best score : " << contester[best].firstname << " (" << findMaxRec(A, n) << ")" << endl;
                cout << "Worst score : " << contester[wors].firstname << " (" << findMinRec(A, n) << ")" << endl;
            }
            else if (m < 3)
            {
                cout << endl
                     << "Ranking doesn't display cause the lack of competition" << endl;
            }
        }
    }
    else
    {
        cout << "You need at least 2 users to acces this feature" << endl;
    }
    admin();
}
//check the best of each categorie
void checkers()
{
    int smth;
    cout << endl
         << "Press the coresponding number : " << endl;
    cout << "1.Physics\n2.Math\n3.Chemistry";
    cin >> smth;
    if (smth == 1)
    {
        double max1 = 0;
        cout << "The best in Physics is ";
        for (i = 1; i <= m; i++)
        {
            if (max1 <= contester[i].p_co)
            {
                max1 = contester[i].p_co;
            }
            else
            {
                continue;
            }
        }
        for (i = 1; i <= m; i++)
        {
            if (max1 == contester[i].p_co)
            {
                cout << contester[i].firstname << " with ";
            }
            else
            {
                continue;
            }
            cout << max1 << " points ";
        }
    }
    else if (smth == 2)
    {
        double max1 = 0;
        cout << "The best in Math is ";
        for (i = 1; i <= m; i++)
        {
            if (max1 <= contester[i].m_co)
            {
                max1 = contester[i].m_co;
            }
            else
            {
                continue;
            }
        }
        for (i = 1; i <= m; i++)
        {
            if (max1 == contester[i].m_co)
            {
                cout << contester[i].firstname << " with ";
            }
            else
            {
                continue;
            }
            cout << max1-1 << " points ";
        }
    }
    else if (smth == 3)
    {
        double max1 = 0;
        cout << "The best in Chemistry is ";
        for (i = 1; i <= m; i++)
        {
            if (max1 <= contester[i].c_co)
            {
                max1 = contester[i].c_co;
            }
            else
            {
                continue;
            }
        }
        for (i = 1; i <= m; i++)
        {
            if (max1 == contester[i].c_co)
            {
                cout << contester[i].firstname << " with ";
            }
            else
            {
                continue;
            }
            cout << max1 << " points ";
        }
    }
    else
    {
        cout << "\nPlease enter a variable from above : \n";
        checkers();
    }
    admin();
}
//contesters voids

//functions that starts the contest
void game()
{
    cin.ignore();
    //time for when u take the exam(borrowed from internet)
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << "Answer every question with 1 for first choice and 2 for second:" << endl;
    cout << "Press ENTER to start. ";
    cin.clear();
    cin.ignore();
    cout << "Time the test started : " << put_time(localtime(&now), "%F %T") << endl
         << endl;
    cout << "UserID : " << contester[current].ID << "   "
         << "TestID : " << testID << endl;

    ofstream foutput;
    ifstream finput;
    ifstream inputFile;
    string question;
    string correct_alternative, userChoice, array[3][100];
    string tr;
    int score = 0;
    finput.open("test.txt");
    foutput.open("test.txt", ios::app);
    inputFile.open("questions.txt");
    if (!inputFile)
        cout << "Error opening data file\n";
    else
    {
        foutput << "TestID: " << testID << "  UserID : " << contester[current].ID << "  " << put_time(localtime(&now), "%F %T") << "\t";
        for (i = 1; i <= questionnumber; i++)
        {
            getline(inputFile, question);
            getline(inputFile, correct_alternative);
            array[1][i] = correct_alternative;
            cout << question;
            cin >> userChoice;
            array[2][i] = userChoice;
            if (userChoice == correct_alternative)
            {
                score += 1;
            }
            else if (userChoice != correct_alternative)
            {
                score += 0;
            }

            if (array[1][i] == array[2][i])
            {
                tr = "(correct)";
            }
            else if (array[1][i] != array[2][i])
            {
                tr = "(wrong)";
            }
            foutput << i << ")  " << array[1][i] << " " << array[2][i] << tr << "\t\t";
        }
        cout << "\nYour score is " << score << "/" << questionnumber;
    }
    foutput << endl;
    inputFile.close();
    finput.close();
    foutput.close();
    contester[current].score += score;
    contester[current].total += questionnumber;
    //array stores the scores per ID
    contester[current].que[testID] = questionnumber;
    contester[current].z[testID] = score;
    contester[current].check[checkbox] = testID;
    score = 0;
    checkbox++;
    testID += 1;
    //calculates the score for each category and stores them
    for (int i = 0; i <= 5; i++)
    {
        if (array[1][i] == array[2][i])
        {
            contester[current].m_co += 1;
        }
        else if (array[1][i] != array[2][i])
        {
            contester[current].m_co += 0;
        }
    }
    contester[current].ma += 5;
    for (int i = 6; i <= 10; i++)
    {
        if (array[1][i] == array[2][i])
        {
            contester[current].p_co += 1;
        }
        else if (array[1][i] != array[2][i])
        {
            contester[current].p_co += 0;
        }
    }
    contester[current].py += 5;
    for (int i = 11; i <= 15; i++)
    {
        if (array[1][i] == array[2][i])
        {
            contester[current].m_co += 1;
        }
        else if (array[1][i] != array[2][i])
        {
            contester[current].m_co += 0;
        }
    }
    contester[current].ma += 5;
    for (int i = 16; i <= 20; i++)
    {
        if (array[1][i] == array[2][i])
        {
            contester[current].c_co += 1;
        }
        else if (array[1][i] != array[2][i])
        {
            contester[current].c_co += 0;
        }
    }
    contester[current].ch += 5;
    if (questionnumber > 20)
    {
        for (int i = 21; i <= questionnumber; i++)
        {
            if (array[1][i] == array[2][i])
            {
                contester[current].o_co += 1;
            }
            else if (array[1][i] != array[2][i])
            {
                contester[current].o_co += 0;
            }
        }
        contester[current].ot += questionnumber - 20;
    }
}
//function that lets user check his score from before
void stats()
{
    for (int i = testID - 1; i >= 1; i--)
    {
        if (contester[current].check[i] == 0)
        {
            cout << "This test belongs to another user!\n";
        }
        else
        {
            cout << "ID : " << contester[current].check[i];
            time_t now = time(0);
            string month;
            tm *ltm = localtime(&now);
            if (1 + ltm->tm_mon == 1)
            {
                month = "JAN";
            }
            else if (1 + ltm->tm_mon == 2)
            {
                month = "FEB";
            }
            else if (1 + ltm->tm_mon == 3)
            {
                month = "MAR";
            }
            else if (1 + ltm->tm_mon == 4)
            {
                month = "APR";
            }
            else if (1 + ltm->tm_mon == 5)
            {
                month = "MAY";
            }
            else if (1 + ltm->tm_mon == 6)
            {
                month = "JUN";
            }
            else if (1 + ltm->tm_mon == 7)
            {
                month = "JUL";
            }
            else if (1 + ltm->tm_mon == 8)
            {
                month = "AUG";
            }
            else if (1 + ltm->tm_mon == 9)
            {
                month = "SEP";
            }
            else if (1 + ltm->tm_mon == 10)
            {
                month = "OCT";
            }
            else if (1 + ltm->tm_mon == 11)
            {
                month = "NOV";
            }
            else if (1 + ltm->tm_mon == 12)
            {
                month = "DEC";
            }
            cout << "   " << ltm->tm_mday << " " << month;
            cout << "   score : " << contester[current].z[i] << "/" << contester[current].que[i] << endl;
        }
    }
    cout << endl
         << "Do you want to check a test (y or n) : ";
    char yorn;
    cin >> yorn;
    if (yorn == 'y' || yorn == 'Y')
    {
        ifstream inputFile;
        string question;
        int d;
        cout << "Which one : ";
        cin >> d;
        inputFile.open("test.txt");
        for (i = 0; i < d - 1; i++)
        {
            getline(inputFile, question);
        }
        getline(inputFile, question);
        cout << question << endl;
        inputFile.close();
    }
    else
    {
        cout << endl;
    }
}
//main
int main()
{
    Intro(3);
    cout << "\t    ";
    UserNumber(m);
    cout << "    To play you need to have an account." << endl;
    cout << "I already have an account(press L)\nI need to create one(press R)  " << endl;
    if (m < 3)
    {
    }
    else if (m >= 3 && m <= 6)
    {
        cout << "If you want to check first five users scores(press T)" << endl;
    }

    char sign;
    cin >> sign;
    if (m < 3)
    {
    }
    else if (m >= 3)
    {
        if (sign == 'T' || sign == 't')
        {

            float *ptr = sortAsc(lol, m);

            for (int j = 1; j <= m; j++)
            {
                lol[j - 1] = contester[j].score;
            }

            for (int i = 1; i < m; i++)
            {
                cout << "#" << i << " " << contester[i + 1].firstname << i << " -> " << *(ptr + i) << "   ";
            }
            cout << endl;
            main();
        }
    }
    if (sign == 'R' || sign == 'r')
    {
        m++;
        signup();
        cout << endl
             << "Do you want to log in (y or n) : ";
        char yorn;
        cin >> yorn;
        if (yorn == 'y' || yorn == 'Y')
        {
            loging();
        }
        else
        {
            cout << "We hope to see you back little Einstein :)\n";
            exit(3);
            return 3;
        }
    }
    else if (sign == 'L' || sign == 'l')
    {
        loging();
    }
    else
    {
        exit(3);
        return 3;
    }
}

//contersters page
void userpage1()
{
    cout << endl
         << "You are logged in as : " << contester[current].firstname;
    cout << endl
         << "1.Start contest\n2.Stats\n3.Check score by categories\n4.Log out\n---> ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        game();
        userpage1();
        break;
    case 2:
        stats();
        userpage1();
        break;
    case 3:
        //enum switch
        if (questionnumber == 20)
        {
            cout << "1.Physics\n2.Math\n3.Chemistry" << endl;
            int select;
            cin >> select;
            if (select == 1)
            {
                cat = physics;
            }
            if (select == 2)
            {
                cat = math;
            }
            if (select == 3)
            {
                cat = chemistry;
            }
            switch (cat)
            {
            case physics:
                cout << "Physics : " << contester[current].p_co << "/" << contester[current].py;
                userpage1();
                break;
            case math:
                cout << "Math : " << contester[current].m_co - 1 << "/" << contester[current].ma;
                userpage1();
                break;
            case chemistry:
                cout << "Chemistry : " << contester[current].c_co << "/" << contester[current].ch;
                userpage1();
            case other:
                cout << endl;
                userpage1();
            }
            break;
        }
        if (questionnumber > 20)
        {
            cout << "1.Physics\n2.Math\n3.Chemistry\n4.Others" << endl;
            int select;
            cin >> select;
            if (select == 1)
            {
                cat = physics;
            }
            if (select == 2)
            {
                cat = math;
            }
            if (select == 3)
            {
                cat = chemistry;
            }
            if (select == 4)
            {
                cat = other;
            }
            switch (cat)
            {
            case physics:
                cout << "Physics : " << contester[current].p_co << "/" << contester[current].py;
                userpage1();
                break;
            case math:
                cout << "Math : " << contester[current].m_co - 1 << "/" << contester[current].ma;
                userpage1();
                break;
            case chemistry:
                cout << "Chemistry : " << contester[current].c_co << "/" << contester[current].ch;
                userpage1();
            case other:
                cout << "Others : " << contester[current].o_co << "/" << contester[current].ot;
                userpage1();
            }
            break;
        }
    default:
        cout << endl;
        main();
    }
}
//admin's page
void admin()
{
    cout << endl;
    cout << endl
         << "1.Add questions\n2.List of contastens\n3.Search users\n4.Compare 2 users\n5.Rankings by categorie\n6.Log out\n---> ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        addquestion();
        admin();
        break;
    case 2:
        list();
        admin();
        break;
    case 3:
        search();
        break;
    case 4:
        compare();
        break;
    case 5:
        checkers();
        break;
    default:
        cout << endl;
        main();
    }
}
//pointer function
float *sortAsc(float *p, int size)
{
    int e, j;
    for (e = 1; e < size; e++)
        for (j = e + 1; j < size; j++)
            if (*(p + j) > *(p + e))
            {
                int temp = *(p + j);
                *(p + j) = *(p + e);
                *(p + e) = temp;
            }
    return p;
}