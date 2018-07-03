import java.util.*;
import java.util.stream.IntStream;

public class GenerateSample {
	public static void main(String[] args) {
		test1();
	}

	static void test1() {
		IntStream stream = IntStream.generate(
				() -> { return (int)(Math.random() * 10000); });

		stream
			.limit(7)
			.forEach(System.out::println);
	}
}
