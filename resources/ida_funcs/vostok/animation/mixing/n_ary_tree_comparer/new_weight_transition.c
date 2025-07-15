void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *to@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node *from)
{
  double v3; // st6
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  void **v5; // [esp+Ch] [ebp-Ch] BYREF
  vostok::animation::mixing::n_ary_tree_comparer *v6; // [esp+10h] [ebp-8h] BYREF
  vostok::animation::mixing::n_ary_tree_comparer *v7; // [esp+14h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+18h] [ebp+0h]

  this->m_equal = 0;
  v3 = ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *))*((_DWORD *)to[1].~vostok::animation::mixing::n_ary_tree_base_node
                                                                                       + 3))(to[1].__vftable);
  v5 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
  v6 = (vostok::animation::mixing::n_ary_tree_comparer *)&vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
  v7 = this;
  retaddr = 0;
  if ( v3 == 0.0 )
  {
    to->accept(to, (vostok::animation::mixing::n_ary_tree_visitor *)&v6);
  }
  else
  {
    from->accept(from, (vostok::animation::mixing::n_ary_tree_visitor *)&v6);
    accept = to->accept;
    v5 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
    v6 = this;
    v7 = 0;
    accept(to, (vostok::animation::mixing::n_ary_tree_visitor *)&v5);
    this->m_needed_buffer_size += 20;
  }
}


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


void __usercall vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 24) += 44;
  *(_BYTE *)(a2 + 32) = 0;
}
