mbed-sample
===

Sample applications for [Mbed](https://www.mbed.com/en/) environment.

## How to start

Please install the following dependencies in advance.

```
$ brew install pipenv
$ pipenv shell
```

```
$ npm install mbed-simulator -g
```

### Simple uTensor Graph (`utensor-simulation`)

This application is for running uTensor with Mbed environment.

First, we are going to crate our model in SavedModel format.

```
$ python save_model.py
```

It will generate a SavedModel in the directory `saved_model`.
To make it readable by uTensor, it is necessary to freeze the model. We need the information of output node.
`saved_model_cli` in TensorFlow will give us information of all nodes contained in the graph.

```
$ saved_model_cli show --dir ./saved_model --all
```

Now we are able to freeze the graph as follows.

```
$ freeze_graph --input_saved_model_dir saved_model --output_node_names add_1 --output_graph freezed_model.pb
```

Freezed model containing all weights parameters in an optimized manner is saved in `freezed_model.pb`.
uTensor is able to convert the model in freezed format into uTensor model. `utensor-cli` generates the C/C++ source code runnable at Mbed environment.

```
$ utensor-cli convert freezed_model.pb --output-nodes=add_1 --model-dir utensor-simulation/models
```

