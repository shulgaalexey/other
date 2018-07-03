import java.util.*;
import java.util.concurrent.*;

public class Demo {

	public static void main(String[] args) {
		completedFutureExample();

		System.out.println("OK");
	}

	static void completedFutureExample() {
		CompletableFuture cf = CompletableFuture.completedFuture("message");
		assert(cf.isDone());
		assert("message".equals(cf.getNow(null)));
	}
}
