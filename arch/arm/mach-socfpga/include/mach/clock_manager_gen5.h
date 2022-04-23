/* SPDX-License-Identifier: GPL-2.0+ */
/*
 *  Copyright (C) 2013-2017 Altera Corporation <www.altera.com>
 */

#ifndef _CLOCK_MANAGER_GEN5_H_
#define _CLOCK_MANAGER_GEN5_H_

#ifndef __ASSEMBLY__

#include <linux/bitops.h>

struct cm_config {
	/* main group */
	u32 main_vco_base;
	u32 mpuclk;
	u32 mainclk;
	u32 dbgatclk;
	u32 mainqspiclk;
	u32 mainnandsdmmcclk;
	u32 cfg2fuser0clk;
	u32 maindiv;
	u32 dbgdiv;
	u32 tracediv;
	u32 l4src;

	/* peripheral group */
	u32 peri_vco_base;
	u32 emac0clk;
	u32 emac1clk;
	u32 perqspiclk;
	u32 pernandsdmmcclk;
	u32 perbaseclk;
	u32 s2fuser1clk;
	u32 perdiv;
	u32 gpiodiv;
	u32 persrc;

	/* sdram pll group */
	u32 sdram_vco_base;
	u32 ddrdqsclk;
	u32 ddr2xdqsclk;
	u32 ddrdqclk;
	u32 s2fuser2clk;

	/* altera group */
	u32 altera_grp_mpuclk;
};

/* Clock manager group */
#define CLKMGR_GEN5_CTRL			0x00
#define CLKMGR_GEN5_BYPASS			0x04
#define CLKMGR_GEN5_INTER			0x08
#define CLKMGR_GEN5_STAT			0x14
/* MainPLL group */
#define CLKMGR_GEN5_MAINPLL_VCO			0x40
#define CLKMGR_GEN5_MAINPLL_MISC		0x44
#define CLKMGR_GEN5_MAINPLL_MPUCLK		0x48
#define CLKMGR_GEN5_MAINPLL_MAINCLK		0x4c
#define CLKMGR_GEN5_MAINPLL_DBGATCLK		0x50
#define CLKMGR_GEN5_MAINPLL_MAINQSPICLK		0x54
#define CLKMGR_GEN5_MAINPLL_MAINNANDSDMMCCLK	0x58
#define CLKMGR_GEN5_MAINPLL_CFGS2FUSER0CLK	0x5c
#define CLKMGR_GEN5_MAINPLL_EN			0x60
#define CLKMGR_GEN5_MAINPLL_MAINDIV		0x64
#define CLKMGR_GEN5_MAINPLL_DBGDIV		0x68
#define CLKMGR_GEN5_MAINPLL_TRACEDIV		0x6c
#define CLKMGR_GEN5_MAINPLL_L4SRC		0x70
/* Peripheral PLL group */
#define CLKMGR_GEN5_PERPLL_VCO			0x80
#define CLKMGR_GEN5_PERPLL_MISC			0x84
#define CLKMGR_GEN5_PERPLL_EMAC0CLK		0x88
#define CLKMGR_GEN5_PERPLL_EMAC1CLK		0x8c
#define CLKMGR_GEN5_PERPLL_PERQSPICLK		0x90
#define CLKMGR_GEN5_PERPLL_PERNANDSDMMCCLK	0x94
#define CLKMGR_GEN5_PERPLL_PERBASECLK		0x98
#define CLKMGR_GEN5_PERPLL_S2FUSER1CLK		0x9c
#define CLKMGR_GEN5_PERPLL_EN			0xa0
#define CLKMGR_GEN5_PERPLL_DIV			0xa4
#define CLKMGR_GEN5_PERPLL_GPIODIV		0xa8
#define CLKMGR_GEN5_PERPLL_SRC			0xac
/* SDRAM PLL group */
#define CLKMGR_GEN5_SDRPLL_VCO			0xc0
#define CLKMGR_GEN5_SDRPLL_CTRL			0xc4
#define CLKMGR_GEN5_SDRPLL_DDRDQSCLK		0xc8
#define CLKMGR_GEN5_SDRPLL_DDR2XDQSCLK		0xcc
#define CLKMGR_GEN5_SDRPLL_DDRDQCLK		0xd0
#define CLKMGR_GEN5_SDRPLL_S2FUSER2CLK		0xd4
#define CLKMGR_GEN5_SDRPLL_EN			0xd8
/* Altera group */
#define CLKMGR_GEN5_ALTR_MPUCLK			0xe0
#define CLKMGR_GEN5_ALTR_MAINCLK		0xe4

#define CLKMGR_STAT				CLKMGR_GEN5_STAT
#define CLKMGR_INTER				CLKMGR_GEN5_INTER
#define CLKMGR_PERPLL_EN			CLKMGR_GEN5_PERPLL_EN

/* Clock speed accessors */
unsigned long cm_get_mpu_clk_hz(void);
unsigned long cm_get_sdram_clk_hz(void);
unsigned int cm_get_l4_sp_clk_hz(void);
unsigned int cm_get_mmc_controller_clk_hz(void);
unsigned int cm_get_qspi_controller_clk_hz(void);
unsigned int cm_get_spi_controller_clk_hz(void);
const unsigned int cm_get_osc_clk_hz(const int osc);
const unsigned int cm_get_f2s_per_ref_clk_hz(void);
const unsigned int cm_get_f2s_sdr_ref_clk_hz(void);

/* Clock configuration accessors */
int cm_basic_init(const struct cm_config * const cfg);
const struct cm_config * const cm_get_default_config(void);
#endif /* __ASSEMBLY__ */

#include <linux/bitops.h>
#define LOCKED_MASK \
	(CLKMGR_INTER_SDRPLLLOCKED_MASK  | \
	CLKMGR_INTER_PERPLLLOCKED_MASK  | \
	CLKMGR_INTER_MAINPLLLOCKED_MASK)

#define CLKMGR_CTRL_SAFEMODE				BIT(0)
#define CLKMGR_CTRL_SAFEMODE_OFFSET			0

#define CLKMGR_BYPASS_PERPLLSRC				BIT(4)
#define CLKMGR_BYPASS_PERPLLSRC_OFFSET			4
#define CLKMGR_BYPASS_PERPLL				BIT(3)
#define CLKMGR_BYPASS_PERPLL_OFFSET			3
#define CLKMGR_BYPASS_SDRPLLSRC				BIT(2)
#define CLKMGR_BYPASS_SDRPLLSRC_OFFSET			2
#define CLKMGR_BYPASS_SDRPLL				BIT(1)
#define CLKMGR_BYPASS_SDRPLL_OFFSET			1
#define CLKMGR_BYPASS_MAINPLL				BIT(0)
#define CLKMGR_BYPASS_MAINPLL_OFFSET			0

#define CLKMGR_INTER_MAINPLLLOST_MASK			BIT(3)
#define CLKMGR_INTER_PERPLLLOST_MASK			BIT(4)
#define CLKMGR_INTER_SDRPLLLOST_MASK			BIT(5)
#define CLKMGR_INTER_MAINPLLLOCKED_MASK			BIT(6)
#define CLKMGR_INTER_PERPLLLOCKED_MASK			BIT(7)
#define CLKMGR_INTER_SDRPLLLOCKED_MASK			BIT(8)

#define CLKMGR_STAT_BUSY				BIT(0)

/* Main PLL */
#define CLKMGR_MAINPLLGRP_VCO_BGPWRDN			BIT(0)
#define CLKMGR_MAINPLLGRP_VCO_BGPWRDN_OFFSET		0
#define CLKMGR_MAINPLLGRP_VCO_DENOM_OFFSET		16
#define CLKMGR_MAINPLLGRP_VCO_DENOM_MASK		0x003f0000
#define CLKMGR_MAINPLLGRP_VCO_EN			BIT(1)
#define CLKMGR_MAINPLLGRP_VCO_EN_OFFSET			1
#define CLKMGR_MAINPLLGRP_VCO_NUMER_OFFSET		3
#define CLKMGR_MAINPLLGRP_VCO_NUMER_MASK		0x0000fff8
#define CLKMGR_MAINPLLGRP_VCO_OUTRESETALL_MASK		0x01000000
#define CLKMGR_MAINPLLGRP_VCO_PWRDN			BIT(2)
#define CLKMGR_MAINPLLGRP_VCO_PWRDN_OFFSET		2
#define CLKMGR_MAINPLLGRP_VCO_REGEXTSEL_MASK		0x80000000
#define CLKMGR_MAINPLLGRP_VCO_RESET_VALUE		0x8001000d

#define CLKMGR_MAINPLLGRP_MPUCLK_CNT_OFFSET		0
#define CLKMGR_MAINPLLGRP_MPUCLK_CNT_MASK		0x000001ff

#define CLKMGR_MAINPLLGRP_MAINCLK_CNT_OFFSET		0
#define CLKMGR_MAINPLLGRP_MAINCLK_CNT_MASK		0x000001ff

#define CLKMGR_MAINPLLGRP_DBGATCLK_CNT_OFFSET		0
#define CLKMGR_MAINPLLGRP_DBGATCLK_CNT_MASK		0x000001ff

#define CLKMGR_MAINPLLGRP_MAINQSPICLK_CNT_OFFSET	0
#define CLKMGR_MAINPLLGRP_MAINQSPICLK_CNT_MASK		0x000001ff

#define CLKMGR_MAINPLLGRP_MAINNANDSDMMCCLK_CNT_OFFSET	0
#define CLKMGR_MAINPLLGRP_MAINNANDSDMMCCLK_CNT_MASK	0x000001ff

#define CLKMGR_MAINPLLGRP_CFGS2FUSER0CLK_CNT_OFFSET	0
#define CLKMGR_MAINPLLGRP_CFGS2FUSER0CLK_CNT_MASK	0x000001ff

#define CLKMGR_MAINPLLGRP_EN_L4MPCLK_MASK		BIT(2)
#define CLKMGR_MAINPLLGRP_EN_DBGATCLK_MASK		BIT(4)
#define CLKMGR_MAINPLLGRP_EN_DBGCLK_MASK		BIT(5)
#define CLKMGR_MAINPLLGRP_EN_DBGTRACECLK_MASK		BIT(6)
#define CLKMGR_MAINPLLGRP_EN_DBGTIMERCLK_MASK		BIT(7)
#define CLKMGR_MAINPLLGRP_EN_S2FUSER0CLK_MASK		BIT(9)

#define CLKMGR_MAINPLLGRP_MAINDIV_L3MPCLK_OFFSET	0
#define CLKMGR_MAINPLLGRP_MAINDIV_L3MPCLK_MASK		0x00000003
#define CLKMGR_MAINPLLGRP_MAINDIV_L3SPCLK_OFFSET	2
#define CLKMGR_MAINPLLGRP_MAINDIV_L3SPCLK_MASK		0x0000000c
#define CLKMGR_MAINPLLGRP_MAINDIV_L4MPCLK_OFFSET	4
#define CLKMGR_MAINPLLGRP_MAINDIV_L4MPCLK_MASK		0x00000070
#define CLKMGR_MAINPLLGRP_MAINDIV_L4SPCLK_OFFSET	7
#define CLKMGR_MAINPLLGRP_MAINDIV_L4SPCLK_MASK		0x00000380

#define CLKMGR_MAINPLLGRP_DBGDIV_DBGATCLK_OFFSET	0
#define CLKMGR_MAINPLLGRP_DBGDIV_DBGATCLK_MASK		0x00000003
#define CLKMGR_MAINPLLGRP_DBGDIV_DBGCLK_OFFSET		2
#define CLKMGR_MAINPLLGRP_DBGDIV_DBGCLK_MASK		0x0000000c

#define CLKMGR_MAINPLLGRP_TRACEDIV_TRACECLK_OFFSET	0
#define CLKMGR_MAINPLLGRP_TRACEDIV_TRACECLK_MASK	0x00000007

#define CLKMGR_MAINPLLGRP_L4SRC_L4MP			BIT(0)
#define CLKMGR_MAINPLLGRP_L4SRC_L4MP_OFFSET		0
#define CLKMGR_MAINPLLGRP_L4SRC_L4SP			BIT(1)
#define CLKMGR_MAINPLLGRP_L4SRC_L4SP_OFFSET		1
#define CLKMGR_MAINPLLGRP_L4SRC_RESET_VALUE		0x00000000
#define CLKMGR_L4_SP_CLK_SRC_MAINPLL			0x0
#define CLKMGR_L4_SP_CLK_SRC_PERPLL			0x1

/* Per PLL */
#define CLKMGR_PERPLLGRP_VCO_DENOM_OFFSET		16
#define CLKMGR_PERPLLGRP_VCO_DENOM_MASK			0x003f0000
#define CLKMGR_PERPLLGRP_VCO_NUMER_OFFSET		3
#define CLKMGR_PERPLLGRP_VCO_NUMER_MASK			0x0000fff8
#define CLKMGR_PERPLLGRP_VCO_OUTRESETALL_MASK		0x01000000
#define CLKMGR_PERPLLGRP_VCO_PSRC_OFFSET		22
#define CLKMGR_PERPLLGRP_VCO_PSRC_MASK			0x00c00000
#define CLKMGR_PERPLLGRP_VCO_REGEXTSEL_MASK		0x80000000
#define CLKMGR_PERPLLGRP_VCO_RESET_VALUE		0x8001000d
#define CLKMGR_PERPLLGRP_VCO_SSRC_OFFSET		22
#define CLKMGR_PERPLLGRP_VCO_SSRC_MASK			0x00c00000

#define CLKMGR_VCO_SSRC_EOSC1				0x0
#define CLKMGR_VCO_SSRC_EOSC2				0x1
#define CLKMGR_VCO_SSRC_F2S				0x2

#define CLKMGR_PERPLLGRP_EMAC0CLK_CNT_OFFSET		0
#define CLKMGR_PERPLLGRP_EMAC0CLK_CNT_MASK		0x000001ff

#define CLKMGR_PERPLLGRP_EMAC1CLK_CNT_OFFSET		0
#define CLKMGR_PERPLLGRP_EMAC1CLK_CNT_MASK		0x000001ff

#define CLKMGR_PERPLLGRP_PERQSPICLK_CNT_OFFSET		0
#define CLKMGR_PERPLLGRP_PERQSPICLK_CNT_MASK		0x000001ff

#define CLKMGR_PERPLLGRP_PERNANDSDMMCCLK_CNT_OFFSET	0
#define CLKMGR_PERPLLGRP_PERNANDSDMMCCLK_CNT_MASK	0x000001ff

#define CLKMGR_PERPLLGRP_PERBASECLK_CNT_OFFSET		0
#define CLKMGR_PERPLLGRP_PERBASECLK_CNT_MASK		0x000001ff

#define CLKMGR_PERPLLGRP_S2FUSER1CLK_CNT_OFFSET		0
#define CLKMGR_PERPLLGRP_S2FUSER1CLK_CNT_MASK		0x000001ff

#define CLKMGR_PERPLLGRP_EN_NANDCLK_MASK		0x00000400
#define CLKMGR_PERPLLGRP_EN_SDMMCCLK_MASK		0x00000100

#define CLKMGR_PERPLLGRP_DIV_CAN0CLK_OFFSET		6
#define CLKMGR_PERPLLGRP_DIV_CAN0CLK_MASK		0x000001c0
#define CLKMGR_PERPLLGRP_DIV_CAN1CLK_OFFSET		9
#define CLKMGR_PERPLLGRP_DIV_CAN1CLK_MASK		0x00000e00
#define CLKMGR_PERPLLGRP_DIV_SPIMCLK_OFFSET		3
#define CLKMGR_PERPLLGRP_DIV_SPIMCLK_OFFSET		3
#define CLKMGR_PERPLLGRP_DIV_USBCLK_OFFSET		0
#define CLKMGR_PERPLLGRP_DIV_USBCLK_MASK		0x00000007

#define CLKMGR_PERPLLGRP_GPIODIV_GPIODBCLK_OFFSET	0
#define CLKMGR_PERPLLGRP_GPIODIV_GPIODBCLK_MASK		0x00ffffff

#define CLKMGR_PERPLLGRP_SRC_NAND_OFFSET		2
#define CLKMGR_PERPLLGRP_SRC_NAND_MASK			0x0000000c
#define CLKMGR_PERPLLGRP_SRC_QSPI_OFFSET		4
#define CLKMGR_PERPLLGRP_SRC_QSPI_MASK			0x00000030
#define CLKMGR_PERPLLGRP_SRC_RESET_VALUE		0x00000015
#define CLKMGR_PERPLLGRP_SRC_SDMMC_OFFSET		0
#define CLKMGR_PERPLLGRP_SRC_SDMMC_MASK			0x00000003
#define CLKMGR_SDMMC_CLK_SRC_F2S			0x0
#define CLKMGR_SDMMC_CLK_SRC_MAIN			0x1
#define CLKMGR_SDMMC_CLK_SRC_PER			0x2
#define CLKMGR_QSPI_CLK_SRC_F2S				0x0
#define CLKMGR_QSPI_CLK_SRC_MAIN			0x1
#define CLKMGR_QSPI_CLK_SRC_PER				0x2

/* SDR PLL */
#define CLKMGR_SDRPLLGRP_VCO_DENOM_OFFSET		16
#define CLKMGR_SDRPLLGRP_VCO_DENOM_MASK			0x003f0000
#define CLKMGR_SDRPLLGRP_VCO_NUMER_OFFSET		3
#define CLKMGR_SDRPLLGRP_VCO_NUMER_MASK			0x0000fff8
#define CLKMGR_SDRPLLGRP_VCO_OUTRESETALL		BIT(24)
#define CLKMGR_SDRPLLGRP_VCO_OUTRESETALL_OFFSET		24
#define CLKMGR_SDRPLLGRP_VCO_OUTRESET_OFFSET		25
#define CLKMGR_SDRPLLGRP_VCO_OUTRESET_MASK		0x7e000000
#define CLKMGR_SDRPLLGRP_VCO_REGEXTSEL_MASK		BIT(31)
#define CLKMGR_SDRPLLGRP_VCO_RESET_VALUE		0x8001000d
#define CLKMGR_SDRPLLGRP_VCO_SSRC_OFFSET		22
#define CLKMGR_SDRPLLGRP_VCO_SSRC_MASK			0x00c00000

#define CLKMGR_SDRPLLGRP_DDRDQSCLK_CNT_OFFSET		0
#define CLKMGR_SDRPLLGRP_DDRDQSCLK_CNT_MASK		0x000001ff
#define CLKMGR_SDRPLLGRP_DDRDQSCLK_PHASE_OFFSET		9
#define CLKMGR_SDRPLLGRP_DDRDQSCLK_PHASE_MASK		0x00000e00

#define CLKMGR_SDRPLLGRP_DDR2XDQSCLK_CNT_OFFSET		0
#define CLKMGR_SDRPLLGRP_DDR2XDQSCLK_CNT_MASK		0x000001ff
#define CLKMGR_SDRPLLGRP_DDR2XDQSCLK_PHASE_OFFSET	9
#define CLKMGR_SDRPLLGRP_DDR2XDQSCLK_PHASE_MASK		0x00000e00

#define CLKMGR_SDRPLLGRP_DDRDQCLK_CNT_OFFSET		0
#define CLKMGR_SDRPLLGRP_DDRDQCLK_CNT_MASK		0x000001ff
#define CLKMGR_SDRPLLGRP_DDRDQCLK_PHASE_OFFSET		9
#define CLKMGR_SDRPLLGRP_DDRDQCLK_PHASE_MASK		0x00000e00

#define CLKMGR_SDRPLLGRP_S2FUSER2CLK_CNT_OFFSET		0
#define CLKMGR_SDRPLLGRP_S2FUSER2CLK_CNT_MASK		0x000001ff
#define CLKMGR_SDRPLLGRP_S2FUSER2CLK_PHASE_OFFSET	9
#define CLKMGR_SDRPLLGRP_S2FUSER2CLK_PHASE_MASK		0x00000e00

#endif /* _CLOCK_MANAGER_GEN5_H_ */
