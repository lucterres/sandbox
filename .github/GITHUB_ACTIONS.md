# 🔄 GitHub Actions - Automação de Build

## 📋 Workflows Disponíveis

### 1. 🏗️ C++ CI Build (build.yml)
**Workflow principal** com builds em múltiplas plataformas e configurações.

#### Triggers:
- ✅ Push para `main` ou `develop`
- ✅ Pull Requests para `main`
- ✅ Execução manual (workflow_dispatch)

#### Plataformas:
- **Windows** (MinGW-w64)
- **Linux** (g++ e clang++)
- **macOS** (Apple Clang)

#### Configurações:
- **Debug** - Símbolos de debug, sem otimização (-g -O0)
- **Release** - Otimização máxima (-O2 -DNDEBUG)

#### Artefatos Gerados:
- `windows-release-build` - Executável Windows otimizado
- `windows-debug-build` - Executável Windows para debug
- `linux-g++-release-build` - Linux (g++) otimizado
- `linux-g++-debug-build` - Linux (g++) debug
- `linux-clang++-release-build` - Linux (clang++) otimizado
- `linux-clang++-debug-build` - Linux (clang++) debug
- `macos-release-build` - macOS otimizado
- `macos-debug-build` - macOS debug

**Retenção**: 30 dias

### 2. ⚡ Quick Build (quick-build.yml)
**Build rápido** para validação imediata de mudanças.

#### Triggers:
- ✅ Push para `main` (apenas arquivos .cpp, .h, .hpp)
- ✅ Execução manual

#### Plataforma:
- **Ubuntu** (mais rápido)

#### Configuração:
- **Release** ultra-otimizado (-O2 -DNDEBUG)

### 3. 🔍 Code Quality (dentro do build.yml)
**Análise de qualidade** de código automatizada.

#### Ferramentas:
- **cppcheck** - Análise estática
- **Estatísticas** - Linhas de código, tamanho

## 🚀 Como Usar

### Executar Manualmente:
1. Vá para **Actions** no GitHub
2. Selecione o workflow desejado
3. Clique em **Run workflow**
4. Escolha a branch
5. Clique em **Run workflow**

### Download de Artefatos:
1. Vá para **Actions** no GitHub
2. Clique no workflow executado
3. Role até **Artifacts**
4. Download do executável desejado

### Ver Status do Build:
Adicione ao README.md:
```markdown
![Build Status](https://github.com/SEU_USUARIO/sandbox/workflows/C%2B%2B%20CI%20Build/badge.svg)
```

## 📊 Matrix Strategy

### Windows:
```yaml
matrix:
  build_type: [Debug, Release]
```
**Total**: 2 builds

### Linux:
```yaml
matrix:
  build_type: [Debug, Release]
  compiler: [g++, clang++]
```
**Total**: 4 builds (2 compiladores × 2 configurações)

### macOS:
```yaml
matrix:
  build_type: [Debug, Release]
```
**Total**: 2 builds

**TOTAL GERAL**: 8 builds paralelos + 1 análise de código = **9 jobs**

## ⚙️ Flags de Compilação

### Release:
```bash
-std=c++17      # Usa C++17
-O2             # Otimização nível 2
-DNDEBUG        # Remove asserts
-Wall           # Warnings principais
-Wextra         # Warnings extras
```

### Debug:
```bash
-std=c++17      # Usa C++17
-g              # Símbolos de debug
-O0             # Sem otimização
-Wall           # Warnings principais
-Wextra         # Warnings extras
```

## 🎯 Exemplos de Uso

### Ver Logs do Build:
1. Clique no workflow executado
2. Clique em um job (ex: "Build on Windows")
3. Veja os logs de cada step

### Debug de Falhas:
- Verifique o step que falhou
- Veja a mensagem de erro completa
- Compare com builds anteriores bem-sucedidos

### Testar Localmente:
Use os mesmos comandos do workflow:
```bash
# Release
g++ -std=c++17 -O2 -DNDEBUG -Wall -Wextra main.cpp -o main

# Debug
g++ -std=c++17 -g -O0 -Wall -Wextra main.cpp -o main_debug
```

## 🔔 Notificações

Por padrão, você receberá emails quando:
- ✅ Build falhar no seu commit
- ✅ Build voltar a funcionar após falha

Configure em: **Settings → Notifications → Actions**

## 📈 Performance

### Tempo Médio de Execução:
- **Quick Build**: ~1-2 minutos
- **Full CI Build**: ~5-8 minutos (paralelo)
- **Code Quality**: ~1-2 minutos

### Otimizações Aplicadas:
- ✅ Builds paralelos com matrix
- ✅ Cache de dependências
- ✅ Quick build separado para validação rápida
- ✅ Artefatos apenas para builds importantes

## 🛠️ Personalização

### Adicionar Mais Testes:
Edite `.github/workflows/build.yml` e adicione:
```yaml
- name: 🧪 Testes Unitários
  run: |
    ./run_tests.sh
```

### Adicionar Deployment:
```yaml
- name: 🚀 Deploy
  if: github.ref == 'refs/heads/main'
  run: |
    # Comandos de deploy
```

### Adicionar Análise de Cobertura:
```yaml
- name: 📊 Cobertura
  run: |
    g++ -coverage main.cpp -o main
    ./main
    gcov main.cpp
```

## 📚 Recursos

- [GitHub Actions Docs](https://docs.github.com/en/actions)
- [Workflow Syntax](https://docs.github.com/en/actions/reference/workflow-syntax-for-github-actions)
- [Actions Marketplace](https://github.com/marketplace?type=actions)

## ✅ Checklist de Configuração

- [x] Workflow criado (build.yml)
- [x] Quick build criado (quick-build.yml)
- [x] Matrix strategy configurada
- [x] Artefatos configurados
- [x] Análise de código configurada
- [ ] Badge adicionado ao README
- [ ] Testes configurados (futuro)
- [ ] Deploy configurado (futuro)
