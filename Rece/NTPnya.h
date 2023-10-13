#include <WiFiUdp.h>
#include <NTPClient.h>

const char* ntpServer = "pool.ntp.org";
const long gmtOffset = 25200;
const int daylightOffset = 3600;
String date, timee, epochtime;

WiFiUDP ntpUDP;
WiFiClient client;
NTPClient waktu(ntpUDP, ntpServer, gmtOffset, daylightOffset);

void NTPS() {
  waktu.begin();
}

void NTPL() {
  waktu.update();
  epochtime = waktu.getEpochTime();
  String date_time = waktu.getFormattedDate();
  int index_date = date_time.indexOf("T");
  date = date_time.substring(0, index_date);
  timee = waktu.getFormattedTime();
}