stlp_std::pair<unsigned int,unsigned int> *__usercall vostok::animation::mixing::computed_operands_count@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_node *from@<eax>,
        int a2@<ecx>,
        stlp_std::pair<unsigned int,unsigned int> *to,
        int a3)
{
  vostok::animation::mixing::n_ary_tree_node_comparer **v4; // ebx
  unsigned int m_operands_count; // eax
  vostok::animation::mixing::n_ary_tree_subtraction_node **v6; // edi
  int v7; // ecx
  bool v8; // zf
  const vostok::animation::base_interpolator *v9; // eax
  stlp_std::pair<unsigned int,unsigned int> *result; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v11; // [esp+0h] [ebp-38h]
  _DWORD v12[3]; // [esp+10h] [ebp-28h] BYREF
  char v13; // [esp+1Ch] [ebp-1Ch]
  void **v14; // [esp+20h] [ebp-18h] BYREF
  const vostok::animation::base_interpolator *right; // [esp+24h] [ebp-14h]
  unsigned int v16; // [esp+28h] [ebp-10h]
  vostok::animation::mixing::n_ary_tree_subtraction_node **v17; // [esp+2Ch] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_node_comparer **v18; // [esp+30h] [ebp-8h]
  unsigned int v19; // [esp+34h] [ebp-4h]

  v4 = (vostok::animation::mixing::n_ary_tree_node_comparer **)&from[1];
  m_operands_count = from->m_operands_count;
  v12[1] = a2;
  v18 = &v4[m_operands_count];
  v6 = (vostok::animation::mixing::n_ary_tree_subtraction_node **)(a3 + 88);
  v7 = a3 + 88 + 4 * *(_DWORD *)(a3 + 4);
  v16 = 0;
  v19 = 0;
  v12[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v12[2] = 0;
  v13 = 0;
  v17 = (vostok::animation::mixing::n_ary_tree_subtraction_node **)v7;
  if ( m_operands_count
    && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_node_comparer *))(*v4)->dispatch)(*v4) )
  {
    ++v4;
    v8 = *(_DWORD *)(a3 + 4) == 0;
    v16 = 1;
    if ( !v8 && (*v6)->is_time_scale(*v6) )
      goto LABEL_9;
  }
  else if ( *(_DWORD *)(a3 + 4) && (*v6)->is_time_scale(*v6) )
  {
    v16 = 1;
LABEL_9:
    v6 = (vostok::animation::mixing::n_ary_tree_subtraction_node **)(a3 + 92);
  }
  right = 0;
  v14 = &vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  if ( v4 != v18 )
  {
    while ( 1 )
    {
      if ( v6 == v17 )
      {
LABEL_21:
        while ( v4 != v18 )
        {
          ++v19;
          ++v4;
        }
        goto LABEL_24;
      }
      if ( vostok::animation::mixing::n_ary_tree_node_comparer::compare(*v4, (int)v12, *v6, v11) == equal )
        break;
      (*v6)->accept(*v6, (vostok::animation::mixing::n_ary_tree_visitor *)&v14);
      v9 = vostok::animation::compare(right);
      if ( !v9 )
        break;
      ++v19;
      if ( v9 != (const vostok::animation::base_interpolator *)1 )
        goto LABEL_17;
      ++v4;
LABEL_18:
      if ( v4 == v18 )
        goto LABEL_21;
    }
    ++v19;
    ++v4;
LABEL_17:
    ++v6;
    goto LABEL_18;
  }
LABEL_24:
  while ( v6 != v17 )
  {
    ++v6;
    ++v19;
  }
  result = to;
  to->first = v19;
  to->second = v16;
  return result;
}
