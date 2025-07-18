0.13a: September 11, 2013 

0.13b
* The client creates a new type of game log - event log. The event log contains enough information to reproduce the full history of the battle. The event log is added by default to submit the bug report

0.14a
* Optimization of data sent across the network. Now increasing the number of players in the match does not affect performance as much

0.14b	
* Fixed a bug that prevented a client connecting to a server when a high percentage of packets were lost (got stuck at 0%)
* Fixed a desync, caused by inverted kinematics
* Fixed one of the reasons for a desync chain (where processing one desync causes a new one)

0.14c	
* Improved stability of the game with bad internet connections (a high percentage of packet loss)

0.14d
* Game launch files compiled into "master gold" version. Increased productivity. Debugging console commands are no longer available.

0.15a
* Added dependence of character's movement and drain of energy from the weight of their equipment
* Removed debug information (camera_position, crosshair_distance)
* Removed a debug display of fire points for weapons

0.15c
* Disabled building of debug information during the game, which resulted in slower performance for the client and server

0.16a
* Added anomaly effects to "Rudnya", "School" and "Radar" locations
* Added support for multiple characters per account. Added the ability to purchase a new character

0.16b	
* 10 vs. 10 gameplay implemented

0.18a	
* Poisoning “thermometer" was removed from the interface
* Temporarily disable all the perks of the character

0.21a
* Changed the algorithm for sending network messages about user : now the information about other users can only be sent at no more than 20 times per second. This change reduces the network traffic
* Increased interval at which the server duplicates lost network messages, which led to a substantial decrease in traffic and load on the client and server. This change is not final
* Added network statistics that allow us to get more detailed information about those users who are still experiencing problems with the network synchronization
* Fixed a desync when picking up a battery

0.22a
* We use Windows Quality of Service to ensure the stability of game messages channel; with appropriate support it prevents a scenario when copying files through a local network results in a loss of connection to match the server because of displacing UDP protocol packets by TCP protocol packets
* Network traffic was significantly optimization
* Fixed a crash when using network statistics
* Используется Windows Quality of Service для гарантирования канала для сообщений игры; при наличии соответствующий поддержки это предотвращает сценарии, когда при копировании файлов по локальной сети происходила потеря соединения с матч сервером в виду полноговытеснения пакетов протокола UDP пакетами TCP; 
