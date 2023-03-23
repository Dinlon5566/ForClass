"""
Numerical Methods Assignment - Solving Polynomials with False Position Method
Author : Dinlon5566(408261292), All rights reserved, no plagiarism
"""
import math
import numpy as np


class Equation:
    def f1(self, x):
        return math.e**x-5.6*x*math.sin(x)+3.2*x+1.8

    def f2(self, x):
        return 1+x**2-math.tan(x)

    def df1(self, x):
        return math.e**x-5.6*(math.sin(x)+x*math.cos(x))+3.2
    
    def df2(self, x):
        return 2*x-1/(math.cos(x)**2)
        
    def __init__(self) -> None:
        self.functions = [self.f1, self.f2]
        self.dfunctions = {'f1': self.df1, 'f2': self.df2}
        


class Solution:
    def falsePostion(self, function, a, b, EPS=0.00001):
        # find the value of f(a),f(b)
        Fa = function(a)
        Fb = function(b)

        if Fa*Fb > 0:
            raise ValueError("The function has no root in the interval")

        x1 = a+function(a)*(b-a)/(function(a)-function(b))
        Fx1 = function(x1)

        if abs(Fx1) < EPS:
            return x1
        elif Fx1*Fa < 0:
            return self.falsePostion(function, a, x1, EPS)
        else:
            return self.falsePostion(function, x1, b, EPS)

    def modiyFalsePostion(self, function, a, b, EPS=0.00001):
        # find the value of f(a),f(b)
        Fa = function(a)
        Fb = function(b)/2

        if Fa*Fb > 0:
            raise ValueError("The function has no root in the interval")

        x1 = a+Fa*(b-a)/(Fa-Fb)
        Fx1 = function(x1)

        if abs(Fx1) < EPS:
            return x1
        elif Fx1*Fa < 0:
            return self.falsePostion(function, x1, a, EPS)
        else:
            return self.falsePostion(function, x1, b, EPS)

    def bisectionMethod(self, function, a, b, EPS=0.00001):
        # find the value of f(a),f(b)
        Fa = function(a)
        Fb = function(b)

        if Fa*Fb > 0:
            raise ValueError("The function has no root in the interval")

        x1 = (a+b)/2
        Fx1 = function(x1)

        if abs(Fx1) < EPS:
            return x1
        elif Fx1*Fa < 0:
            return self.bisectionMethod(function, a, x1, EPS)
        else:
            return self.bisectionMethod(function, x1, b, EPS)

    def newtonMethod_(self, function,Df, x, EPS=0.00001):
        Fx = function(x)
        while abs(Fx) > EPS:
            if abs(Df(x)) < EPS:
                return None
            x = x - Fx/Df(x)
            Fx = function(x)
        return x

    def newtonMethod(self, function, a, b, EPS=0.00001):
        eq=Equation()
        Df=eq.dfunctions[function.__name__]
        return self.newtonMethod_(function,Df, (a+b)/2, EPS)
        

    def findSolution(self, EqFuntion, solFuntion, left, right, step=0.1, EPS=0.00001):
        if left > right:
            left, right = right, left
        result = []
        i = left
        RecursionErrorTimes = 0

        while i <= right:
            i += step

            try:
                if EqFuntion(i)*EqFuntion(i + step) < 0:
                    result.append(solFuntion(EqFuntion, i, i+step, EPS))
                elif EqFuntion(i) == 0:
                    result.append(i)
            except RecursionError:
                RecursionErrorTimes += 1

        return result


def main():
    eq = Equation()
    sol = Solution()

    # Set values here
    left = -50
    right = 50
    step = 0.0001
    EPS = 0.0000001

    print('\nSolution by Bisection Method:')
    method = sol.bisectionMethod
    t = 1
    for f in eq.functions:
        result = sol.findSolution(f, method, left, right, step, EPS)
        print('function ', t, ':\n', result)
        t += 1

    print('\nSolution by False Position Method:')
    method = sol.falsePostion
    t = 1
    for f in eq.functions:
        result = sol.findSolution(f, method, left, right, step, EPS)
        print('function ', t, ':\n', result)
        t += 1

    print('\nSolution by newtonMethod :')
    method = sol.newtonMethod
    t = 1
    for f in eq.functions:
        result = sol.findSolution(f, method, left, right, step, EPS)
        print('function ', t, ':\n', result)
        t += 1


if __name__ == '__main__':
    main()
