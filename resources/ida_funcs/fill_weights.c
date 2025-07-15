void __usercall fill_weights(vostok::animation::mixing::binary_tree_animation_node *animation@<eax>)
{
  vostok::animation::mixing::binary_tree_base_node *i; // esi
  vostok::animation::mixing::binary_tree_weight_node *(__thiscall *cast_weight)(vostok::animation::mixing::binary_tree_base_node *); // edx
  int v4; // eax
  vostok::animation::mixing::binary_tree_weight_node *(__thiscall *v5)(vostok::animation::mixing::binary_tree_base_node *); // edx
  vostok::animation::mixing::binary_tree_base_node *j; // ebp
  int v7; // ebx
  vostok::animation::mixing::binary_tree_base_node *k; // esi
  int v9; // edi
  float v10; // [esp+Ch] [ebp-4h] BYREF

  for ( i = animation->m_next_weight; i; i = i->m_next_weight )
  {
    cast_weight = i->cast_weight;
    i->m_same_weight = 0;
    v4 = (int)cast_weight(i);
    v5 = i->cast_weight;
    v10 = *(float *)(v4 + 24);
    v5(i)->m_simplified_weight = v10;
  }
  for ( j = animation->m_next_weight; j; j = j->m_next_weight )
  {
    if ( !j->m_same_weight )
    {
      v7 = (int)j->cast_weight(j);
      if ( v7 )
      {
        for ( k = j->m_next_weight; k; k = k->m_next_weight )
        {
          v9 = (int)k->cast_weight(k);
          if ( v9 )
          {
            (*(void (__thiscall **)(_DWORD, float *, _DWORD))(**(_DWORD **)(v7 + 20) + 16))(
              *(_DWORD *)(v7 + 20),
              &v10,
              *(_DWORD *)(v9 + 20));
            if ( v10 == 0.0 )
            {
              k->m_same_weight = j;
              *(float *)(v7 + 28) = *(float *)(v9 + 24) * *(float *)(v7 + 28);
            }
          }
        }
      }
    }
  }
}
