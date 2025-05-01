# 🟡 Pac-Man Console Game (C++)

Versi sederhana dari game **Pac-Man** yang berjalan di terminal dengan karakter ASCII, dibuat menggunakan **C++ OOP** dan berbagai design pattern seperti:

- 🧠 **State Pattern** (untuk perilaku dinamis ghost)
- 🎨 **Decorator Pattern** (untuk menambahkan kemampuan sementara ke ghost)
- 🏭 **Factory Pattern** (untuk membuat berbagai jenis ghost)

## 🎮 Fitur Utama

- Gerakan Pac-Man dengan WASD
- Ghost bisa:
  - Berkeliaran (Wander)
  - Mengejar Pac-Man saat dekat (Chase)
  - Ketakutan setelah Pac-Man makan power pellet (Frightened)
  - Kembali ke base setelah dimakan (ReturnToBase)
- Pac-Man bisa memakan ghost saat mereka dalam keadaan ketakutan
- Ghost yang ketakutan bisa diberi kemampuan ekstra dengan **Decorator Pattern** (misalnya: jalan lebih cepat)

## 🧱 Struktur Proyek
Pacman/ │ ├── src/ │ ├── header/ │ │ ├── ghost.h │ │ ├── pacman.h │ │ ├── map.h │ │ ├── game_manager.h │ │ ├── ghost_state.h │ │ ├── frightened_state.h │ │ ├── chase_state.h │ │ ├── wander_state.h │ │ ├── return_to_base_state.h │ │ └── ghost_decorator.h │ │ │ ├── source/ │ │ ├── ghost.cpp │ │ ├── pacman.cpp │ │ ├── map.cpp │ │ ├── game_manager.cpp │ │ ├── main.cpp │ │ ├── frightened_state.cpp │ │ ├── chase_state.cpp │ │ ├── return_to_base_state.cpp │ │ ├── wander_state.cpp │ │ └── ghost_decorator.cpp │ └── README.md
## ⚙️ Cara Menjalankan

1. **Kompilasi** program (gunakan `g++`, `clang++`, atau build system seperti `CMake`):
   ```bash
   g++ -std=c++17 src/source/*.cpp -o Pacman
Jalankan dari terminal:
bash
./Pacman

🎮 Kontrol
Tombol	Aksi
W	Gerak atas
A	Gerak kiri
S	Gerak bawah
D	Gerak kanan
X	Keluar

💡 Design Pattern yang Digunakan
State Pattern:
Ghost dapat berubah perilaku (Wander, Chase, Frightened, ReturnToBase) secara dinamis selama permainan.

Decorator Pattern:
Ghost dalam FrightenedState bisa dibungkus dengan FastFrightenedDecorator untuk menambahkan kecepatan sementara tanpa mengubah class asli.

Factory Pattern:
Ghost dibuat melalui GhostFactory::createGhost(GhostType, x, y) agar fleksibel menambah jenis ghost di masa depan.
