void __usercall stlp_std::sort_heap<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node **__last@<eax>,
        node_predicate __comp)
{
  int v3; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::animation::mixing::n_ary_tree_base_node **)((char *)__first + v3 - 4);
      v5 = v3 - 4;
      *(vostok::animation::mixing::n_ary_tree_base_node **)((char *)__first + v3 - 4) = *__first;
      stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}
