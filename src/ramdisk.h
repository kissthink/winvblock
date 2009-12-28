/**
 * Copyright (C) 2009, Shao Miller <shao.miller@yrdsb.edu.on.ca>.
 *
 * This file is part of WinVBlock, derived from WinAoE.
 *
 * WinVBlock is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * WinVBlock is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with WinVBlock.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _ramdisk_h
#  define _ramdisk_h

/**
 * @file
 *
 * RAM disk specifics
 *
 */

winvblock__def_struct ( ramdisk__type )
{
  disk__type disk;
  winvblock__uint32 DiskBuf;
  winvblock__uint32 DiskSize;
};

extern disk__io_decl (
  ramdisk__io
 );
extern winvblock__uint32 ramdisk__max_xfer_len (
  disk__type_ptr disk_ptr
 );
extern winvblock__uint32 ramdisk__query_id (
  disk__type_ptr disk_ptr,
  BUS_QUERY_ID_TYPE query_type,
  PWCHAR buf_512
 );

/*
 * Establish a pointer into the RAM disk device's extension space
 */
__inline ramdisk__type_ptr STDCALL
ramdisk__get_ptr (
  driver__dev_ext_ptr dev_ext_ptr
 )
{
  /*
   * Since the device extension is the first member of the disk
   * member of an AoE disk, and the disk structure is itself the
   * first member of an AoE disk structure, a simple cast will suffice
   */
  return ( ramdisk__type_ptr ) dev_ext_ptr;
}

#endif				/* _ramdisk_h */
