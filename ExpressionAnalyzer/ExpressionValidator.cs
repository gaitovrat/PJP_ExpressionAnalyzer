using System.Text.RegularExpressions;

namespace ExpressionAnalyzer;

public class ExpressionValidator
{
    private readonly Regex _regex;

    public ExpressionValidator()
    {
        _regex = new Regex("^(\\(?\\d+\\s?[\\+\\-\\*\\/]\\s?)+\\d+\\)?$");
    }

    public bool Validate(string expression)
    {
        return _regex.IsMatch(expression);
    }
}