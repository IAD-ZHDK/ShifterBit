# ShifterBit

**a little bits compatible module that connects to shiftr.io**

![Multiple ShifterBits](http://joel-github-static.s3.amazonaws.com/shifter-bit/teaser.jpg)

## Parts

- [ESP8266 Breakout](http://www.mouser.ch/ProductDetail/Adafruit/2471/?qs=sGAEpiMZZMuJ3l9lTgMBp%2frnoxsPagxMQVIxc1X%252bEHbnrRJkxRVMMQ%3d%3d)
- [SD Card Holder](http://www.mouser.ch/ProductDetail/Molex/47352-1001/?qs=sGAEpiMZZMuJakaoiLiBpqoYXsE4YrD3r%2fU0grh%2fJ8Q%3d)
- [MCP41010](http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf)
- SD Card & Adapter

## Useful Links

- [Little Bits Eagle Templates](https://github.com/littleBitsbitLab/HDK-eagle-templates-libraries)
- [SD Card Holder Eagle Part](http://www.eaglecentral.ca/forums/index.php?t=msg&th=48291&start=0&e7001add2d4226236598bac9739173f3)
- [ESP8266 Breakout Info](https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout/overview)

## Configuration

To configure edit the `/config.txt` on the SD card:

```
# Wifi Config
wifi_ssid: MY_WIFI
wifi_key: hidden_secret

# MQTT Config
mqtt_broker: broker.shiftr.io
mqtt_user: try
mqtt_password: try
mqtt_client_id: bit1

# Publish & Subscribe
# set to '-' to disable
publish_topic: data
subscribe_topic: -
```
