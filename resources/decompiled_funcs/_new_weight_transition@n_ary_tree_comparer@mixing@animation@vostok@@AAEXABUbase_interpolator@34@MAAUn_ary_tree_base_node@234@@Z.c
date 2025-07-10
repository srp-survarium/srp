void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node *to@<esi>,
        const vostok::animation::base_interpolator *to_animation_interpolator,
        float from)
{
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  vostok::animation::mixing::n_ary_tree_double_dispatcher dispatcher; // [esp+4h] [ebp-1Ch] BYREF
  _DWORD v6[3]; // [esp+8h] [ebp-18h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_node weight; // [esp+14h] [ebp-Ch] BYREF

  accept = to->accept;
  v6[0] = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
  v6[1] = this;
  v6[2] = 0;
  accept(to, (vostok::animation::mixing::n_ary_tree_visitor *)v6);
  weight.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
  weight.m_interpolator = to_animation_interpolator;
  LODWORD(weight.m_weight) = clear_value;
  dispatcher.__vftable = (vostok::animation::mixing::n_ary_tree_double_dispatcher_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v6[0] = 0;
  vostok::animation::mixing::n_ary_tree_weight_node::accept(&weight, &dispatcher, to);
  if ( v6[0] )
  {
    this->m_equal = 0;
    if ( ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *))*((_DWORD *)to[1].~vostok::animation::mixing::n_ary_tree_base_node
                                                                                         + 3))(to[1].__vftable) != 0.0 )
      this->m_needed_buffer_size += 32;
  }
}
