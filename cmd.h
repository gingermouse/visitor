#ifndef H_CMD
#define H_CMD

class Core;
class Pip;

class ICmd {
public:
    virtual void execute(Core& cmd) = 0;
    virtual void execute(Pip& cmd) = 0;
    virtual ~ICmd() = default;
};

class DistinationCmd {
public:
    virtual void accept(ICmd& cmd) = 0;
    
    virtual ~DistinationCmd() = default;
};

class Core : public DistinationCmd {
public:
    ~Core() = default;
    void accept(ICmd &cmd) override { cmd.execute(*this); }
};

class Pip : public DistinationCmd {
public:
    ~Pip() = default;
    void accept(ICmd& cmd) override { cmd.execute(*this); }
};

class CommandOne : public ICmd {
public:
    CommandOne(int a, int b) : _a(a), _b(b) { };
    ~CommandOne() = default;
    CommandOne& operator()(int a, int b) {
        _a = a;
        _b = b;
        return *this;
    }
    void execute(Core& cmd);
    void execute(Pip& cmd);
    int get_result() { return _result; }
    void set_values(int a, int b) {
        _a = a;
        _b = b;
    }
    
private:
    int _a;
    int _b;
    int _result;
};

#endif
