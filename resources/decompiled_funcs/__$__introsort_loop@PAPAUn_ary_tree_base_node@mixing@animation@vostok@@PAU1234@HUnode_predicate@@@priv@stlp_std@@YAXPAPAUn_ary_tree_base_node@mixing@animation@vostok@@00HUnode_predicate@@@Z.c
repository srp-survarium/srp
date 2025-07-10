void __cdecl stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,int,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first,
        vostok::animation::mixing::n_ary_tree_base_node **__last,
        vostok::animation::mixing::n_ary_tree_base_node **__formal,
        int __depth_limit,
        vostok::animation::mixing::n_ary_tree_base_node **__comp)
{
  vostok::animation::mixing::n_ary_tree_base_node **v5; // ebx
  vostok::animation::mixing::n_ary_tree_base_node **v6; // eax
  vostok::animation::mixing::n_ary_tree_base_node **v7; // esi
  node_predicate v8; // [esp+0h] [ebp-10h]

  v5 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v6 = (vostok::animation::mixing::n_ary_tree_base_node **)stlp_std::priv::__median<vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
                                                                 __first,
                                                                 &__first[(v5 - __first) / 2],
                                                                 v5 - 1,
                                                                 (node_predicate)__comp);
      v7 = stlp_std::priv::__unguarded_partition<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
             __first,
             v5,
             *v6,
             (node_predicate)__comp);
      stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,int,node_predicate>(
        v7,
        v5,
        0,
        __depth_limit,
        (node_predicate)__comp);
      v5 = v7;
      if ( (int)(((char *)v7 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
      __first,
      v5,
      v5,
      __comp,
      v8);
  }
}
