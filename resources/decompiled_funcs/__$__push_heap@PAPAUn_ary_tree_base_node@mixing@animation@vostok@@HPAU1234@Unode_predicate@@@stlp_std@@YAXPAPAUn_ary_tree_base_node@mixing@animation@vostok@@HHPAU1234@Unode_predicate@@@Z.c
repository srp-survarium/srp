void __usercall stlp_std::__push_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<edi>,
        int __holeIndex,
        int __topIndex,
        vostok::animation::mixing::n_ary_tree_base_node *__val)
{
  int v4; // ebx
  int v5; // esi
  vostok::animation::mixing::n_ary_tree_base_node *v6; // ecx
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  bool v8; // cc
  void **v9; // [esp+10h] [ebp-Ch] BYREF
  int v10; // [esp+14h] [ebp-8h]

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      v6 = __first[v5];
      accept = v6->accept;
      v9 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
      v10 = 0;
      accept(v6, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v9, __val);
      if ( v10 != 1 )
        break;
      __first[v4] = __first[v5];
      v4 = v5;
      v8 = v5 <= __topIndex;
      v5 = (v5 - 1) / 2;
    }
    while ( !v8 );
  }
  __first[v4] = __val;
}
