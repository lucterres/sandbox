# 🎯 Como Controlar as Opções do F5

## 📋 Configurações Disponíveis

### 🚀 Debug Rápido (Padrão F5)
- **Uso**: Desenvolvimento diário
- **Compilação**: Otimizada (-O1) sem símbolos de debug completos
- **Velocidade**: ⚡ Rápida
- **Console**: Integrado no VS Code

### 🐛 Debug Completo (com símbolos)
- **Uso**: Debugging detalhado
- **Compilação**: Com todos os símbolos de debug (-g -O0)
- **Velocidade**: 🐌 Mais lenta
- **Console**: Integrado no VS Code
- **Recursos**: Breakpoints, step-by-step, variáveis

### ⚡ Execução Ultra-Rápida
- **Uso**: Testes rápidos
- **Compilação**: Máxima otimização (-O2 -DNDEBUG)
- **Velocidade**: ⚡⚡ Ultra rápida
- **Console**: Terminal integrado do VS Code ✅

### 🔧 Debug com Console Externo
- **Uso**: Debug com entrada/saída complexa
- **Compilação**: Com símbolos de debug
- **Console**: Janela separada do Windows

## 🎮 Como Controlar

### Método 1: Seleção Direta
1. **Ctrl + Shift + D** (painel Debug)
2. Clique na **seta para baixo** ao lado do botão play
3. Selecione a configuração desejada
4. Pressione **F5**

### Método 2: Command Palette
1. **Ctrl + Shift + P**
2. Digite: "Debug: Select and Start Debugging"
3. Escolha a configuração
4. Pressione **F5**

### Método 3: Mudança Padrão
1. **Ctrl + Shift + D**
2. No dropdown do topo, selecione a configuração
3. Ela será usada como padrão para **F5**

## 🚀 Atalhos Rápidos

- **F5**: Usar configuração padrão selecionada
- **Ctrl + F5**: Executar sem debug (mais rápido)
- **Shift + F5**: Parar debugging
- **F9**: Toggle breakpoint
- **F10**: Step over
- **F11**: Step into

## ⚙️ Personalização

Para criar suas próprias configurações, edite:
`.vscode/launch.json`

Exemplo de argumentos personalizados:
```json
"args": ["arg1", "arg2", "--verbose"]
```

## 🎯 Dicas

1. **Use "Debug Rápido"** para 90% do desenvolvimento
2. **Use "Debug Completo"** quando precisar de breakpoints detalhados
3. **Use "Execução Ultra-Rápida"** para testes de performance
4. **Use "Console Externo"** para programas com muita entrada/saída

## 🔄 Mudança Rápida de Configuração

No painel Debug (Ctrl+Shift+D), você verá um dropdown no topo.
Clique nele para trocar rapidamente entre as configurações!