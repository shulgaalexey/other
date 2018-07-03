import java.util.*;
import java.util.stream.Stream;

public class ToArraySample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		Stream<Integer> stream = Stream.of(5, 6, 7, 8, 9, 10);

		Object[] arr = stream.toArray();

		System.out.println(Arrays.toString(arr));
	}

	static void test2() {
		Stream<String> stream = Stream.of("Geeks", "for", "gfg", "GeeksQuiz");

		Object[] arr = stream
			.filter(str -> str.startsWith("G"))
			.toArray();

		System.out.println(Arrays.toString(arr));
	}
}
