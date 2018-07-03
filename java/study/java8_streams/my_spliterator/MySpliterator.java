import java.util.*;

public class MySpliterator<T> {
	private List<T> dataSrc;
	Iterator<T> iterator;
	Iterator<T> bound;

	private MySpliterator(List<T> list) {
		dataSrc = list;
		iterator = dataSrc.iterator();
	}

	private MySpliterator(List<T> list, Iterator<T> bound) {
		dataSrc = list;
		iterator = dataSrc.iterator();
		this.bound = bound;
	}

	public boolean tryAdvance(MyConsumer<? super T> action) {
		if (!iterator.hasNext())
			return false;

		action.accept(iterator.next());
		return true;
	}

	public void forEachRemaining(MyConsumer<? super T> action) {
		while (iterator.hasNext())
			action.accept(iterator.next());
	}

	public MySpliterator<T> trySplit() {
		return null;
	}

	public static <T> MySpliterator<T> of(List<T> list) {
		return new MySpliterator<T>(list);
	}
}

