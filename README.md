<div align="justify">

<img align="right" width=310 src=".corporate_resources/Logos/largo_V9_sin_fondo.svg" />

# WeCareLab LoRa implementation:

Before continuing with the implementation explained here it is recommended to first read the [basic concepts](https://github.com/wecarelab/LoRa/wiki/Basic-concepts)  needed to understand this project in the wiki.

# Hardware we're gonna need:

Although node-by-node connections can be made with LoRa, one of its most important features is that a single device can handle multiple nodes. For this you need a Gateway device, these devices have a very high price compared to the price of each of the nodes. Therefore, for these first experiments, a low cost gateway will be used using the same module as the nodes. This Gateway has many limitations since it can only work with one channel. Since these are the first tests with the LoRa technology it is more than enough, since with a single channel you can continue using multiple nodes.

## Gateway Hardware

<img align="right" width=100 src="/res/images/RFM95W.png" />

The hardware of the gateway is composed of a Raspberry Pi 2 B(image below), a module RFM95W (right-hand image) and a WIFI USB device for mobility, although the latter is not strictly necessary as the RPI has an RJ45 cable connection.

<img align="left" width=300 src="/res/images/raspberry-pi-2b.png" />

**IMPORTANT:** Since no PCBs are used in this first approach to LoRa (to facilitate connections) be sure to **solder the antenna to the RFM95W first**. Many radio modules will stop working ( breaking down ) if they are switched on without the antenna. Therefore before connecting the RPI to the RFM95W make sure you have an antenna connected at all times. The connections between the two devices must be made as follows:

```
      RPI            Radio module
   GND pin 25----------GND   (ground in)
   3V3 pin 17----------3.3V  (3.3V in)
 GPIO4 pin  7----------RST   (Reset)
CS/CE0 pin 24----------NSS   (CS chip select in)
   SCK pin 23----------SCK   (SPI clock in)
  MOSI pin 19----------MOSI  (SPI Data in)
  MISO pin 21----------MISO  (SPI Data out)
```
</div>
