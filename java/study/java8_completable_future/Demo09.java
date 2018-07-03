import java.util.*;
import java.util.concurrent.*;

public class Demo09 {
	public static void main(String[] args) {

		CompletableFuture<String> future1 = CompletableFuture.supplyAsync(() -> {
				sleep(1);
				return "Future 1";
		});

		CompletableFuture<String> future2 = CompletableFuture.supplyAsync(() -> {
			sleep(2);
			return "Future 2";
		});

		CompletableFuture<String> future3 = CompletableFuture.supplyAsync(() -> {
			sleep(3);
			return "Future 3";
		});

		CompletableFuture<Object> anyOfFuture = CompletableFuture.anyOf(
				future2, future1, future3);

		try {
			System.out.println(anyOfFuture.get());
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	static void sleep(int sec) {
		try {
			TimeUnit.SECONDS.sleep(sec);
		} catch (InterruptedException e) {
			throw new IllegalStateException(e);
		}
	}
}
