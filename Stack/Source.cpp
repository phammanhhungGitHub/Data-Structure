#include<iostream>
#include<string>
#include<cassert>
#include"Stack.h"

int ArithmeticOperation(int operand1, int operand2, char op)
{
	switch (op)
	{
		case '+':
			return operand2 + operand1;
		case '-':
			return operand2 - operand1;
		case '*':
			return operand2 * operand1;
		case '/':
			assert(operand1 != 0 && "Divide by zero");
			return operand2 / operand1;
		default:
			throw std::invalid_argument("received invalid operator");
	}
}

int EvaluatePostfixExpression(std::string exp)
{
	int result = 0;
	Stack<int> stack;
	int num = 0;
	for (size_t i = 0; i < exp.length(); ++i)
	{
		if ('0' <= exp[i] && exp[i] <= '9')
		{
			num = num * 10 + exp[i] - 48;
		}
		else if (exp[i] == ' ' )
		{
			if (i > 0 && '0' <= exp[i - 1] && exp[i - 1] <= '9')
			{
				stack.Push(num);
				num = 0;
			}
		}
		else
		{
			int op1 = stack.Top();
			stack.Pop();
			int op2 = stack.Top();
			stack.Pop();
			stack.Push(ArithmeticOperation(op1, op2, exp[i]));
		}
	}

	return stack.Top();
}

bool HasHigherPrecedence(char op1, char op2)
{
	if (op1 == '+' || op1 == '-')
	{
		if (op2 == '*' || op2 == '/')
			return true;
		else if (op2 == '+' || op2 == '-')
			return false;
		else
			throw std::invalid_argument("Invalid operator");
	}
	else if (op1 == '*' || op1 == '/')
		return false;
	else
		throw std::invalid_argument("Invalid operator");
}

std::string InfixToPostfix(const std::string& exp)
{
	std::string result = "";
	Stack<char> opStack;
	for (size_t i = 0; i < exp.length(); ++i)
	{
		if ('0' <= exp[i] && exp[i] <= '9')
		{
			result += exp[i];
		}
		else if (exp[i] == '(')
		{
			opStack.Push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			while (opStack.Top() != '(')
			{
				result = result + " " + opStack.Top();
				opStack.Pop();
			}
			opStack.Pop();
			result = result + " ";
		}
		else
		{
			if (opStack.IsEmpty())
			{
				opStack.Push(exp[i]);
				result = result + " ";
				continue;
			}
			while (!opStack.IsEmpty() && opStack.Top() != '(' && !HasHigherPrecedence(opStack.Top(), exp[i]))
			{
				result = result + " " + opStack.Top();
				opStack.Pop();
			}
			result = result + " ";
			opStack.Push(exp[i]);
		}
	}

	while (!opStack.IsEmpty())
	{
		result = result + " " + opStack.Top();
		opStack.Pop();
	}
	return result;
}

int main()
{
	std::string infixExp;
	std::cout << "Enter a expression: ";
	getline(std::cin, infixExp);
	std::string postfixExp = InfixToPostfix(infixExp);
	std::cout << "Result: " << EvaluatePostfixExpression(postfixExp);
	//std::cout << postfixExp;

	return 0;
}