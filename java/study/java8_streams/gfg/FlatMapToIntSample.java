import java.util.*;
import java.util.stream.IntStream;

public class FlatMapToIntSample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		List<String> list = Arrays.asList("1", "2", "3", "4", "5");

		list.stream()
			.flatMapToInt(num -> IntStream.of(Integer.parseInt(num)))
			.forEach(System.out::println);
	}

	static void test2() {
		List<String> list = Arrays.asList("Geeks", "GFG", "GeeksforGeeks", "gfg");

		list.parallelStream()
			.flatMapToInt(str -> IntStream.of(str.length()))
			.forEach(System.out::println);
	}
}
