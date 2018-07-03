import java.util.*;
import java.util.concurrent.*;

public class Demo04 {
	public static void main(String[] args) {
		CompletableFuture<String> future = CompletableFuture.supplyAsync(() -> {
			sleep(1);
			return "Alex";
		}).thenApply(name -> {
			return "Hello " + name;
		}).thenApply(greeting -> {
			return greeting + ", welcome to Java 8 completable futures";
		});

		try {
			System.out.println(future.get());
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	static void sleep(int s) {
		try {
			TimeUnit.SECONDS.sleep(s);
		} catch (InterruptedException e) {
			throw new IllegalStateException(e);
		}
	}
}
