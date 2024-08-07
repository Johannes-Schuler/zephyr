# SPDX-License-Identifier: Apache-2.0

board_runner_args(jlink "--device=STM32F030R8" "--speed=4000")
<<<<<<< HEAD

include(${ZEPHYR_BASE}/boards/common/openocd.board.cmake)
include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
=======
board_runner_args(probe-rs "--chip=STM32F030R8Tx")

include(${ZEPHYR_BASE}/boards/common/openocd.board.cmake)
include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/probe-rs.board.cmake)
>>>>>>> 72dd6bb55432e5fd641ac3b93179a1186ed97911
