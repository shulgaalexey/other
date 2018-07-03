import java.util.*;
import java.util.concurrent.*;

public class Demo02 {
	public static void main(String[] args) {
		test1();
	}

	static void test1() {
		Executor executor = Executors.newFixedThreadPool(10);
		CompletableFuture<String> future = CompletableFuture.supplyAsync(() -> {
			try {
				TimeUnit.SECONDS.sleep(1);
			} catch (InterruptedException e) {
				throw new IllegalStateException(e);
			}

			return "Result of the asynchronous computation";
		}, executor);

		try {
		String result = future.get();
		System.out.println(result);
		} catch (InterruptedException | ExecutionException e) {
			System.out.println(e);
		}
	}
}
