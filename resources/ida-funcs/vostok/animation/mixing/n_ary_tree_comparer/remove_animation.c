void __userpurge vostok::animation::mixing::n_ary_tree_comparer::remove_animation(
        vostok::animation::mixing::n_ary_tree_comparer *this@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<ecx>,
        const vostok::animation::mixing::n_ary_tree_animation_node *weight_driving_animation@<eax>,
        unsigned int is_new_driving_animation)
{
  const vostok::animation::base_interpolator *m_weight_interpolator; // eax
  BOOL v6; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v7; // ecx
  unsigned int v8; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // eax
  unsigned int m_operands_count; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v13; // ecx
  void (__thiscall *v14)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***); // eax
  char v15; // al
  unsigned int m_time_synchronization_group_id; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_root; // eax
  unsigned int v18; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v19; // ecx
  void (__thiscall *v20)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***); // eax
  BOOL v21; // ecx
  unsigned int v22; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl **v23; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl **v24; // esi
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v25; // ecx
  void (__thiscall *v26)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***); // edx
  char v27; // al
  int v28; // ecx
  unsigned int operands_offset; // [esp+Ch] [ebp-14h] BYREF
  void **v30; // [esp+10h] [ebp-10h]
  void **v31; // [esp+14h] [ebp-Ch] BYREF
  vostok::animation::mixing::n_ary_tree_comparer *v32; // [esp+18h] [ebp-8h]
  int v33; // [esp+1Ch] [ebp-4h]

  if ( weight_driving_animation )
    m_weight_interpolator = weight_driving_animation->m_weight_interpolator;
  else
    m_weight_interpolator = animation->m_weight_interpolator;
  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))m_weight_interpolator->transition_time)(m_weight_interpolator) == 0.0 )
    return;
  if ( !animation->m_is_transitting_to_zero || (_BYTE)is_new_driving_animation )
  {
    this->m_equal = 0;
    if ( animation->m_time_driving_animation
      || !animation->m_operands_count
      || (v15 = (*((int (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                 + 3))(animation[1].__vftable),
          is_new_driving_animation = 1,
          !v15) )
    {
      is_new_driving_animation = 0;
    }
    m_time_synchronization_group_id = animation->m_time_synchronization_group_id;
    if ( m_time_synchronization_group_id != -1 )
    {
      m_time_root = this->m_to->m_time_root;
      if ( m_time_root )
      {
        while ( m_time_root->m_time_synchronization_group_id != m_time_synchronization_group_id )
        {
          m_time_root = m_time_root->m_next_time_animation;
          if ( !m_time_root )
            goto LABEL_35;
        }
        if ( m_time_root != animation )
          is_new_driving_animation = 0;
      }
    }
LABEL_35:
    vostok::animation::mixing::n_ary_tree_comparer::new_animation(
      &operands_offset,
      (vostok::animation::mixing::n_ary_tree_comparer *)&is_new_driving_animation,
      this,
      animation,
      &is_new_driving_animation);
    v18 = is_new_driving_animation;
    this->m_needed_buffer_size += 4 * is_new_driving_animation + 4;
    if ( operands_offset < v18 )
    {
      v19 = animation[1].__vftable;
      v20 = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***))*((_DWORD *)v19->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node + 2);
      v30 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
      v31 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
      v32 = this;
      v33 = 0;
      v20(v19, &v31);
    }
    this->m_needed_buffer_size += 20;
    v21 = animation->m_operands_count
       && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 3))(animation[1].__vftable);
    v22 = animation->m_operands_count - v21;
    if ( v22 )
    {
      if ( v22 == 1 )
      {
        v27 = (*((int (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
               + 3))(animation[1].__vftable);
        v30 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
        v31 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
        v32 = this;
        v33 = 0;
        v28 = *((_DWORD *)&animation[1].__vftable + (v27 != 0));
        (*(void (__thiscall **)(int, void ***))(*(_DWORD *)v28 + 8))(v28, &v31);
        this->m_needed_buffer_size += 12;
        return;
      }
      this->m_needed_buffer_size += 4 * v22 + 8;
      v23 = &animation[1].__vftable + animation->m_operands_count;
      v24 = &animation[1].__vftable
          + ((*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
              + 3))(animation[1].__vftable) != 0);
      if ( v24 != v23 )
      {
        do
        {
          v25 = *v24;
          v26 = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***))*((_DWORD *)(*v24)->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node + 2);
          v30 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
          v31 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
          v32 = this;
          v33 = 0;
          v26(v25, &v31);
          ++v24;
        }
        while ( v24 != v23 );
        this->m_needed_buffer_size += 12;
        return;
      }
    }
    else
    {
      this->m_needed_buffer_size += 12;
    }
    this->m_needed_buffer_size += 12;
    return;
  }
  v6 = animation->m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(animation[1].__vftable);
  v7 = (vostok::animation::mixing::n_ary_tree_comparer *)animation->m_time_synchronization_group_id;
  v8 = animation->m_operands_count - v6;
  is_new_driving_animation = v6;
  if ( v7 != (vostok::animation::mixing::n_ary_tree_comparer *)-1 )
  {
    v9 = this->m_to->m_time_root;
    if ( v9 )
    {
      while ( (vostok::animation::mixing::n_ary_tree_comparer *)v9->m_time_synchronization_group_id != v7 )
      {
        v9 = v9->m_next_time_animation;
        if ( !v9 )
          goto LABEL_18;
      }
      if ( v9 != animation )
        is_new_driving_animation = 0;
    }
  }
LABEL_18:
  vostok::animation::mixing::n_ary_tree_comparer::new_animation(
    &operands_offset,
    v7,
    this,
    animation,
    &is_new_driving_animation);
  m_operands_count = animation->m_operands_count;
  is_new_driving_animation += v8;
  v11 = animation + 1;
  for ( i = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)animation + 4 * m_operands_count + 88);
        v11 != i;
        v11 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v11 + 4) )
  {
    if ( !(*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 3))(v11->__vftable)
      || !operands_offset )
    {
      v13 = v11->__vftable;
      v14 = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***))*((_DWORD *)v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node + 2);
      v30 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
      v31 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
      v32 = this;
      v33 = 0;
      v14(v13, &v31);
    }
  }
  this->m_needed_buffer_size += 4 * is_new_driving_animation;
}
