import tensorflow as tf

input = tf.placeholder(tf.int32, shape=(1, 1), name='input')
a = tf.constant([1], name='a')
b = tf.constant([2], name='b')
c = a + b + input

init = tf.global_variables_initializer()

with tf.Session() as sess:
    sess.run(init)
    ret = sess.run(c, feed_dict={input: [[10]]})
    print(ret)
    tf.saved_model.simple_save(sess, './saved_model', inputs={"input": input}, outputs={"output": c})

