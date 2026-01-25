# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/include/diskio.h"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/include/ff.h"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/include/ffconf.h"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/include/sleep.h"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/include/xilffs.h"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/include/xilffs_config.h"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/include/xilrsa.h"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/include/xiltimer.h"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/include/xtimer_config.h"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/lib/libxilffs.a"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/lib/libxilrsa.a"
  "/home/tom/Documents/Projet_Innovative/platform/zynq_fsbl/zynq_fsbl_bsp/lib/libxiltimer.a"
  )
endif()
