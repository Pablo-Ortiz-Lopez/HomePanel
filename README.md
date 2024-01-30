# Home Automation Project

Welcome to my Home Automation repository! This custom project has been meticulously crafted to fulfill my specific home automation needs, and I've decided to share it here in case anyone else has similar requirements and is seeking a starting point. 

The project includes a variety of custom hardware, along with an ESPHome + HomeAssistant Docker Compose project. 

Firmware for these devices is powered by ESPHome, enabling seamless over-the-air (OTA) updates to enhance and expand functionality.

## Getting Started

To set up and run the Home Automation Project, follow these steps:

1. **Clone the Repository:** Begin by cloning this repository to your local machine:

   ```
   git clone git@github.com:Pablo-Ortiz-Lopez/HomePanel.git
   cd HomePanel
   ```

2. **Install Docker:** Ensure you have Docker installed on your system, as the project relies on it to manage the services.

3. **Start the Panels:** To launch HomeAssistant + ESPHome, run:

   ```
   ./system start
   ```
> If you don't need ESPHome, you can run this command with the --prod flag.
> 
> Note that stuff may break, contact me if you have any issues starting the Compose project, and I will respond shortly.

4. Access the panels: The control panels can be accessed at
    * HomeAssistant: ```http://localhost```
    * ESPHome: ```http://localhost/esphome```

> It is recommended to setup a CloudFlare proxy to enjoy the benefits of HTTPS and its CDN, for free.

## Custom Hardware

The Home Automation Project features custom hardware components designed to enhance your home automation experience. These components include:

- **Climate Control Unit:** This unit is capable of controlling infrared (IR) based air conditioners. It also features a relay for controlling a heater. Additionally, the climate control unit supports CO2 monitoring using the JST connector, providing insights into air quality in your home.

- **Dimmer:** The dimmer is designed to control the brightness of a lightbulb. Adjust the lighting in any room to create the perfect ambiance for any occasion.

## Firmware and OTA Updates

The firmware for the custom hardware components is powered by ESPHome. This enables seamless over-the-air (OTA) updates, allowing you to improve and expand your devices' functionality without the need for physical updates.

To update the firmware OTA:

1. Make necessary changes to the ESPHome configuration files for your devices.
2. Send the changes to your devices using the ESPHome control panel
   
> Note that the first time you will need to flash ESPHome to your device using Serial. Contact me or check out my blog for more information on this.

> Some devices, namely the LightController, are powered by an Atmega328P microcontroller. Those devices don't use ESPHome, and instead rely on Arduino IDE to flash their firmware via ICSP.
## Additional Information

For more details about the project, you can visit my blog at [ortizma.com](https://ortizma.com). If you have any questions, issues, or suggestions, feel free to contact me directly at [pabloortiz132@gmail.com](mailto:pabloortiz132@gmail.com).

## Contributing

We welcome contributions to the Home Automation Project! If you'd like to improve the project, fix bugs, or add new features, please follow these steps:

1. Fork the repository and create a new branch.
2. Make your changes and improvements.
3. Test your changes thoroughly.
4. Create a pull request detailing your changes and explaining their benefits.