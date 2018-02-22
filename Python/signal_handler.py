from __future__ import print_function
import signal
from os import kill, getpid
from sys import stderr
import global_variables


class Singleton(type):
    _instances = {}

    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(Singleton, cls).__call__(*args, **kwargs)
        return cls._instances[cls]


class SignalHandler(object):
    __metaclass__ = Singleton

    def __init__(self, signals_set):
        super(SignalHandler, self).__init__()
        self.__pids_set = set()
        signals_set = set(signals_set)
        self.__signals_set = signals_set
        [signal.signal(sig, self.handler) for sig in self.__signals_set]
        signal.signal(signal.SIGTERM, self.handler)

    def handler(self, sig, frm):
        if sig == signal.SIGALRM:
            global_variables.pipe_flag = False
            print("The 'SIGALRM' signal was caught", file=stderr)
        elif sig == signal.SIGPIPE:
            print("The 'SIGPIPE' signal was caught\n", file=stderr)
            global_variables.pipe_flag = False
        elif sig in [signal.SIGINT, signal.SIGTSTP]:
            print("The 'SIGINT' or 'SIGTSTP' signal was caught\nThe file successfully changed", file=stderr)
            global_variables.file_signal_flag = True

        else:
            global_variables.pipe_flag = False
            print(getpid())
            kill(getpid(), signal.SIGKILL)
            print("The process was successfully killed", file=stderr)

    def add_process_pid(self, pid):
        self.__pids_set.add(pid)
