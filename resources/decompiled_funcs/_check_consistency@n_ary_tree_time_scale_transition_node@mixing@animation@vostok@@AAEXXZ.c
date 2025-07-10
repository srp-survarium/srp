void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_transition_node::check_consistency(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this)
{
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v2; // [esp+0h] [ebp-4h] BYREF

  v2 = this;
  accept = this->accept;
  v2 = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)&vostok::animation::mixing::time_scale_transition_debug::`vftable';
  accept(this, (vostok::animation::mixing::n_ary_tree_visitor *)&v2);
}
