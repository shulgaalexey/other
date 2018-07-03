import java.util.*;
import java.util.OptionalInt;
import java.util.stream.IntStream;

public class FindAnySample {
	public static void main(String[] args) {
		test1();
		test2();
		test3();
	}

	static void test1() {
		List<Integer> list = Arrays.asList(2, 4, 6, 8, 10);

		Optional<Integer> answer = list.stream().findAny();

		if (answer.isPresent())
			System.out.println(answer.get());
		else
			System.out.println("no value");
	}

	static void test2() {
		List<String> list = Arrays.asList("Geeks", "for", "GeeksQuiz", "GFG");

		Optional<String> answer = list.parallelStream().findAny();

		if (answer.isPresent())
			System.out.println(answer.get());
		else
			System.out.println("No value");
	}

	static void test3() {
		IntStream stream = IntStream.of(4, 5, 8, 10, 12, 16)
			.parallel();

		stream = stream.filter(i -> i % 4 == 0);

		OptionalInt answer = stream.findAny();
		if (answer.isPresent())
			System.out.println(answer.getAsInt());
		else
			System.out.println("No result");
	}
}
