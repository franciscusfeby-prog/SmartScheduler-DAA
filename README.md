SmartScheduler-DAA

### *UTS Desain dan Analisis Algoritma 2025/2026*

**Nama:** Franciscus Feby Etdolo  
**NIM:** 01085240013    

---

## 📖 Deskripsi Proyek

**SmartScheduler** adalah mini-proyek Ujian Tengah Semester untuk mata kuliah **Desain dan Analisis Algoritma (DAA)**.  
Proyek ini bertujuan untuk membuat sistem penjadwalan (*scheduling*) yang efisien di lingkungan *cloud computing*, di mana setiap **pekerjaan (job)** memiliki waktu proses dan deadline berbeda.

Masalah ini sering terjadi pada sistem nyata seperti:

* CPU Scheduling di sistem operasi,  
* Cloud task management,  
* Manufacturing pipeline, dan  
* Real-time task management system.

Algoritma yang digunakan harus mampu:

1. **Meminimalkan total waktu penyelesaian (total completion time)**  
2. **Memaksimalkan jumlah job yang selesai tepat waktu**

---

## ⚙️ Tujuan Proyek

* Menentukan urutan eksekusi *job* yang paling efisien.  
* Menjaga agar sistem tetap optimal meskipun beban tinggi.  
* Mengimplementasikan algoritma penjadwalan dalam bahasa C++.  
* Melakukan analisis kompleksitas waktu dan ruang dari algoritma yang dipilih.

---

## 🧠 Algoritma yang Digunakan — *Earliest Deadline First (EDF)*

**Pendekatan:** *Greedy Algorithm*

**Konsep utama:**  
Job yang memiliki **deadline paling awal** akan dikerjakan terlebih dahulu.

### Langkah-langkah:

1. Masukkan daftar job (ID, processing time, deadline).  
2. Urutkan job berdasarkan deadline (ascending).  
3. Jalankan job satu per satu sesuai urutan.  
4. Hitung waktu selesai setiap job dan cek apakah memenuhi deadline.  
5. Hitung total completion time serta jumlah job yang selesai tepat waktu.

---

## 🧩 Contoh Kasus

| Job | Processing Time | Deadline |
| --- | --------------- | -------- |
| A   | 3               | 6        |
| B   | 2               | 8        |
| C   | 1               | 9        |
| D   | 5               | 15       |

**Urutan Eksekusi (EDF):**  
A → B → C → D  

**Hasil:**  
Semua job selesai sebelum deadline ✅  
**Total Completion Time:** 3 + 5 + 6 + 11 = **25**

---

## 💻 Implementasi Program

File utama: `src/main.cpp`

```cpp
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
```

---

## 📈 Analisis Kompleksitas

| Langkah                   | Deskripsi                        | Kompleksitas          |
| ------------------------- | -------------------------------- | --------------------- |
| Input data                | Membaca n job                    | O(n)                  |
| Sorting                   | Mengurutkan berdasarkan deadline | **O(n log n)**        |
| Eksekusi job              | Menjalankan setiap job           | O(n)                  |
| **Total Time Complexity** | Dominan oleh sorting             | **T(n) = O(n log n)** |
| **Space Complexity**      | Menyimpan daftar job             | **O(n)**              |

---

## 🗂️ Struktur Repositori

```
SmartScheduler-DAA/
│
├── README.md
├── Franciscus_01085240013_UTS-DAA.txt
├── report/
│   └── SmartScheduler_Report.docx
└── src/
    └── main.cpp
```

---

## 🧰 Cara Menjalankan Program

### 🔹 Menggunakan Terminal / CMD

1. Pastikan kamu sudah menginstall **g++** (C++ Compiler).  
2. Buka terminal di folder `src`.  
3. Jalankan perintah berikut:

```bash
g++ main.cpp -o SmartScheduler
```

4. Kemudian jalankan:

```bash
./SmartScheduler
```

5. Masukkan data job sesuai petunjuk.

---

## 🧾 Contoh Input & Output

**Input:**

```
Masukkan jumlah job: 3
Job 1 ID: A
Processing time: 3
Deadline: 6
Job 2 ID: B
Processing time: 2
Deadline: 8
Job 3 ID: C
Processing time: 1
Deadline: 9
```

**Output:**

```
Urutan Eksekusi:
A selesai pada 3 (deadline: 6) ✅
B selesai pada 5 (deadline: 8) ✅
C selesai pada 6 (deadline: 9) ✅

Total Completion Time: 14
Jobs selesai tepat waktu: 3 dari 3
```

---

## 🎯 Kesimpulan

Algoritma **Earliest Deadline First (EDF)** terbukti memberikan hasil cepat dan efisien untuk penjadwalan berbasis waktu.  
Dengan kompleksitas **O(n log n)**, algoritma ini dapat digunakan di berbagai sistem seperti cloud computing, CPU scheduling, dan task management.  
Solusi ini seimbang antara optimalitas dan efisiensi — sesuai kebutuhan dunia nyata.

---

## 👤 Identitas

* **Nama:** Franciscus Feby Etdolo  
* **NIM:** 01085240013  
* **Universitas:** Universitas Pelita Harapan (UPH)
