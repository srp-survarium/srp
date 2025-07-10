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
