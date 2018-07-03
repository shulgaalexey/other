import java.util.*;
import java.util.concurrent.*;
import java.util.stream.*;

public class Demo08 {
	public static void main(String[] args) {

		// Download contents of all pages
		List<CompletableFuture<String>> webPages = IntStream.range(1, 20)
			.mapToObj(Integer::toString) // Iterating throw all pages
			.map(str -> "Web Page URL " + str) // Generating web page URL
			.map(webPageURL -> downloadWebPage(webPageURL)) // Downloading web page
			.collect(Collectors.toList());

		// Create a combined Future using allOf()
		CompletableFuture<Void> allFutures = CompletableFuture.allOf(
				webPages.toArray(new CompletableFuture[webPages.size()]));

		CompletableFuture<List<String>> allPagesContentsFuture =
			allFutures.thenApply(v -> {
				return webPages.stream()
					.map(future -> future.join())
					.collect(Collectors.toList());
			});

		CompletableFuture<Long> countFuture =
			allPagesContentsFuture.thenApply(page -> {
			return page.stream()
				.filter(pageContent -> pageContent.contains("Web"))
				.count();
		});

		try {
		System.out.println("Number of pages containing Web keyword is " +
				countFuture.get());
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	static CompletableFuture<String> downloadWebPage(String pageLink) {
		System.out.println("Download page: " + pageLink);
		return CompletableFuture.supplyAsync(() -> {
			sleep(1);
			return "Ready page src " + pageLink;
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
