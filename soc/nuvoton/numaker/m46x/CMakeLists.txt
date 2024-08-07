# Copyright (c) 2023 Nuvoton Technology Corporation.
#
# SPDX-License-Identifier: Apache-2.0

zephyr_sources(soc.c)

zephyr_include_directories(.)

<<<<<<< HEAD
=======
zephyr_library_sources_ifdef(CONFIG_POWEROFF poweroff.c)

>>>>>>> 72dd6bb55432e5fd641ac3b93179a1186ed97911
set(SOC_LINKER_SCRIPT ${ZEPHYR_BASE}/include/zephyr/arch/arm/cortex_m/scripts/linker.ld CACHE INTERNAL "")
