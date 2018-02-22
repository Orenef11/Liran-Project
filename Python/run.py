from __future__ import print_function
import socket
from os import getpid
import struct
import errno
from sys import stderr, stdout
from files_question_class import create_files_question_with_multiprocess
from signal_handler import SignalHandler
import signal
import global_variables
from time import sleep


def client(address_family, tcp_or_udf_protocol):
    files_path_list = []
    client = socket.socket(address_family, tcp_or_udf_protocol)
    try:
        client.connect(("localhost", global_variables.PORT))
    except socket.error as error:
        print("Connect error:", error, file=stderr)
        exit(1)

    try:
        print("Client send pid to server (pid={})".format(getpid()), file=stderr)
        client.send(struct.pack('I', getpid()))
    except socket.error as error:
        print("Send error:", error, file=stderr)
        exit(1)
    try:
        num_of_files = struct.unpack('i', client.recv(4))[0]
        files_path_list = [client.recv(struct.unpack('i', client.recv(4))[0]) for _ in xrange(num_of_files)]

    except socket.error as error:

        print("Receive error:", error, file=stderr)
        exit(1)

    return files_path_list


def send_to_pipe(question_str):
    print(question_str)
    stdout.flush()
    sleep(global_variables.question_wait)


def main():
    try:
        stdout.flush()
        finished_files_size, file_idx = 0, 0

        SignalHandler([signal.SIGALRM, signal.SIGPIPE, signal.SIGINT, signal.SIGTSTP])
        files_path_list = client(socket.AF_INET, socket.SOCK_STREAM)
        # files_path_list = ["Data/1.txt", "Data/2.txt"]
        files_size = len(files_path_list)
        files_question_obj_list = create_files_question_with_multiprocess(files_path_list)

        while global_variables.pipe_flag and finished_files_size != files_size:
            question_str = files_question_obj_list[file_idx].get_question()
            try:
                if question_str == "":
                    finished_files_size += 1
                    file_idx += 1
                    file_idx %= files_size
                else:
                    finished_files_size = 0
                    send_to_pipe(question_str)
                if global_variables.file_signal_flag is True:
                    global_variables.file_signal_flag = False
                    file_idx += 1
                    file_idx %= files_size
            except IOError as e:
                if e.errno == errno.EPIPE:
                    print("PythonBrokenPipeError: the pipe broken", file=stderr)
                else:
                    print("PythonUncatchEror: ", str(e), file=stderr)

        if finished_files_size == files_size:
            print("The program has finished reading the questions and therefore it ends", file=stderr)

    except Exception as e:
        print("RunPythonError:", str(e), file=stderr)


if __name__ == '__main__':
    main()
