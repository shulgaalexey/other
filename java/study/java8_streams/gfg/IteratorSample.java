import java.util.*;
import java.util.stream.IntStream;

public class IteratorSample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		IntStream stream = IntStream.of(2, 4, 6, 8);

		PrimitiveIterator.OfInt answer = stream.iterator();

		while (answer.hasNext())
			System.out.println(answer.nextInt());
	}

	static void test2() {
		IntStream stream = IntStream.range(2, 8);

		PrimitiveIterator.OfInt answer = stream.iterator();

		while (answer.hasNext())
			System.out.println(answer.nextInt());
	}
}
