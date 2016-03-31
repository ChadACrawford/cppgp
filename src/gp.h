#ifndef GP_H
#define GP_H

class GP {
public:
  GP();
  void generation();
  void select();
  void cross();
  void mut();
private:
  int max_depth;
};

#endif
