/*
 * 任务是判断是否为回文
 * 忽略大小写和标点符号
 */


#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>


using namespace std;
bool Is_huiwen(const string &line);
string gen_new_str(const string &line);
//inline char TocharLower(const char &c){return std::tolower(c);}

int main() {
    string line;


    while(cin >> line && line != "quit"){

        string new_line(gen_new_str(line));

        if(Is_huiwen(new_line))
            cout << line << " is huiwenzi" << endl;
        else
            cout << line << " is not huiwenzi" << endl;
    }

    return 0;
}



bool Is_huiwen(const std::string &line){

    bool ans = false;
    auto start = line.begin();
    auto end = line.rbegin();
    for(int i = 0; i <= line.size()/2; i++){
        if(*start == *end){
            ++start;
            ++end;
        }
        else
            return ans;
    }
    ans = true;
    return ans;

}

string gen_new_str(const std::string &line){

    bool is_edit = false;
    string edit(line);//不知道为什么一定要赋一个初值，不然edit在transform之后没有内容
    transform(line.begin(), line.end(), edit.begin(), ::tolower);

    for(auto i = edit.begin(); i != edit.end(); i++){

        if(ispunct(*i) || isspace(*i)){
            is_edit = true;
            edit.erase(i);
        }
    }

    if(is_edit)
    {cout<< "String is edited."<< endl;
        cout<< "edit string is: " << edit << endl;}
    else
        cout << "String didn't change. " <<  endl;
    return edit;
}
