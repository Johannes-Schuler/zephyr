# Copyright (c) 2021 Nordic Semiconductor ASA.
# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
if((CONFIG_BOARD_NRF5340_AUDIO_DK_NRF5340_CPUAPP OR CONFIG_BOARD_NRF5340_AUDIO_DK_NRF5340_CPUAPP_NS)
    AND CONFIG_BOARD_ENABLE_CPUNET)
  zephyr_library()
  zephyr_library_sources(nrf5340_audio_dk_cpunet_reset.c)

  if(CONFIG_BUILD_WITH_TFM)
    zephyr_library_include_directories(
      $<TARGET_PROPERTY:tfm,TFM_BINARY_DIR>/api_ns/interface/include
    )
  endif()
=======
if(CONFIG_BOARD_NRF5340_AUDIO_DK_NRF5340_CPUAPP OR CONFIG_BOARD_NRF5340_AUDIO_DK_NRF5340_CPUAPP_NS)
  zephyr_library()
  zephyr_library_sources(nrf5340_audio_dk_config.c)
>>>>>>> 72dd6bb55432e5fd641ac3b93179a1186ed97911
endif()
