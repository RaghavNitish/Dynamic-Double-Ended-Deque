#include <iostream>
#include "header.h"
#include <string>
#include <exception>

int main(){
    std::string line;
    deque obj;
	while(getline(std::cin, line)){

        if (line.substr(0, 13) == "enqueue_front"){
            int operand = std::stoi(line.substr(13));
            obj.enqueue_front(operand);
        }
        else if (line.substr(0, 12) == "enqueue_back"){
            int operand = std::stoi(line.substr(12));
            obj.enqueue_back(operand);
        }
        else if (line.substr(0, 13) == "dequeue_front"){
            obj.dequeue_front();
        }
        else if (line.substr(0, 12) == "dequeue_back"){
            obj.dequeue_back();
        }
        else if (line.substr(0, 5) == "clear"){
            obj.clear();
        }
        else if (line.substr(0, 5) == "front"){
            int operand = std::stoi(line.substr(6));
            obj.front(operand);
        }
        else if (line.substr(0, 4) == "back"){
            int operand = std::stoi(line.substr(5));
            obj.back(operand);
        }
        else if (line.substr(0, 5) == "empty"){
            obj.empty();
        }
        else if (line.substr(0, 4) == "size"){
            obj.size();
        }
        else if (line.substr(0, 5) == "print"){
            obj.print();
        }
	}
    return 0;
}