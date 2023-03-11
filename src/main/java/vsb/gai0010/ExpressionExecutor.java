package vsb.gai0010;

import java.util.ArrayList;
import java.util.List;

public class ExpressionExecutor {
    private final List<Float> values;
    private final List<Character> operators;

    public ExpressionExecutor() {
        this.values = new ArrayList<>();
        this.operators = new ArrayList<>();
    }

    public float execute(String expression) {
        for (int i = 0; i < expression.length(); i++) {
            if (expression.charAt(i) == '(') {
                this.operators.add(expression.charAt(i));
            } else if (expression.charAt(i) == ')') {
                while (this.operators.get(this.operators.size() - 1) != '(') {
                    this.action(this.operators.remove(this.operators.size() - 1));
                }
                this.operators.remove(this.operators.size() - 1);
            } else if (isOperation(expression.charAt(i))) {
                char operation = expression.charAt(i);

                while (this.operators.size() > 0 &&
                        (priority(this.operators.get(this.operators.size() - 1)) >=
                                priority(operation))) {
                    this.action(this.operators.remove(this.operators.size() - 1));
                }

                this.operators.add(operation);
            } else {
                StringBuilder builder = new StringBuilder();
                for (; i < expression.length() && Character.isDigit(expression.charAt(i)); i++) {
                    builder.insert(0, expression.charAt(i));
                }
                i--;
                float number = Float.parseFloat(builder.toString());
                this.values.add(number);
            }
        }

        while (this.operators.size() > 0) {
            this.action(this.operators.remove(this.operators.size() - 1));
        }

        return this.values.get(this.values.size() - 1);
    }

    private static int priority(char operand) {
        switch (operand) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            default:
                return -1;
        }
    }

    private static boolean isOperation(char operand) {
        return operand == '+' || operand == '-' || operand == '*' || operand == '/';
    }

    private void action(char operand) {
        float right  = this.values.remove(this.values.size() - 1);
        float left = this.values.remove(this.values.size() - 1);

        switch (operand) {
            case '+':
                this.values.add(right + left);
                break;
            case '-':
                this.values.add(right - left);
                break;
            case '*':
                this.values.add(right * left);
                break;
            case '/':
                this.values.add(right / left);
                break;
        }
    }
}
