#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void showCMD(string input){
  string exec;
  cout << "PARSED COMMAND:" << endl;
  string word = "";
  int count = 0;
  char track;
  for (char c : input){
    if (c != ' ') exec += c;

    else if (c == ' ' && track != ' ') exec += c;

    if (c == ' ' && count == 0 && track != ' '){
      cout << word << endl;
      word = "";
    }

    track = c;

    if (c == '"' || count == 1){
      if (c != '"') word += c;

      if (c == '"'){
        count++;
        if (count == 2) count = 0;
      }
    }

    else if (count == 0 || count == 2){
      if (c != ' ') word += c;
    }
  }
  cout << word << endl;
  cout << "EXECUTING: " << exec << endl;
}

void help(string input){
  string fileName = "help.txt";
  ifstream file(fileName, ifstream::in);
  while(getline(file, input)){
    cout << input << endl;
  }
}

void deleteNow(string input){
  string exec;
  cout << "PARSED COMMAND:" << endl;
  string word = "";
  int count = 0;
  char track;
  for (char c : input){
    if (c != ' ') exec += c;

    else if (c == ' ' && track != ' ') exec += c;

    if (c == ' ' && count == 0 && track != ' '){
      cout << word << endl;
      word = "";
    }

    track = c;

    if (c == '"' || count == 1){
      if (c != '"') word += c;

      if (c == '"'){
        count++;
        if (count == 2) count = 0;
      }
    }

    else if (count == 0 || count == 2){
      if (c != ' ') word += c;
    }
  }
  cout << word << endl;
  cout << "EXECUTING: " << exec << endl;
}

void add(string input){
  string exec;
  cout << "PARSED COMMAND:" << endl;
  string word = "";
  int count = 0;
  char track;
  for (char c : input){
    if (c != ' ') exec += c;

    else if (c == ' ' && track != ' ') exec += c;

    if (c == ' ' && count == 0 && track != ' '){
      cout << word << endl;
      word = "";
    }

    track = c;

    if (c == '"' || count == 1){
      if (c != '"') word += c;

      if (c == '"'){
        count++;
        if (count == 2) count = 0;
      }
    }

    else if (count == 0 || count == 2){
      if (c != ' ') word += c;
    }
  }
  cout << word << endl;
  cout << "EXECUTING: " << exec << endl;
}

void prefix(string input){
  input.erase(0, 12);
  string b;
  string a;
  int count = 0;

  for (char c : input){
    if(c != ' '){
      a += c;
    }

    if(c == ' ' && count != 1){
      b = a;
      a = "";
      count++;
    }
  }

  string firstString = b.substr(0,3);

  if(firstString == a){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }
}

void suffix(string input){
  input.erase(0, 10);

  string b;
  string a;
  int count = 0;

  for (char c : input){
    if(c != ' '){
      a += c;
    }

    if(c == ' ' && count != 1){
      b = a;
      a = "";
      count++;
    }
  }

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  string firstString = b.substr(0,3);

  if(firstString == a){
    cout << "true" << endl;
  } else{
    cout << "false" << endl;
  }
}

void read(string fileName){
  fileName.erase(0,6);
  cout << ifstream(fileName).rdbuf();

}

void toTitleCase(string str) {
  string result;

  for(int i = 0; i < str.length(); i++){
    if(i == 0 || str[i-1] == ' '){
      result.append(1,toupper(str[i]));
    }else {
      result.append(1,str[i]);
    }
  }

  result.erase(0, 13);

  for(int i = 0; i < result.length(); i++){
    if (result[0] == 'T' && result[1] == 'h' && result[2] == 'e' && result[3] == ' '){
      result.erase(0, 4);
      result.append(", The");
    }
  }
  cout << result << endl;
}

void toTrim (string input){

  input.erase(0, 6);

  string exec;
  char track;

  for (char c : input){
    if (c != ' ') exec += c;

    else if (c == ' ' && track != ' ') exec += c;

    track = c;
  }
  cout << exec << endl;
}

int main(){
  string input; //input line read from user

  cout << "Welcome to MuLib, your personal Music Library Centre.\nPlease enter .quit to exit or .help for help\n";

  while(true){
    cout << "CMD or .quit: ";

    /*
    if(input.compare(".log start")){
    string fileName = "log.txt";
    ofstream file(fileName, ofstream::out);
    while (true){
    getline(cin, input);
    file << input << endl;
  }
}
*/

getline(cin, input);

if(input.compare(".quit") == 0) break;

if(input.compare(".help") == 0) help(input);

if ((input[0] == 'a' && input[1] == 'd' && input[2] == 'd' && input[3] == ' ' && input[4] == '-' && (input[5] == 'r' ||input[5] == 's' ||input[5] == 'u' || input[5] == 't' || input[5] == 'p' || input[5] == 'l')) && input[6] == ' '){
  add(input);
}

if ((input[0] == 'd' && input[1] == 'e' && input[2] == 'l' && input[3] == 'e' && input[4] == 't'  && input[5] == 'e'  && input[6] == ' '  && input[7] == '-' && (input[8] == 's' ||input[8] == 'r' ||input[8] == 'u' || input[8] == 't' || input[8] == 'p' || (input[8] == 'G' && input[9] == 'l' && input[10] == 'o' && input[11] == 'b' && input[12] == 'a' && input[13] == 'l' ))) && input[6] == ' '){
  deleteNow(input);
}

if(input.compare("show songs") == 0) showCMD(input);

if(input.compare("show users") == 0) showCMD(input);

if(input[0] == 's' && input[1] == 'h' && input[2] == 'o' && input[3] == 'w' && input[4] == ' '  && input[5] == 'p'  && input[6] == 'l'  && input[7] == 'a' && input[8] == 'y' && input[9] == 'l' && input[10] == 'i' && input[11] == 's' && input[12] == 't' && input[13] == 's' && input[14] == ' ' && input[15] == '-' && input[16] == 'u' && input[17] == ' '){
  showCMD(input);
}

if(input[0] == 's' && input[1] == 'h' && input[2] == 'o' && input[3] == 'w' && input[4] == ' '  && input[5] == 's'  && input[6] == 'o'  && input[7] == 'n' && input[8] == 'g' && input[9] == 's' && input[10] == ' ' && input[11] == '-' && (input[12] == 'u' || input[12] == 'p') && input[13]){
  showCMD(input);
}

if(input[0] == '.' && input[1] == 's' && input[2] == 't' && input[3] == 'a' && input[4] == 'r' && input[5] == 't' && input[6] == 's' && input[7] == 'W' && input[8] == 'i' && input[9] == 't' && input[10] == 'h' && input[11] == ' '){
  prefix(input);
}

if(input[0] == '.' && input[1] == 'e' && input[2] == 'n' && input[3] == 'd' && input[4] == 's' && input[5] == 'W' && input[6] == 'i' && input[7] == 't' && input[8] == 'h' && input[9] == ' '){
  suffix(input);
}

if(input[0] == '.' && input[1] == 'r' && input[2] == 'e' && input[3] == 'a' &&  input[4] == 'd' && input[5] == ' ') read(input);

if(input[0] == '.' && input[1] == 't' && input[2] == 'o' && input[3] == 'T' &&  input[4] == 'i' &&  input[5] == 't' &&  input[6] == 'l' &&  input[7] == 'e' &&  input[8] == 'C' &&  input[9] == 'a' &&  input[10] == 's' && input[11] == 'e' && input[12] == ' '){
  toTitleCase(input);
}

if(input[0] == '.' && input[1] == 't' && input[2] == 'r' && input[3] == 'i' && input[4] == 'm' && input[5] == ' ') toTrim(input);

if(input.compare("show recordings") == 0) showCMD(input);

if(input.compare("show tracks") == 0) showCMD(input);

}
return(0);
}
