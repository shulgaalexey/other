import java.util.*;

public class MyDemo {
	public static void main(String[] args) {
		System.out.println("yo");

		List<Integer> list = Arrays.asList(1, 2, 3, 4, 5);

		MySpliterator<Integer> ms = MySpliterator.of(list);

		// Demo1
		/*
		//while (ms.tryAdvance(n -> System.out.print(n))) {
		while (ms.tryAdvance(System.out::print)) {
			System.out.println("+");
		}
		System.out.println("-");
		*/

		// Demo2
		System.out.println("One-by-one");
		ms.tryAdvance(System.out::println);
		ms.tryAdvance(System.out::println);

		System.out.println("Remaining");
		ms.forEachRemaining(System.out::print);
		System.out.println("");

		System.out.println("DONE");
	}
}
