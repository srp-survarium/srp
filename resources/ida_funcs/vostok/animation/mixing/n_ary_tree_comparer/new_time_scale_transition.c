void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *to@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node *from)
{
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // edx
  void (__thiscall *v4)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  double v5; // st6
  void (__thiscall *v6)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  void **v7; // [esp+Ch] [ebp-10h] BYREF
  void **v8; // [esp+10h] [ebp-Ch] BYREF
  vostok::animation::mixing::n_ary_tree_comparer *v9; // [esp+14h] [ebp-8h] BYREF
  vostok::animation::mixing::n_ary_tree_comparer *v10; // [esp+18h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+1Ch] [ebp+0h]

  accept = from->accept;
  v7 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v8 = 0;
  accept(from, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v7, to);
  if ( v8 )
  {
    this->m_equal = 0;
    v5 = ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *))*((_DWORD *)to[1].~vostok::animation::mixing::n_ary_tree_base_node
                                                                                         + 3))(to[1].__vftable);
    v8 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
    v9 = (vostok::animation::mixing::n_ary_tree_comparer *)&vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
    v10 = this;
    retaddr = 0;
    if ( v5 == 0.0 )
    {
      to->accept(to, (vostok::animation::mixing::n_ary_tree_visitor *)&v9);
    }
    else
    {
      from->accept(from, (vostok::animation::mixing::n_ary_tree_visitor *)&v9);
      v6 = to->accept;
      v7 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
      v8 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
      v9 = this;
      v10 = 0;
      v6(to, (vostok::animation::mixing::n_ary_tree_visitor *)&v8);
      this->m_needed_buffer_size += 20;
    }
  }
  else
  {
    v4 = from->accept;
    v7 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
    v8 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
    v9 = this;
    v10 = 0;
    v4(from, (vostok::animation::mixing::n_ary_tree_visitor *)&v8);
  }
}


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


void __usercall vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *to@<edi>)
{
  double v2; // st6
  void **v3; // [esp+8h] [ebp-Ch] BYREF
  vostok::animation::mixing::n_ary_tree_comparer *v4; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  this->m_equal = 0;
  v2 = ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *))*((_DWORD *)to[1].~vostok::animation::mixing::n_ary_tree_base_node
                                                                                       + 3))(to[1].__vftable);
  v3 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
  v4 = this;
  v5 = 0;
  if ( v2 == 0.0 )
  {
    ((void (__cdecl *)(void ***, void **, void **, vostok::animation::mixing::n_ary_tree_comparer *, int))to->accept)(
      &v3,
      &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'},
      v3,
      v4,
      v5);
  }
  else
  {
    this->m_needed_buffer_size += 20;
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *, void ***, void **, void **, vostok::animation::mixing::n_ary_tree_comparer *, int))to->accept)(
      to,
      &v3,
      &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'},
      v3,
      v4,
      v5);
    this->m_needed_buffer_size += 20;
  }
}
