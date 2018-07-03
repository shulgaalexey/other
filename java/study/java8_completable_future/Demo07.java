import java.util.*;
import java.util.concurrent.*;

public class Demo07 {
	public static void main(String[] args) {
		CompletableFuture<Double> future = getWeight()
			.thenCombine(getHeight(), (weight, height) -> {
				Double heightInMeter = height / 100;
				return weight / (heightInMeter * heightInMeter);
			});

		try {
			System.out.println("Your BMI is: " + future.get());
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	static CompletableFuture<Double> getWeight() {
		return CompletableFuture.supplyAsync(() -> {
			sleep(1);
			System.out.println("get weight");
			return 65.;
		});
	}

	static CompletableFuture<Double> getHeight() {
		return CompletableFuture.supplyAsync(() -> {
			sleep(1);
			System.out.println("get height");
			return 177.8;
		});
	}

	static void sleep(int sec) {
		try {
			TimeUnit.SECONDS.sleep(sec);
		} catch (InterruptedException e) {
			throw new IllegalStateException(e);
		}
	}
}
