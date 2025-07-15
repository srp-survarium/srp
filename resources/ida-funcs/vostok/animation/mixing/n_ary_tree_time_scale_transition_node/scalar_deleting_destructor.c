vostok::animation::mixing::n_ary_tree_time_scale_transition_node *__thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::`scalar deleting destructor'(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this,
        char a2)
{
  this->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_transition_node::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
