import java.util.*;
import java.util.stream.IntStream;
import java.util.IntSummaryStatistics;

public class SummaryStatistics {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		IntStream stream = IntStream.of(4, 5, 6, 7);

		IntSummaryStatistics summary_data = stream.summaryStatistics();

		System.out.println(summary_data);
	}

	static void test2() {
		IntStream stream = IntStream.range(5, 9);

		IntSummaryStatistics summary_data = stream.summaryStatistics();

		System.out.println(summary_data);
	}
}
