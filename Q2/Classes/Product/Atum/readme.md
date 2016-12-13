# Atum
## Sensor based ambient lighting

Atum's goal is to recreate natural real-time ambient lighting conditions inside your workspace, decreasing fatigue while preserving a natural circadian rythm.  Atum's iterations are as follows:

1. Ambient lighting presets driven by weather API & local time
    * Current iteration of Atum
    * Leverages a Teensy 3.2 to drive a WS2812B LED strip
    * Theoretically capable of driving thousands of LED's for full coverage
2. Single sensor-driven dynamic lighting recreation
    * Includes a single outdoor light sensor
    * Recreates exterior lighting conditions within your workspace
3. Multiple sensor-driven dynamic lighting
    * Uses multiple light and color sensors strategically placed to re-create
    point accurate lighting conditions
