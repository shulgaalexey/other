import java.util.*;

public class MapToLongSample {

	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		System.out.println("The stream after applying the function is:");

		List<String> list = Arrays.asList("25", "225", "1000", "20", "15");

		list.stream()
			.mapToLong(num -> Long.parseLong(num))
			.filter(num -> Math.sqrt(num) / 5 == 3)
			.forEach(System.out::println);
	}

	static void test2() {
		List<String> list = Arrays.asList("Data Structures", "JAVA", "OOPS",
				"GeeksforGeeks", "Algorithms");

		list.stream()
			.mapToLong(str -> Long.bitCount(str.length()))
			.forEach(System.out::println);
	}
}
