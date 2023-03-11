"""
Numerical Methods Assignment - Solving Polynomials with False Position Method
Author : Dinlon5566(408261292), All rights reserved, no plagiarism
"""
import math


class Equation:
    def f1(self, x):
        return pow(math.e, 2*x) - pow(x, 3)+2*x-7

    def f2(self, x):
        return pow(x, 6)-3*(pow(x, 5))+2*(pow(x, 2))-7*x-12

    def f3(self, x):
        return pow(x, 2)*math.sin(3*x)-4*x*math.cos(x*2)-x-3

    def __init__(self) -> None:
        self.functions = [self.f1, self.f2, self.f3]


class Solution:
    def falsePostion(self, function, a, b, EPS=0.00001):
        # find the value of f(a),f(b)
        Fa = function(a)
        Fb = function(b)

        if (Fa*Fb > 0):
            raise ValueError("The function has no root in the interval")

        x1 = a+function(a)*(b-a)/(function(a)-function(b))
        Fx1 = function(x1)

        if (Fx1 == 0):
            return x1
        elif (abs(Fx1) < EPS):
            return x1
        elif (Fx1*Fa < 0):
            return self.falsePostion(function, a, x1, EPS)
        else:
            return self.falsePostion(function, x1, b, EPS)

    def bisectionMethod(self, function, a, b, EPS=0.00001):
        # find the value of f(a),f(b)
        Fa = function(a)
        Fb = function(b)

        if (Fa*Fb > 0):
            raise ValueError("The function has no root in the interval")

        x1 = (a+b)/2
        Fx1 = function(x1)
        if (Fx1 == 0):
            return x1
        elif (abs(Fx1) < EPS):
            return x1
        elif (Fx1*Fa < 0):
            return self.bisectionMethod(function, a, x1, EPS)
        else:
            return self.bisectionMethod(function, x1, b, EPS)

    def findSolution(self, EqFuntion, solFuntion, left, right, step=0.1, EPS=0.00001):
        if (left > right):
            left, right = right, left
        result = []
        i = left

        while (i <= right):
            i += step
            if (EqFuntion(i)*EqFuntion(i+step) < 0):
                result.append(solFuntion(EqFuntion, i, i+step, EPS))
            elif (EqFuntion(i) == 0):
                result.append(i)

        return result


def main():
    eq = Equation()
    sol = Solution()

    # Set values here
    left = -10
    right = 10
    step = 0.1
    EPS = 0.000000001
    method = sol.bisectionMethod

    for f in eq.functions:
        print("The roots of the function by are: ")
        result = sol.findSolution(f, method, left, right, step, EPS)
        print(result)


if __name__ == '__main__':
    main()
