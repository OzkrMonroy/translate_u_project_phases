# Proyecto de Traducción en C++

Este proyecto es una aplicación de traducción que utiliza un **Árbol AVL** para gestionar el diccionario. Es compatible con **Windows**, **macOS** y **Linux**, y está configurado para ejecutarse en **Visual Studio Code**.

## 📂 Estructura del Proyecto

```
.
├── .vscode/
│    ├── tasks.json     # Configuración para compilar
│    └── launch.json    # Configuración para depurar
├── bin/                # Carpeta de salida (ignorada en Git)
└── src/                # Código fuente
     ├── main.cpp
     ├── utils/
     │      └── jsonReader/JSONReader.cpp
     ├── translateManager/TranslateManager.cpp
     ├── dictionaryAVLTree/DictionaryAVLTree.cpp
     └── dictionaryMenu/DictionaryMenu.cpp
```

## ⚙️ Configuración Inicial

Antes de ejecutar el proyecto:

1. **Crear la carpeta `bin`** en la raíz del proyecto:

   ```bash
   mkdir bin
   ```

   ⚠️ Esta carpeta está en el `.gitignore` para no rastrear los archivos compilados.

2. **Asegúrate de tener `g++` instalado**:

   - **Windows**: Utiliza `MSYS2` con el entorno `ucrt64`.
   - **macOS/Linux**: Puedes usar `g++` del sistema o instalarlo con `brew` o `apt`.

## 🛠️ Configuración de `tasks.json`

Esta configuración compila el proyecto y genera el ejecutable en la carpeta `bin`.

```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"label": "Compilar C++",
			"type": "shell",
			"command": "g++",
			"args": [
				"-g",
				"-std=c++17",
				"\"${workspaceFolder}/src/main.cpp\"",
				"\"${workspaceFolder}/src/utils/jsonReader/JSONReader.cpp\"",
				"\"${workspaceFolder}/src/translateManager/TranslateManager.cpp\"",
				"\"${workspaceFolder}/src/dictionaryAVLTree/DictionaryAVLTree.cpp\"",
				"\"${workspaceFolder}/src/dictionaryMenu/DictionaryMenu.cpp\"",
				"-o",
				"\"${workspaceFolder}/bin/build\""
			],
			"group": {
				"kind": "build",
				"isDefault": true
			}
		}
	]
}
```

## 🐞 Configuración de `launch.json`

Esto permite depurar el programa en **Windows**, **macOS** y **Linux**.

### 🔵 Windows

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Run C++ (Windows)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/bin/build.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/msys64/ucrt64/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Compilar C++"
        }
    ]
}
```

### 🍎 macOS/Linux

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Run C++ (macOS/Linux)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/bin/build",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "lldb",
            "preLaunchTask": "Compilar C++",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

## ▶️ Cómo Ejecutar el Proyecto

1. **Compilar**: Ejecuta `Ctrl + Shift + B` o selecciona la tarea **Compilar C++**.

2. **Ejecutar/Depurar**: Presiona `F5` y elige tu entorno:

   - **Windows**: `Run C++ (Windows)`
   - **macOS/Linux**: `Run C++ (macOS/Linux)`

## 📝 Notas Adicionales

- El programa está preparado para mostrar caracteres especiales (`ñ`, `á`, `é`, etc.) correctamente en **Windows** mediante `SetConsoleOutputCP(CP_UTF8);`.

- En **macOS** y **Linux**, no es necesario realizar configuraciones adicionales para UTF-8, ya que el sistema lo maneja de forma nativa.

- Asegúrate de tener `g++` accesible en el `PATH` en todos los sistemas operativos. Puedes verificarlo con:

   ```bash
   g++ --version
   ```



