import java.util.*;
import java.util.stream.Stream;

public class ForEachOrderedSample {
	public static void main(String[] args) {
		test1();
		test2();
		test3();
	}

	static void test1() {
		List<Integer> list = Arrays.asList(10, 19, 20, 2);

		list.parallelStream()
			.forEachOrdered(System.out::println);
	}

	static void test2() {
		List<String> list = Arrays.asList("GFG", "Geeks", "for", "GeeksforGeeks");

		list.stream()
			.forEachOrdered(System.out::println);
	}

	static void test3() {
		Stream<String> stream = Stream.of("GFG", "Geeks",  "for", "GeeksforGeeks");

		stream.parallel();

		stream.flatMap(str -> Stream.of(str.charAt(2)))
			.forEachOrdered(System.out::println);
	}
}
