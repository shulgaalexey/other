using System;
using System.Collections;
using System.Collections.Generic;

namespace IteratorDemo {
	sealed class MyStack<T> : IEnumerable<T> {
		private T[] values = new T[100];
		private int top = 0;

		public void Push(T t) {
			values[top] = t;
			top++;
		}

		public T Pop() {
			top--;
			return values[top];
		}

		// This allows to use MyStack in the forreach statement
		public IEnumerator<T> GetEnumerator() {
			for (int index = top - 1; index >= 0; index--)
				yield return values[index];
		}

		IEnumerator IEnumerable.GetEnumerator() {
			return GetEnumerator();
		}

		public IEnumerable<T> TopToBottom {
			get { return this; }
		}

		public IEnumerable<T> BottomToTop {
			get {
				for (int index = 0; index <= top - 1; index++)
					yield return values[index];
			}
		}

		public IEnumerable<T> TopN(int itemsFromTop) {
			int startIndex = itemsFromTop >= top ? 0 : top - itemsFromTop;

			for (int index = top - 1; index >= startIndex; index--)
				yield return values[index];
		}
	}
}
