import axios from "axios";

const api = axios.create({
    baseURL: "https://io.adafruit.com/api/v2/mariajuliacintra/feeds/",
    headers:{
        accept: "application/json",
        "Content-Type": "application/json",
        "X-AIO-Key": ""
    },
});

const sheets = {
    toggleLED: (stateLED) => api.post("botaoalarme/data", stateLED),
};

export default sheets;