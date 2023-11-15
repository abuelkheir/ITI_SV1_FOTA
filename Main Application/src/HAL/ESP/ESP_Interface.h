/*
 * ESP_Interface.h
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 */

#ifndef HAL_ESP_ESP_INTERFACE_H_
#define HAL_ESP_ESP_INTERFACE_H_

//---------------------------------------------------------function--------------------------------------------------------
void ESP8266_VoidInit();

void ESP8266_VoidConnectToAccessPoint(u8 * ssid, u8 * password);

void ESP8266_VoidOpenServerTcpConnection(u8 * serverIP, u8 * PortNo);

void ESP8266_VoidSendHttpRequest(u8 * url, u8 * length);

u8 ESP8266_VCOMMVaild();

#endif /* HAL_ESP_ESP_INTERFACE_H_ */
