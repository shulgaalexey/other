import java.util.*;
import java.util.stream.Stream;

public class AllMatchSample {
	public static void main(String[] args) {
		test1();
		test2();
		test3();
	}

	static void test1() {
		List<Integer> list = Arrays.asList(3, 4, 6, 12, 20);

		boolean answer = list.stream()
			.allMatch(n -> n % 3 == 0);

		System.out.println(answer);
	}

	static void test2() {
		Stream<String> stream = Stream.of("Geeks", "for", "GeeksQuiz", "GeeksforGeeks");

		boolean answer = stream.allMatch(str ->	str.length() > 2);

		System.out.println(answer);
	}

	static void test3() {
		Stream<String> stream = Stream.of("Geeks", "for", "GeeksQuiz", "GeeksforGeeks");

		boolean answer = stream.allMatch(str -> Character.isUpperCase(str.charAt(1)));

		System.out.println(answer);
	}
}
