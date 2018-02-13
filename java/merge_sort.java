import java.util.Arrays;

public class merge_sort {


	public static void split_and_sort(int[] arr, int start, int finish, int[] tmp) {
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
		split_and_sort(arr, start, mid, tmp);
		split_and_sort(arr, mid + 1, finish, tmp);
		merge(arr, start, mid + 1, finish, tmp);
	}

	public static void merge(int[] arr, int p1, int p2, int finish, int[] tmp) {

		int i = p1;
		int j = p2;
		int k = p1;

		// Merging two arrays into tmp buffer using two pointers
		while ((i < p2) && (j <= finish)) {
			if (arr[i] < arr[j])
				tmp[k++] = arr[i++];
			else
				tmp[k++] = arr[j++];
		}

		// Copying the remaining part to the buffer
		for (; j <= finish; j++)
			tmp[k++] = arr[j];

		for (; i < p2; i++)
			tmp[k++] = arr[i];

		// Copying tmp buffer to the original array
		for (k = 0; k < (finish - p1 + 1); k++)
			arr[p1 + k] = tmp[p1 + k];
	}

	public static void msort(int[] arr) {
		int[] tmp = new int[arr.length];
		split_and_sort(arr, 0, arr.length - 1, tmp);
	}

	public static void main(String[] args) {
		int[] arr = {13, 7, 6, 45, 21, 9, 101, 102};
		int[] arr2 = {13, 7, 6, 45, 21, 9, 101, 102};

		System.out.printf("Origin: %s\n", Arrays.toString(arr));

		msort(arr);

		System.out.printf("Sorted: %s\n", Arrays.toString(arr));
		Arrays.sort(arr2); // that is too easy
		System.out.printf("Needed: %s\n", Arrays.toString(arr2));
	}
}
