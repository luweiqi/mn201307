/*
 * Copyright (C) 2012 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/*
 *Version SP9832A-2_SR3593_SCH_V1.0.0_V1.0
 */

#include <asm/io.h>
#include <asm/arch/pinmap.h>
#define BIT_PIN_SLP_ALL  (BIT_PIN_SLP_AP|BIT_PIN_SLP_CP0|BIT_PIN_SLP_CP1|BIT_PIN_SLP_VCP0|BIT_PIN_SLP_VCP1)

static pinmap_t pinmap[]={
{REG_PIN_CTRL0,0x08000000},
{REG_PIN_CTRL1,0x0},
{REG_PIN_CTRL2,0x00285000}, // uart0->bt'uart;  uart1->ap'uart0; uart2->cp1'uart1(lte dsp uart); uart3->ap'uart3; uart4->cp0 uart1(td dsp uart), BIT17:15=0
{REG_PIN_CTRL3,0x0},
{REG_PIN_CTRL4,(1<<4)|(1<<1)|0x0},
{REG_PIN_CTRL5,0x0},
{REG_PIN_RFSDA0,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI_DATA_RF0
{REG_PIN_RFSCK0,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI_CLK_RF0
{REG_PIN_RFSEN0,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI_CSN_RF0
{REG_PIN_RFSDA1,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_RFSCK1,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_RFSEN1,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_RFCTL15,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL16,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL17,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL18,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL19,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL20,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL21,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL22,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL23,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL24,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL25,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL26,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LTE_RX_PRIORITY
{REG_PIN_RFCTL0,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL0
{REG_PIN_RFCTL1,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL1
{REG_PIN_RFCTL2,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL2
{REG_PIN_RFCTL3,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL3
{REG_PIN_RFCTL4,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL4
{REG_PIN_RFCTL5,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL6,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL7,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL8,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL8
{REG_PIN_RFCTL9,              BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL9
{REG_PIN_RFCTL10,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL10
{REG_PIN_RFCTL11,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL12,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL13,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL14,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL27,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LTE_TX_PRIORITY
{REG_PIN_XTL_EN,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//GPS_GPIO0
{REG_PIN_RFFE_SCK0,           BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SCLK0
{REG_PIN_RFFE_SDA0,           BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SDA0
{REG_PIN_RFCTL28,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL29,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_SIMCLK0,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_CLK
{REG_PIN_SIMDA0,              BIT_PIN_SLP_VCP1|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//SIM0_DA
{REG_PIN_SIMRST0,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_RST
{REG_PIN_SIMCLK1,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_CLK
{REG_PIN_SIMDA1,              BIT_PIN_SLP_VCP1|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//SIM1_DA
{REG_PIN_SIMRST1,             BIT_PIN_SLP_VCP1|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_RST
{REG_PIN_SIMCLK2,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SIMDA2,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SIMRST2,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_OE},//NC
{REG_PIN_SD0_D3,              BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(3)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD0_D3
{REG_PIN_SD0_D2,              BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(3)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD0_D2
{REG_PIN_SD0_CMD,             BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(3)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD0_CMD
{REG_PIN_SD0_D0,              BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(3)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD0_D0
{REG_PIN_SD0_D1,              BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(3)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD0_D1
{REG_PIN_SD0_CLK0,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(4)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SD0_CLK0
{REG_PIN_SD1_CLK,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(0)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SD1_CLK
{REG_PIN_SD1_CMD,             BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(0)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD1_CMD
{REG_PIN_SD1_D0,              BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(0)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD1_D0
{REG_PIN_SD1_D1,              BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(0)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD1_D1
{REG_PIN_SD1_D2,              BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(0)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD1_D2
{REG_PIN_SD1_D3,              BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(0)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SD1_D3
{REG_PIN_IIS0DI,              BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//BT_IISDO
{REG_PIN_IIS0DO,              BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//BT_IISDI
{REG_PIN_IIS0CLK,             BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//BT_IISCLK
{REG_PIN_IIS0LRCK,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//BT_IISRCK
{REG_PIN_U0TXD,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//BT_U0RXD
{REG_PIN_U0RXD,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//BT_U0TXD
{REG_PIN_U0CTS,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//BT_U0RTS
{REG_PIN_U0RTS,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//BT_U0CTS
{REG_PIN_PTEST,               BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//GND
{REG_PIN_ANA_INT,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//ANA_INT
{REG_PIN_EXT_RST_B,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//EXT_RST_B
{REG_PIN_CHIP_SLEEP,          BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CHIP_SLEEP
{REG_PIN_XTL_BUF_EN0,         BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//XTL_BUF_EN0
{REG_PIN_XTL_BUF_EN1,         BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//XTL_BUF_EN1
{REG_PIN_CLK_32K,             BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//CLK_32K
{REG_PIN_AUD_SCLK,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AUD_SCLK
{REG_PIN_AUD_ADD0,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//AUD_ADD0
{REG_PIN_AUD_ADSYNC,          BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//AUD_ADSYNC
{REG_PIN_AUD_DAD1,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AUD_DAD1
{REG_PIN_AUD_DAD0,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AUD_DAD0
{REG_PIN_AUD_DASYNC,          BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AUD_DASYNC
{REG_PIN_ADI_D,               BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//ADI_D
{REG_PIN_ADI_SYNC,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//ADI_SYNC
{REG_PIN_ADI_SCLK,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//ADI_SCLK
{REG_PIN_LCM_RSTN,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPU|BIT_PIN_SLP_OE},//LCM_RSTN
{REG_PIN_DSI_TE,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//LCM_FMARK
{REG_PIN_MTDO_ARM,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_MTDI_ARM,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_MTCK_ARM,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_MTMS_ARM,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_MTRST_N_ARM,         BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_DTDO_LTE,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TDO_LTE_WG
{REG_PIN_DTDI_LTE,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TDI_LTE_WG
{REG_PIN_DTCK_LTE,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TCK_LTE_WG
{REG_PIN_DTMS_LTE,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TMS_LTE_WG
{REG_PIN_DRTCK_LTE,           BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RTCK_LTE_WG
{REG_PIN_NFWPN,               BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//DAT0
{REG_PIN_NFRB,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_CMD
{REG_PIN_NFCLE,               BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//DAT6
{REG_PIN_NFALE,               BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//DAT7
{REG_PIN_NFREN,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//EMMC_CLK
{REG_PIN_NFD4,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//DAT5
{REG_PIN_NFD5,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//DAT4
{REG_PIN_NFD6,                BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_NFD7,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//DAT3
{REG_PIN_NFD10,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(2)|BITS_PIN_AF(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_RST
{REG_PIN_NFD11,               BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//DAT1
{REG_PIN_NFD14,               BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//DAT2
{REG_PIN_NFCEN0,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_NFWEN,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_NFD0,                BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_NFD1,                BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_NFD2,                BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_NFD3,                BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_NFD8,                BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_NFD9,                BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_NFD12,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_NFD13,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_NFD15,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//No Ball in SCH
{REG_PIN_CCIRD0,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_CCIRD1,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_CMMCLK,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//MCLK
{REG_PIN_CMPCLK,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_CMRST0,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RST0
{REG_PIN_CMRST1,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RST1
{REG_PIN_CMPD0,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//PWDN0
{REG_PIN_CMPD1,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//PWDN1
{REG_PIN_SCL0,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C0_SCL
{REG_PIN_SDA0,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C0_SDA
{REG_PIN_SPI2_CSN,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//GPS_SPI_CS
{REG_PIN_SPI2_DO,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//GPS_SPI_DI
{REG_PIN_SPI2_DI,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//GPS_SPI_DO
{REG_PIN_SPI2_CLK,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//GPS_SPI_CLK
{REG_PIN_SPI0_CSN,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//OTG_ID                ?????    
{REG_PIN_SPI0_DO,             BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C1_SDA
{REG_PIN_SPI0_DI,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//FLASH_EN       
{REG_PIN_SPI0_CLK,            BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C1_SCL
{REG_PIN_MEMS_MIC_CLK0,       BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//WF_COEXIST
{REG_PIN_MEMS_MIC_DATA0,      BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//GPS_COEXIST     
{REG_PIN_MEMS_MIC_CLK1,       BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//GPS_INT   
{REG_PIN_MEMS_MIC_DATA1,      BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//WIFI_WAKE_HOST
{REG_PIN_KEYOUT0,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//KEYOUT0    
{REG_PIN_KEYOUT1,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//Marlin_RST
{REG_PIN_KEYOUT2,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_OE},//FLASH_LED
{REG_PIN_KEYIN0,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN0
{REG_PIN_KEYIN1,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN1
{REG_PIN_KEYIN2,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN2
{REG_PIN_SCL2,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C2_SCL
{REG_PIN_SDA2,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C2_SDA
{REG_PIN_CLK_AUX0,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SLEEP_32K
{REG_PIN_IIS1DI,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//GPS_PDN
{REG_PIN_IIS1DO,              BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//CHG_DONE
{REG_PIN_IIS1CLK,             BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//BT_DEV_WAKE
{REG_PIN_IIS1LRCK,            BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//BT_HOST_WAKE
{REG_PIN_TRACECLK,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//BAND_INFO1    
{REG_PIN_TRACECTRL,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//BAND_INFO2   
{REG_PIN_TRACEDAT0,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_OE},//MAIN_AF_EN ,maning mod for a25
{REG_PIN_TRACEDAT1,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//GPS_GPIO1
{REG_PIN_TRACEDAT2,           BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//LCM_BL_PWM
{REG_PIN_TRACEDAT3,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//G_INT1
{REG_PIN_TRACEDAT4,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//PROX_INT
{REG_PIN_TRACEDAT5,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//TF_DET
{REG_PIN_TRACEDAT6,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_OE},//AW3614 EN
{REG_PIN_TRACEDAT7,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_OE},//AUDIOPA_EN, maning
{REG_PIN_EXTINT0,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CTP_INT
{REG_PIN_EXTINT1,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//CTP_RST
{REG_PIN_SCL3,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C3_SCL
{REG_PIN_SDA3,                BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C3_SDA
{REG_PIN_U1TXD,               BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//U1TXD
{REG_PIN_U1RXD,               BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//U1RXD
{REG_PIN_U2TXD,               BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//U2TXD
{REG_PIN_U2RXD,               BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//U2RXD
{REG_PIN_U3TXD,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//GPS_U0RXD
{REG_PIN_U3RXD,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//GPS_U0TXD
{REG_PIN_U3CTS,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//GPS_U0RTS
{REG_PIN_U3RTS,               BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//GPS_U0CTS
{REG_PIN_U4TXD,               BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//U4TXD
{REG_PIN_U4RXD,               BIT_PIN_SLP_ALL|BIT_PIN_NULL|BITS_PIN_DS(1)|BITS_PIN_AF(0)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//U4RXD
};

/*here is the adie pinmap such as 2723*/
static pinmap_t adie_pinmap[]={
{REG_PIN_ANA_EXT_XTL_EN0,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},
};

int  pin_init(void)
{
	int i;
	for (i = 0; i < sizeof(pinmap)/sizeof(pinmap[0]); i++) {
		__raw_writel(pinmap[i].val, CTL_PIN_BASE + pinmap[i].reg);
	}

	for (i = 0; i < sizeof(adie_pinmap)/sizeof(adie_pinmap[0]); i++) {
		sci_adi_set(CTL_ANA_PIN_BASE + adie_pinmap[i].reg, adie_pinmap[i].val);
	}

	return 0;
}

