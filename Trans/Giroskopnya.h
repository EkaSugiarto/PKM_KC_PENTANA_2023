static const int RXPin = 14, TXPin = 13;  // announce your Rx and Tx pins
SoftwareSerial GY25Serial(RXPin, TXPin);

unsigned char Re_buf[8], counter = 0;

void GiroskopnyaS() {
  GY25Serial.begin(9600);  // SoftwareSerial can only support 9600 baud rate for GY 25 but Serial3 can support 115200 and 9600 both
  GY25Serial.write(0XA5);
  GY25Serial.write(0X54);  //correction mode
  GY25Serial.write(0XA5);
  GY25Serial.write(0X51);  //0X51:query mode, return directly to the angle value, to be sent each read, 0X52:Automatic mode,send a direct return angle, only initialization
}

void GiroskopnyaL() {
  GY25Serial.write(0XA5);
  GY25Serial.write(0X51);  //send it for each read
  while (GY25Serial.available()) {
    Re_buf[counter] = (unsigned char)GY25Serial.read();
    if (counter == 0 && Re_buf[0] != 0xAA) return;
    counter++;
    if (counter == 8)  // package is complete
    {
      counter = 0;
      if (Re_buf[0] == 0xAA && Re_buf[7] == 0x55)  // data package is correct
      {
        Yaw = (int16_t)(Re_buf[1] << 8 | Re_buf[2]) / 100.00;
        Pitch = (int16_t)(Re_buf[3] << 8 | Re_buf[4]) / 100.00;
        Roll = (int16_t)(Re_buf[5] << 8 | Re_buf[6]) / 100.00;
      }
    }
  }  // End of while
}  // End of serialEvent