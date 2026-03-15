# Air Raid Alert

A Portable Air Raid Alert Device built on an ESP32 with a custom 3D-printed case. 

[<img alt="A Portable Air Raid Alert" width="500px" src="https://github.com/2CoderOK/air-raid-alert/blob/main/air-raid_case.jpg" />](https://youtu.be/96fwc9KidEc)

This device connects to WiFi networks and uses HTTP GET requests to obtain the current air raid alert status from a web service (e.g., api.ukrainealarm.com). It can be used as a personal notification device or as an endpoint connected to an external siren speaker for public places.

## ✨ Features
* **WiFi Connectivity:** Establishes a connection with a WiFi network to perform API requests.
* **Time Synchronization:** Utilizes NTP (Network Time Protocol) to stay up to date.
* **Visual Indication:** Displays the current air raid alert status using an RGB LED.
* **Audio Alerts:** Emits a warning melody via a piezo buzzer.
* **Mute Toggle:** Includes a physical switch to easily mute the buzzer.
* **Operational Hours:** Configurable active hours to avoid unnecessary disturbances.

## 🛠️ Hardware Requirements
To build this project, you will need the following components:
* **ESP32 Wroom DevKit Module** (The heart of the device)
* **RGB LED** (For visual status indication)
* **Piezo Buzzer** (For audio alerts)
* **2-Way or 3-Way Switch** (For muting the buzzer)
* **220 Ohm Resistors** (x2, for the Red and Green pins of the RGB LED)
* **Jumper Wires**
* **USB Cable / 5V DC Power Adapter** (For powering the MCU)
* **3D Printed Case** (STL/Blend files provided in the repository)

### Optional Add-ons
* **For Public Siren Use:** A 5V Relay and an external siren speaker (requires a separate power source for the siren).
* **For Portability:** The 3D case (`air-raid_alert_case.blend`) is designed with a compartment to accommodate two 18650 rechargeable batteries (planned for a future V2 autonomous upgrade).

## 💻 Software & Libraries Used
The project is programmed in C++ for the ESP32 and utilizes the following libraries:
* `HTTPClient`
* `ArduinoJson` (For deserializing the API response)
* `NTPClient` (For exact time and operational hours)
* `WiFi` & `WiFiUdp`

## 🔌 Circuit Diagram
<img alt="Air Raid Alert - Circuit Diagram" width="500" src="https://github.com/2CoderOK/air-raid-alert/blob/main/circuit_diagram.png" />

## 🎥 Build Video & Previews
Watch the full build process and see the device in action on YouTube:  
[**A Portable Air Raid Alert Device - Watch on YouTube**](https://youtu.be/96fwc9KidEc)

[<img alt="A Portable Air Raid Alert" width="500px" src="https://github.com/2CoderOK/air-raid-alert/blob/main/air-raid_preview.png" />](https://youtu.be/96fwc9KidEc)

---

[<img alt="Buy me a coffee" height="50px" src="https://github.com/2CoderOK/jp-trainer/blob/main/yellow-button.png" />](https://www.buymeacoffee.com/coderok)
