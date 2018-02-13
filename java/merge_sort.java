import java.util.Arrays;

public class merge_sort {


	public static void split_and_sort(int[] arr, int start, int finish) {
		if (start < finish) {
			if (start == finish)
				return;
			if ((finish - start) == 2) {
				if (arr[start] > arr[finish]) {
					int tmp = arr[start];
					arr[start] = arr[finish];
					arr[finish] = tmp;
				}
				return;
			}
			int mid = (finish - start) / 2;
			split_and_sort(arr, start, mid);
			split_and_sort(arr, mid + 1, finish);
			merge(arr, start, mid + 1, finish);
		}
	}

	public static void merge(int[] arr, int p1, int p2, int finish) {
		//int[finish - p1] tmp
		int[] tmp = new int[finish - p1];

		int i = p1;
		int j = p2;
		int k = 0;

		// Merging two arrays into tmp buffer using two pointers
		while ((i < p2) && (j <= finish)) {
			if (arr[i] < arr[j]) {
				tmp[k] = arr[i];
				k++;
				i++;
			} else {
				tmp[k] = arr[j];
				k++;
				j++;
			}
		}

		// Copying the remaining part to the buffer
		if (j < finish) {
			for (; j <= finish; j++)
				tmp[k++] = arr[j];
		} else {
			for (; i < p2; i++)
				tmp[k++] = arr[i];
		}

		// Copying tmp buffer to the original array
		for (i = 0; i < tmp.length; i++)
			arr[p1 + i] = tmp[i];
	}

	public static void msort(int[] arr) {

		//Arrays.sort(arr); // that is too easy

		split_and_sort(arr, 0, arr.length - 1);
	}

	public static void main(String[] args) {
		int[] arr = {13, 7, 6, 45, 21, 9, 101, 102};

		msort(arr);

		System.out.printf("Sorted: %s", Arrays.toString(arr));
	}
}
