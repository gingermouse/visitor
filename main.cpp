#include <iostream>
#include "cmd.h"

class A {
public:
    explicit A(bool wwc) : _work_with_core(wwc) {
        if(_work_with_core) _dcmd = new Core;  // Work with r_core
        else _dcmd = new Pip;  // Work with r2pip
    }
    ~A() {
        delete _dcmd;
    }
    
    // It's a function which has to interact with r_core or p2pip
    void some_function() {
        // ...
        CommandOne cmdOne(5, 10);  // Create a command
        _dcmd->accept(cmdOne);  // Execute the command
        std::cout << "Result of CommandOne is " << cmdOne.get_result() << std::endl;  // Get result
        // ...
        for(int i = 0; i < 10; ++i) {
            _dcmd->accept( cmdOne(i, i*2) );
            std::cout << i << ": result is " << cmdOne.get_result() << std::endl;
        }
    }

private:
    int _val;
    bool _work_with_core;
    DistinationCmd* _dcmd;  // Destination of commands: api r_core or p2pip
};

int main() {
    A obj_1(false);  // Use pip
    A obj_2(true);  // Use r_core
    std::cout << "Execution via pip" << std::endl;
    obj_1.some_function();  // 150
    std::cout << std::endl << "Execution via core" << std::endl;
    obj_2.some_function();  // 15
    return 0;
}
