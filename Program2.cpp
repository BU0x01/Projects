// Batbilegt Ulziibayar(800697683)
// CS150 & 002
// 10/07/2022
// Assignment 2 & Ranked election choice system

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    string input, input01, input02, input03, input04, input05, input06, input07, vote;
    string d01[8000];
    string d02[8000];
    string d03[8000];
    string d04[8000];
    string d05[8000];
    string d06[8000];
    string d07[8000];
    fstream data01;
    data01.open("election.txt");

    int count = 0;
    if (data01)
    {
        getline(data01, input, ' ');
        getline(data01, vote);
        while (data01)
        {
            getline(data01, input01, ' ');
            data01 >> d01[count];
            getline(data01, input02, ' ');
            data01 >> d02[count];
            getline(data01, input03, ' ');
            data01 >> d03[count];
            getline(data01, input04, ' ');
            data01 >> d04[count];
            getline(data01, input05, ' ');
            data01 >> d05[count];
            getline(data01, input06, ' ');
            data01 >> d06[count];
            getline(data01, input07, '\n');
            data01 >> d07[count];
            count++;
        }
    }

    double num01 = 0;
    double num02 = 0;
    double num03 = 0;
    double num04 = 0;
    double num05 = 0;
    double num06 = 0;
    double num07 = 0;

    for (int i = 0; i < count; i = i + 1)
    {
        if (d01[i] == "1")
        {
            num01++;
        }
        else if (d01[i] == "2")
        {
            num02++;
        }
        else if (d01[i] == "3")
        {
            num03++;
        }
        else if (d01[i] == "4")
        {
            num04++;
        }
        else if (d01[i] == "5")
        {
            num05++;
        }
        else if (d01[i] == "6")
        {
            num06++;
        }
        else if (d01[i] == "7")
        {
            num07++;
        }
    }

    double array01[10];
    array01[0] = num01;
    array01[1] = num02;
    array01[2] = num03;
    array01[3] = num04;
    array01[4] = num05;
    array01[5] = num06;
    array01[6] = num07;

    double percentile = stoi(input);
    double array02[10];

    for (int i = 0; i <= 10; i++)
    {
        array02[i] = (array01[i] / percentile) * 100;
    }

    cout << "Election Results: " << endl;
    cout << "Number of voters: " << input << endl;
    cout << "Number of contestants: " << vote << endl;
    cout << "Current Results:" << endl;

    int vote01 = stoi(vote);
    for (int i = 1; i <= vote01; i = i + 1)
    {
        cout << " " << i << ":"
             << "      " << array01[i - 1] << "      " << setprecision(5) << array02[i - 1] << endl;
    }

    double min = array02[0];
    for (int i = 0; i <= vote01; i = i + 1)
    {
        if (array02[i] >= 50)
        {
            cout << "Final result: Candidate " << i + 1 << " wins." << endl;
            cout << "********************************" << endl;
        }
        else if (array02[i] < min)
        {
            array02[i] = min;
        }
    }

    return 0;
}