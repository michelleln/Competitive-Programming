#include <iostream>
#include <set>
#include <string>

int main(){
    std::set <std::string> myset;
    std::string word;
    while (std::cin >> word){
        std::string renewWord = "";
        for (int i = 0; i < (int) word.length(); i++){
            if ('A' <= word[i] && word[i] <= 'Z'){
                word[i] = word[i] - 'A' + 'a';
            }
        }
        for (int i = 0; i < (int) word.length(); i++){
            if ('a' <= word[i] && word[i] <= 'z'){
                renewWord += word[i];
            }
            else {
                
            }
        }
    }
}