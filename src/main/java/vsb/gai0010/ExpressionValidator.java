package vsb.gai0010;

import java.util.regex.Pattern;

public class ExpressionValidator {
    final private Pattern pattern;

    public ExpressionValidator() {
        pattern = Pattern.compile("^(\\(?\\d+\\s?[+\\-*/]\\s?)+\\d+\\)?$");
    }

    public boolean validate(String expression) {
        return this.pattern.matcher(expression).find();
    }
}
