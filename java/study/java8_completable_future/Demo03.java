import java.util.*;
import java.util.concurrent.*;

public class Demo03 {
	public static void main(String[] args) {
		test1();
	}

	static void test1() {
		CompletableFuture<String> future = CompletableFuture.supplyAsync(() -> {
			sleep(1);
			System.out.println("return Alex");
			return "Alex";
		});

		CompletableFuture<String> greeting = future.thenApply(name -> {
			sleep(1);
			System.out.println("return Hello");
			return "Hello " + name;
		});

		try {
			System.out.println(greeting.get());
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
