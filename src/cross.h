#ifndef CROSS_H
#define CROSS_H

class GPCross {
public:
  GPCross(Fitness* f);
  virtual Program* cross(Program* pool, int pool_size, int new_pool_size);
private:
  Fitness* f;
};

class GPCrossTree : public GPCross {
public:
  GPCross(Fitness* f, int max_depth, double cross_p);

  Program* cross(Program* pool, int pool_size, int new_pool_size);
private:
  int max_depth;
};

#endif
