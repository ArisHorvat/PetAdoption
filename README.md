# 🦮Pet Adoption App

Welcome to the **Pet Adoption App**! This application is designed to facilitate the adoption of dogs, providing an intuitive interface for both administrators and users. The app allows users to browse available pets and enables administrators to manage the pet database effectively.

## Features

### User Accounts
- **Browse Pets**: Users can view a list of available dogs, including their breed, name, and age.
- **Adopt a Dog**: Users can adopt a dog with a simple button click.
- **Navigation**: Users can easily navigate to the next available dog or view a list of their adopted pets.
- **Filter Functionality**: Users can filter pets based on breed and age using input fields. The app displays pets that match the specified criteria.

### Admin Accounts
- **Pet Management**: Administrators have access to a comprehensive table containing all registered pets.
- **Operations**: Admins can add, update, and remove pets from the database.
- **Undo/Redo Functionality**: Easily revert or redo the latest actions for managing pets in the database.

## Implementation

- **Layered Architecture**: The application is structured in layers, promoting separation of concerns and maintainability.
- **Graphical User Interface (GUI)**: Developed using **Qt**, allowing seamless switching between admin and user functionalities through tabs.
- **Repository Management**: The app supports multiple repository types, allowing for easy switching between in-memory, CSV, and HTML repositories. Depending on the selected repository, the list of adopted pets can be saved in:
  - **TXT** format for in-memory storage
  - **CSV** format for CSV repositories
  - **HTML** format for HTML repositories
- **Model-View Approach**: The adoption list for users is implemented using the Model-View method, ensuring a clear separation between data and presentation.
- **Domain Model**: Custom classes have been defined to represent pets, including attributes and behaviors specific to the domain.
- **Exception Handling**: Custom exception classes and validators are implemented to ensure data integrity and provide informative error messages.
---

Thank you for checking out the **Pet Adoption App**! We hope you find the perfect furry friend!
