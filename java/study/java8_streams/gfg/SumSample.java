import java.util.*;

public class SumSample {
	public static void main(String[] args) {
		test1();
	}

	static void test1() {
		List<Integer> list = new ArrayList<Integer>();

		list.add(1);
		list.add(5);
		list.add(6);
		list.add(7);
		list.add(8);
		list.add(9);
		list.add(10);

		System.out.println(sum(list));
	}

	static int sum(List<Integer> list) {
		return list.stream()
			.filter(i -> i > 5)
			.mapToInt(i -> i)
			.sum();
	}
}
