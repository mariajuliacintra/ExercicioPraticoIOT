void handleAlarme(AdafruitIO_Data *data){
  String valor = data -> toString();
  Serial.print(F("Valor recebido do feed: "));
  Serial.println(valor);

  if (valor == "true"){
     alarmeAtivo = true;
     Serial.println(F("Alarme ARMADO pelo dash/app"));
     digitalWrite(LED_AMARELO, HIGH);
     digitalWrite(LED_VERDE, LOW);
  }else{
    alarmeAtivo = false;
    Serial.println(F("Alarme DESARMADO pelo dash/app"));
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, HIGH);
  }
}

void ativarAlerta(){
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(LED_ALARM, HIGH);
  delay(200);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_ALARM, LOW);
}

void desligarAlerta(){
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_ALARM, LOW);
  handleAlarme(AdafruitIO_Data *data);
}