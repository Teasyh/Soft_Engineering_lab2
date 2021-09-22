#include<bits/stdc++.h>
using namespace std;

//Define Keyword class
class Keyword
{
public:
    string word;
    int num; //The number of keywords
    void Search_word(string);//The function to search specific keywords
    void Judge_ifelse();//The function to judge if-else or if-else if
    void PrintResult();
};
//The array to store the keywords
Keyword key[32] = { "auto", 0,"break",0,"case",0,"char",0,"const", 0,"continue",0,"default",0,"do", 0,
                    "double",0,"else",0,"enum",0,"float",0,"for",0,"goto",0,"if",0,"int",0,
                    "long",0,"register",0, "while", 0,"return",0,"short",0,"signed",0,"sizeof",0,"static", 0,
                    "struct",0,"switch",0,"typedef",0,"union",0,"unsigned",0,"void", 0 ,"volatile",0,"while", 0 };
//Declare variables and functions
int count_switch = 0;
int count_case[100] = {0};
//further and final requirements
int count_ifelse = 0;
int count_ifelseif = 0;
bool p_if = false, p_else = false, mark_if = false;

void Search_word(string str)
{
    for(int i = 0; i<32; i++)
    {
        if(str.find(key[i].word) != -1)
        {
            //Do and double are duplicated, so we need to determine that when the keyword is double, the number of do is reduced by one
            if(str.find("double") != -1)
            {
                if(i == 8)
                {
                    key[7].num--;
                }
            }
            key[i].num++;
            if(i == 25)
            {
                count_switch++;
            }
            else if(count_switch != 0 && i==2)
            {
                count_case[count_switch]++;//count case in one switch structure
            }
            if(i == 14)
            {
                p_if = true;
            }
            if(i == 9)
            {
                p_else = true;
            }
        }
    }
}

//Output the results
void PrintResult()
{
    int level;
    int sum = 0;
    cout << "Please enter the level of requirement: " << endl;
    cin >> level;
    if(level > 0)
    {
        for (int i = 0; i < 32; i++)
        {
            sum += key[i].num;//Calculate the total number of keywords
        }
    }
    cout << "Key words number :" << sum << endl;
    if(level > 1)
    {
        cout << "Switch number :" << count_switch << endl;
        cout << "Case number : ";
        if(count_case[1] == 0)
        {
            cout << 0;
        }
        else
        {
            for (int i = 1; i <= count_switch; i++)
            {
                cout << count_case[i] << " ";//Calculate the "case" number for each switch structure
            }
        }
        cout << endl;
    }
    if (level > 2)
    {
        cout << "if-else number: " << count_ifelse << endl;
    }
    if (level > 3)
    {
        cout << "if-elseif-else number: " << count_ifelseif << endl;
    }
}
int main()
{
    string file_name;
    cout << "Please enter the file address:" << endl;
    cin >> file_name;
    ifstream file;
    file.open(file_name.c_str());//read the file 
    string str;
    if (!file.fail())
    {
        while (!file.eof())
        {
            getline(file, str); //read by lines
            Search_word(str);
            Judge_ifelse();
        }
    }
    else
    {
        cout << "The file was not successfully opened" << endl;
        return -1;
    }
    //output the results
    PrintResult();
    return 0;
}
