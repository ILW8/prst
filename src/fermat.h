#pragma once

#include "arithmetic.h"
#include "inputnum.h"
#include "task.h"
#include "file.h"
#include "exp.h"
#include "params.h"
#include "proof.h"

class Fermat
{
public:
    static const int AUTO = 0;
    static const int FERMAT = 1;
    static const int PROTH = 2;
    static const int POCKLINGTON = 3;

public:
    Fermat(int type, InputNum& input, Params& params, Logging& logging, Proof* proof);
    virtual ~Fermat() { }

    virtual void run(InputNum& input, arithmetic::GWState& gwstate, File& file_checkpoint, File& file_recoverypoint, Logging& logging, Proof* proof);

    int type() { return _type; }
    int a() { return _a; }
    bool success() { return _success; }
    std::string& res64() { return _res64; }

    BaseExp* task_tail_simple() { return _task_tail_simple.get(); }
    BaseExp* task_ak_simple() { return _task_ak_simple.get(); }
    BaseExp* task_ak() { return _task_ak.get(); }
    BaseExp* task() { return _task.get(); }

protected:
    void on_point(int index, arithmetic::Giant& X);

protected:
    int _type;
    std::unique_ptr<InputNum> _input_k;
    std::unique_ptr<InputNum> _input_base2;
    int _a;

    std::unique_ptr<BaseExp> _task_tail_simple;
    std::unique_ptr<BaseExp> _task_ak_simple;
    std::unique_ptr<BaseExp> _task_ak;
    std::unique_ptr<BaseExp> _task;

    Proof* _proof;
    int _n;
    std::vector<int> _points;
    arithmetic::Giant _Xm1;

    bool _success = false;
    std::string _res64;
};
