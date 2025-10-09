# 🎯 Guia Rápido - GitHub Actions

## ✅ Parabéns! GitHub Actions Configurado com Sucesso!

Seu repositório agora tem **build automatizado** em 3 plataformas!

## 🔍 Como Ver os Builds

### 1️⃣ Acessar a Aba Actions
```
https://github.com/lucterres/sandbox/actions
```

Ou clique na aba **Actions** no topo do repositório.

### 2️⃣ Ver Builds em Execução
- Workflows em execução aparecem com ⏳ (amarelo)
- Workflows bem-sucedidos aparecem com ✅ (verde)
- Workflows com falha aparecem com ❌ (vermelho)

### 3️⃣ Ver Detalhes de um Build
1. Clique no workflow desejado
2. Você verá todos os jobs (Windows, Linux, macOS)
3. Clique em um job para ver os logs detalhados

### 4️⃣ Download de Executáveis
1. Clique em um workflow concluído com sucesso
2. Role até o final da página
3. Seção **Artifacts** terá os executáveis:
   - `windows-release-build` - Windows otimizado
   - `linux-g++-release-build` - Linux (g++) otimizado
   - `macos-release-build` - macOS otimizado
   - E versões debug de cada um

## 🚀 Próximos Commits

Cada vez que você fizer `git push`, os workflows serão executados automaticamente!

### O que acontece agora:
1. ✅ Você faz `git push origin main`
2. 🔄 GitHub detecta os novos commits
3. ⏳ **Workflows automaticamente** rodam os builds!

## 📊 Builds Executados

Vá para Actions e você verá:
- **C++ CI Build** - 2 jobs paralelos (Windows Debug + Release)
- **Code Quality** - Análise de código

### Tempo Estimado:
- Full CI Build: ~3-5 minutos

## 🎨 Badges no README

Os badges já estão no README e vão atualizar automaticamente:
- ![Build Status] - Status do último build
- ![Quick Build] - Status do quick build
- ![C++17] - Versão do C++

## 📱 Notificações

Você receberá emails quando:
- ✅ Build falhar
- ✅ Build voltar a funcionar
- ℹ️ Pode configurar em Settings → Notifications

## 🎯 Workflow Triggers

### Automático:
- Push para `main` ou `develop`
- Pull Requests para `main`
- Mudanças em arquivos `.cpp`, `.h`, `.hpp`

### Manual:
1. Vá para **Actions**
2. Selecione um workflow
3. Clique em **Run workflow**
4. Escolha a branch
5. Clique em **Run workflow**

## 📈 Matrix Strategy

Seus builds agora rodam em:

### Windows (2 builds):
- ✅ Debug - Com símbolos de debug
- ✅ Release - Otimizado para performance

### Análise de Código (1 job):
- ✅ cppcheck - Análise estática
- ✅ Estatísticas de código

**Total: 2 builds paralelos + 1 análise de código = 3 jobs**

## 🔧 Personalização Futura

### Adicionar Testes:
```yaml
- name: Run Tests
  run: ./run_tests.sh
```

### Adicionar Deployment:
```yaml
- name: Deploy
  if: github.ref == 'refs/heads/main'
  run: deploy.sh
```

### Adicionar Notificação Slack:
```yaml
- name: Slack Notification
  uses: 8398a7/action-slack@v3
```

## 📚 Documentação Completa

Veja `.github/GITHUB_ACTIONS.md` para documentação detalhada.

## 🎉 Próximos Passos

1. ✅ **Vá para Actions** → Ver o primeiro build rodando
2. ✅ **Faça uma mudança** em `main.cpp` → Commit → Push
3. ✅ **Veja o build** ser executado automaticamente
4. ✅ **Download** dos executáveis compilados

---

**🚀 Seu projeto agora tem CI/CD profissional!**

Acesse agora: https://github.com/lucterres/sandbox/actions
