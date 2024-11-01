#ifndef XV6_FILE_H
#define XV6_FILE_H

#include "defs.h"
#include "fs.h"
#include "types.h"
#include "date.h"

struct file {
  enum { FD_NONE, FD_PIPE, FD_INODE } type;
  int ref; // reference count
  char readable;
  char writable;
  struct pipe* pipe;
  struct inode* ip;
  uint off;
};

// in-memory copy of an inode
struct inode {
  uint dev;  // Device number
  uint inum; // Inode number
  int ref;   // Reference count
  int flags; // I_BUSY, I_VALID
  short type; // copy of disk inode
  short major;
  short minor;
  short nlink;
  uint size;
  // update file metadata
  uint addrs[NDIRECT + 2];
  //part 1 adding create time field
  struct rtcdate createTime;
};
#define I_BUSY 0x1
#define I_VALID 0x2

// table mapping major device number to
// device functions
struct devsw {
  int (*read)(struct inode*, char*, int);
  int (*write)(struct inode*, char*, int);
};

extern struct devsw devsw[];

#define CONSOLE 1

#endif // XV6_FILE_H
