# coding=utf-8
import math

MAX_ITERATIONS = 100

def function(t):
    cs = 9.0
    c0 = 2.0
    ka = 0.88

    return cs - (cs - c0) * math.exp(-ka * t)


def derivative(t):
    cs = 9.0
    c0 = 2.0
    ka = 0.88

    return ka * (cs - c0) * math.exp(-ka * t)


def function_zero(t):
    return 1 - 7 * math.exp(-0.88 * t)


def derivative_zero(t):
    return 0.88 * 7 * math.exp(-0.88 * t)


def newton_raphson_core(x0):
    return x0 - function(x0)/derivative(x0)


def newton_raphson(x0, tolerance):
    x1 = 0
    error = tolerance + 1
    iteration = 0

    try:
        while error > tolerance and iteration < MAX_ITERATIONS:
            x1 = newton_raphson_core(x0)
            error = math.fabs(x1 - x0)
            #print("x0:%lf. x1:%lf. erro:%lf.funcao %lf\n", x0, x1, error, function(x1))
            x0 = x1
            iteration = iteration + 1

        if iteration >= MAX_ITERATIONS:
            print("Nao ficou dentro da tolerancia de erro em " + str(MAX_ITERATIONS) + "iteracoes.")
    except OverflowError:
        print("Erro: Overflow, nao foi possível convergir.")
    except:
        print("Erro! Nao foi possível convergir.")

    return x1


print("\nt = 1 dia")
print("resultado =", newton_raphson(1.0, 10E-6))
print("")
print("t = 5 dias")
print("resultado =", newton_raphson(5.0, 10E-6))
print("")
print("t = 10 dias")
print("resultado =", newton_raphson(10.0, 10E-6))
