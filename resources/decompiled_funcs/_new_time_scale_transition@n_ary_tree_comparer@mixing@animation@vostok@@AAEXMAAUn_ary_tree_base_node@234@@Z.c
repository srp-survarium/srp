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
