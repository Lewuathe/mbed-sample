import tensorflow as tf

input = tf.placeholder(tf.int32, shape=(2, 2), name='input')
a = tf.constant([[1, 2], [3, 4]], name='a')
c = a + input

init = tf.global_variables_initializer()

with tf.Session() as sess:
    sess.run(init)
    ret = sess.run(c, feed_dict={input: [[1, 2], [3, 4]]})
    print(ret)
    tf.saved_model.simple_save(sess, './saved_model', inputs={"input": input}, outputs={"output": c})

