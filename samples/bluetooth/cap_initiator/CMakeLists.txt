# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(cap_initiator)

target_sources(app PRIVATE
  src/main.c
<<<<<<< HEAD
  src/cap_initiator_unicast.c
)

=======
  src/cap_initiator_tx.c
)

zephyr_sources_ifdef(CONFIG_SAMPLE_UNICAST src/cap_initiator_unicast.c)
zephyr_sources_ifdef(CONFIG_SAMPLE_BROADCAST src/cap_initiator_broadcast.c)

>>>>>>> 72dd6bb55432e5fd641ac3b93179a1186ed97911
zephyr_library_include_directories(${ZEPHYR_BASE}/samples/bluetooth)
