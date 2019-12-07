#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
String command = "";

void setup() {
  SerialBT.begin("ESP32");
}

void loop() {
  if (SerialBT.available()){
    while((String)SerialBT.peek() != "-1"){
      command.concat((char)SerialBT.read());
    }
    SerialBT.println(command);
    command = "";
  }
}
