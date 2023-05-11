#pragma once

#include "fermat.h"

class Pocklington : public Fermat
{
public:
    Pocklington(InputNum& input, Params& params, Logging& logging, Proof* proof);

    void run(InputNum& input, arithmetic::GWState& gwstate, File& file_checkpoint, File& file_recoverypoint, Logging& logging, Proof* proof) override;

protected:
    class FactorTask
    {
    public:
        FactorTask(int i) : index(i) { }
        int index;
        std::unique_ptr<CarefulExp> taskFactor;
        std::unique_ptr<CarefulExp> taskCheck;
    };

protected:
    bool _all_factors = false;
    std::unique_ptr<InputNum> _input_k;
    std::unique_ptr<InputNum> _input_base2;
    std::vector<FactorTask> _tasks;
};
