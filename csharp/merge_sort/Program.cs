using System;
using System.Collections.Generic;

namespace merge_sort {
	class Program {

		static void print(string tag, int[] arr) {
			Console.Write(tag);
			foreach (var i in arr)
				Console.Write($"{i} ");
			Console.Write(Environment.NewLine);
		}

		static void split_and_sort(ref int[] arr, int start, int finish, ref int[] tmp) {
			if (start >= finish)
				return;
			if ((finish - start) == 1) {
				if (arr[start] > arr[finish]) {
					int swp = arr[start];
					arr[start] = arr[finish];
					arr[finish] = swp;
				}
				return;
			}

			int mid = start + (finish - start) / 2;
			split_and_sort(ref arr, start, mid, ref tmp);
			split_and_sort(ref arr, mid + 1, finish, ref tmp);
			merge(ref arr, start, mid + 1, finish, ref tmp);
		}

		static void merge(ref int[] arr, int p1, int p2, int finish, ref int[] tmp) {
			int i = p1;
			int j = p2;
			int k = p1;

			while ((i < p2) && (j <= finish)) {
				if (arr[i] < arr[j])
					tmp[k++] = arr[i++];
				else
					tmp[k++] = arr[j++];
			}

			while (i < p2)
				tmp[k++] = arr[i++];
			while(j <= finish)
				tmp[k++] = arr[j++];

			for (k = p1; k <= finish; k++)
				arr[k] = tmp[k];
		}

		static void msort(ref int[] arr) {
			int[] tmp = new int[arr.Length];
			split_and_sort(ref arr, 0, arr.Length - 1, ref tmp);
		}

		static void Main(string[] args) {
			int[] arr = {13, 7, 6, 45, 21, 9, 101, 102};
			print("Origin: ", arr);
			msort(ref arr);
			print("Sorted: ", arr);
		}
	}
}
