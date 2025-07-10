vostok::animation::mixing::n_ary_tree_base_node *const *__usercall stlp_std::priv::__median<vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>@<eax>(
        vostok::animation::mixing::n_ary_tree_base_node *const *__b@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node **__c@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *const *__a)
{
  int v3; // ecx
  void (__thiscall *v4)(int, void ***, int); // eax
  bool v5; // zf
  int v6; // ecx
  void (__thiscall *v7)(int, void ***, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  vostok::animation::mixing::n_ary_tree_base_node *const *result; // eax
  int v9; // ecx
  void (__thiscall *v10)(int, void ***, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  int v11; // [esp+8h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_base_node *v12; // [esp+8h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_base_node *v13; // [esp+8h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_base_node *v14; // [esp+10h] [ebp-10h]
  void **v15; // [esp+14h] [ebp-Ch] BYREF
  int v16; // [esp+18h] [ebp-8h]
  void **v17; // [esp+1Ch] [ebp-4h] BYREF
  void *retaddr; // [esp+20h] [ebp+0h]

  v3 = (int)*__a;
  v4 = *(void (__thiscall **)(int, void ***, int))(**(_DWORD **)__a + 4);
  v11 = (int)*__b;
  v15 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v16 = 0;
  v4(v3, &v15, v11);
  v14 = *__c;
  v5 = retaddr == (void *)1;
  v17 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  retaddr = 0;
  if ( v5 )
  {
    (*(void (__thiscall **)(_DWORD, void ***, vostok::animation::mixing::n_ary_tree_base_node *))(**(_DWORD **)__b + 4))(
      *__b,
      &v17,
      v14);
    if ( v16 != 1 )
    {
      v6 = (int)*__a;
      v7 = *(void (__thiscall **)(int, void ***, vostok::animation::mixing::n_ary_tree_base_node *))(**(_DWORD **)__a + 4);
      v12 = *__c;
      v15 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
      v16 = 0;
      v7(v6, &v15, v12);
      if ( v16 == 1 )
        return __c;
      return __a;
    }
    return __b;
  }
  (*(void (__thiscall **)(_DWORD, void ***, vostok::animation::mixing::n_ary_tree_base_node *))(**(_DWORD **)__a + 4))(
    *__a,
    &v17,
    v14);
  if ( v16 == 1 )
    return __a;
  v9 = (int)*__b;
  v10 = *(void (__thiscall **)(int, void ***, vostok::animation::mixing::n_ary_tree_base_node *))(**(_DWORD **)__b + 4);
  v13 = *__c;
  v15 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v16 = 0;
  v10(v9, &v15, v13);
  result = __c;
  if ( v16 != 1 )
    return __b;
  return result;
}
