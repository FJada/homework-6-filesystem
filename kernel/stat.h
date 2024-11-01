#ifndef XV6_STAT_H
#define XV6_STAT_H
#include "kernel/date.h"
// #include "kernel/x86.h"
#define T_DIR 1  // Directory
#define T_FILE 2 // File
#define T_DEV 3  // Device

struct stat {
  short type;  // Type of file
  int dev;     // File system's disk device
  uint ino;    // Inode number
  short nlink; // Number of links to file
  uint size;   // Size of file in bytes

  //part 2 update stat with create time field
  struct rtcdate createTime;

};

#endif // XV6_STAT_H
