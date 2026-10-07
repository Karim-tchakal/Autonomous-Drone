#include <Arduino.h>

HardwareSerial CRSF(1);

// Sender ESP32-S3 TX pin
#define CRSF_TX_PIN 17

#define CRSF_BAUD 420000

// CRSF channel values
#define CRSF_MIN 172
#define CRSF_MID 992
#define CRSF_MAX 1811

uint16_t channels[16] = {
  172,   // CH1
  400,   // CH2
  600,   // CH3
  800,   // CH4
  1000,  // CH5
  1200,  // CH6
  1400,  // CH7
  1600,  // CH8
  1800,  // CH9
  1811,  // CH10
  900,   // CH11
  700,   // CH12
  500,   // CH13
  300,   // CH14
  1100,  // CH15
  1300   // CH16
};

// CRSF CRC8
uint8_t crc8(const uint8_t *ptr, uint8_t len)
{
  uint8_t crc = 0;

  while (len--)
  {
    crc ^= *ptr++;

    for (uint8_t i = 0; i < 8; i++)
    {
      if (crc & 0x80)
        crc = (crc << 1) ^ 0xD5;
      else
        crc <<= 1;
    }
  }

  return crc;
}

// Pack 16 channels × 11 bits = 22 bytes
void packChannels(uint8_t *payload)
{
  uint32_t bitBuffer = 0;
  uint8_t bits = 0;
  uint8_t index = 0;

  for (int i = 0; i < 16; i++)
  {
    bitBuffer |= ((uint32_t)channels[i]) << bits;
    bits += 11;

    while (bits >= 8)
    {
      payload[index++] = bitBuffer & 0xFF;
      bitBuffer >>= 8;
      bits -= 8;
    }
  }

  if (bits > 0)
    payload[index++] = bitBuffer & 0xFF;
}

// Send CRSF RC_CHANNELS_PACKED frame
void sendCRSF()
{
  uint8_t frame[26];

  frame[0] = 0xC8;  // CRSF address

  frame[1] = 24;    // type + 22 payload + CRC

  frame[2] = 0x16;  // RC_CHANNELS_PACKED

  packChannels(&frame[3]);

  frame[25] = crc8(&frame[2], 23);

  CRSF.write(frame, sizeof(frame));
}

void setup()
{
  CRSF.begin(
    CRSF_BAUD,
    SERIAL_8N1,
    -1,              // no RX needed
    CRSF_TX_PIN
  );
}

void loop()
{
  sendCRSF();

  // CRSF RC frames are commonly sent around every 4 ms
  delay(4);
}