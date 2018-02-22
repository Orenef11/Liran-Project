from __future__ import print_function
from random import randint, uniform
from time import time, sleep
from os import path, makedirs
from shutil import rmtree
from multiprocessing import Pool, cpu_count
from sys import stderr, stdout
import signal
from signal_handler import SignalHandler


class FileQuestion(object):
    def __init__(self, file_path, timeout):
        SignalHandler([signal.SIGALRM, signal.SIGINT, signal.SIGTSTP])
        self.__file_path = file_path
        self.__lines_idx = 0
        self.__lines_size = 0
        self.__lines_list = []

        start = time()
        end = start + timeout
        while end > time():
            self.__create_questions()
        self.__save_to_file()
        print("The '{}' file created successfully".format(self.__file_path), file=stderr)

    def __str__(self):
        return "File name is '{}\nThe number of rows are '{}'\nCurrent row number is '{}'\n".format(
            self.__file_path, self.__lines_size, self.__lines_idx + 1)

    def __len__(self):
        return self.__lines_size

    def __create_questions(self):
        self.__lines_list.append("{} {} {}\n".format(round(uniform(1001, 2000), 5), round(uniform(1001, 2000), 5),
                                                   randint(0, 3)))
        self.__lines_size += 1

    def __save_to_file(self):
        a = self.__lines_list
        f = open(self.__file_path, 'w')
        f.writelines(a)
        f.close()

    def insert_lines(self, lines_list):
        self.__lines_size += len(lines_list)
        lines_list = [line + '\n' for line in lines_list]
        with open(self.__file_path, "a") as f:
            f.writelines(lines_list)

        self.__lines_idx += len(lines_list)

    def get_question(self):
        if self.__lines_idx >= len(self.__lines_list):
            print("The questions are finished with the current file, going to the next file", file=stderr)
            return "\n"
        self.__lines_idx += 1
        return self.__lines_list[self.__lines_idx - 1]
    # @property
    # def lines_idx(self):
    #     return self.__lines_idx

    # @lines_idx.setter
    # def lines_idx(self, lines_idx):
    #     self.__lines_idx = lines_idx


def create_file_question_obj(args):
    return FileQuestion(*args)


def create_files_question_with_multiprocess(folder_path_list):
    if len(folder_path_list) == 0:
        print("The files path list is empty", file=stderr)
        exit()
    folder_path = path.split(folder_path_list[0])[0]
    if path.isdir(folder_path):
        rmtree(folder_path)
        sleep(1)

    makedirs(folder_path)

    multiprocess_args_list = [(file_path, uniform(0, 1)) for file_path in folder_path_list]
    p = Pool(processes=cpu_count() * 2)
    files_question_obj_list = p.map(create_file_question_obj, multiprocess_args_list)
    p.close()
    print("Total files successfully created are '{}'".format(len(files_question_obj_list)), file=stderr)
    return files_question_obj_list


