# 🏥 Hospital and ICU Management System

A **C++-based Hospital and ICU Management System** designed to simplify hospital bed management and organize patient-related information through a simple, menu-driven application.

## 📌 Overview

The Hospital and ICU Management System is a software project developed in C++ to manage hospital and Intensive Care Unit (ICU) bed-related operations. It aims to make hospital resource management more organized by reducing manual record-keeping and helping users maintain patient and bed information efficiently.

The project uses C++ programming concepts and file handling to support data management and persistence.

## ✨ Features

- 🏥 **Hospital Bed Management** — Manage hospital bed-related information.
- 🩺 **ICU Management** — Support the organization of ICU bed resources.
- 👨‍⚕️ **Patient Information** — Maintain patient-related records supported by the application.
- 💾 **File Handling** — Store application data using a local text file.
- 🖥️ **Menu-Driven Interface** — Interact with the system through a straightforward console interface.
- ⚙️ **C++ Implementation** — Demonstrates core programming concepts and structured application logic.

> Note: The exact operations available depend on the implementation in the source code.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Compiler:** GCC / MinGW / Any compatible C++ compiler
- **Data Storage:** Text-file-based storage
- **Development Environment:** Visual Studio Code, Code::Blocks, Dev-C++, or another compatible IDE

## 📂 Project Structure

```text
Hospital-and-ICU-Managment-System/
│
├── Hospital & ICU bed managment system.cpp
│   └── Main C++ source code
│
├── Hospital & ICU bed managment system.exe
│   └── Compiled Windows executable
│
├── hospital_data.txt
│   └── Local hospital data storage
│
└── README.md
    └── Project documentation
```

## 🚀 Getting Started

### Prerequisites

Before running the project, make sure you have:

- A C++ compiler such as GCC or MinGW.
- A Windows environment if you want to run the provided `.exe` file.
- A terminal or compatible C++ IDE.

### 1. Clone the Repository

Open your terminal and run:

```bash
git clone https://github.com/Sarcastic-introvert/Hospital-and-ICU-Managment-System.git
```

### 2. Navigate to the Project Directory

```bash
cd Hospital-and-ICU-Managment-System
```

### 3. Compile the Source Code

If you have GCC installed, run:

```bash
g++ "Hospital & ICU bed managment system.cpp" -o hospital_management
```

### 4. Run the Application

On Windows:

```bash
hospital_management.exe
```

Alternatively, run the executable already included in the repository, if compatible with your system.

## 💾 Data Storage

The project includes a `hospital_data.txt` file for local data storage. This allows the application to work with file-based records rather than relying exclusively on temporary in-memory data.

Keep the data file in the location expected by the program so that the application can access it correctly.

## 🎯 Learning Objectives

This project demonstrates practical applications of C++ programming, including:

- Functions and program organization.
- Conditional statements and loops.
- Input and output operations.
- File handling and data persistence.
- Basic hospital resource management logic.
- Building a menu-driven console application.

## 🔮 Future Enhancements

Potential improvements include:

- Patient registration and unique patient IDs.
- Separate management for general beds and ICU beds.
- Automatic bed availability tracking.
- Patient admission and discharge management.
- Search, update, and delete operations for patient records.
- Input validation and improved error handling.
- A graphical user interface.
- Database integration for more scalable data storage.
- Login and access-control functionality.

## 🤝 Contributing

Contributions and suggestions are welcome.

1. Fork this repository.
2. Create a new branch for your changes.
3. Implement and test your improvements.
4. Commit your changes with a descriptive message.
5. Push your branch and open a pull request.

## 📄 License

No license is specified here. Please check the repository's licensing information before using or redistributing the code.

## 👨‍💻 Author

**Sarcastic-introvert**

GitHub Repository: [Hospital and ICU Management System](https://github.com/Sarcastic-introvert/Hospital-and-ICU-Managment-System)

---

⭐ If you find this project useful for learning C++ and file handling, consider giving the repository a star.
