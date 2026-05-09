## Software Requirements Specification (SRS)

### Scanlin

---

## 1. Introduction

The **Scanlin** is a specialized C++ command-line utility engineered for high-speed filesystem traversal and metadata extraction. Unlike standard utilities, this project focuses on hardware-aware performance, memory efficiency, and robust error handling in complex Linux environments.

## 2. Overall Description

### 2.1 Product Perspective

This tool is a low-level system utility that interacts directly with the Linux kernel via POSIX system calls. It is designed to be a lightweight, dependency-free binary capable of analyzing massive directory trees with minimal overhead.

### 2.2 User Classes and Characteristics

* **Systems Engineers:** Users requiring precise metadata and performance metrics.
* **Automation Scripts:** The utility is designed to be pipe-friendly, allowing for integration into larger backend workflows.

### 2.3 Design & Implementation Constraints

* **Language:** C++17 or higher (for modern memory management and performance).
* **API:** Direct utilization of POSIX headers (`<dirent.h>`, `<sys/stat.h>`, and `<unistd.h>`).
* **Safety:** Must use `lstat()` instead of `stat()` to identify and safely handle symbolic links, preventing circular traversal.

---

## 3. Functional Requirements

### 3.1 Advanced Traversal Logic

* **FR-1 (Recursive Engine):** The system shall implement a **Depth-First Search (DFS)** algorithm to maintain a low memory footprint (Stack-based or recursive).
* **FR-2 (Depth Control):** Users must be able to specify a maximum depth to prevent the scanner from entering excessively deep or irrelevant sub-trees.
* **FR-3 (Symlink Management):** The system shall detect symbolic links and provide a configurable option to either follow them or ignore them to avoid infinite loops.

### 3.2 Metadata Extraction & Logging

* **FR-4 (Stat Collection):** For every filesystem object, the scanner must extract:
* **Inodes:** To track unique file identity.
* **Permissions:** Represented in octal and human-readable formats.
* **Timestamps:** Access, Modification, and Change (atime, mtime, ctime).


* **FR-5 (Custom Logging):** Integration of a structured logging mechanism to track the scan's progress and record "Permission Denied" errors without halting execution.

### 3.3 Output & Reporting

* **FR-6 (Format Support):** Results must be exportable to **JSON** and **CSV** for programmatic consumption.
* **FR-7 (Summary Statistics):** Upon completion, the tool shall display a summary including:
* Total execution time (in milliseconds).
* Total data volume processed.
* File type distribution (Regular files vs. Directories vs. Symlinks).



---

## 4. External Interface Requirements

### 4.1 Command Line Interface (CLI)

The utility shall support standard Linux flag conventions:

* `-p, --path`: Specify the root directory.
* `-d, --depth`: Limit recursion depth.
* `-o, --output`: Define the output file path and format.
* `-t, --threads`: Specify the number of concurrent worker threads.

### 4.2 System Interfaces

* **VFS Interaction:** The system shall use `opendir()`, `readdir()`, and `closedir()` for directory enumeration to ensure compatibility across different Linux filesystems (Ext4, XFS, Btrfs).

---

## 5. Non-Functional Requirements

### 5.1 Performance & Scalability

* **Throughput:** The scanner should be optimized for high IOPS, utilizing multi-threading where hardware permits.
* **Memory Efficiency:** The application must maintain a stable memory profile even when scanning directories containing millions of files.

### 5.2 Reliability

* **Fault Tolerance:** The scanner must implement `errno` checking after every system call to handle edge cases like filesystem corruption or disconnected network mounts.
* **Resource Management:** Ensure zero memory leaks (verified via Valgrind) and proper file descriptor closure.

---

## 6. Analysis Models

### 6.1 Logical Architecture

* **Scanner Core:** Manages the DFS traversal and thread pool.
* **Metadata Processor:** Handles the `lstat` calls and data normalization.
* **Exporter:** Formats the collected data into the requested output schema.

### 6.2 Data Structures

* **Work Queue:** A thread-safe queue for distributing sub-directories among worker threads.
* **B-Tree/Adaptive Radix Tree (Optional):** If internal indexing is required for post-scan analysis, high-performance structures should be prioritized for memory-efficient lookups.
