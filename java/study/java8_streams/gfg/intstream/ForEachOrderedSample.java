import java.util.*;
import java.util.stream.IntStream;

public class ForEachOrderedSample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		IntStream stream = IntStream.of(2, 3, 4, 5);

		stream.forEachOrdered(System.out::println);
	}

	static void test2() {
		IntStream stream = IntStream.range(2, 5);

		stream
			.parallel()
			.forEachOrdered(System.out::println);
	}
}
