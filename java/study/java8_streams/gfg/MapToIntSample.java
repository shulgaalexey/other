import java.util.*;

public class MapToIntSample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		List<String> list = Arrays.asList("3", "6", "8", "14", "15");

		list.stream()
			.mapToInt(num -> Integer.parseInt(num))
			.filter(num -> num % 3 == 0)
			.forEach(System.out::println);
	}

	static void test2() {
		List<String> list = Arrays.asList("Geeks", "for", "gfg",
				"GeeksforGeeks", "GeeksQuiz");

		list.stream()
			.mapToInt(str -> str.length())
			.forEach(System.out::println);
	}
}
