#include <WiFi.h>
#include <HTTPClient.h>

// Credenciais WiFi
const char* ssid = "";
const char* password = "";

// Configurações do Telegram
const char* telegramToken = ""; // token do Bot
const char* chatID = ""; // chat ID

// Pino do sensor de umidade
const int soilMoisturePin = 34;

// Definir as faixas de valores de umidade para as categorias
int lowThreshold = 400;  // Limite inferior para baixa umidade
int highThreshold = 700; // Limite superior para alta umidade

// Variáveis de estado
unsigned long lastNotificationTime = 0;
const unsigned long notificationInterval = 3600000; // 1 hora em milissegundos
String lastNotificationState = ""; // Armazena o último estado enviado (low ou high)

// Funções de membros Fuzzy para baixa, média e alta
float lowMembership(int moisture) {
  if (moisture <= lowThreshold) return 1.0; // 100% de baixa umidade
  if (moisture > lowThreshold && moisture <= (lowThreshold + 100)) return (lowThreshold + 100 - moisture) / 100.0;
  return 0.0;
}

float mediumMembership(int moisture) {
  if (moisture > lowThreshold && moisture < highThreshold) return (moisture - lowThreshold) / (highThreshold - lowThreshold);
  return 0.0;
}

float highMembership(int moisture) {
  if (moisture >= highThreshold) return 1.0; // 100% de alta umidade
  if (moisture < highThreshold && moisture >= (highThreshold - 100)) return (moisture - (highThreshold - 100)) / 100.0;
  return 0.0;
}

void setup() {
  Serial.begin(115200);

  // Configuração WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi!");

  // Configuração do pino
  pinMode(soilMoisturePin, INPUT);
}

void loop() {
  int soilMoisture = analogRead(soilMoisturePin);
  Serial.print("Umidade do solo: ");
  Serial.println(soilMoisture);

  // Calculando os graus de pertencimento Fuzzy
  float low = lowMembership(soilMoisture);
  float medium = mediumMembership(soilMoisture);
  float high = highMembership(soilMoisture);

  Serial.print("Baixa umidade: ");
  Serial.println(low);
  Serial.print("Média umidade: ");
  Serial.println(medium);
  Serial.print("Alta umidade: ");
  Serial.println(high);

  // Determina o estado atual - baixa, alta ou normal
  String currentState = "";
  if (low > 0.5) {
    currentState = "low"; // Baixa umidade
  } else if (high > 0.5) {
    currentState = "high"; // Alta umidade
  } else {
    currentState = "normal"; // Umidade normal
  }

  // Envia notificações apenas para baixa ou alta umidade com intervalo de 1 hora
  unsigned long currentTime = millis();
  if ((currentState == "low" || currentState == "high") &&
      (currentTime - lastNotificationTime >= notificationInterval || currentState != lastNotificationState)) {
    if (currentState == "low") {
      sendTelegramMessage("Sua plantinha está com sede! 🌵💦 Regue ela! 🥺");
    } else if (currentState == "high") {
      sendTelegramMessage("Solo encharcado! Sua plantinha pode estar se afogando! 😬🌱");
    }

    // Atualiza o estado da ultima notificação e o tempo
    lastNotificationState = currentState;
    lastNotificationTime = currentTime;
  }

  // Enviar os dados para o backend
  sendDataToBackend(soilMoisture, currentState);

  delay(60000); // Atraso de 1 minuto para evitar sobrecarga
}

// Função para enviar mensagem para o Telegram
void sendTelegramMessage(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = "https://api.telegram.org/bot" + String(telegramToken) + "/sendMessage?chat_id=" + String(chatID) + "&text=" + message;

    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.println("Mensagem enviada com sucesso!");
    } else {
      Serial.print("Erro ao enviar mensagem: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi desconectado. Não foi possível enviar a mensagem.");
  }
}

// Função para enviar os dados do sensor para o backend
void sendDataToBackend(int soilMoisture, String currentState) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = ""; // IP do backend
    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    // Cria payload JSON com os dados do sensor e o estado da umidade
    String jsonPayload = "{\"soilMoisture\":" + String(soilMoisture) + ", \"moistureState\":\"" + currentState + "\"}";

    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      Serial.println("Dados enviados ao backend com sucesso!");
    } else {
      Serial.print("Erro ao enviar dados ao backend: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi desconectado. Não foi possível enviar os dados.");
  }
}
