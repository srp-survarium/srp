void __usercall stlp_std::__make_heap<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate,vostok::animation::mixing::n_ary_tree_base_node *,int>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node **__last,
        node_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::animation::mixing::n_ary_tree_base_node *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}
