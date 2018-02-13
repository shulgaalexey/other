using System;
using System.Collections.Generic;

namespace lists {
	class Item<T> {
		public Item(T data, Item<T> next = null) {
			Data = data;
			Next = next;
		}
		public T Data { get; }
		public Item<T> Next { get; set; }
		public override string ToString() => "" + Data;
	}

	class Program {
		static void workingWithStrings() {
			var names = new List<string> {"<name>", "RRR", "Anna", "Felipe"};
			foreach (var name in names) {
				Console.WriteLine($"Hello {name.ToUpper()}!");
			}
			Console.WriteLine($"Totally names: {names.Count}");

			Console.WriteLine($"Index of Anna: {names.IndexOf("Anna")}");

			names.Sort();
			Console.WriteLine("Sorted list:");
			foreach (var name in names) {
				Console.WriteLine($"{name} ");
			}
		}

		static void trace<T>(Item<T> lst) {
			while (lst != null) {
				Console.WriteLine(lst.Data);
				lst = lst.Next;
			}
		}

		static Item<T> reverse<T>(Item<T> lst) {
			var head = lst;
			var cur = (head != null) ? head.Next : null;
			head.Next = null;
			while (cur != null) {
				var next = cur.Next;
				cur.Next = head;
				head = cur;
				cur = next;
			}
			return head;
		}


		static void Main(string[] args) {
			//workingWithStrings();

			// List:
			//
			//		a -> b -> c -> d -> e -> null
			//
			// to be converted into
			//
			//		e -> d -> c -> b -> a -> null
			//
			var e = new Item<char>('e');
			var d = new Item<char>('d', e);
			var c = new Item<char>('c', d);
			var b = new Item<char>('b', c);
			var a = new Item<char>('a', b);


			Console.WriteLine("Initial list:");
			trace(a);

			Console.WriteLine("Reversing...");
			var reversedList = reverse(a);

			Console.WriteLine("Reversed List:");
			trace(reversedList);
		}
	}
}
