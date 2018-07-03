import java.util.*;
import java.util.stream.IntStream;

public class FlatMapSample {
	public static void main(String[] args) {
		test1();
	}

	static void test1() {
		IntStream stream = IntStream.of(2, 3, 4, 5, 6);

		stream
			.flatMap(n -> IntStream.of(n, -n, n*n))
			.forEach(System.out::println);
	}
}
