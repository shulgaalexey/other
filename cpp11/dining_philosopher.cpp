#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <utility>
#include <chrono>
#include <functional>
#include <atomic>
using namespace std;

class Eater {
	const int max_eat_times = 3;
	int name;
	unique_lock<mutex> left_fork_acquired;
	unique_lock<mutex> right_fork_acquired;
	atomic_bool &keep_eating;
	int times_ate;
public:
	Eater(mutex &left_fork, mutex &right_fork, atomic_bool &keep_eating, int name) :
		name{name},
		left_fork_acquired{left_fork, defer_lock},
		right_fork_acquired{right_fork, defer_lock},
		keep_eating{keep_eating},
		times_ate{0} {
			//cout << "Construct eater: " << name << endl;
		}
	~Eater() {
			//cout << "Destruct eater: " << name << endl;
	}
	static void eat(Eater *eater) {
		while (eater->keep_eating && (eater->times_ate < eater->max_eat_times)) {
			eater->take_left_fork();
			if (eater->take_right_fork()) {
				eater->do_eat();
				eater->put_right_fork();
			}
			eater->put_left_fork();
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << "Eater: " << eater->name << " done\n";
	}
	int get_name() const { return name; }
	int get_times_ate() const { return times_ate; }
private:
	void do_eat() {
		++times_ate;
		cout << "Eater eating: " << name << "   ate:   " << times_ate << "times\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	void take_left_fork() {
		//cout << "Eater [" << name << "] takes left fork:..." << endl;
		left_fork_acquired.lock();
		//cout << "Eater [" << name << "] takes left fork:...ok" << endl;
	}
	void put_left_fork() {
		//cout << "Eater [" << name << "] puts left fork:..." << endl;
		left_fork_acquired.unlock();
	}
	bool take_right_fork() {
		//cout << "Eater [" << name << "] takes right fork:..." << endl;
		bool ret = right_fork_acquired.try_lock();
		//cout << "Eater [" << name << "] takes right fork:......OK" << endl;
		return ret;
	}
	void put_right_fork() {
		//cout << "Eater [" << name << "] puts right fork:..." << endl;
		right_fork_acquired.unlock();
	}
};


class Dinner {
	const int N = 6;
	vector<Eater *> eaters;
	vector<mutex *> forks;
	vector<thread *> threads;
	atomic_bool keep_eating;
public:
	Dinner() : keep_eating(false)  {
		cout << "Construct dinner\n";
		eaters.resize(N);
		forks.resize(N);

		for (int i = 0; i < N; ++i)
			forks[i] = new mutex();

		for (int i = 0; i < N; ++i)
			eaters[i] = new Eater(*forks[i], *forks[(i + 1) % N], keep_eating, i);
	}
	~Dinner() {
		stop();
		cout << "Destruct dinner\n";
	}
	void start() {
		cout << "Start dinner\n";
		keep_eating = true;
		for (int i = 0; i < N; ++i)
			threads.push_back(new thread(Eater::eat, eaters[i]));
	}
	void wait() {
		if (threads.empty())
			return;

		cout << "Wait for dinner\n";

		for (size_t i = 0; i < threads.size(); ++i) {
			threads[i]->join();
			delete threads[i];
		}
		threads = vector<thread *>();

		cout << "\nReport\n";
		cout << "==================================\n";

		for (int i = 0; i < N; ++i)
			cout << "Eater: " << eaters[i]->get_name() << " ate " <<
				eaters[i]->get_times_ate() << " times\n";
	}
	void stop() {
		cout << "Stop dinner\n";
		keep_eating = false;
		wait();
	}
};

int main(void) {
	Dinner dinner;
	dinner.start();
	//this_thread::sleep_for(chrono::milliseconds(17 * 1000));
	//dinner.stop();
	dinner.wait();
	return 0;
}
