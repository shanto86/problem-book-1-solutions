"""
Problem: UVa 12412 A Typical Homework
Author: sjsakib
"""
from collections import OrderedDict


class Student:

    def __init__(self, sid, cid, name, ch, mat, en, pro):
        self.sid = sid
        self.cid = cid
        self.name = name
        self.ch = ch
        self.mat = mat
        self.en = en
        self.pro = pro

        self.total = ch + mat + en + pro
        self.average = "{:.2f}".format(self.total/4 + 1e-5)
        self.passed = (ch >= 60) + (mat >= 60) + (en >= 60) + (pro >= 60)
        self.rank = 0

    def __str__(self):
        return "{} {} {} {} {} {} {} {} {}".format(self.rank, self.sid, self.cid, self.ch, self.mat,
                                                   self.en, self.pro, self.total, self.average)


db = OrderedDict()


def printMainMenu():
    print("Welcome to Student Performance Management System (SPMS).\n")
    print("1 - Add")
    print("2 - Remove")
    print("3 - Query")
    print("4 - Show ranking")
    print("5 - Show Statistics")
    print("0 - Exit\n")


def update_index():
    all = sorted(db.values(), key=lambda s: s.total, reverse=True)
    rank = 1
    for i, s in enumerate(all):
        if i and s.total < all[i-1].total:
            s.rank = i + 1
            rank = i + 1
        else:
            s.rank = rank


def add():
    while True:
        print("Please enter the SID, CID, name and four scores. Enter 0 to finish.")
        inp = input().strip()
        if inp is '0':
            break
        inp = inp.split()
        sid, cid, name = inp[:3]
        ch, mat, en, pro = map(int, inp[3:])
        if db.get(sid) is None:
            db[sid] = Student(sid, cid, name, ch, mat, en, pro)
        else:
            print("Duplicated SID.")
    update_index()


def remove():
    while True:
        print("Please enter SID or name. Enter 0 to finish.")
        inp = input().strip()
        if inp == '0':
            break
        count = 0
        if db.get(inp) is not None:
            del db[inp]
            count = 1
        for s in list(db):
            if db[s].name == inp:
                del db[s]
                count += 1
        print("{} student(s) removed.".format(count))
    update_index()


def query():
    while True:
        print("Please enter SID or name. Enter 0 to finish.")
        inp = input().strip()
        if inp == '0':
            break
        if db.get(inp) is not None:
            print(db[inp])
        for s in db.values():
            if s.name == inp:
                print(s)


def show_statistics():
    ov = [0]*5
    ch = [0]*3
    mat = [0]*3
    en = [0]*3
    pro = [0]*3
    count = 0
    print("Please enter class ID, 0 for the whole statistics.")
    cid = input().strip()
    for s in db.values():
        if (int(cid) and s.cid == cid) or not int(cid):
            ov[s.passed] += 1
            count += 1

            mat[0] += s.mat
            mat[1] += s.mat >= 60
            mat[2] += s.mat < 60

            pro[0] += s.pro
            pro[1] += s.pro >= 60
            pro[2] += s.pro < 60

            ch[0] += s.ch
            ch[1] += s.ch >= 60
            ch[2] += s.ch < 60

            en[0] += s.en
            en[1] += s.en >= 60
            en[2] += s.en < 60
    if count != 0:
        mat[0] = "{:.2f}".format(mat[0]/count + 1e-5)
        ch[0] = "{:.2f}".format(ch[0]/count + 1e-5)
        en[0] = "{:.2f}".format(en[0]/count + 1e-5)
        pro[0] = "{:.2f}".format(pro[0]/count + 1e-5)
    else:
        mat[0] = "-nan"
        ch[0] = "-nan"
        en[0] = "-nan"
        pro[0] = "-nan"

    print("Chinese")
    print("Average Score:", ch[0])
    print("Number of passed students:", ch[1])
    print("Number of failed students:", ch[2])
    print("")

    print("Mathematics")
    print("Average Score:", mat[0])
    print("Number of passed students:", mat[1])
    print("Number of failed students:", mat[2])
    print("")

    print("English")
    print("Average Score:", en[0])
    print("Number of passed students:", en[1])
    print("Number of failed students:", en[2])
    print("")

    print("Programming")
    print("Average Score:", pro[0])
    print("Number of passed students:", pro[1])
    print("Number of failed students:", pro[2])
    print("")

    print("Overall:")
    print("Number of students who passed all subjects:", ov[4])
    print("Number of students who passed 3 or more subjects:", sum(ov[3:]))
    print("Number of students who passed 2 or more subjects:", sum(ov[2:]))
    print("Number of students who passed 1 or more subjects:", sum(ov[1:]))
    print("Number of students who failed all subjects:", ov[0])
    print("")


while True:
    printMainMenu()
    cmd = int(input())
    if cmd == 0:
        break
    elif cmd == 1:
        add()
    elif cmd == 2:
        remove()
    elif cmd == 3:
        query()
    elif cmd == 4:
        print("Showing the ranklist hurts students' self-esteem. Don't do that.")
    elif cmd == 5:
        show_statistics()
