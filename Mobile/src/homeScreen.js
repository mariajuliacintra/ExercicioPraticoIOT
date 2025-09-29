import React from "react";
import { View, Button } from "react-native";
import { useNavigation } from "@react-navigation/native";
import { useState } from "react";
import api from "./axios/axios";

const HomeScreen = () => {
  const navigation = useNavigation();
  const [stateLed, setStateLed] = useState({ value: false }); // chave : valor (chave adafruit sempre === value)

  handleCam = () => {
    navigation.navigate("Cam");
  };

  async function ledToggle() {
    //Faz a requisição da API do adafruit
    try {
      const response = await api.toggleLED({ value: `${!stateLed.value}`});
      setStateLed({value : !stateLed.value});
      console.log("Resposta: ", response.data);
    } catch (error) {
        console.log("Erro", error.response.data);
    }
  }

  return (
    <View style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
      <View style={{ marginBottom: "20", flexDirection: "column" }}>
        <Button title="Abrir camera" onPress={handleCam} color="red" />
      </View>
      <View>
        <Button
          title={stateLed.value ? "Desligar led" : "Ligar led"}
          onPress={ledToggle}
          color={stateLed.value ? "red" : "green"}
        />
      </View>
      <View style={{marginTop: 20}}>
        <Button
        title="Listar Eventos"
        onPress={() => navigation.navigate("Eventos")}
        />
      </View>
    </View>
  );
};
export default HomeScreen;
