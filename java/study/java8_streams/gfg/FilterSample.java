import java.util.*;
import java.util.stream.Stream;

public class FilterSample {
	public static void main(String[] args) {
		test1();
		test2();
		test3();
	}

	static void test1() {
		List<Integer> list = Arrays.asList(3, 4, 25, 6, 12, 20);

		list.parallelStream()
			.filter(num -> num % 5 == 0)
			.forEach(System.out::println);
	}

	static void test2() {
		Stream<String> stream = Stream.of("Geeks", "fOr", "GEEKSQUIZ", "GeeksforGeeks");

		stream
			.filter(str -> Character.isUpperCase(str.charAt(1)))
			.forEach(System.out::println);
	}

	static void test3() {
		Stream<String> stream = Stream.of("Geeks", "fOr", "GEEKSQUIZ", "GeeksforGeeks");

		stream
			.filter(str -> str.endsWith("s"))
			.forEach(System.out::println);
	}

}
