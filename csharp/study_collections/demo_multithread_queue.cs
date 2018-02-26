using System;
using System.Collections.Concurrent;
using System.Threading;
using System.Threading.Tasks;

namespace StudyCollections {
	internal sealed class DemoMultithreadQueue {
		public void DoDemo() {
			Console.WriteLine("Demo Multithreaded Queue");

			var cq = new ConcurrentQueue<int>();

			// Populate the queue with init walues
			for (int i = 0; i < 10000; i++)
				cq.Enqueue(i);

			int result;
			if (!cq.TryPeek(out result)) {
				Console.WriteLine("CQ: TryPeek failed when it should have succeeded");
			} else if (result != 0) {
				Console.WriteLine("CQ: Expected TryPeek result of 0, got {0}", result);
			}

			int outerSum = 0;

			// Action to consume the ConcurrentQueue
			Action action = () => {
				int localSum = 0;
				int localValue;
				while (cq.TryDequeue(out localValue)) {
					localSum += localValue;
				}
				Interlocked.Add(ref outerSum, localSum);
			};

			// Parallel tasks scheduled
			Parallel.Invoke(action, action, action, action);

			Console.WriteLine("outerSum = {0}, should be 49995000", outerSum);
		}
	}
}
