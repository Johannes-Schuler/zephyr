# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_USBC_VBUS_ADC usbc_vbus_adc.c)
<<<<<<< HEAD
=======
zephyr_library_sources_ifdef(CONFIG_USBC_VBUS_NUMAKER usbc_vbus_numaker.c)
>>>>>>> 72dd6bb55432e5fd641ac3b93179a1186ed97911
