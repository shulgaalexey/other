import java.util.*;
import java.util.stream.Collectors;

public class MapSample {
	public static void main(String[] args) {
		test1();
		test2();
		test3();
	}

	static void test1() {
		System.out.println("The stream after applying the function is:");

		List<Integer> list = Arrays.asList(3, 6, 9, 12, 15);

		list.stream()
			.map(num -> num * 3)
			.forEach(System.out::println);
	}

	static void test2() {
		System.out.println("The stream after applying the function is:");

		List<String> list = Arrays.asList("geeks", "gfg", "g", "e", "e", "k", "s");

		List<String> answer = list.stream()
			.map(String::toUpperCase)
			.collect(Collectors.toList());

		System.out.println(answer);
	}

	static void test3() {
		System.out.println("The stream after applying the function is:");

		List<String> list = Arrays.asList("Geeks", "FOR", "GEEKSQUIZ", "Computer",
				"Science", "gfg");

		list.stream()
			.map(str -> str.length())
			.forEach(System.out::println);
	}
}
