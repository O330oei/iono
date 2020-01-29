/*
  Subscribe.ino - Arduino sketch showing the use of the Iono library

    Copyright (C) 2014-2018 Sfera Labs S.r.l. - All rights reserved.

    For information, see the iono web site:
    http://www.sferalabs.cc/iono-arduino

  This code is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  See file LICENSE.txt for further informations on licensing terms.
*/

#include <Iono.h>

void setup() {
  Serial.begin(9600);
  Iono.setup();

  /*
  / Call onDI1Change() every time
  / DI1 changes value and is stable
  / for 500ms
  */
  Iono.subscribeDigital(DI1, 500, &onDI1Change);

  /*
  / Call onAV2Change() every time
  / the voltage on AV2 changes of
  / a value >= 1V, without any delay
  */
  Iono.subscribeAnalog(AV2, 0, 1, &onAV2Change);
}

void loop() {
  // Check all the inputs
  Iono.process();
  delay(100);
}

void onDI1Change(uint8_t pin, float value) {
  Serial.print("DI1 switched ");
  Serial.println(value == HIGH ? "on" : "off");
}

void onAV2Change(uint8_t pin, float value) {
  Serial.print("AV2 voltage: ");
  Serial.println(value);
}
