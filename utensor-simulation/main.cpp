#include "models/freezed_model.hpp"  //gernerated model file
#include "tensor.hpp"  //useful tensor classes
#include "mbed.h"
#include <stdio.h>

Serial pc(USBTX, USBRX, 115200);  //baudrate := 115200

int main(void)
{
  printf("Simple Add Model\n");

  Context ctx;  //creating the context class, the stage where inferences take place
  //wrapping the input data in a tensor class
  float input_data[1] = {3.0};
  Tensor* input_x = new WrappedRamTensor<float>({1}, (float*) &input_data);

  get_freezed_model_ctx(ctx, input_x);  // pass the tensor to the context
  S_TENSOR pred_tensor = ctx.get("add_1:0");  // getting a reference to the output tensor
  ctx.eval(); //trigger the inference

  int pred_label = *(pred_tensor->read<int>(0, 0));  //getting the result back
  printf("Predicted label: %lf\r\n", pred_label);

  return 0;
}