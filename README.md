# C++ Sandbox - Proje## 🤖 CI/CD com GitHub Actions

O projeto poss## 📦 Artefatos do Build Automatizado

Após cada build bem-sucedido no GitHub Actions, você pode baixar os executáveis Windows:

1. Vá para **Actions** no GitHub
2. Clique no workflow executado
3. Role até **Artifacts**
4. Download dos executáveis:
   - `windows-release-build` - Versão otimizada
   - `windows-debug-build` - Versão com símbolos de debuglow automatizado que compila e testa o código:

- **🪟 Windows** (MinGW-w64)
  - Build Debug (com símbolos de debug)
  - Build Release (otimizado)
- **🔍 Análise de Código** (cppcheck)

Cada commit dispara builds automáticos com configurações Debug e Release. [Veja mais detalhes](.github/GITHUB_ACTIONS.md).udos

![C++ CI Build](https://github.com/lucterres/sandbox/workflows/C++%20CI%20Build/badge.svg)
![C++17](https://img.shields.io/badge/C++-17-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Tests](https://img.shields.io/badge/tests-passing-brightgreen.svg)

## 📋 Sobre o Projeto

Projeto sandbox para aprendizado e desenvolvimento em C++ com configuração completa para VS Code, **testes unitários** e **CI/CD automatizado** via GitHub Actions.

## 🚀 Características

- ✅ **Testes Unitários** - Framework de testes leve sem dependências externas
- 🧪 **Biblioteca de Utilitários** - Funções testáveis para operações com ponteiros

- ✅ Configuração completa do VS Code para C++
- ✅ Integração com g++ (MinGW-w64 via Strawberry Perl)
- ✅ **GitHub Actions** - Build automatizado para Windows
- ✅ Múltiplas configurações de build (rápida, debug, ultra-rápida)
- ✅ Debug integrado com GDB
- ✅ Suporte a C++17
- ✅ Tasks otimizadas para diferentes cenários

## 🤖 CI/CD com GitHub Actions

O projeto possui workflows automatizados que compilam e testam o código em múltiplas plataformas:

- **🪟 Windows** (MinGW-w64)
- **� Linux** (g++ e clang++)
- **🍎 macOS** (Apple Clang)

Cada commit dispara builds automáticos com configurações Debug e Release. [Veja mais detalhes](.github/GITHUB_ACTIONS.md).

## �🛠️ Configurações de Build

### Build Tasks Disponíveis (VS Code)

| Task | Otimização | Debug | Velocidade | Uso |
|------|------------|-------|------------|-----|
| **Build C++ (Fast)** | `-O1` | Não | ⚡ Rápida | Desenvolvimento diário |
| **Build C++ (Debug)** | `-O0 -g` | Sim | 🐌 Lenta | Debugging detalhado |
| **Quick Build** | `-O2 -DNDEBUG` | Não | ⚡⚡ Ultra | Testes de performance |

### Configurações de Debug (F5)

- 🚀 **Debug Rápido (Padrão)** - Compilação otimizada com debug básico
- 🐛 **Debug Completo** - Debug completo com símbolos
- ⚡ **Execução Ultra-Rápida** - Máxima performance
- 🔧 **Debug com Console Externo** - Para programas com I/O complexa

## 🎯 Como Usar

### Compilar e Executar
- **Ctrl + Shift + B** - Build rápido (padrão)
- **F5** - Debug rápido
- **Ctrl + F5** - Executar sem debug

### Trocar Configuração de Debug
1. **Ctrl + Shift + D** (painel Debug)
2. Selecione a configuração no dropdown
3. Pressione **F5**

## 🧪 Testes Unitários

O projeto inclui um **framework de testes leve** desenvolvido especificamente para este projeto, sem dependências externas.

### Executar Testes

#### Via VS Code Tasks:
- **Ctrl + Shift + P** → `Tasks: Run Task` → `Build and Run Tests`

#### Via Terminal:
```bash
# Compilar e executar testes
g++ -std=c++17 -g -O0 test_main.cpp -o test_runner.exe
./test_runner.exe

# Ou usar o PowerShell script integrado
powershell -Command "g++ -std=c++17 -g -O0 test_main.cpp -o test_runner.exe; if ($LASTEXITCODE -eq 0) { ./test_runner.exe }"
```

### Funcionalidades Testadas

- ✅ **Dereferenciamento Seguro** - Verificação de ponteiros nulos
- ✅ **Validação de Ponteiros** - Detecção de ponteiros válidos/inválidos  
- ✅ **Ponteiros para Ponteiros** - Duplo dereferenciamento seguro
- ✅ **Operações com Endereços** - Obtenção e comparação de endereços
- ✅ **Aritmética de Ponteiros** - Cálculo de offsets e endereços adjacentes
- ✅ **Tipos Diversos** - Suporte para int, double, char e outros tipos

### Arquivos de Teste

- `test_framework.h` - Framework de testes (assertions, macros, relatórios)
- `test_main.cpp` - Casos de teste para todas as funcionalidades
- `pointer_utils.h` - Biblioteca de utilitários para operações com ponteiros

Os testes são executados automaticamente no **GitHub Actions** em todas as plataformas.

## 📦 Artefatos do Build Automatizado

Após cada build bem-sucedido, você pode baixar os executáveis:

1. Vá para **Actions** no GitHub
2. Clique no workflow executado
3. Role até **Artifacts**
4. Download dos executáveis para Windows, Linux ou macOS

## �📁 Estrutura do Projeto

```
sandbox/
├── .github/
│   ├── workflows/
│   │   └── build.yml          # CI/CD com testes automáticos
│   └── GITHUB_ACTIONS.md      # Documentação CI/CD
├── .vscode/
│   ├── c_cpp_properties.json  # Configuração IntelliSense
│   ├── launch.json            # Configurações de debug
│   ├── settings.json          # Configurações do workspace
│   └── tasks.json             # Tasks de build e testes
├── build/                     # Arquivos compilados
├── main.cpp                   # Código fonte principal
├── pointer_utils.h            # Biblioteca de utilitários
├── test_framework.h           # Framework de testes unitários
├── test_main.cpp             # Casos de teste
├── DEBUG_OPCOES.md           # Documentação de debug
└── README.md                 # Este arquivo
```

## 🔧 Requisitos

- **Compilador**: g++ (MinGW-w64)
- **Debugger**: GDB
- **Editor**: Visual Studio Code
- **Extensões**:
  - C/C++ (Microsoft)
  - C/C++ Extension Pack

## 🔗 Instalação do Compilador

O projeto usa o g++ do **Strawberry Perl**, localizado em:
```
C:\Strawberry\c\bin\g++.exe
```

Se você não tem o Strawberry Perl instalado, pode obtê-lo em:
- [Strawberry Perl](http://strawberryperl.com/)
- Ou instalar MinGW-w64 diretamente

## 📚 Recursos Adicionais

- [Documentação C++](https://en.cppreference.com/)
- [VS Code C++ Documentation](https://code.visualstudio.com/docs/languages/cpp)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)

## 📝 Notas

- Os arquivos `.exe` são ignorados pelo Git (ver `.gitignore`)
- Configurações otimizadas para desenvolvimento rápido
- Suporte completo a C++17

## 👤 Autor

**terres_petro**

## 📅 Última Atualização

Outubro 2025

---

**Dica**: Para detalhes sobre as configurações de debug, consulte [DEBUG_OPCOES.md](DEBUG_OPCOES.md)
