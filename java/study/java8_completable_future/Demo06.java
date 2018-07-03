import java.util.*;
import java.util.concurrent.*;

public class Demo06 {
	public static void main(String[] args) {
		try {
		getUserDetails("Knstn")
			.thenCompose(user -> getCreditRating(user))
			.get();
		} catch (InterruptedException | ExecutionException e) {
			System.out.println(e.toString());
		}
	}

	static CompletableFuture<String> getUserDetails(String userId) {
		return CompletableFuture.supplyAsync(() -> {
			sleep(1);
			System.out.println("get user id");
			return "User: " + userId;
		});
	}

	static CompletableFuture<Double> getCreditRating(String userId) {
		return CompletableFuture.supplyAsync(() -> {
			sleep(1);
			System.out.println("get credit rating");
			return 3.14;
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
