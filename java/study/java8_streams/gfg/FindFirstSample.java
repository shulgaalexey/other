import java.util.*;

public class FindFirstSample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		List<Integer> list = Arrays.asList(3, 5, 7, 9, 11);

		Optional<Integer> answer = list.stream().findFirst();

		if (answer.isPresent())
			System.out.println(answer.get());
		else
			System.out.println("no value");
	}

	static void test2() {
		List<String> list = Arrays.asList("GeeksforGeeks", "for", "GeeksQuiz", "GFG");

		Optional<String> answer = list.stream().findFirst();

		if (answer.isPresent())
			System.out.println(answer.get());
		else
			System.out.println("no value");
	}
}
