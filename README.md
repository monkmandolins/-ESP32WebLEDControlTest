# -ESP32WebLEDControlTest
Using ESP32C3 to broadcast a website. Using this to control the state of an LED. Experimenting with websites, CSS, etc.



Flash & use

Save as led_pwm_c3.yaml.

esphome run led_pwm_c3.yaml (first time will open the ESPHome Web flasher).

After it joins Wi-Fi, Home Assistant will discover a light entity named “Grow Light” that supports seamless brightness control.



2. Pure-Arduino sketch with MQTT discovery (no YAML / ESPHome)
What it does
Connects to Wi-Fi and your MQTT broker.

Publishes an MQTT Home Assistant discovery packet once at (re)connect.

Subscribes to led_pwm_c3/light/set (JSON payload) and drives hardware PWM on the LED pin.

Publishes current state/brightness on led_pwm_c3/light/state.

Libraries you need
PubSubClient (Nick O’Leary)

ArduinoJson ≥ 6

WiFi.h (built-in with ESP32 core)
