const express = require('express');
const router = express.Router();

// Variável para armazenar os dados do sensor
let sensorData = {
  soilMoisture: null,
  moistureState: null, 
  timestamp: null,
};

// Endpoint para receber os dados do ESP32
router.post("/sensor", (req, res) => {
  const { soilMoisture, moistureState } = req.body; // Adicione moistureState
  console.log("Payload recebido do ESP32:", req.body); // Loga o payload recebido

  if (soilMoisture !== undefined && moistureState) {
    sensorData = {
      soilMoisture,
      moistureState, // Armazena o estado da umidade recebido
      timestamp: new Date(),
    };
    console.log("Dados processados e armazenados:", sensorData);
    res.status(200).send("Dados recebidos com sucesso!");
  } else {
    console.error("Erro: Payload inválido.", req.body);
    res.status(400).send("Dados inválidos.");
  }
});

// Endpoint para o frontend obter os dados
router.get("/sensor", (req, res) => {
  res.status(200).json(sensorData); // Inclui moistureState na resposta
});

module.exports = router;
