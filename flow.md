Flow for Scanlin directory scanner

    A([Start Scanner]) --> B[Open Directory Path]
    B --> C{Success?}
    
    C -- No --> D[Print Error/Skip]
    C -- Yes --> E[Read Next Entry]
    
    E -- No more entries --> F[Close Directory]
    F --> G([Return to Parent Folder])
    
    E -- Entry Found --> H{Is it '.' or '..'?}
    H -- Yes --> E
    
    H -- No --> I[Run lstat on Path]
    I --> J{Is it a Directory?}
    
    J -- Yes --> K[Print DIR Name]
    K --> L[RECURSE: Call Scanner on this Path]
    L --> E
    
    J -- No --> M[Print FILE Name + Size]
    M --> E
