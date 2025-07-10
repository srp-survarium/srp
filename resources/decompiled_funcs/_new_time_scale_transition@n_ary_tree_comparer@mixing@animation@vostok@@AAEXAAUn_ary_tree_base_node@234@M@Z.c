void __usercall vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node *from@<esi>)
{
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  void (__thiscall *v3)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  vostok::animation::mixing::n_ary_tree_interpolator_selector interpolator_selector; // [esp+0h] [ebp-1Ch] BYREF
  void **v5; // [esp+8h] [ebp-14h]
  _DWORD v6[4]; // [esp+Ch] [ebp-10h] BYREF

  accept = from->accept;
  interpolator_selector.__vftable = (vostok::animation::mixing::n_ary_tree_interpolator_selector_vtbl *)&vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  interpolator_selector.m_result = 0;
  accept(from, &interpolator_selector);
  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator_selector.m_result->transition_time)(interpolator_selector.m_result) == 0.0 )
  {
    this->m_needed_buffer_size += 20;
  }
  else
  {
    this->m_equal = 0;
    v3 = from->accept;
    v5 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
    v6[0] = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
    v6[1] = this;
    v6[2] = 0;
    v3(from, (vostok::animation::mixing::n_ary_tree_visitor *)v6);
    this->m_needed_buffer_size += 40;
  }
}
