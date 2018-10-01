#include <ESP8266WiFi.h>

WiFiClient client;

uint8_t GPIO_Pin = 4;
int count =0;
String MakerIFTTT_Key ;
String MakerIFTTT_Event;
char *append_str(char *here, String s) {  int i=0; while (*here++ = s[i]){i++;};return here-1;}
char *append_ul(char *here, unsigned long u) { char buf[20]; return append_str(here, ultoa(u, buf, 10));}
char post_rqst[256];char *p;char *content_length_here;char *json_start;int compi;

void IntCallback(){
  count=1;
}

void setup()
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(GPIO_Pin), IntCallback, RISING);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("FD-43","fuckoff123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");
  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
  if (client.connect("maker.ifttt.com",80)) {
    MakerIFTTT_Key ="lwPyORUOVWSa2z6qG0Xr4_RMIzA7aMp1znRKDGcmNgz";
    MakerIFTTT_Event ="Dustbin";
    p = post_rqst;
    p = append_str(p, "POST /trigger/");
    p = append_str(p, MakerIFTTT_Event);
    p = append_str(p, "/with/key/");
    p = append_str(p, MakerIFTTT_Key);
    p = append_str(p, " HTTP/1.1\r\n");
    p = append_str(p, "Host: maker.ifttt.com\r\n");
    p = append_str(p, "Content-Type: application/json\r\n");
    p = append_str(p, "Content-Length: ");
    content_length_here = p;
    p = append_str(p, "NN\r\n");
    p = append_str(p, "\r\n");
    json_start = p;
    p = append_str(p, "{\"value1\":\"");
    p = append_str(p, "+917869255763");
    p = append_str(p, "\",\"value2\":\"");
    p = append_str(p, "Testing Dustbin");
    p = append_str(p, "\",\"value3\":\"");
    p = append_str(p, "");
    p = append_str(p, "\"}");

    compi= strlen(json_start);
    content_length_here[0] = '0' + (compi/10);
    content_length_here[1] = '0' + (compi%10);
    client.print(post_rqst);

  }
}

void loop()
{
  if(count==1){
    if (client.connect("maker.ifttt.com",80)) {
    MakerIFTTT_Key ="lwPyORUOVWSa2z6qG0Xr4_RMIzA7aMp1znRKDGcmNgz";
    MakerIFTTT_Event ="Dustbin";
    p = post_rqst;
    p = append_str(p, "POST /trigger/");
    p = append_str(p, MakerIFTTT_Event);
    p = append_str(p, "/with/key/");
    p = append_str(p, MakerIFTTT_Key);
    p = append_str(p, " HTTP/1.1\r\n");
    p = append_str(p, "Host: maker.ifttt.com\r\n");
    p = append_str(p, "Content-Type: application/json\r\n");
    p = append_str(p, "Content-Length: ");
    content_length_here = p;
    p = append_str(p, "NN\r\n");
    p = append_str(p, "\r\n");
    json_start = p;
    p = append_str(p, "{\"value1\":\"");
    p = append_str(p, "+917869255763");
    p = append_str(p, "\",\"value2\":\"");
    p = append_str(p, "Testing Dustbin");
    p = append_str(p, "\",\"value3\":\"");
    p = append_str(p, "");
    p = append_str(p, "\"}");

    compi= strlen(json_start);
    content_length_here[0] = '0' + (compi/10);
    content_length_here[1] = '0' + (compi%10);
    client.print(post_rqst);

  }
    Serial.println("in");
    count=0;
  }
}
