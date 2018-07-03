import java.util.*;
import java.util.stream.Stream;
import java.util.stream.Collectors;

public class CountingSample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		Stream<Integer> i = Stream.of(1, 2, 3, 4, 5, 6);

		long count_int = i.collect(Collectors.counting());

		System.out.println(count_int);
	}

	static void test2() {
		Stream<String> s = Stream.of("ONE", "TWO", "THREE", "FOUR");

		long count_string = s.collect(Collectors.counting());

		System.out.println(count_string);
	}
}
