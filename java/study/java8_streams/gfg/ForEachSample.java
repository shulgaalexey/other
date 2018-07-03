import java.util.*;
import java.util.stream.Stream;

public class ForEachSample {
	public static void main(String[] args) {
		test1();
		test2();
		test3();
	}

	static void test1() {
		List<Integer> list = Arrays.asList(2, 4, 6, 8, 10);

		list.stream()
			.sorted(Comparator.reverseOrder())
			.forEach(System.out::println);
	}

	static void test2() {
		List<String> list = Arrays.asList("GFG", "Geeks", "for", "GeeksforGeeks");

		list.stream()
			.forEach(System.out::println);
	}

	static void test3() {
		Stream<String> stream = Stream.of("GFG", "Geeks", "for", "GeeksforGeeks");

		stream.sorted(Comparator.reverseOrder())
			.flatMap(str -> Stream.of(str.charAt(1)))
			.forEach(System.out::println);
	}
}
