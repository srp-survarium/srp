vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *__thiscall vostok::animation::mixing::n_ary_tree_time_scale_node::`scalar deleting destructor'(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        char a2)
{
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
