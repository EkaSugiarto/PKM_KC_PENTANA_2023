String db[10];
boolean parsing = false;
int i, j;

String latitude, longitude, yaw, pitch, roll, Derajat;

void ParsingL() {
  j = 0;

  db[j] = "";

  for (i = 1; i < LoRAdata.length(); i++) {
    if (LoRAdata[i] == ';') {
      j++;
      db[j] = "";
    } 
    
    else {
      db[j] = db[j] + LoRAdata[i];
    }
  }
  Serial.println(LoRAdata);
  latitude = db[0];
  longitude = db[1];
  yaw = db[2];
  pitch = db[3];
  roll = db[4];
  Derajat = db[5];

  FirebaseL();
}