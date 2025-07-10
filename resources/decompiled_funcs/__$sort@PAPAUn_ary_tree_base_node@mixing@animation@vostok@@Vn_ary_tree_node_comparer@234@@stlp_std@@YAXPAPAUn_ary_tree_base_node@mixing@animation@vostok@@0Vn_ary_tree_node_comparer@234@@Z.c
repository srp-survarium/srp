void __usercall stlp_std::sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_node_comparer>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node **__last@<eax>,
        vostok::animation::mixing::n_ary_tree_node_comparer __comp)
{
  int v4; // eax
  int i; // ecx
  vostok::animation::mixing::n_ary_tree_node_comparer v6; // [esp-8h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_node_comparer v7; // [esp-8h] [ebp-Ch]

  if ( __first != __last )
  {
    v6.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v6.result = __comp.result;
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,int,vostok::animation::mixing::n_ary_tree_node_comparer>(
      __first,
      __last,
      0,
      2 * i,
      v6);
    v7.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v7.result = __comp.result;
    stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_node_comparer>(
      __first,
      __last,
      v7);
  }
}
