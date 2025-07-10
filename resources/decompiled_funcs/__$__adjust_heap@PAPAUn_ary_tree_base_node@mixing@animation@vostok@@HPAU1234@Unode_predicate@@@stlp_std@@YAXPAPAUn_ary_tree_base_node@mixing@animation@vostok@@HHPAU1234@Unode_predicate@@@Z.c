void __usercall stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<eax>,
        int __holeIndex,
        int __len,
        vostok::animation::mixing::n_ary_tree_base_node *__val,
        node_predicate __comp)
{
  int v5; // ebx
  int v6; // esi
  bool i; // zf
  vostok::animation::mixing::n_ary_tree_base_node *v9; // ecx
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  vostok::animation::mixing::n_ary_tree_base_node *v11; // [esp-4h] [ebp-20h]
  void **v12; // [esp+10h] [ebp-Ch] BYREF
  int v13; // [esp+14h] [ebp-8h]

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    v9 = __first[v6];
    accept = v9->accept;
    v11 = __first[v6 - 1];
    v12 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v13 = 0;
    accept(v9, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v12, v11);
    if ( v13 == 1 )
      --v6;
    __first[v5] = __first[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    __first[v5] = __first[v6 - 1];
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
    __first,
    v5,
    __holeIndex,
    __val,
    __comp);
}
