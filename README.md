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
- **Sensores IoT** capturam os dados ambientais.
- **ESP32** processa os dados e envia para a nuvem ou servidor local.
- **Algoritmos de IA** analisam as condições e decidem as ações corretivas.
- **Notificações** são enviadas ao usuário.
- **Interface Web** para usuário receber o feedback do estados das plantas, histórico de alertas e dashboards.

## Fluxo de Dados

- **Captura de Dados**: Sensores medem a umidade, temperatura e luz.
- **Transmissão de Dados**: Dados são enviados ao ESP32.
- **Processamento e Análise**: Dados são processados e analisados.
- **Ação**: Ajustes são feitos com base nas análises.
- **Feedback ao Usuário**: Notificações e atualizações são enviadas ao usuário.

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
