// Auto generated code by esphomeyaml
#include "esphomelib/application.h"

using namespace esphomelib;

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  App.set_name("spareroom_dht");
  App.init_log();
  auto *wificomponent = App.init_wifi();
  wificomponent->set_sta(WiFiAp{
      .ssid = "EgorandTron_2.4",
      .password = "Emm7s0h@ppy!",
      .channel = -1,
  });
  auto *otacomponent = App.init_ota();
  otacomponent->set_auth_password_hash("914c7a71d1c1086ef3c6b543385043c1");
  otacomponent->start_safe_mode();
  App.init_mqtt("192.168.128.180", 1883, "homeassistant", "h0m3@sst2086");
  auto application_makedhtsensor = App.make_dht_sensor("Spare Room Temp", "Spare Room Humidity", 5, 180000);
  application_makedhtsensor.dht->set_dht_model(sensor::DHT_MODEL_DHT22);
  auto *sensor_sensor_2 = application_makedhtsensor.dht->get_temperature_sensor();
  auto *sensor_sensor = application_makedhtsensor.dht->get_humidity_sensor();
  sensor_sensor_2->set_unit_of_measurement("\302\260F");
  sensor_sensor->set_filters({});
  sensor_sensor_2->set_filters({
      new sensor::LambdaFilter([=](float x) {
        return x * (9.0/5.0) + 32.0;
    }),
  });
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
  delay(16);
}
