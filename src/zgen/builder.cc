#include "zgen/builder.h"
#include "pipe/none.h"
#include "pipe/partial.h"
#include "pipe/full.h"
#include "pipe/full_with_guidance_feature.h"
#include "pipe/full_with_topdown_feature.h"
#include "pipe/full_with_topdown_constrain.h"
#include <boost/log/trivial.hpp>

SR::Pipe* build_pipe(bool learn, const option_t& opts) {
  SR::Pipe* pipe = NULL;
 
  switch (opts.input_type) {
    case option_t::NONE:
      pipe = new SR::NonePipe(
          opts.postag_dict_path.c_str(),
          learn, 
          opts.output_label,
          opts.beam_size);
      break;
    case option_t::PARTIAL:
      pipe = new SR::PartialPipe(
          opts.postag_dict_path.c_str(),
          learn,
          opts.output_label,
          opts.beam_size);
      break;
    case option_t::FULL:
      pipe = new SR::FullPipe(
          opts.postag_dict_path.c_str(),
          learn,
          opts.output_label,
          opts.beam_size);
      break;
    case option_t::FULL_WITH_GUIDANCE_FEATURE:
      pipe = new SR::FullWithGuidanceFeaturePipe(
          learn,
          opts.beam_size);
      break;
    case option_t::FULL_WITH_TOPDOWN_FEATURE:
      pipe = new SR::FullWithTopDownFeaturePipe(
          learn,
          opts.beam_size);
      break;
    case option_t::FULL_WITH_TOPDOWN_CONSTRAIN:
      pipe = new SR::FullWithTopDownConstrainPipe(
          learn,
          opts.beam_size);
      break;
    default:
      return NULL;
  }
  return pipe;
}
