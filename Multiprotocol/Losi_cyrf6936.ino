/*
 This project is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Multiprotocol is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Multiprotocol.  If not, see <http://www.gnu.org/licenses/>.
 */

#if defined(LOSI_CYRF6936_INO)

#include "iface_cyrf6936.h"

#define LOSI_FORCE_ID

const uint8_t LOSI_data_code[][8] = {
	//(Freq-1)%5=0
	{ 0x83, 0xF7, 0xA8, 0x2D, 0x7A, 0x44, 0x64, 0xD3 },
	{ 0x3F, 0x2C, 0x4E, 0xAA, 0x71, 0x48, 0x7A, 0xC9 },
	{ 0x17, 0xFF, 0x9E, 0x21, 0x36, 0x90, 0xC7, 0x82 },
	{ 0xBC, 0x5D, 0x9A, 0x5B, 0xEE, 0x7F, 0x42, 0xEB },
	{ 0x24, 0xF5, 0xDD, 0xF8, 0x7A, 0x77, 0x74, 0xE7 },
	{ 0x3D, 0x70, 0x7C, 0x94, 0xDC, 0x84, 0xAD, 0x95 },
	{ 0x1E, 0x6A, 0xF0, 0x37, 0x52, 0x7B, 0x11, 0xD4 },
	{ 0x62, 0xF5, 0x2B, 0xAA, 0xFC, 0x33, 0xBF, 0xAF },
	//(Freq-1)%5=1
	{ 0x40, 0x56, 0x32, 0xD9, 0x0F, 0xD9, 0x5D, 0x97 },
	{ 0x8E, 0x4A, 0xD0, 0xA9, 0xA7, 0xFF, 0x20, 0xCA },
	{ 0x4C, 0x97, 0x9D, 0xBF, 0xB8, 0x3D, 0xB5, 0xBE },
	{ 0x0C, 0x5D, 0x24, 0x30, 0x9F, 0xCA, 0x6D, 0xBD },
	{ 0x50, 0x14, 0x33, 0xDE, 0xF1, 0x78, 0x95, 0xAD },
	{ 0x0C, 0x3C, 0xFA, 0xF9, 0xF0, 0xF2, 0x10, 0xC9 },
	{ 0xF4, 0xDA, 0x06, 0xDB, 0xBF, 0x4E, 0x6F, 0xB3 },
	{ 0x9E, 0x08, 0xD1, 0xAE, 0x59, 0x5E, 0xE8, 0xF0 },
	//(Freq-1)%5=2
	{ 0xC0, 0x90, 0x8F, 0xBB, 0x7C, 0x8E, 0x2B, 0x8E },
	{ 0x80, 0x69, 0x26, 0x80, 0x08, 0xF8, 0x49, 0xE7 },
	{ 0x7D, 0x2D, 0x49, 0x54, 0xD0, 0x80, 0x40, 0xC1 },
	{ 0xB6, 0xF2, 0xE6, 0x1B, 0x80, 0x5A, 0x36, 0xB4 },
	{ 0x42, 0xAE, 0x9C, 0x1C, 0xDA, 0x67, 0x05, 0xF6 },
	{ 0x9B, 0x75, 0xF7, 0xE0, 0x14, 0x8D, 0xB5, 0x80 },
	{ 0xBF, 0x54, 0x98, 0xB9, 0xB7, 0x30, 0x5A, 0x88 },
	{ 0x35, 0xD1, 0xFC, 0x97, 0x23, 0xD4, 0xC9, 0x88 },
	//(Freq-1)%5=3
	{ 0xE1, 0xD6, 0x31, 0x26, 0x5F, 0xBD, 0x40, 0x93 },
	{ 0xDC, 0x68, 0x08, 0x99, 0x97, 0xAE, 0xAF, 0x8C },
	{ 0xC3, 0x0E, 0x01, 0x16, 0x0E, 0x32, 0x06, 0xBA },
	{ 0xE0, 0x83, 0x01, 0xFA, 0xAB, 0x3E, 0x8F, 0xAC },
	{ 0x5C, 0xD5, 0x9C, 0xB8, 0x46, 0x9C, 0x7D, 0x84 },
	{ 0xF1, 0xC6, 0xFE, 0x5C, 0x9D, 0xA5, 0x4F, 0xB7 },
	{ 0x58, 0xB5, 0xB3, 0xDD, 0x0E, 0x28, 0xF1, 0xB0 },
	{ 0x5F, 0x30, 0x3B, 0x56, 0x96, 0x45, 0xF4, 0xA1 },
	//(Freq-1)%5=4
	{ 0x03, 0xBC, 0x6E, 0x8A, 0xEF, 0xBD, 0xFE, 0xF8 },
	{ 0x88, 0x17, 0x13, 0x3B, 0x2D, 0xBF, 0x06, 0xD6 },
	{ 0xF1, 0x94, 0x30, 0x21, 0xA1, 0x1C, 0x88, 0xA9 },
	{ 0xD0, 0xD2, 0x8E, 0xBC, 0x82, 0x2F, 0xE3, 0xB4 },
	{ 0x8C, 0xFA, 0x47, 0x9B, 0x83, 0xA5, 0x66, 0xD0 },
	{ 0x07, 0xBD, 0x9F, 0x26, 0xC8, 0x31, 0x0F, 0xB8 },
	{ 0xEF, 0x03, 0x95, 0x89, 0xB4, 0x71, 0x61, 0x9D },
	{ 0x40, 0xBA, 0x97, 0xD5, 0x86, 0x4F, 0xCC, 0xD1 },
	//Bind
	{ 0xD7, 0xA1, 0x54, 0xB1, 0x5E, 0x89, 0xAE, 0x86 }
};

static uint16_t __attribute__((unused)) LOSI_check(uint16_t val)
{
	const uint8_t PROGMEM tab[] = { 0xF1, 0xDA, 0xB6, 0xC8 };
	uint8_t res = crc8, tmp;
	uint16_t calc = val>>2; 								// don't care about the 2 first bits
	for(uint8_t i=0; i<5; i++)
	{
		tmp=pgm_read_byte_near(&tab[i&0x03]);
		if(calc&0x0001)
			res ^= tmp>>4;
		calc >>= 1;
		if(calc&0x0001)
			res ^= tmp;
		calc >>= 1;
	}
	return val ^ (res<<12);
}

static void __attribute__((unused)) LOSI_send_packet()
{
	memcpy(packet, rx_tx_addr, 4);
	if(IS_BIND_IN_PROGRESS)
	{
		memcpy(&packet[4], rx_tx_addr, 4);
		crc = 0x0170;
		for(uint8_t i=0; i < 8; i++)
			crc += packet[i];
		packet[8] = crc >> 8;
		packet[9] = crc;
	}
	else
	{
		for(uint8_t i=0; i<3; i++)
		{
			uint16_t val = LOSI_check(Channel_data[i]<<1);
			packet[4+i*2] = val >> 8;
			packet[5+i*2] = val;
		}
	}

	CYRF_SetPower(0x38);
	CYRF_WriteDataPacketLen(packet, 0x0A);
	#if 0
		for(uint8_t i=0; i < 0x0A; i++)
			debug("%02X ", packet[i]);
		debugln();
	#endif
}

static void __attribute__((unused)) LOSI_cyrf_init()
{
	/* Initialise CYRF chip */
	CYRF_WriteRegister(CYRF_28_CLK_EN, 0x02);
	CYRF_WriteRegister(CYRF_32_AUTO_CAL_TIME, 0x3C);
	CYRF_WriteRegister(CYRF_35_AUTOCAL_OFFSET, 0x14);
	CYRF_WriteRegister(CYRF_06_RX_CFG, 0x48);
	CYRF_WriteRegister(CYRF_1B_TX_OFFSET_LSB, 0x55);
	CYRF_WriteRegister(CYRF_1C_TX_OFFSET_MSB, 0x05);
	//CYRF_WriteRegister(CYRF_0F_XACT_CFG, 0x24);
	CYRF_SetPower(0x38);									// 64 SDR mode -> 8 bytes data code
	CYRF_WriteRegister(CYRF_12_DATA64_THOLD, 0x0A);
	CYRF_WriteRegister(CYRF_39_ANALOG_CTRL, 0x01);
	CYRF_WritePreamble(0x333304);
	//CYRF_WriteRegister(CYRF_27_CLK_OVERRIDE, 0x00);
	CYRF_WriteRegister(CYRF_10_FRAMING_CFG, 0x4A);
	CYRF_WriteRegister(CYRF_1F_TX_OVERRIDE, 0x04);			// No CRC
	//CYRF_WriteRegister(CYRF_1E_RX_OVERRIDE, 0x14);
	//CYRF_WriteRegister(CYRF_14_EOP_CTRL, 0x02);
	CYRF_ConfigDataCode(&LOSI_data_code[40], 16);			// Load bind data code by default
}

uint16_t LOSI_callback()
{
	#ifdef MULTI_SYNC
		telemetry_set_input_sync(packet_period);
	#endif
	if(bind_counter)
	{
		bind_counter--;
		if(bind_counter==0)
		{
			BIND_DONE;
			// Load normal data code
			CYRF_ConfigDataCode(LOSI_data_code[(((hopping_frequency[0] - 1) % 5) << 3) + num_ch], 16);
			packet_period = 19738;
		}
	}
	LOSI_send_packet();
	return packet_period;
}

void LOSI_init()
{
	LOSI_cyrf_init();

	CYRF_FindBestChannels(hopping_frequency, 1, 0, 0x07, 0x4F);	// 0x07 and 0x4F are unknown limits, this routine resets the CRC Seed to 0
	hopping_frequency[0] |= 1;									// Only odd channels are used, integrated in CYRF code...

	#ifdef LOSI_FORCE_ID
		/*	
		rx_tx_addr[0] = 0x47;
		rx_tx_addr[1] = 0x52;
		rx_tx_addr[2] = 0xAE;
		rx_tx_addr[3] = 0xAA;
		crc8 = 0x0B;
		num_ch = 0x07;
		//Data codes hopping_frequency[0] % 5
		//{ 0x40, 0xBA, 0x97, 0xD5, 0x86, 0x4F, 0xCC, 0xD1, 0xD7, 0xA1, 0x54, 0xB1, 0x5E, 0x89, 0xAE, 0x86 },
		//{ 0x62, 0xF5, 0x2B, 0xAA, 0xFC, 0x33, 0xBF, 0xAF, 0x40, 0x56, 0x32, 0xD9, 0x0F, 0xD9, 0x5D, 0x97 },
		//{ 0x9E, 0x08, 0xD1, 0xAE, 0x59, 0x5E, 0xE8, 0xF0, 0xC0, 0x90, 0x8F, 0xBB, 0x7C, 0x8E, 0x2B, 0x8E },
		//{ 0x35, 0xD1, 0xFC, 0x97, 0x23, 0xD4, 0xC9, 0x88, 0xE1, 0xD6, 0x31, 0x26, 0x5F, 0xBD, 0x40, 0x93 },
		//{ 0x5F, 0x30, 0x3B, 0x56, 0x96, 0x45, 0xF4, 0xA1, 0x03, 0xBC, 0x6E, 0x8A, 0xEF, 0xBD, 0xFE, 0xF8 }
		*/
		rx_tx_addr[0] = 0x56;
		rx_tx_addr[1] = 0x52;
		rx_tx_addr[2] = 0x22;
		rx_tx_addr[3] = 0x8A;
		crc8 = 0x0F;
		num_ch = 0x02;
		//Data codes hopping_frequency[0] % 5
		//{ 0xF1, 0x94, 0x30, 0x21, 0xA1, 0x1C, 0x88, 0xA9, 0xD0, 0xD2, 0x8E, 0xBC, 0x82, 0x2F, 0xE3, 0xB4 },
		//{ 0x17, 0xFF, 0x9E, 0x21, 0x36, 0x90, 0xC7, 0x82, 0xBC, 0x5D, 0x9A, 0x5B, 0xEE, 0x7F, 0x42, 0xEB },
		//{ 0x4C, 0x97, 0x9D, 0xBF, 0xB8, 0x3D, 0xB5, 0xBE, 0x0C, 0x5D, 0x24, 0x30, 0x9F, 0xCA, 0x6D, 0xBD },
		//{ 0x7D, 0x2D, 0x49, 0x54, 0xD0, 0x80, 0x40, 0xC1, 0xB6, 0xF2, 0xE6, 0x1B, 0x80, 0x5A, 0x36, 0xB4 },
		//{ 0xC3, 0x0E, 0x01, 0x16, 0x0E, 0x32, 0x06, 0xBA, 0xE0, 0x83, 0x01, 0xFA, 0xAB, 0x3E, 0x8F, 0xAC }
		
		// Note: crc8=00..0F and num_ch=00..07
	#endif

	CYRF_ConfigRFChannel(hopping_frequency[0]);

	bind_counter = IS_BIND_IN_PROGRESS?300:1;
	packet_period = 8763;
}

#endif
