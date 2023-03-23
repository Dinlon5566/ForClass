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
    def __init__(self) -> None:
        self.methods = [self.falsePostion, self.bisectionMethod, self.newtonMethod, self.secantMethod]

    def falsePostion(self, function, a, b, EPS=0.00001):
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
        
    def secantMethod(self, function, x0, x1, EPS):
        f0 = function(x0)
        f1 = function(x1)

        if abs(f1) < EPS:
            return x1

        try:
            x2 = x1 - f1*(x1 - x0)/(f1 - f0)
        except ZeroDivisionError:
            raise ValueError("Divided by zero")

        return self.secantMethod(function, x1, x2, EPS)

    def fixedPointMethod_(self, function, x, EPS=0.00001):
        Fx = function(x)
        while abs(Fx-x) > EPS:
            x = Fx
            Fx = function(x)
        return x
    
    def fixedPointMethod(self, function, a, b, EPS=0.00001):
        return self.fixedPointMethod_(function, (a+b)/2, EPS)

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
            except OverflowError:
                result.append('')

        return result

def solutionFunction(function, method, left, right, step, EPS):
    sol = Solution()
    print('f(x) : ', function.__name__)
    print('method : ', method.__name__)
    result = sol.findSolution(function, method, left, right, step, EPS)
    checkResult(function, result)

def checkResult(function, result):
    for i in result:
        print('f(', i, ') = ', function(i))
        if abs(function(i)) > 0.00001:
            print('Error!')
    print('Correct!')

def main():
    eq = Equation()
    sol = Solution()

    # Set values here
    left = -50
    right = 50
    step = 0.01
    EPS = 0.0000001

    for method in sol.methods:
        for function in eq.functions:
            solutionFunction(function, method, left, right, step, EPS)


if __name__ == '__main__':
    main()
