void __thiscall vostok::animation::mixing::n_ary_tree_converter::fix_weight_driving_animations_with_null_weights(
        vostok::animation::mixing::n_ary_tree_converter *this,
        const vostok::animation::mixing::expression *expression,
        int *__comp)
{
  const vostok::animation::mixing::expression *v3; // ebx
  vostok::animation::mixing::base_lexeme *m_lexeme; // eax
  vostok::animation::mixing::binary_tree_base_node *v5; // edi
  vostok::animation::mixing::binary_tree_weight_node *v6; // eax
  vostok::animation::mixing::binary_tree_weight_node *v7; // ecx
  vostok::animation::mixing::binary_tree_base_node *m_next_weight; // eax
  bool v9; // zf
  void *v10; // esp
  vostok::animation::mixing::binary_tree_animation_node *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebx
  const vostok::animation::mixing::expression *v14; // esi
  vostok::animation::mixing::binary_tree_weight_node *v15; // eax
  int v16; // ecx
  const vostok::animation::mixing::expression *v17; // eax
  unsigned int v18; // ecx
  stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > *v19; // eax
  vostok::animation::mixing::binary_tree_animation_node *first; // ecx
  _DWORD v21[4]; // [esp+0h] [ebp-38h] BYREF
  stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > value; // [esp+10h] [ebp-28h] BYREF
  vostok::buffer_vector<stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > > v23; // [esp+1Ch] [ebp-1Ch] BYREF
  _DWORD v24[2]; // [esp+28h] [ebp-10h] BYREF
  unsigned int __val; // [esp+30h] [ebp-8h] BYREF
  vostok::animation::mixing::binary_tree_weight_node *m_weight_synchronization_group_id; // [esp+34h] [ebp-4h] BYREF

  v3 = expression;
  m_lexeme = expression[9].m_lexeme;
  v5 = *(vostok::animation::mixing::binary_tree_base_node **)&m_lexeme[12].m_cloned;
  v6 = *(vostok::animation::mixing::binary_tree_weight_node **)&m_lexeme[7].m_cloned;
  v7 = 0;
  __val = 1;
  m_weight_synchronization_group_id = 0;
  if ( v6 )
  {
    v7 = v6;
    ++v6->m_reference_count;
    m_weight_synchronization_group_id = v6;
  }
  while ( v7 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      goto LABEL_10;
    if ( !LOBYTE(v7[3].m_interpolator) )
    {
      m_next_weight = v7[3].m_next_weight;
      if ( m_next_weight != v5 )
      {
        if ( m_next_weight == (vostok::animation::mixing::binary_tree_base_node *)-1 )
        {
LABEL_10:
          v9 = v7->m_reference_count-- == 1;
          if ( v9 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v7->~vostok::animation::mixing::binary_tree_base_node)(
              v7,
              0);
          break;
        }
        ++__val;
        v5 = m_next_weight;
      }
    }
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v7[1].m_simplified_weight,
      &m_weight_synchronization_group_id);
    v7 = m_weight_synchronization_group_id;
  }
  v10 = alloca(12 * __val);
  value.second.second = 0;
  v23.m_begin = (stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > *)v21;
  v23.m_end = (stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > *)v21;
  v11 = (vostok::animation::mixing::binary_tree_animation_node *)v3[9].m_lexeme;
  v23.m_max_end = (stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > *)&v21[3 * __val];
  m_weight_synchronization_group_id = (vostok::animation::mixing::binary_tree_weight_node *)v11->m_weight_synchronization_group_id;
  value.first = (unsigned int)m_weight_synchronization_group_id;
  value.second.first = v11;
  vostok::buffer_vector<stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *>>>::push_back(
    &v23,
    &value);
  v12 = *(_DWORD *)&v3[9].m_lexeme[7].m_cloned;
  v13 = 0;
  __val = 0;
  if ( v12 )
  {
    v13 = v12;
    ++*(_DWORD *)(v12 + 16);
    __val = v12;
  }
  while ( 1 )
  {
    v14 = 0;
    if ( !v13 )
      break;
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      goto LABEL_21;
    if ( !*(_BYTE *)(v13 + 116) )
    {
      v15 = *(vostok::animation::mixing::binary_tree_weight_node **)(v13 + 100);
      if ( v15 != m_weight_synchronization_group_id )
      {
        if ( v15 == (vostok::animation::mixing::binary_tree_weight_node *)-1 )
        {
LABEL_21:
          v9 = (*(_DWORD *)(v13 + 16))-- == 1;
          if ( v9 )
            (**(void (__thiscall ***)(unsigned int, _DWORD))v13)(v13, 0);
          break;
        }
        value.second.second = 0;
        m_weight_synchronization_group_id = v15;
        value.first = (unsigned int)v15;
        value.second.first = (vostok::animation::mixing::binary_tree_animation_node *)v13;
        vostok::buffer_vector<stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *>>>::push_back(
          &v23,
          &value);
      }
    }
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)(v13 + 60),
      (vostok::animation::mixing::binary_tree_weight_node **)&__val);
    v13 = __val;
  }
  v24[1] = &v23;
  v16 = *__comp;
  v24[0] = &binary_tree_weight_driving_animation_getter::`vftable';
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v16 + 4))(v16, v24);
  v17 = (const vostok::animation::mixing::expression *)expression[9].m_lexeme;
  expression = 0;
  if ( v17 )
  {
    ++v17[2].m_node.m_object;
    v14 = v17;
    expression = v17;
  }
  while ( v14 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      goto LABEL_33;
    if ( !LOBYTE(v14[14].m_lexeme) )
    {
      v18 = (unsigned int)v14[12].m_lexeme;
      if ( v18 == -1 )
      {
LABEL_33:
        v9 = v14[2].m_node.m_object-- == (vostok::animation::mixing::binary_tree_base_node *)1;
        if ( v9 )
          ((void (__thiscall *)(const vostok::animation::mixing::expression *, _DWORD))v14->m_node.m_object->__vftable)(
            v14,
            0);
        return;
      }
      LOBYTE(__comp) = 0;
      __val = v18;
      v19 = stlp_std::lower_bound<stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *>> *,unsigned int,find_weight_driving_animation_predicate>(
              v23.m_begin,
              v23.m_end,
              &__val);
      first = v19->second.first;
      if ( first == (vostok::animation::mixing::binary_tree_animation_node *)v14 )
      {
        v14[6].m_lexeme = 0;
        v14[4].m_lexeme = (vostok::animation::mixing::base_lexeme *)v19->second.second->m_weight_interpolator;
      }
      else
      {
        v14[6].m_lexeme = (vostok::animation::mixing::base_lexeme *)first;
      }
    }
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v14[7].m_lexeme,
      (vostok::animation::mixing::binary_tree_weight_node **)&expression);
    v14 = expression;
  }
}
