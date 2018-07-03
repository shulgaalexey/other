import java.util.*;
import java.util.concurrent.*;

public class Demo10 {
	static CompletableFuture<String> getMaturity(Integer age) {
		return CompletableFuture.supplyAsync(() -> {
				if (age < 0)
					throw new IllegalArgumentException("Age can not be negative");

				if (age > 18)
					return "Adult";
				else
					return "Child";
		//}).exceptionally(ex -> {
		//	System.out.println("Oops! An exception - " + ex.getMessage());
		//	return "Unknown!";
		//});
		}).handle((res, ex) -> {
			if (ex != null) {
				System.out.println("Oops! An exception - " + ex.getMessage());
				return "Unknown!";
			}

			return res;
		});
}

public static void main(String[] args) {

	CompletableFuture<String> maturityFuture =
		getMaturity(-1);
		//getMaturity(1);
		//getMaturity(100);


	try {
		System.out.println("Maturity: " + maturityFuture.get());
	} catch (InterruptedException | ExecutionException e) {
		System.out.println(e.toString());
	}
}
}
