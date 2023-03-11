package vsb.gai0010;

import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ExpressionValidator validator = new ExpressionValidator();
        ExpressionExecutor executor = new ExpressionExecutor();
        String[] expressions;

        System.out.println("PJP - ExpressionAnalyzer");
        expressions = new String[scanner.nextInt()];
        scanner.nextLine(); // clear

        for (int i = 0; i < expressions.length; i++) {
            expressions[i] = scanner.nextLine();
        }

        for (String expression : expressions) {
            if (validator.validate(expression)) {
                String expressionWithoutWhitespace = expression.replaceAll("\\s+", "");
                System.out.println(executor.execute(expressionWithoutWhitespace));
            } else {
                System.out.println("ERROR");
            }
        }
    }
}
