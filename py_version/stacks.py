import sys

class Stacks:
    class StacksError(Exception): pass

    def __init__(self):
        self.a = [int(x) for x in sys.argv[:0:-1]]
        if len(set(self.a)) != len(self.a):
            raise Stacks.StacksError
        self.b = []
        self.ops = { "sa": lambda: Stacks.__swap(self.a),
            "sb": lambda: Stacks.__swap(self.b),
            "ss": lambda: Stacks.__comb(self.ops["sa"], self.ops["sb"]),
            "pa": lambda: Stacks.__push(self.a, self.b),
            "pb": lambda: Stacks.__push(self.b, self.a),
            "ra": lambda: Stacks.__rot(self.a),
            "rb": lambda: Stacks.__rot(self.b),
            "rr": lambda: Stacks.__comb(self.ops["ra"], self.ops["rb"]),
            "rra": lambda: Stacks.__rrot(self.a),
            "rrb": lambda: Stacks.__rrot(self.b),
            "rrr": lambda: Stacks.__comb(self.ops["rra"], self.ops["rrb"]) }

    def __str__(self):
        return "{}\n{}".format(str(self.a), str(self.b))

    def is_sorted(self, *, full=True):
        return (all((self.a[i] >= self.a[i + 1] for i in range(len(self.a) - 1)))
            and not (full and len(self.b)))

    def do_op(self, op):
        try:
            self.ops[op]()
        except IndexError:
            pass

    def __swap(s):
        s[-1], s[-2] = s[-2], s[-1]

    def __push(s1, s2):
        s1.append(s2.pop(len(s2) - 1))

    def __rot(s):
        s.insert(0, s.pop(len(s) - 1))

    def __rrot(s):
        s.append(s.pop(0))

    def __comb(op1, op2):
        error = None

        try:
            op1()
        except Exception as ex:
            error = ex
        op2()
        if error: raise error
