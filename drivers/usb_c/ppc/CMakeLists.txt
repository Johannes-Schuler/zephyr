# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_USBC_PPC_SHELL shell.c)
zephyr_library_sources_ifdef(CONFIG_USBC_PPC_NX20P3483 nxp_nx20p3483.c)
<<<<<<< HEAD
=======
zephyr_library_sources_ifdef(CONFIG_USBC_PPC_NUMAKER usbc_ppc_numaker.c)
>>>>>>> 72dd6bb55432e5fd641ac3b93179a1186ed97911
