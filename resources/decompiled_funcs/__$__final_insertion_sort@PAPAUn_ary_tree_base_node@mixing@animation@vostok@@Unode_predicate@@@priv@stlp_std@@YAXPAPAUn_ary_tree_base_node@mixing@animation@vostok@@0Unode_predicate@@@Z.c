void __usercall stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<eax>,
        vostok::animation::mixing::n_ary_tree_base_node **__last,
        node_predicate __comp)
{
  vostok::animation::mixing::n_ary_tree_base_node **v4; // ebx
  vostok::animation::mixing::n_ary_tree_base_node **j; // esi
  vostok::animation::mixing::n_ary_tree_base_node **v6; // esi
  vostok::animation::mixing::n_ary_tree_base_node **i; // esi

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
    {
      for ( i = __first + 1; i != __last; ++i )
        stlp_std::priv::__linear_insert<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
          __first,
          i,
          *i,
          __comp);
    }
  }
  else
  {
    v4 = __first + 16;
    for ( j = __first + 1; j != v4; ++j )
      stlp_std::priv::__linear_insert<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        __first,
        j,
        *j,
        __comp);
    v6 = __first + 16;
    if ( v4 != __last )
    {
      do
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
          v6,
          *v6,
          __comp);
        ++v6;
      }
      while ( v6 != __last );
    }
  }
}
