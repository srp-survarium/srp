void __usercall fill_weights(vostok::animation::mixing::binary_tree_animation_node *animation@<eax>)
{
  vostok::animation::mixing::binary_tree_base_node *i; // esi
  vostok::animation::mixing::binary_tree_base_node_vtbl *v3; // eax
  vostok::animation::mixing::binary_tree_base_node *j; // esi
  int v5; // ebx
  vostok::animation::mixing::binary_tree_base_node *k; // edi
  int v7; // eax
  float m_weight; // [esp+8h] [ebp-4h]
  int v9; // [esp+8h] [ebp-4h]

  for ( i = animation->m_next_weight; i; i = i->m_next_weight )
  {
    v3 = i->__vftable;
    i->m_same_weight = 0;
    m_weight = v3->cast_weight(i)->m_weight;
    i->cast_weight(i)->m_simplified_weight = m_weight;
  }
  for ( j = animation->m_next_weight; j; j = j->m_next_weight )
  {
    if ( !j->m_same_weight )
    {
      v5 = (int)j->cast_weight(j);
      if ( v5 )
      {
        for ( k = j->m_next_weight; k; k = k->m_next_weight )
        {
          v7 = (int)k->cast_weight(k);
          v9 = v7;
          if ( v7 )
          {
            if ( !vostok::animation::compare(*(const vostok::animation::base_interpolator **)(v7 + 20)) )
            {
              k->m_same_weight = j;
              *(float *)(v5 + 28) = *(float *)(v9 + 24) * *(float *)(v5 + 28);
            }
          }
        }
      }
    }
  }
}
