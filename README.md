# Monitoramento de Plantas

Este projeto é um sistema de monitoramento inteligente para plantas, utilizando sensores IoT, um microcontrolador ESP32 e algoritmos de Inteligência Artificial para ajudar a gerenciar as necessidades das plantas, como luz, água e temperatura. A planta será monitorada em tempo real e o usuário receberá notificações sobre o estado da planta e quando ações corretivas são necessárias.

## Descrição

O projeto visa automatizar e otimizar os cuidados com plantas, especialmente em ambientes onde a interação humana pode ser limitada. O sistema monitora a umidade do solo, temperatura, umidade do ar e exposição à luz. A IA integrada analisa esses dados e informa ao usuário quando a planta precisa de luz, água ou calor. O atuador principal é uma lâmpada que simula a luz solar para ajustar a temperatura ou compensar a falta de luz.

## Funcionalidades

- **Monitoramento da umidade do solo**
- **Monitoramento da temperatura e umidade do ar**
- **Monitoramento da intensidade de luz**
- **Notificações inteligentes** para o usuário informando se a planta precisa de luz, água ou mais calor.
- **Controle automático da lâmpada** para simular luz solar e regular a temperatura.
- **Algoritmos de Inteligência Artificial** que analisam os dados e tomam decisões.
- **Interface Web** para visualização de dados e alertas históricos.

## Requisitos Funcionais

1. O sistema deve medir e registrar a umidade do solo.
2. O sistema deve monitorar a temperatura e umidade do ambiente.
3. O sistema deve medir a intensidade da luz que atinge as plantas.
4. O sistema deve enviar notificações ao usuário quando a planta necessitar de cuidados (luz, água ou calor).
5. A lâmpada deve ser acionada automaticamente quando os níveis de luz ou temperatura forem insuficientes.
6. O sistema deve ser capaz de rodar algoritmos de IA para tomar decisões sobre as necessidades da planta.

## Requisitos Não Funcionais

1. **Interface amigável**: O sistema deve fornecer uma interface intuitiva e fácil de usar, com acesso ao histórico de alertas e gráficos de monitoramento.
2. **Alta disponibilidade**: O sistema deve operar continuamente, enviando dados em tempo real e respondendo rapidamente a condições adversas.
3. **Confiabilidade**: Os sensores devem ser precisos e o sistema deve garantir a coleta correta de dados e a tomada de decisões baseada neles.

## Componentes de Hardware

1. **ESP32**
   - Função: Microcontrolador principal que processa os dados dos sensores, roda os algoritmos de IA e aciona o atuador (lâmpada).
   
2. **AM2302 (DHT22) - Sensor de Temperatura e Umidade**
   - Função: Monitora a temperatura e a umidade do ambiente.
   
3. **GY-30 BH1750FVI - Sensor de Iluminação**
   - Função: Monitora a intensidade de luz ambiente (lux).
   
4. **V1.2 Sensor de Umidade do Solo**
   - Função: Monitora a umidade do solo onde a planta está plantada.

5. **Relé de Estado Sólido ou Relé Mecânico de 5V**
   - Função: Controla a lâmpada para simular luz solar ou gerar calor quando necessário.
   
6. **Lâmpada Incandescente ou Halógena (40W a 100W)**
   - Função: Atua como fonte de luz/sol para as plantas, regulando também a temperatura quando necessário.
   
7. **Fonte de Alimentação 5V para ESP32**
   - Função: Fornece energia ao ESP32.
   
8. **Protoboard e Jumpers**
   - Função: Facilitar as conexões dos sensores e relés ao ESP32.
   
9. **Resistores (10kΩ)**
   - Função: Utilizados com o sensor de luz para controlar a tensão de entrada ao ESP32.

## Arquitetura do Sistema

1. **Captura de Dados**: Sensores de umidade, temperatura, e luz monitoram o ambiente e enviam os dados para o ESP32.
2. **Processamento e Análise**: O ESP32 processa os dados coletados e executa algoritmos de IA para avaliar as condições da planta.
3. **Ações Corretivas**: Dependendo das condições, a lâmpada é acionada para regular a luz e a temperatura.
4. **Notificações**: O sistema envia alertas ao usuário sobre as necessidades da planta.
5. **Interface Web**: O usuário pode visualizar o estado da planta e os alertas históricos.

## Fluxo de Dados

1. Os sensores capturam dados ambientais e os enviam ao ESP32.
2. O ESP32 processa os dados e executa os algoritmos de IA para decidir sobre a necessidade de ações corretivas.
3. O atuador (lâmpada) é acionado se necessário.
4. O sistema envia notificações para o usuário via um sistema de comunicação (por exemplo, via Wi-Fi ou Bluetooth).

## Benefícios

- **Automação do cuidado com plantas**.
- **Otimização dos recursos** (água, luz e calor).
- **Notificações em tempo real** garantem que a planta esteja sempre em condições ideais.

## Desafios

- **Precisão dos sensores**.
- **Integração e sincronização dos sensores e atuadores**.
- **Manutenção dos sensores** e atualização dos algoritmos de IA com novos dados.

## Como Contribuir

1. Faça um fork do repositório.
2. Crie uma branch para suas alterações (`git checkout -b minha-feature`).
3. Faça commit das suas mudanças (`git commit -m 'Adiciona nova feature'`).
4. Envie um pull request.

## Licença

Este projeto é licenciado sob a MIT License - veja o arquivo [LICENSE](LICENSE) para mais detalhes.
