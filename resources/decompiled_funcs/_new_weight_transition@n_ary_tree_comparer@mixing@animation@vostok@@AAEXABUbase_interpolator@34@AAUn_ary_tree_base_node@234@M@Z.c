void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node *from@<esi>,
        const vostok::animation::base_interpolator *from_animation_interpolator,
        float to)
{
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  void (__thiscall *v5)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  void **v6; // [esp+8h] [ebp-1Ch] BYREF
  _DWORD v7[3]; // [esp+Ch] [ebp-18h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_node weight; // [esp+18h] [ebp-Ch] BYREF

  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))from_animation_interpolator->transition_time)(from_animation_interpolator) == 0.0 )
  {
    this->m_needed_buffer_size += 12;
    this->m_equal = 0;
  }
  else
  {
    accept = from->accept;
    v6 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
    v7[0] = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
    v7[1] = this;
    v7[2] = 0;
    accept(from, (vostok::animation::mixing::n_ary_tree_visitor *)v7);
    v5 = from->accept;
    weight.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    weight.m_interpolator = from_animation_interpolator;
    LODWORD(weight.m_weight) = clear_value;
    v6 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v7[0] = 0;
    v5(from, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v6, &weight);
    if ( v7[0] )
    {
      this->m_needed_buffer_size += 32;
      this->m_equal = 0;
    }
  }
}
