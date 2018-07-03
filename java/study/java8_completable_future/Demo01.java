import java.util.*;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.ExecutionException;

public class Demo01 {
	public static void main(String[] args) {
		test1();
		test2();
	}

	static void test1() {
		CompletableFuture<Void> future = CompletableFuture.runAsync(new Runnable() {
			@Override
			public void run() {
				try {
					TimeUnit.SECONDS.sleep(1);
				} catch (InterruptedException e) {
					throw new IllegalStateException(e);
				}
				System.out.println("I'll run in a separate thread than main thread");
			}
		});

		try {
			future.get();
		} catch (InterruptedException | ExecutionException e) {
			System.out.println(e.toString());
		}
	}

	static void test2() {
		CompletableFuture<Void> future = CompletableFuture.runAsync(() -> {
			try {
				TimeUnit.SECONDS.sleep(1);
			} catch (InterruptedException e) {
				throw new IllegalStateException(e);
			}
			System.out.println("Another extra thread reporting");
		});

		try {
			future.get();
		} catch (InterruptedException | ExecutionException e) {
			System.out.println(e.toString());
		}
	}
}
