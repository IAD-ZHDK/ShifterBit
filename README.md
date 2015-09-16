# ShifterBit

**a little bits compatible module that connects to shiftr.io**

## Materials

- [ESP8266 Breakout](http://www.mouser.ch/ProductDetail/Adafruit/2471/?qs=sGAEpiMZZMuJ3l9lTgMBp%2frnoxsPagxMQVIxc1X%252bEHbnrRJkxRVMMQ%3d%3d)
- [SD Card Holder](http://www.mouser.ch/ProductDetail/Molex/47352-1001/?qs=sGAEpiMZZMuJakaoiLiBpqoYXsE4YrD3r%2fU0grh%2fJ8Q%3d)
- SD Card & Adapter

## Configuration

To configure edit the `/arduino/config.txt`:

```
mqtt_user: try
mqtt_password: try
mqtt_client_id: bit1
publish_topic: /data
subscribe_topic: /data
```
