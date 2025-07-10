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
