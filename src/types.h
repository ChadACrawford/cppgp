#ifndef TYPES_H
#define TYPES_H

#define GP_NUM_TYPES 4
#define GPTYPE_ERR 0
#define GPTYPE_INT 1
#define GPTYPE_REAL 2
#define GPTYPE_BOOL 3

struct GPValue {
  int type;
  int* value;
  GPValue(int type, int* value);
  ~GPValue();
};

#endif
