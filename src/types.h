#ifndef TYPES_H
#define TYPES_H

#define GPTYPE_ERR 0
#define GPTYPE_INT 1
#define GPTYPE_REAL 2
#define GPTYPE_BOOL 3

struct GPValue {
  int type;
  bool is_ptr;
  int* value;
  GPValue(int type, int* value);
  ~GPValue();
};

#endif
