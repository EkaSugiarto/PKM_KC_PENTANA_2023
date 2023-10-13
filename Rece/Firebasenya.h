#include <FirebaseESP32.h>

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define DEVICE_UID "Receiver"

#define API_KEY "AIzaSyBCecdj3K7pYWIQUe-NUHOEXPakLjM5ZSw"
#define DATABASE_URL "https://pentanasmartboat-default-rtdb.asia-southeast1.firebasedatabase.app/"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

String fuid = "", databasePath;

int count = 0;
bool isAuthenticated = false;

FirebaseJson data_json;

void FirebaseS() {
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  Firebase.reconnectWiFi(true);
  Serial.println("------------------------------------");
  Serial.println("Sign up new user...");

  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("Success");
    isAuthenticated = true;

    fuid = auth.token.uid.c_str();
  }

  else {
    Serial.printf("Failed, %s\n", config.signer.signupError.message.c_str());
    isAuthenticated = false;
  }

  config.token_status_callback = tokenStatusCallback;

  Firebase.begin(&config, &auth);

  data_json.add("Latitude", latitude);
  data_json.add("Longitude", longitude);
  data_json.add("Yaw", yaw);
  data_json.add("Pitch", pitch);
  data_json.add("Roll", roll);
  data_json.add("RSSI", RSSII);
  data_json.add("Time", timee);
  data_json.add("Derajat", Derajat);
}

void FirebaseL() {
  data_json.set("Latitude", latitude);
  data_json.set("Longitude", longitude);
  data_json.set("Yaw", yaw);
  data_json.set("Pitch", pitch);
  data_json.set("Roll", roll);
  data_json.set("RSSI", RSSII);
  data_json.set("Time", timee);
  data_json.set("Derajat", Derajat);
  databasePath = "/database3/" + epochtime;

  if (isAuthenticated && Firebase.ready()) {

    if (Firebase.setJSON(fbdo, databasePath.c_str(), data_json)) {
      Serial.println("PASSED");
    }

    else {
      Serial.println("FAILED");
    }
  }
}