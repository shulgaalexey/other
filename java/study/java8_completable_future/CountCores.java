import java.util.*;
import java.util.concurrent.*;


public class CountCores {
	public static void main(String[] args) {
		System.out.println(
				ForkJoinPool.commonPool().getPoolSize());
		System.out.println(
				Runtime.getRuntime().availableProcessors());
	}
}
