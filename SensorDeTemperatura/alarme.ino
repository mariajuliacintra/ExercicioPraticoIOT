void handleAlarme(AdafruitIO_Data *data){
  String valor = data->toString();
  
  Serial.print(F("Valor recebido do feed: "));
  Serial.println(valor);

  bool novoEstado = (valor == "true");

  // Só atualiza e imprime mensagem se o estado realmente mudou
  if (novoEstado != alarmeAtivo) {
    alarmeAtivo = novoEstado;

    if (alarmeAtivo) {
      Serial.println(F("Alarme ARMADO pelo dash/app"));
      digitalWrite(LED_AMARELO, HIGH);
      digitalWrite(LED_VERDE, LOW);
    } else {
      Serial.println(F("Alarme DESARMADO pelo dash/app"));
      digitalWrite(LED_AMARELO, LOW);
      digitalWrite(LED_VERDE, HIGH);
    }
  }
}
void ativarAlerta() {
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);

  // Pisca buzzer e LED vermelho 
  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(LED_ALARM, HIGH);
  delay(200);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_ALARM, LOW);
  delay(200);
}

void desligarAlerta() {
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_ALARM, LOW);

  if (alarmeAtivo) {
    digitalWrite(LED_AMARELO, HIGH); // Alarme armado
    digitalWrite(LED_VERDE, LOW);
  } else {
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, HIGH); // Alarme desarmado
  }
}