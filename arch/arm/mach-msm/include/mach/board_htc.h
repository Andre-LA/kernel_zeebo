/* arch/arm/mach-msm/include/mach/BOARD_HTC.h
 * Copyright (C) 2007-2009 HTC Corporation.
 * Author: Thomas Tsai <thomas_tsai@htc.com>
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
#ifndef __ASM_ARCH_MSM_BOARD_HTC_H
#define __ASM_ARCH_MSM_BOARD_HTC_H

#include <linux/types.h>
#include <linux/list.h>
#include <asm/setup.h>
#if defined(CONFIG_MSM_AMSS_VERSION_WINCE)
#include <mach/msm_hsusb.h>
#endif

struct msm_pmem_setting{
	resource_size_t pmem_start;
	resource_size_t pmem_size;
	resource_size_t pmem_adsp_start;
	resource_size_t pmem_adsp_size;
	resource_size_t pmem_gpu0_start;
	resource_size_t pmem_gpu0_size;
	resource_size_t pmem_gpu1_start;
	resource_size_t pmem_gpu1_size;
	resource_size_t pmem_camera_start;
	resource_size_t pmem_camera_size;
	resource_size_t ram_console_start;
	resource_size_t ram_console_size;
#if defined(CONFIG_MSM_AMSS_VERSION_WINCE)
	resource_size_t fb_start;
	resource_size_t fb_size;
#endif
};

enum {
	MSM_SERIAL_UART1	= 0,
	MSM_SERIAL_UART2,
	MSM_SERIAL_UART3,
#ifdef CONFIG_SERIAL_MSM_HS
	MSM_SERIAL_UART1DM,
	MSM_SERIAL_UART2DM,
#endif
	MSM_SERIAL_NUM,
};


/* common init routines for use by arch/arm/mach-msm/board-*.c */

#if !defined(CONFIG_MSM_AMSS_VERSION_WINCE)
void __init msm_add_usb_devices(void (*phy_reset) (void));
#else
void __init msm_add_usb_devices(struct msm_hsusb_platform_data* board_pdata);
#endif
void __init msm_add_mem_devices(struct msm_pmem_setting *setting);
void __init msm_init_pmic_vibrator(void);

struct mmc_platform_data;
int __init msm_add_sdcc_devices(unsigned int controller, struct mmc_platform_data *plat);
int __init msm_add_sdcc(unsigned int controller, struct mmc_platform_data *plat,
			unsigned int stat_irq, unsigned long stat_irq_flags);
void msm_delete_sdcc(unsigned int controller);
int __init msm_add_serial_devices(unsigned uart);

int __init board_mfg_mode(void);
int __init board_mcp_monodie(void);
int __init parse_tag_smi(const struct tag *tags);
int __init parse_tag_hwid(const struct tag * tags);
int __init parse_tag_skuid(const struct tag * tags);
int parse_tag_engineerid(const struct tag * tags);
int __init parse_tag_monodie(const struct tag *tags);

void notify_usb_connected(int online);

char *board_serialno(void);

extern struct resource resources_msm_fb[];

#if defined(CONFIG_MSM_AMSS_VERSION_WINCE)
#define MACHINE_VARIANT_UNDEFINED	0x0
#define MACHINE_VARIANT_RHOD_1XX	0x0101
#define MACHINE_VARIANT_RHOD_2XX	0x0102
#define MACHINE_VARIANT_RHOD_3XX	0x0103
#define MACHINE_VARIANT_RHOD_4XX	0x0104
#define MACHINE_VARIANT_RHOD_5XX	0x0105

int get_machine_variant_type(void);
#endif

#endif
