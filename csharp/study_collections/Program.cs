// https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/collections
using System;
using System.Collections.Generic;
using System.Linq;

// Use:
//  - IEnumerable<T> for forward only iterations
//  - IDictionary<TKey, TValue>
//  - ReadOnlyCollection<T>
namespace StudyCollections {
	class Program {
		static void Main(string[] args) {
			Console.WriteLine("Hello World!");

			DemoList d1 = new DemoList();
			d1.DoDemo();
			d1.DoDemo2();
			d1.DoDemo3();

			DemoMultithreadQueue d2 = new DemoMultithreadQueue();
			d2.DoDemo();

			DemoDictionary d3 = new DemoDictionary();
			d3.DoDemo();

			DemoSort d4 = new DemoSort();
			d4.DoDemo();

			DemoCustomCollection d5 = new DemoCustomCollection();
			d5.DoDemo();

			DemoYield d6 = new DemoYield();
			d6.DoDemo();
		}
	}
}
