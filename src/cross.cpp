#include "cross.h"
#include "random.h"

#include <cstdlib>

// GPCross

GPCross::GPCross(Fitness* f) : f(f) {}

Program** GPCross::run(Program** pool, int pool_size, int new_pool_size) {}

//GPCrossTree

GPCrossTree::GPCrossTree(Fitness* f, int max_depth, double cross_p) :
  GPCross(f),
  max_depth(max_depth),
  cross_p(cross_p)
{}

ProgramNode* copy_subtree_into_tree(ProgramNode* tree, int replace_id, ProgramNode* subtree) {
  if(tree->get_id() == replace_id) {
    return subtree->copy_deep();
  }
  else {
    ProgramNode* new_tree = tree->copy_shallow();
    for(int i = 0; i < new_tree->get_num_children(); i++) {
      new_tree->set_child(i, copy_subtree_into_tree(tree->get_child(i), replace_id, subtree));
    }
    return new_tree;
  }
}

ProgramNode* get_random_subtree(ProgramNode* tree, int level, int type) {
  if(tree->get_num_children() <= 0) {
    if(type == -1 || tree->get_type() == type) {
      return tree;
    }
    else {
      return 0;
    }
  }
  else {
    if(level <= 0 && (type == -1 || tree->get_type() == type)) {
      return tree;
    }
    else {
      ProgramNode* subtree;
      int r = rand() % tree->get_num_children();
      subtree = get_random_subtree(tree->get_child(r), level-1, type);
      return subtree;
    }
  }
}

Program** GPCrossTree::run(Program** pool, int pool_size, int new_pool_size) {
  Program** new_pool = new Program*[new_pool_size];
  for(int i = 0; i < new_pool_size; i += 2) {
    int r1 = rand() % pool_size, r2 = rand() % pool_size;
    if(rand_double() > cross_p) {
      new_pool[i] = pool[r1]->copy();
      new_pool[i+1] = pool[r2]->copy();
    }
    else {
      int level = rand() % max_depth;
      ProgramNode* subtree1 = get_random_subtree(pool[r1]->get_root(), level, -1);
      ProgramNode* subtree2 = get_random_subtree(pool[r2]->get_root(), level, subtree1->get_type());
      if(subtree2) {
        ProgramNode* tree1 = copy_subtree_into_tree(pool[r1]->get_root(), subtree1->get_id(), subtree2);
        ProgramNode* tree2 = copy_subtree_into_tree(pool[r2]->get_root(), subtree2->get_id(), subtree1);
        new_pool[i] = new Program(pool[r1]->get_num_params(), tree1);
        new_pool[i+1] = new Program(pool[r2]->get_num_params(), tree2);
      }
      else {
        new_pool[i] = pool[r1]->copy();
        new_pool[i+1] = pool[r2]->copy();
      }
      // if(subtree1) delete subtree1;
      // if(subtree2) delete subtree2;
    }
  }

  for(int i = 0; i < pool_size; i++) {
    delete pool[i];
  }
  delete[] pool;
  
  return new_pool;
}
