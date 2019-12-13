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
  int input_data[4] = {1, 2, 3, 4};
  Tensor* input_x = new WrappedRamTensor<int>({2, 2}, input_data);

  get_freezed_model_ctx(ctx, input_x);  // pass the tensor to the context
  ctx.eval(); //trigger the inference
  S_TENSOR output_tensor = ctx.get("add:0");  // getting a reference to the output tensor

  const int* outputs = output_tensor->read<int>(0, 4);  //getting the result back
  printf("output[0]: %d\r\n", outputs[0]);
  printf("output[1]: %d\r\n", outputs[1]);
  printf("output[2]: %d\r\n", outputs[2]);
  printf("output[3]: %d\r\n", outputs[3]);
  return 0;
}