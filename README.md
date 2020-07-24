<div align="justify">

<img align="right" width=320 src=".corporate_resources/Logos/largo_V9_sin_fondo.svg" />

# WeCareLab LoRa implementation:

Before continuing with the implementation explained here it is recommended to first read the [basic concepts](https://github.com/wecarelab/LoRa/wiki/Basic-concepts)  needed to understand this project in the wiki.

# Hardware we're gonna need:

Although node-by-node connections can be made with LoRa, one of its most important features is that a single device can handle multiple nodes. For this you need a Gateway device, these devices have a very high price compared to the price of each of the nodes. Therefore, for these first experiments, a low cost gateway will be used using the same module as the nodes. This Gateway has many limitations since it can only work with one channel. Since these are the first tests with the LoRa technology it is more than enough, since with a single channel you can continue using multiple nodes.

## Gateway Hardware

<img align="right" width=100 src="./res/images/RFM95W.png" />

The hardware of the gateway is composed of a Raspberry Pi 2 B(image below), a module RFM95W (right-hand image) and a WIFI USB device for mobility, although the latter is not strictly necessary as the RPI has an RJ45 cable connection.

<img align="left" width=300 src="./res/images/raspberry-pi-2b.png" />

**IMPORTANT:** Since no PCBs are used in this first approach to LoRa (to facilitate connections) be sure to **solder the antenna to the RFM95W first**. Many radio modules will stop working ( breaking down ) if they are switched on without the antenna. Therefore before connecting the RPI to the RFM95W make sure you have an antenna connected at all times.

The connections between the two devices must be made as follows:

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

In the following picture you can see one of the many possibilities to physically connect the two components. Note that the orientation of the node antennas and the gateway antennas must have the same orientation. Therefore, depending on where the RPI is to be placed, the antenna must be oriented preferably upwards.

<div align="center">
  <img  width=300 src="./res/images/RPI_RFM95W.jpg" />
</div>

## Node Hardware

In order to create a LoRa node in these examples, an Arduino Mini will be used together with the RFM95W module. The connections between these two are:

```
       Arduino      Radio module
         GND----------GND   (ground in)
         3V3----------3.3V  (3.3V in)
  SS pin D10----------NSS   (CS chip select in)
 SCK pin D13----------SCK   (SPI clock in)
MOSI pin D11----------MOSI  (SPI Data in)
MISO pin D12----------MISO  (SPI Data out)
```

At the moment we will not add any sensor to simplify the examples as much as possible and focus on LoRa communication.

# Software we're gonna need:

This repository is oriented to recompile the maximum information from different sources and make easier the implementation of LoRa. For the gateway software is used the one provided by the non-lucrative organization  [WAZIUP](https://www.waziup.io). In the  [repository](https://github.com/CongducPham/LowCostLoRaGw) of this organization you can find more information about the multitude of options it offers.


</div>
