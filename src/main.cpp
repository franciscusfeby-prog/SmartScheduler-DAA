#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    string id;
    int processing_time;
    int deadline;
    int completion_time;
};

int main() {
    int n;
    cout << "Masukkan jumlah job: ";
    cin >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << " ID: ";
        cin >> jobs[i].id;
        cout << "Processing time: ";
        cin >> jobs[i].processing_time;
        cout << "Deadline: ";
        cin >> jobs[i].deadline;
    }

    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.deadline < b.deadline;
    });

    int current_time = 0, on_time = 0, total_completion = 0;

    cout << "\nUrutan Eksekusi:\n";
    for (auto &job : jobs) {
        current_time += job.processing_time;
        job.completion_time = current_time;
        total_completion += current_time;

        cout << job.id << " selesai pada " << job.completion_time
             << " (deadline: " << job.deadline << ")";
        if (job.completion_time <= job.deadline) {
            cout << " ✅";
            on_time++;
        }
        cout << endl;
    }

    cout << "\nTotal Completion Time: " << total_completion << endl;
    cout << "Jobs selesai tepat waktu: " << on_time << " dari " << n << endl;
    return 0;
}