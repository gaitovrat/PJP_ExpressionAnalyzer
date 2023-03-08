namespace ExpressionAnalyzer;

public class ExpressionExecutor
{
    public float Execute(string expression)
    {
        var values = new List<float>();
        var operators = new List<char>();
        
        for (var i = 0; i < expression.Length; i++)
        {
            if (expression[i] == '(')
            {
                operators.Add(expression[i]);
            }
            else if (expression[i] == ')')
            {
                while (operators[^1] != '(')
                {
                    Action(values, operators[^1]);
                    operators.RemoveAt(operators.Count - 1);
                }
                
                operators.RemoveAt(operators.Count - 1);
            }
            else if (Operation(expression[i]))
            {
                var operation = expression[i];
                while (operators.Count > 0 && Priority(operators[^1]) >= Priority(operation))
                {
                    Action(values, operation);
                    operators.RemoveAt(operators.Count - 1);
                }
                
                operators.Add(operation);
            }
            else
            {
                var number = "";
                for (; i < expression.Length && char.IsDigit(expression[i]); i++)
                {
                    number = number.Insert(number.Length, expression[i].ToString());
                }

                i--;
                int.TryParse(number, out var numberInt);
                values.Add(numberInt);
            }
        }

        while (operators.Count > 0)
        {
            Action(values, operators[^1]);
            operators.RemoveAt(operators.Count - 1);
        }
        
        return values[^1];
    }

    private int Priority(char operand)
    {
        return operand switch
        {
            '-' or '+' => 1,
            '*' or '/' => 2,
            _ => -1
        };
    }

    private bool Operation(char operand)
    {
        return operand is '+' or '-' or '*' or '/';
    }

    private void Action(List<float> values, char operand)
    {
        var right = values[^1];
        values.RemoveAt(values.Count - 1);
        var left = values[^1];
        values.RemoveAt(values.Count - 1);

        switch (operand)
        {
            case '+':
                values.Add(right + left);
                break;
            case '-':
                values.Add(right - left);
                break;
            case '*':
                values.Add(right * left);
                break;
            case '/':
                values.Add(right / left);
                break;
        }
    }
}