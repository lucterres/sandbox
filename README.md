# C++ Sandbox - Projeto de Estudos

## 📋 Sobre o Projeto

Projeto sandbox para aprendizado e desenvolvimento em C++ com configuração completa para VS Code.

## 🚀 Características

- ✅ Configuração completa do VS Code para C++
- ✅ Integração com g++ (MinGW-w64 via Strawberry Perl)
- ✅ Múltiplas configurações de build (rápida, debug, ultra-rápida)
- ✅ Debug integrado com GDB
- ✅ Suporte a C++17
- ✅ Tasks otimizadas para diferentes cenários

## 🛠️ Configurações de Build

### Build Tasks Disponíveis

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

## 📁 Estrutura do Projeto

```
sandbox/
├── .vscode/
│   ├── c_cpp_properties.json  # Configuração IntelliSense
│   ├── launch.json            # Configurações de debug
│   ├── settings.json          # Configurações do workspace
│   └── tasks.json             # Tasks de build
├── build/                     # Arquivos compilados
├── main.cpp                   # Código fonte principal
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
