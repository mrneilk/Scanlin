Linux Directory Scanner
--

This Project will illustrate, use of a basic directory scanner functionality created using cpp.



We will initiate this a software engineering project. 

What will be added: SRS, Flow Diagram, Use Case, Test Document, End user Document.

Current Implementation Status
--

**Completed:**
- Basic directory scanning functionality using POSIX API
- `list_directory()` function that:
  - Opens a directory using `opendir()`
  - Iterates through directory entries using `readdir()`
  - Skips "." and ".." directory pointers
  - Prints file and subdirectory names found in the specified path
- Main function that scans the current directory (".")
- Error handling for failed directory opening
- Header files: iostream, dirent.h, sys/stat.h, string, vector

**Pending:**
- Advanced filtering and file classification
- Recursive directory traversal
- File metadata display (size, permissions, timestamps)
- SRS and Flow Diagram documentation
- Use Case documentation
- Test Document
- End user documentation

Tools and Resources
--
Draw.io - for flow representation 


License and Project Use:
--
GNU GENERAL PUBLIC LICENSE v3
