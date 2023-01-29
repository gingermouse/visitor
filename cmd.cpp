#include "cmd.h"
#include "core.h"
#include "pip.h"


// Implementation of CommandOne functions
void CommandOne::execute(Core& cmd) {
        _result = core_function(_a, _b);
    }
void CommandOne::execute(Pip& cmd) {
        _result = pip_function(_a, _b);
    }  

// Implementation of CommandTwo functions
// ... similar things
