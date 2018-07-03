import java.util.*;
import java.util.stream.*;

public class StreamDemo {
	public static void main(String[] args) {

		// Demonstration of map method
		List<Integer> number = Arrays.asList(2, 3, 4, 5);

		List<Integer> square = number.stream()
			.map(x -> x * x)
			.collect(Collectors.toList());
		System.out.println(square);

		// Demonstration of filter method
		List<String> names = Arrays.asList("Reflection", "Collection", "Stream");

		List<String> result = names.stream()
			.filter(s -> s.startsWith("S"))
			.collect(Collectors.toList());
		System.out.println(result);

		// Demonstration of sorted method
		List<String> show = names.stream()
			.sorted()
			.collect(Collectors.toList());
		System.out.println(show);

		// Collect method returns a set
		Set<Integer> squareSet = number.stream()
			.map(x -> x * x)
			.collect(Collectors.toSet());
		System.out.println(squareSet);

		// Demonstration of forEach method
		number.stream()
			.map(x -> x * x)
			.forEach(y -> System.out.println(y));

		// Demonstration of reduce method
		int even = number.stream()
			.filter(x -> x % 2 == 0)
			.reduce(0, (ans, i) -> ans + i);
		System.out.println(even);
	}
}
