vostok::journaling::input_handler *__thiscall vostok::animation::mixing::n_ary_tree_time_scale_node::`scalar deleting destructor'(
        vostok::journaling::input_handler *this,
        char a2)
{
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
