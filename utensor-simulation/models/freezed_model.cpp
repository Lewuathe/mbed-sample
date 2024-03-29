// Auto generated by utensor-cli

#include "freezed_model.hpp"
#include "freezed_model_weight.hpp"
#include "uTensor/core/context.hpp"
#include "uTensor/core/tensor.hpp"
#include "uTensor/ops/MathOps.hpp"


void get_freezed_model_ctx(Context& ctx, Tensor* input_0) {

{ // add tensor for placeholders
    ctx.add(input_0, "input:0", 1);
}
{    
    ctx.add(new BinaryTensor<int>({2,2}, inline_a_0), 
            "a:0", 
            1);
}
{
    ctx.add(new RamTensor<int>(), "add:0");
    ctx.push(new AddOp<int, int>(),
             { "a:0", "input:0" }, 
             { "add:0" });
}
}