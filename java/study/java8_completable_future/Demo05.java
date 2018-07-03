import java.util.*;
import java.util.concurrent.*;

public class Demo05 {
	public static void main(String[] args) {
		try {
			CompletableFuture.supplyAsync(() -> {
				sleep(1);
				return "Knstn";
			}).thenApply(name -> {
				return "Hello " + name;
			}).thenAccept(product -> {
				System.out.println(product);
			}).thenRun(() -> {
				sleep(1);
				System.out.println("bye");
			}).get();
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
