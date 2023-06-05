#include <iostream>
#include <stack>
int size;
int array[200005];
std::stack <int> candidate;

int main(){
    std::cin >> size;
    for (int i = 1; i <= size; i++){
        std::cin >> array[i];
    }
    candidate.push(0);
    for (int position = 1; position <= size; position++){
        while (!candidate.empty()){
            if (array[position] <= array[candidate.top()]){
                candidate.pop();
            }
            else {
                std::cout << candidate.top() << ' ';
                break;
            }
        }
        candidate.push(position);
    }
}