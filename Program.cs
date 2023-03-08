using ExpressionAnalyzer;

Console.WriteLine("PJP - ExpressionAnalyzer");

if (int.TryParse(Console.ReadLine(), out var expressionCount))
{
    var expressions = new string[expressionCount];
    var validator = new ExpressionValidator();
    var executor = new ExpressionExecutor();

    for (var index = 0; index < expressionCount; index++) 
    {
        expressions[index] = Console.ReadLine() ?? "";
    }
    expressions = expressions.Where(expression => expression != "").ToArray();
    
    foreach (var expression in expressions)
    {
        if (validator.Validate(expression))
        {
            var expressionWithoutWhitespace = expression.ToCharArray()
                .Where(ch => !char.IsWhiteSpace(ch)).ToArray();
            var value = executor.Execute(new string(expressionWithoutWhitespace));
            Console.WriteLine(value);
        }
        else
        {
            Console.WriteLine("ERROR");
        }
    }
}
else
{
    Console.WriteLine("Unable to parse it to number.");
}
