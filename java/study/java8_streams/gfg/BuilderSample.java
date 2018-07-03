import java.util.*;
import java.util.stream.Stream;
import java.util.stream.Collectors;

public class BuilderSample {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		Stream.Builder<String> builder = Stream.builder();

		Stream<String> stream = builder
			.add("Geeks")
			.add("for")
			.add("Geeks")
			.build();

		stream
			.forEach(System.out::println);
	}

	static void test2() {
		Stream.Builder<String> builder = Stream.builder();

		Stream<String> stream = builder
			.add("Geeks")
			.add("for")
			.add("Geeks")
			.build();

		List<String> list = stream
			.map(String::toLowerCase)
			.collect(Collectors.toList());

		System.out.println(list);
	}
}
