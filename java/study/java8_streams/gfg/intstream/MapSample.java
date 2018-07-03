import java.util.*;
import java.util.stream.IntStream;

public class MapSample {
	public static void main(String[] args) {
		test1();
	}

	static void test1() {
		IntStream stream = IntStream.range(2, 5);

		stream
			.parallel()
			.map(n -> n * n)
			.forEachOrdered(System.out::println);
	}
}
