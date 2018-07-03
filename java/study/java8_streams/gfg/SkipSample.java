import java.util.*;
import java.util.stream.IntStream;

public class SkipSample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		IntStream stream = IntStream.range(5, 12);

		stream
			.skip(4)
			.forEach(System.out::println);
	}

	static void test2() {
		IntStream stream = IntStream.range(5, 12);

		stream
			.parallel()
			.skip(4)
			.forEach(System.out::println);
	}
}
