import java.util.stream.Stream;
import java.util.*;

public class NoMatchSample {
	public static void main(String[] args) {
		test1();
		test2();
		test3();
	}

	static void test1() {

		Stream<String> stream = Stream.of("CSE", "C++", "Jav", "DS");

		boolean answer = stream.noneMatch(str -> (str.length() == 4));

		System.out.println(answer);
	}

	static void test2() {
		List<Integer> list = Arrays.asList(4, 0, 6, 2);

		boolean answer = list.stream().noneMatch(num -> num < 0);

		System.out.println(answer);
	}

	static void test3() {
		Stream<String> stream =
			Stream.of("Geeks", "fOr", "GEEKQUIZ", "GeeksforGeeks", "CSe");

		boolean answer = stream.noneMatch(
				str -> Character.isUpperCase(str.charAt(1))
				&& Character.isLowerCase(str.charAt(2))
				&& str.charAt(0) == 'f');

		System.out.println(answer);
	}
}
