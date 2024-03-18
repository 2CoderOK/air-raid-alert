# air-raid-alert
A Portable Air Raid Alert Device.

This project runs on an ESP32 Wroom DevKit with a connected piezo buzzer, an RGB LED, and a 2-way switch. 
The device connects to WiFi networks and uses HTTP GET requests to obtain the current air raid alert status from a web service.
The device's 3D case was designed to accommodate two 18650 batteries if needed (see air-raid_alert_case.blend)
Additionally, an external siren speaker can be connected via a relay if the device is to be used in public places.

Libraries used: HTTPClient, ArduinoJson, NTPClient, WiFi and WiFiUdp

<img alt="Air Raid Alert - Circuit Diagram" src="https://github.com/2CoderOK/air-raid-alert/blob/main/circuit_diagram.png" />

Here you can watch a video on how it was built: [https://youtube.com/@coderok](https://youtu.be/96fwc9KidEc)

[<img alt="A Portable Air Raid Alert" src="https://github.com/2CoderOK/air-raid-alert/blob/main/air-raid_preview.png" />](https://youtu.be/96fwc9KidEc)

[<img alt="A Portable Air Raid Alert" src="https://github.com/2CoderOK/air-raid-alert/blob/main/air-raid_case.jpg" />](https://youtu.be/96fwc9KidEc)

[<img alt="Buy me a coffee" height="50px" src="https://github.com/2CoderOK/jp-trainer/blob/main/yellow-button.png" />](https://www.buymeacoffee.com/coderok)
