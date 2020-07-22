<div style="text-align: justify">
# Basic concepts
LoRa is a wireless technology just like WiFi or Bluetooth and the most important features compared to other technologies are:
- Interference tolerance.
- Low consumption.
- Long range, in ideal conditions more than 20 km.
- Low data transfer, until 255 bytes.
- Working frequencies: 868MHz in EU, 915MHz in USA and 433MHz in Asia
- It uses a type of modulation patented by Semtech called Chirp Spread Spectrum or CSS.

Note that LoRa and LoRaWan are not the same, LoraWAN is a network protocol that uses LoRa technology. LoRaWAN is a type of low power, wide area network (LPWAN). The main components of LoRaWAN are the gateways and the nodes:
- Gateway: receives and sends information  to the different nodes.
- Nodes: are the final devices that send and receive information to one or several Gateways.

In addition to the features inherited from LoRa , LoRaWAN adds some more:
- Secure two-way connections.
- Interoperability of the various LoRaWAN networks worldwide (optional).
- More than 50.000 modes can be connected in a single network.

The following image shows the information flow of the different elements in a LoRaWAN implementation. In this scheme you can see that the nodes can communicate with the final server fully encrypted. The Gateway simply acts as an intermediary between the different nodes and the server manages the information of the nodes.

![LoRa_comunication](/images/LoRa_communication.svg)

![NetworkTopologies](/images/NetworkTopologies.svg) Other networks use a mesh network architecture. In a mesh, individual end nodes send information from other nodes to increase the communication range and size of the network. While this increases distance, it also adds complexity, reduces network capacity, and reduces battery life, since the nodes receive and send information from other nodes that is probably irrelevant to them. Star architecture makes the most sense for preserving battery life when long-range connectivity can be achieved.


In a LoRaWAN network the nodes are not associated with a specific Gateway. Instead, data transmitted by one node can be received by multiple gateways. Each Gateway will send the received packet from the end node to the network cloud/server. The complexity is transferred to the network server, which manages the network and will filter out redundant packets received, perform security checks, etc. If a node is mobile or is moving there is no need to manage the transition from one Gateway to another as the server will take care of discarding duplicates and managing the information. In the following image you can see the architecture of LoRaWAN.

![LoRa_network_architecture](/images/LoRa_network_architecture.png)

A very important aspect when using LoRa is the regulations that limit its use. In the case of the European Union this is established according to the frequency used:
- (863.0 - 868.0 MHz): 1%
- (868.0 - 868.6 MHz): 1%
- (868.7 - 869.2 MHz): 0.1%
- (869.4 - 869.65 MHz): 10%
- (869.7 - 870.0 MHz): 1%

This refers to the frequency usage by a given node in 24 hours (1 day). Therefore, the necessary calculations have to be made according to the transmitted data in order not to exceed the use of the band used according to this limitation.

To be able to make the necessary calculations it is important to understand the concept of "spreading factor (SF)". LoRa uses what is known as a "chirp" protocol, something that was developed for sonar and radar applications during World War II, so it is by no means a new technique.

The "chirp" protocol uses fixed-amplitude frequency modulation. It can use the entire assigned spectrum to transmit signals, producing a signal that sweeps through the channel. There are two types of chirps: one that moves up in frequency and one that moves down in frequency, i.e. when there is a "chirp" it will move across the assigned frequency in either direction.

The spreading factor is the duration of the chirp. LoRa operates with propagation factors of 7 to 12. SF7 is the shortest time in the air, SF12 will be the longest. Each increase in the spreading factor doubles the time in the air to transmit the same amount of data. Using the same bandwidth and a longer transmission time results in less data transmitted per unit of time.

In the following table you can see an example of the time taken to send 100 bytes with or without ACK in the different spreading factors mentioned above. Since the RFM95W module will be used as the main LoRa module, it has 10 operating modes in its API. Each of these modes configures a different bandwidth and scattering factor to offer a wide range of possibilities to the programmer.

| Modo | BW  | SF | Sensibilidad(dB) | Tiempo de transmisión para un paquete de 100 bytes | Tiempo de transmisión para un paquete de 100 bytes con ACK |
|:----:|:---:|:--:|:----------------:|:--------------------------------------------------:|:----------------------------------------------------------:|
| 1    | 125 | 12 | -134             | 4245                                               | 5781                                                       |
| 2    | 250 | 12 | -131             | 2193                                               | 3287                                                       |
| 3    | 125 | 10 | -129             | 1208                                               | 2120                                                       |
| 4    | 500 | 12 | -128             | 1167                                               | 2040                                                       |
| 5    | 250 | 10 | -126             | 674                                                | 1457                                                       |
| 6    | 500 | 11 | -125.5           | 715                                                | 1499                                                       |
| 7    | 250 | 9  | -123             | 428                                                | 1145                                                       |
| 8    | 500 | 9  | -120             | 284                                                | 970                                                        |
| 9    | 500 | 8  | -117             | 220                                                | 890                                                        |
| 10   | 500 | 7  | -114             | 186                                                | 848                                                        |

Although European Union legislation allows 1% of the time, the different servers in LoRaWAN will add their own limitations. In the case of the cloud "TheThingsNetwork" indicates that if you want to use their servers you have to comply with the following limitations, among others: do not exceed 30 seconds of sending per day, separate the messages with several minutes between them and do not exceed 13 bytes per packet.

Depending on the application to be implemented you can use this type of network or create your own. In this case and given that the limitations of the different clouds/servers are excessive to be able to experiment with LoRa, it has been decided to use a local MQTT server. 

MQTT( Message Queuing Telemetry Transport) is a M2M (machine-to-machine) communication protocol. The MQTT protocol defines two types of network entities: a broker and multiple clients. A MQTT broker is a server that receives all the messages from the clients and then routes them to the appropriate destination clients. A MQTT client is any device that executes a MQTT library and connects to a MQTT broker through a network. The MQTT protocol is organized based on a hierarchy of topics. Customers can act in two different ways: which send messages to the different topics or who subscribe to the different topics. 
In our case the MQTT server will act as a cloud server, where the nodes will publish different messages in the MQTT broker and a computer with a MQTT client will receive this data to store it in a file.At the moment no security is implemented since the main objective is to understand the different concepts and implementations of LoRa.


# Hardware we need


</div>




