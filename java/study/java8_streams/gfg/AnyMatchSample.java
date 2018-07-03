import java.util.*;
import java.util.stream.Stream;

public class AnyMatchSample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	private static void test1() {
		List<Integer> list = Arrays.asList(3, 4, 6, 12, 20);

		boolean answer = list.stream().anyMatch(n -> (n * (n + 1)) / 4 == 5);

		System.out.println(answer);
	}

	private static void test2() {
		Stream<String> stream =
			Stream.of("Geeks", "fOr", "GEEKSQUIZ", "GeeksforGeeks");

		boolean answer = stream.anyMatch(str -> Character.isUpperCase(str.charAt(1)));

		System.out.println(answer);
	}
}
