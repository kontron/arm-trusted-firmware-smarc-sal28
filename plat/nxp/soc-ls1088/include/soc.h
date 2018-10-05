/*
 * Copyright 2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Author Ruchika Gupta <ruchika.gupta@nxp.com>
 */

#ifndef _SOC_H
#define	_SOC_H

/* Chassis specific defines - common across SoC's of a particular platform */
#include <lsch3.h>

/* ARM Required MACRO's */
/* Required platform porting definitions */
#define PLAT_PRIMARY_CPU		0x0

/* Number of cores in platform */
#define PLATFORM_CORE_COUNT		 8	
#define NUMBER_OF_CLUSTERS		 2
#define CORES_PER_CLUSTER	 	 4

 /* set to 0 if the clusters are not symmetrical */
#define SYMMETRICAL_CLUSTERS    1

#define PLATFORM_CACHE_LINE_SHIFT	6	/* 64 byte */

#define NXP_OCRAM_SIZE			0x20000

#define NXP_QSPI_FLASH_ADDR		0x20000000
#define NXP_NOR_FLASH_ADDR		0x30000000

#define NUM_DRAM_REGIONS		3
#define	NXP_DRAM0_ADDR			0x80000000
#define NXP_DRAM0_MAX_SIZE		0x80000000	/*  2 GB  */

#define NXP_DRAM1_ADDR			0x2080000000
#define NXP_DRAM1_MAX_SIZE		0x1F80000000	/* 126 G */

#define NXP_DRAM2_ADDR			0x6000000000
#define NXP_DRAM2_MAX_SIZE		0x2000000000	/* 128G */

/*DRAM0 Size defined in platform_def.h */
#define	NXP_DRAM0_SIZE			PLAT_DEF_DRAM0_SIZE

/* CCSR space memory Map */
#define NXP_DDR_ADDR			0x01080000
#define NXP_DDR2_ADDR			0x01090000
/* TZC is not there in LS2088 */
#define NXP_TZC_ADDR			0x01100000
#define NXP_DCFG_ADDR			0x01E00000
#define NXP_PMU_ADDR			0x01E30000
#define NXP_RESET_ADDR			0x01E60000
#define NXP_SFP_ADDR			0x01E80000 //--check
#define NXP_SEC_REGFILE_ADDR		0x01E88000 //--check
#define NXP_RST_ADDR			0x01E88000
#define NXP_SNVS_ADDR			0x01E90000
/* SCFG not present in LS1088 */
#define NXP_I2C_ADDR			0x02000000
#define NXP_QSPI_ADDR			0x020C0000
#define NXP_ESDHC_ADDR			0x02140000
#define NXP_UART_ADDR			0x021C0500
#define NXP_UART1_ADDR			0x021C0600
#define NXP_OCRAM_TZPC_ADDR		0x02200000
#define NXP_IFC_ADDR			0x02240000
#define NXP_GPIO1_ADDR			0x02300000
#define NXP_GPIO2_ADDR			0x02310000
#define NXP_GPIO3_ADDR			0x02320000
#define NXP_GPIO4_ADDR			0x02330000
#define NXP_WDOG1_TZ_ADDR		0x023C0000
#define NXP_TIMER_ADDR			0x023E0000
#define NXP_TIMER_STATUS_ADDR		0x023F0000
#define NXP_CCI_ADDR			0x04090000

#define NXP_SMMU_ADDR			0x05000000
#define NXP_GICD_ADDR			0x06000000
#define NXP_GICR_ADDR			0x06100000
#define NXP_CAAM_ADDR			0x08000000

#define TZPC_BLOCK_SIZE		0x1000

/* PORSR1 */
#define PORSR1_RCW_MASK		0xFF800000
#define PORSR1_RCW_SHIFT	23

/* CFG_RCW_SRC[6:0] */
#define RCW_SRC_TYPE_MASK		0x70

/* RCW SRC NOR */
#define	NOR_16B_VAL			0x20

/* RCW SRC Serial Flash
 * 1. SERAIL NOR (QSPI)
 * 2. OTHERS (SD/MMC, SPI, I2C1
 */
#define RCW_SRC_SERIAL_MASK	0x7F
#define QSPI_VAL		0x62
#define SDHC_VAL		0x40
#define EMMC_VAL		0x41

/*
 * Required LS standard platform porting definitions
 * for CCN-504 - Read from RN-F node ID register
 */
#define PLAT_CLUSTER_TO_CCN_ID_MAP 1,9,11,19

/* Errata */
#define NXP_ERRATUM_A011396

#define NUM_OF_DDRC				2

/* Defines required for using XLAT tables from ARM common code */
#define PLAT_PHY_ADDR_SPACE_SIZE	(1ull << 40)
#define PLAT_VIRT_ADDR_SPACE_SIZE	(1ull << 40)

/* Clock Divisors */
// TBD - Check Platform Clk
#define NXP_PLATFORM_CLK_DIVIDER	1
#define NXP_UART_CLK_DIVIDER		2

 /* pwr mgmt features supported in the soc-specific code:
  *   value == 0x0, the soc code does not support this feature
  *   value != 0x0, the soc code supports this feature
  */
#define SOC_CORE_RELEASE      0x0
#define SOC_CORE_RESTART      0x0
#define SOC_CORE_OFF          0x0
#define SOC_CORE_STANDBY      0x0
#define SOC_CORE_PWR_DWN      0x0
#define SOC_CLUSTER_STANDBY   0x0
#define SOC_CLUSTER_PWR_DWN   0x0  
#define SOC_SYSTEM_STANDBY    0x0
#define SOC_SYSTEM_PWR_DWN    0x0 
#define SOC_SYSTEM_OFF        0x0 
#define SOC_SYSTEM_RESET      0x0 

#define SYSTEM_PWR_DOMAINS 1
#define PLAT_NUM_PWR_DOMAINS   (PLATFORM_CORE_COUNT + \
				NUMBER_OF_CLUSTERS  + \
				SYSTEM_PWR_DOMAINS)

 /* Power state coordination occurs at the system level */
#define PLAT_PD_COORD_LVL MPIDR_AFFLVL2
#define PLAT_MAX_PWR_LVL  PLAT_PD_COORD_LVL

 /* Local power state for power domains in Run state */
#define LS_LOCAL_STATE_RUN  PSCI_LOCAL_STATE_RUN

 /* define retention state */
#define PLAT_MAX_RET_STATE  (PSCI_LOCAL_STATE_RUN + 1)
#define LS_LOCAL_STATE_RET  PLAT_MAX_RET_STATE

 /* define power-down state */
#define PLAT_MAX_OFF_STATE  (PLAT_MAX_RET_STATE + 1)
#define LS_LOCAL_STATE_OFF  PLAT_MAX_OFF_STATE

 /* Some data must be aligned on the biggest cache line size in the platform.
  * This is known only to the platform as it might have a combination of
  * integrated and external caches.
  */
#define CACHE_WRITEBACK_GRANULE	 (1 << 6)

 /* One cache line needed for bakery locks on ARM platforms */
#define PLAT_PERCPU_BAKERY_LOCK_SIZE (1 * CACHE_WRITEBACK_GRANULE)

#ifndef __ASSEMBLER__
/* CCI slave interfaces */
static const int cci_map[] = {
	3,
	4,
};
#endif

#endif // _SOC_H