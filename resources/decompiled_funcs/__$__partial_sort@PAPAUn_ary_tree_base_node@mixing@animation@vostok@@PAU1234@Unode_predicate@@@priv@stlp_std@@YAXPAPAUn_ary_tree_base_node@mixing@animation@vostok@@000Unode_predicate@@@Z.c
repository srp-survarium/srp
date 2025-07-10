void __usercall stlp_std::priv::__partial_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<eax>,
        vostok::animation::mixing::n_ary_tree_base_node **__middle,
        vostok::animation::mixing::n_ary_tree_base_node **__last,
        vostok::animation::mixing::n_ary_tree_base_node **__formal)
{
  vostok::animation::mixing::n_ary_tree_base_node **v4; // ebx
  int v6; // ebp
  vostok::animation::mixing::n_ary_tree_base_node *v7; // ecx
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  vostok::animation::mixing::n_ary_tree_base_node *v9; // [esp-8h] [ebp-28h]
  vostok::animation::mixing::n_ary_tree_base_node *v10; // [esp-4h] [ebp-24h]
  void **v11; // [esp+18h] [ebp-8h] BYREF
  int v12; // [esp+1Ch] [ebp-4h]

  v4 = __middle;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate,vostok::animation::mixing::n_ary_tree_base_node *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      v7 = *v4;
      accept = (*v4)->accept;
      v10 = *__first;
      v11 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
      v12 = 0;
      accept(v7, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v11, v10);
      if ( v12 == 1 )
      {
        v9 = *v4;
        *v4 = *__first;
        stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
          __first,
          0,
          v6,
          v9,
          (node_predicate)__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
  }
  stlp_std::sort_heap<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate>(
    __first,
    __middle,
    (node_predicate)__formal);
}
