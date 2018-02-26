using System;
using System.Collections.Generic;

namespace StudyCollections {
	internal sealed class Car : IComparable<Car> {
		public string Name { get; set; }
		public int Speed {get; set; }
		public string Color { get; set; }

		// Needed for sort
		public int CompareTo(Car other) {
			int compare = String.Compare(this.Color, other.Color, true);

			// If colors are the same, compare the speed
			if (compare == 0) {
				compare = this.Speed.CompareTo(other.Speed);

				// Use descending order for speed
				compare = -compare;
			}

			return compare;
		}
	}

	internal sealed class DemoSort {
		public void DoDemo() {
			Console.WriteLine("Demo Sort");

			var cars = new List<Car> {
				{new Car() {Name = "car1", Color = "blue", Speed = 20}},
				{new Car() {Name = "car2", Color = "red", Speed = 50}},
				{new Car() {Name = "car3", Color = "green", Speed = 10}},
				{new Car() {Name = "car4", Color = "blue", Speed = 50}},
				{new Car() {Name = "car5", Color = "blue", Speed = 30}},
				{new Car() {Name = "car6", Color = "red", Speed = 60}},
				{new Car() {Name = "car7", Color = "green", Speed = 50}},
			};

			// Sort cars
			//   - by color alphabetically
			//   - by speed in descending order

			cars.Sort();

			foreach (Car thisCar in cars) {
				Console.Write(thisCar.Color.PadRight(5) + " ");
				Console.Write(thisCar.Speed.ToString() + " ");
				Console.Write(thisCar.Name);
				Console.WriteLine();
			}
		}
	}
};
