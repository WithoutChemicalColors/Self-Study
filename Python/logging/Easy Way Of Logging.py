# Easy way to implement logging to all function
# Decorator + Logging

import logging
logging.basicConfig(level=logging.INFO)

# skip this one
for item in logging.root.handlers[:]:
    logging.root.removeHandler(item)
    
# A wrapper for hello() <- no input function
def record(func):
    def wrapper():
        logging.info("%s is starging" % func.__name__)
        func()
        logging.info("%s is finished" % func.__name__)
    return wrapper

@record
def hello():
    print("Hello")
    
hello()

# if the hello is expected to have some parameters
# get it by wrapper
def record(func):
    def wrapper(*arg):
        logging.info("%s is starging" % func.__name__)
        ans = func(*arg)
        logging.info("%s is finished" % func.__name__)
        return ans
    return wrapper

@record
def hello(cin):
    print("Hello %d" % cin)
    return cin*10
    
what_is_this = hello(10)
print(what_is_this)