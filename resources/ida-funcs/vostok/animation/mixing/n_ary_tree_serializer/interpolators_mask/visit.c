void __thiscall vostok::animation::mixing::n_ary_tree_serializer::interpolators_mask::visit(
        vostok::animation::mixing::n_ary_tree_serializer::interpolators_mask *this,
        const vostok::animation::instant_interpolator *__formal)
{
  this->mask |= 1u;
}


void __thiscall vostok::animation::mixing::n_ary_tree_serializer::interpolators_mask::visit(
        vostok::animation::mixing::n_ary_tree_serializer::interpolators_mask *this,
        const vostok::animation::linear_interpolator *interpolator)
{
  if ( ((double (__thiscall *)(const vostok::animation::linear_interpolator *))interpolator->transition_time)(interpolator) == g_jump_prepare_interval_length )
  {
    this->mask |= 2u;
  }
  else if ( ((double (__thiscall *)(const vostok::animation::linear_interpolator *))interpolator->transition_time)(interpolator) == g_short_jump_transition_time )
  {
    this->mask |= 4u;
  }
  else
  {
    interpolator->transition_time(interpolator);
    this->mask |= 8u;
  }
}
