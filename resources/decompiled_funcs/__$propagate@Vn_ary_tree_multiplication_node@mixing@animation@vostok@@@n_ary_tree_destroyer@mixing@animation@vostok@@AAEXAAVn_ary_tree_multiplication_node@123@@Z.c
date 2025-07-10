void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_destroyer *node,
        vostok::animation::mixing::n_ary_tree_addition_node *nodea)
{
  _DWORD *v3; // esi
  int v4; // edi

  v3 = &nodea[1].__vftable;
  v4 = (int)&nodea[1] + 4 * nodea->m_operands_count;
  if ( &nodea[1] != (vostok::animation::mixing::n_ary_tree_addition_node *)v4 )
  {
    do
    {
      (*(void (__thiscall **)(_DWORD, vostok::animation::mixing::n_ary_tree_destroyer *))(*(_DWORD *)*v3 + 8))(
        *v3,
        node);
      ++v3;
    }
    while ( v3 != (_DWORD *)v4 );
  }
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_addition_node *, _DWORD))nodea->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node)(
    nodea,
    0);
}
