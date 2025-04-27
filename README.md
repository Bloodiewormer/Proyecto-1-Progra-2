# Proyecto 1 Programacion 2 

## Library Management System  

This project is a Library Management System developed for the course "Programación 2,EIF205, I ciclo 2025" at the Universidad Nacional de Costa Rica. It provides a comprehensive solution for managing library resources, including books, magazines, articles, videos, users, and loan records.  

## Table of Contents  

- [Features](#features)  
- [Requirements](#requirements)  
- [Installation](#installation)  
- [Usage](#usage)  
- [File Structure](#file-structure)  
- [Contributing](#contributing)  
- [License](#license)  

## Features  

- **Material Management**: Add, modify, and delete materials such as books, magazines, articles, and videos (both physical and digital).  
- **User Management**: Register, modify, and delete users, including their borrowing history.  
- **Loan System**: Borrow and return materials with proper tracking and validation.  
- **Reports**: Generate detailed reports for materials, users, and loan records.  
- **Time Management**: Simulate time progression to manage loan durations and overdue materials.  
- **Data Persistence**: Save and load data for users, materials, and loans via files.  

## Requirements  

- **C++14**: The project is implemented using C++14.  
- **Dynamic Memory Management**: Efficient use of dynamic memory for managing collections.  
- **User-Friendly Interface**: Intuitive menu-driven navigation with clear prompts and error handling.  

## Installation  

1. Clone the repository:
2. Open the project in Visual Studio or your preferred C++ IDE.  
3. Build the solution to compile the project.  

## Usage  

1. Run the `Controladora.cpp` file to start the application.  
2. The system will present a **Main Menu** with the following options:  
   - **Material Management**: Add, modify, or delete library materials.  
   - **User Management**: Register, modify, or delete users.  
   - **Loan System**: Borrow or return materials.  
   - **Reports**: View detailed reports on users, materials, and loans.  
   - **Save Data**: Persist data to files for future sessions.  
   - **Exit**: Safely close the application.  

3. **Submenus**:  
   - **Material Submenu**: Choose between physical and digital materials, and their specific types (e.g., books, videos).  
   - **User Submenu**: Manage user details and borrowing history.  
   - **Reports Submenu**: Generate reports for materials, users, and loan records.  
   - **Time Management Submenu**: Simulate time progression to test overdue scenarios.  

## File Structure  

- **Controladora.cpp**: Main controller for the application logic.  
- **IntefazUsuario.cpp**: Handles user interface and menu options.  
- **Usuario.h / Usuario.cpp**: Manages user-related data.  
- **Libro.h / Libro.cpp**: Defines book attributes and functionalities.  
- **Revista.h / Revista.cpp**: Manages magazine details.  
- **ArticuloDigital.h / ArticuloDigital.cpp**: Handles digital articles.  
- **VideoDigital.h / VideoDigital.cpp**: Manages digital video resources.  
- **ArticuloFisico.h / ArticuloFisico.cpp**: Handles physical articles.  
- **VideoFisico.h / VideoFisico.cpp**: Manages physical video resources.  
- **GestorArchivos.h / GestorArchivos.cpp**: Handles file operations for data persistence.  

## Contributing  

Contributions are welcome! If you'd like to improve the project or fix any issues, please fork the repository and submit a pull request.  

## License  

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
