#ifndef TYPES_H
#define TYPES_H

#define GP_NUM_TYPES 5
#define GPTYPE_ERR 0
#define GPTYPE_INT 1
#define GPTYPE_REAL 2
#define GPTYPE_BOOL 3
#define GPTYPE_CATEGORY 4

#include <string>
#include <vector>

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

class GPVCategoryModel {
public:
  GPVCategoryModel(std::string name);
  int size();
  std::string get_name();
  std::string get_class_name(int value);
private:
  std::string name;
  std::vector<std::string> classes;
};

struct GPVCategory: public GPValue {
  int value;
  GPVCategoryModel* model;
  std::string class_name();
  GPVCategory(int value, GPVCategoryModel* model);
};



#endif
