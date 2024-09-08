# Monitoramento de Plantas

Este projeto é um sistema de monitoramento inteligente para plantas, utilizando sensores IoT e um microcontrolador ESP32.

## Descrição

O projeto visa resolver a dificuldade de gerenciar cuidados com plantas, especialmente em ambientes com interação limitada. O sistema automatiza o controle da umidade do solo, temperatura e exposição à luz.

## Funcionalidades

- Monitoramento da umidade do solo
- Controle da temperatura ambiente
- Ajuste da intensidade da luz
- Notificações e alertas para o usuário

## Requisitos Não Funcionais
- Interface de usuário intuitiva e fácil de usar.
- Processamento rápido dos dados para garantir respostas em tempo real.

## Componentes

- **ESP32**: Microcontrolador central
- **Sensores de Umidade do Solo**: Medem a umidade do solo
- **Sensores de Temperatura e Umidade**: Monitoram a temperatura e umidade ao redor das plantas
- **Sensores de Luz**: Avaliam a intensidade da luz

## Arquitetura do Sistema
1. **Sensores IoT** capturam os dados ambientais.
2. **ESP32** processa os dados e envia para a nuvem ou servidor local.
3. **Algoritmos de IA** analisam as condições e decidem as ações corretivas.
4. **Notificações** são enviadas ao usuário via interface web.

## Fluxo de Dados

1. **Captura de Dados**: Sensores medem a umidade, temperatura e luz.
2. **Transmissão de Dados**: Dados são enviados ao ESP32.
3. **Processamento e Análise**: Dados são processados e analisados.
4. **Ação**: Ajustes são feitos com base nas análises.
5. **Feedback ao Usuário**: Notificações e atualizações são enviadas ao usuário.

## Benefícios

- Otimização dos recursos
- Facilidade de monitoramento

## Desafios

- Precisão dos sensores
- Integração de sistemas
- Manutenção e atualização

## Como Contribuir

1. Faça um fork do repositório
2. Crie uma branch para suas alterações
3. Faça commit das suas mudanças
4. Envie um pull request

## Licença

Este projeto é licenciado sob a MIT License - veja o arquivo [LICENSE](LICENSE) para detalhes.
