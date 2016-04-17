#ifndef TYPES_H
#define TYPES_H

#define GP_NUM_TYPES 5
#define GPTYPE_ERR 0
#define GPTYPE_INT 1
#define GPTYPE_REAL 2
#define GPTYPE_BOOL 3
#define GPTYPE_CATEGORY 4

struct GPValue {
  int type;
  GPValue* copy();
protected:
  GPValue(int type);
};

struct GPVErr: public GPValue {
  const char* message;
  GPVErr(const char* message);
};

struct GPVInt: public GPValue {
  int value;
  GPVInt(int value);
};

struct GPVReal: public GPValue {
  double value;
  GPVReal(double value);
};

struct GPVBool: public GPValue {
  bool value;
  GPVBool(bool value);
};

struct GPVCategory: public GPValue {
  int value;
  int num_categories;
  GPVCategory(int value, int num_categories);
};



#endif
