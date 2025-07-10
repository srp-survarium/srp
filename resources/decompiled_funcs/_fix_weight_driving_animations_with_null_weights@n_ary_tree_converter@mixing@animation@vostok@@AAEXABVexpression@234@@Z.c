void __thiscall vostok::animation::mixing::n_ary_tree_converter::fix_weight_driving_animations_with_null_weights(
        vostok::animation::mixing::n_ary_tree_converter *this,
        vostok::animation::mixing::n_ary_tree_converter *expression,
        const vostok::animation::mixing::expression *expressiona)
{
  vostok::animation::mixing::base_lexeme *m_animations_root; // eax
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  bool v12; // zf
  void *v13; // esp
  vostok::animation::mixing::base_lexeme *v14; // ecx
  unsigned int v15; // edi
  vostok::animation::mixing::base_lexeme *v16; // eax
  vostok::animation::mixing::binary_tree_animation_node *v17; // eax
  vostok::animation::mixing::binary_tree_animation_node *v18; // esi
  unsigned int m_weight_synchronization_group_id; // eax
  stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > *m_end; // ecx
  vostok::animation::mixing::binary_tree_animation_node *m_object; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v22; // eax
  vostok::animation::mixing::binary_tree_animation_node *v23; // ecx
  vostok::animation::mixing::binary_tree_base_node *v24; // ecx
  vostok::animation::mixing::base_lexeme *v25; // eax
  vostok::animation::mixing::base_lexeme *v26; // esi
  stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > *v27; // eax
  vostok::animation::mixing::binary_tree_animation_node *first; // ecx
  int v29; // ecx
  vostok::animation::mixing::base_lexeme *v30; // eax
  vostok::animation::mixing::base_lexeme *v31; // ecx
  _DWORD v32[4]; // [esp+0h] [ebp-20h] BYREF
  binary_tree_weight_driving_animation_getter weight_driving_animation_getter; // [esp+10h] [ebp-10h] BYREF
  vostok::buffer_vector<stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > > animations; // [esp+18h] [ebp-8h] BYREF

  m_animations_root = (vostok::animation::mixing::base_lexeme *)expression->m_animations_root;
  v4 = *(_DWORD *)&m_animations_root[12].m_cloned;
  v5 = *(_DWORD *)&m_animations_root[7].m_cloned;
  v6 = 0;
  v7 = 1;
  if ( v5 )
  {
    v6 = v5;
    ++*(_DWORD *)(v5 + 16);
  }
  while ( v6 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      goto LABEL_14;
    if ( !*(_BYTE *)(v6 + 116) )
    {
      v8 = *(_DWORD *)(v6 + 100);
      if ( v8 != v4 )
      {
        if ( v8 == -1 )
        {
LABEL_14:
          v12 = (*(_DWORD *)(v6 + 16))-- == 1;
          if ( v12 )
            (**(void (__thiscall ***)(int, _DWORD))v6)(v6, 0);
          break;
        }
        v4 = *(_DWORD *)(v6 + 100);
        ++v7;
      }
    }
    v9 = *(_DWORD *)(v6 + 60);
    v10 = 0;
    if ( v9 )
    {
      v10 = *(_DWORD *)(v6 + 60);
      ++*(_DWORD *)(v9 + 16);
    }
    v11 = v6;
    v6 = v10;
    v12 = (*(_DWORD *)(v11 + 16))-- == 1;
    if ( v12 )
      (**(void (__thiscall ***)(int, _DWORD))v11)(v11, 0);
  }
  v13 = alloca(12 * v7);
  v14 = (vostok::animation::mixing::base_lexeme *)expression->m_animations_root;
  animations.m_begin = (stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > *)v32;
  animations.m_end = (stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *> > *)v32;
  v15 = *(_DWORD *)&v14[12].m_cloned;
  if ( v32 )
  {
    v32[0] = *(_DWORD *)&v14[12].m_cloned;
    v32[1] = v14;
    v32[2] = 0;
  }
  v16 = (vostok::animation::mixing::base_lexeme *)expression->m_animations_root;
  ++animations.m_end;
  v17 = *(vostok::animation::mixing::binary_tree_animation_node **)&v16[7].m_cloned;
  v18 = 0;
  if ( v17 )
  {
    v18 = v17;
    ++v17->m_reference_count;
  }
  while ( v18 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      goto LABEL_33;
    if ( !v18->m_null_weight_found )
    {
      m_weight_synchronization_group_id = v18->m_weight_synchronization_group_id;
      if ( m_weight_synchronization_group_id != v15 )
      {
        if ( m_weight_synchronization_group_id == -1 )
        {
LABEL_33:
          v12 = v18->m_reference_count-- == 1;
          if ( v12 )
            ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v18->~vostok::animation::mixing::binary_tree_base_node)(
              v18,
              0);
          break;
        }
        m_end = animations.m_end;
        v15 = v18->m_weight_synchronization_group_id;
        if ( animations.m_end )
        {
          animations.m_end->first = m_weight_synchronization_group_id;
          m_end->second.first = v18;
          m_end->second.second = 0;
        }
        ++animations.m_end;
      }
    }
    m_object = v18->m_next_weight_animation.m_object;
    v22 = 0;
    if ( m_object )
    {
      v22 = v18->m_next_weight_animation.m_object;
      ++m_object->m_reference_count;
    }
    v23 = v18;
    v18 = v22;
    v12 = v23->m_reference_count-- == 1;
    if ( v12 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v23->~vostok::animation::mixing::binary_tree_base_node)(
        v23,
        0);
  }
  v24 = expressiona->m_node.m_object;
  weight_driving_animation_getter.m_animations = &animations;
  weight_driving_animation_getter.__vftable = (binary_tree_weight_driving_animation_getter_vtbl *)&binary_tree_weight_driving_animation_getter::`vftable';
  v24->accept(v24, &weight_driving_animation_getter);
  v25 = (vostok::animation::mixing::base_lexeme *)expression->m_animations_root;
  v26 = 0;
  if ( v25 )
  {
    ++v25[2].m_buffer;
    v26 = v25;
  }
  while ( v26 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      goto LABEL_49;
    if ( !v26[14].m_cloned )
    {
      if ( *(_DWORD *)&v26[12].m_cloned == -1 )
      {
LABEL_49:
        v12 = v26[2].m_buffer-- == (vostok::mutable_buffer *)1;
        if ( v12 )
          ((void (__thiscall *)(vostok::animation::mixing::base_lexeme *, _DWORD))v26->m_buffer->m_data)(v26, 0);
        return;
      }
      expressiona = *(const vostok::animation::mixing::expression **)&v26[12].m_cloned;
      v27 = stlp_std::priv::__lower_bound<stlp_std::pair<unsigned int,stlp_std::pair<vostok::animation::mixing::binary_tree_animation_node *,vostok::animation::mixing::binary_tree_animation_node *>> *,unsigned int,find_weight_driving_animation_predicate,find_weight_driving_animation_predicate,int>(
              animations.m_begin,
              animations.m_end,
              (unsigned int *)&expressiona);
      first = v27->second.first;
      if ( first == (vostok::animation::mixing::binary_tree_animation_node *)v26 )
      {
        *(_DWORD *)&v26[6].m_cloned = 0;
        *(_DWORD *)&v26[4].m_cloned = v27->second.second->m_weight_interpolator;
      }
      else
      {
        *(_DWORD *)&v26[6].m_cloned = first;
      }
    }
    v29 = *(_DWORD *)&v26[7].m_cloned;
    v30 = 0;
    if ( v29 )
    {
      v30 = *(vostok::animation::mixing::base_lexeme **)&v26[7].m_cloned;
      ++*(_DWORD *)(v29 + 16);
    }
    v31 = v26;
    v26 = v30;
    v12 = v31[2].m_buffer-- == (vostok::mutable_buffer *)1;
    if ( v12 )
      ((void (__thiscall *)(vostok::animation::mixing::base_lexeme *, _DWORD))v31->m_buffer->m_data)(v31, 0);
  }
}
