#!/usr/bin/python3

from stacks import Stacks
import sys

verb = False

if __name__ == "__main__":
    if "-verb" in sys.argv:
        verb = True
        sys.argv.pop(sys.argv.index("-verb"))

    try:
        stacks = Stacks()
    except:
        exit("Error")

    while True:
        if verb:
            print(stacks)
            print('---')
        try:
            stacks.do_op(input())
            if verb: print('---')
        except KeyError:
            exit("Error")
        except EOFError:
            break

    print("OK" if stacks.is_sorted() else "KO")
