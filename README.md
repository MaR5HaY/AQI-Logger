**Project A – Air Quality Logger (DHT11 + MQ135)**

This Arduino project monitors **temperature**, **humidity**, and **air quality** using:

-**DHT11 Sensor** – For temperature and humidity.
-**MQ135 Sensor** – For CO₂ and general air pollution (raw AQI value).
- **16x2 LCD (I2C)** – Displays all sensor readings in real-time.

**Components Used:**
- Arduino UNO/Nano
- DHT11 Sensor
- MQ135 Air Quality Sensor
- 16x2 I2C LCD Display
- Jumper wires + Breadboard

**Output:**
- Line 1: `T:25.3C H:65%`
- Line 2: `AQI: 325` (raw value from MQ135)

**Libraries Required:**
- `DHT` by Adafruit
- `LiquidCrystal_I2C` by Frank de Brabander
- `Wire` (built-in)

**Use Case:**
Helps visualize environmental data for hobby/home setups or science projects.

