#ifndef __SR_CONSTRAINT_H__
#define __SR_CONSTRAINT_H__

#include "types/settings.h"
#include "types/instance.h"
#include "types/engine.h"

#include <unordered_map>

namespace ZGen {

namespace ShiftReduce {

class Constraint {
public:
  Constraint(const char * postag_dict_path);

  void get_possible_tags(const char * word,
      std::vector< postag_t > & possible_tags);

private:
  void init_default_possible_tags();

  typedef std::bitset<kNumberOfPoSTags>                 postag_mask_t;
  typedef std::unordered_map< word_t, postag_mask_t > map_t;
  map_t                                                 postag_constrains;
};

typedef Constraint constraint_t;

}

}

#endif  //  end for __SR_CONSTRAINT_H__
