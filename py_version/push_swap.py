#!/usr/bin/python3

from stacks import Stacks
import sys

verb = False

class Solver:
    def __init__(self, stacks):
        if verb: print(stacks)
        self.stacks = stacks
        self.binds = []
        self.rot = []
        self.rev = False

    def solve(self):
        if self.stacks.is_sorted():
            return
        self.__exec("pb")
        while len(self.stacks.a) > 3:
            for k, v in self.__get_best_rot().items():
                for i in range(v):
                    self.__exec(k)
            self.__exec("pb")
        self.__small_sort()
        self.rev = True
        while len(self.stacks.b):
            for k, v in self.__get_best_rot().items():
                for i in range(v):
                    self.__exec(k)
            self.__exec("pa")
        self.__final_rot()

    def __final_rot(self):
        min_i = self.stacks.a.index(min(self.stacks.a))
        op = "ra" if (abs(min_i - len(self.stacks.a)) - 1
            < (min_i + 1) % len(self.stacks.a)) else "rra"
        while not self.stacks.is_sorted():
            self.__exec(op)

    def __small_sort(self):
        sort_op = [ lambda: (self.__exec("sa")
            if self.stacks.a[len(self.stacks.a) - 1]
            > self.stacks.a[len(self.stacks.a) - 2]
            else None),
            lambda: self.__exec("rra"),
            lambda: self.__exec("sa") ]

        while not self.stacks.is_sorted(full=False):
            sort_op.pop(0)()

    def __bind(self, a, b):
        self.binds.clear()
        
        for nb in a:
            next_i = b.index(min(b))
            for i in range(len(b)):
                if (b[next_i] < nb < b[i] or nb < b[i] < b[next_i]):
                    next_i = i
            self.binds.append(next_i)

    def __get_raw_rot(self):
        self.rot.clear()
        if self.rev:
            self.__bind(self.stacks.b, self.stacks.a)
            for i in range(len(self.stacks.b)):
                self.rot.append({ "ra": abs(self.binds[i] - (len(self.stacks.a) - 1)),
                    "rra": (self.binds[i] + 1) % len(self.stacks.a),
                    "rb": abs(i - (len(self.stacks.b) - 1)),
                    "rrb": (i + 1) % len(self.stacks.b) })
        else:
            self.__bind(self.stacks.a, self.stacks.b)
            for i in range(len(self.stacks.a)):
                self.rot.append({ "ra": abs(i - (len(self.stacks.a) - 1)),
                    "rra": (i + 1) % len(self.stacks.a),
                    "rb": abs(self.binds[i] - len(self.stacks.b)) % len(self.stacks.b),
                    "rrb": self.binds[i] })

    def __get_opt_rot(self):
        self.__get_raw_rot()
        for rot in self.rot:
            rot["min"] = {}
            rot["opt_r"] = {}
            rot["opt_rr"] = {}

            if rot["ra"] < rot["rra"]:
                rot["min"]["ra"] = rot["ra"]
            else:
                rot["min"]["rra"] = rot["rra"]
            if rot["rb"] < rot["rrb"]:
                rot["min"]["rb"] = rot["rb"]
            else:
                rot["min"]["rrb"] = rot["rrb"]
            rot["min"]["ops"] = sum(rot["min"].values())

            if rot["ra"] < rot["rb"]:
                rot["opt_r"]["rr"] = rot["ra"]
                rot["opt_r"]["rb"] = rot["rb"] - rot["ra"]
            else:
                rot["opt_r"]["rr"] = rot["rb"]
                rot["opt_r"]["ra"] = rot["ra"] - rot["rb"]
            rot["opt_r"]["ops"] = sum(rot["opt_r"].values())

            if rot["rra"] < rot["rrb"]:
                rot["opt_rr"]["rrr"] = rot["rra"]
                rot["opt_rr"]["rrb"] = rot["rrb"] - rot["rra"]
            else:
                rot["opt_rr"]["rrr"] = rot["rrb"]
                rot["opt_rr"]["rra"] = rot["rra"] - rot["rrb"]
            rot["opt_rr"]["ops"] = sum(rot["opt_rr"].values())

            del(rot["ra"])
            del(rot["rb"])
            del(rot["rra"])
            del(rot["rrb"])

    def __get_best_rot(self):
        self.__get_opt_rot()
        min_ops = min(val["ops"] for entry in self.rot for val in entry.values())
        for entry in self.rot:
            for ops in entry.values():
                if ops["ops"] == min_ops:
                    return { k: v for k, v in ops.items() if v and k != "ops" }

    def __exec(self, op, *, rev=False):
        if verb: print("---")
        print(op)
        self.stacks.do_op(op)
        if verb: print(self.stacks)

if __name__ == "__main__":
    if "-verb" in sys.argv:
        verb = True
        sys.argv.pop(sys.argv.index("-verb"))

    try:
        stacks = Stacks()
    except:
        exit("Error")

    solver = Solver(stacks)
    solver.solve()
