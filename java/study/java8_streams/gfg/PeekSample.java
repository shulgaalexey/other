import java.util.*;

public class PeekSample {
	public static void main(String[] args) {
		test1();
	}

	static void test1() {
		List<Integer> list = Arrays.asList(0, 2, 4, 6, 8, 10);

		list.stream()
			.peek(System.out::println)
			.count();
	}
}
