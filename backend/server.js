const express = require("express");
const cors = require("cors");
const path = require("path");
const sensorRouter = require("./routes/sensorRouter");

const app = express();
const PORT = 3000;

// middleware
app.use(cors());
app.use(express.json());

// arquivos da pasta frontend
app.use(express.static(path.join(__dirname, 'frontend')));

// rotas relacionadas ao sensor
app.use(sensorRouter);

// inicia o servidor
app.listen(PORT, () => {
  console.log(`Servidor rodando em http://localhost:${PORT}`);
});
