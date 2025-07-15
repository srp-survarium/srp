void __userpurge vostok::animation::mixing::n_ary_tree_comparer::remove_animation(
        vostok::animation::mixing::n_ary_tree_comparer *this@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<ecx>,
        const vostok::animation::mixing::n_ary_tree_animation_node *weight_driving_animation@<eax>,
        unsigned int is_new_driving_animation)
{
  const vostok::animation::base_interpolator *m_weight_interpolator; // ecx
  char v6; // al
  unsigned int v7; // ecx
  int v8; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *k; // eax
  vostok::animation::mixing::n_ary_tree_comparer **v10; // ebx
  vostok::animation::mixing::n_ary_tree_comparer **v11; // esi
  char v12; // al
  unsigned int m_time_synchronization_group_id; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *i; // eax
  unsigned int v15; // eax
  BOOL v16; // ecx
  unsigned int v17; // eax
  vostok::animation::mixing::n_ary_tree_comparer **v18; // ebx
  vostok::animation::mixing::n_ary_tree_comparer **j; // esi
  char v20; // al
  unsigned int v21; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v22; // [esp+10h] [ebp-4h] BYREF

  this->m_equal = 0;
  if ( weight_driving_animation )
    m_weight_interpolator = weight_driving_animation->m_weight_interpolator;
  else
    m_weight_interpolator = animation->m_weight_interpolator;
  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))m_weight_interpolator->transition_time)(m_weight_interpolator) == 0.0 )
  {
    this->m_equal = 0;
  }
  else if ( !animation->m_is_transitting_to_zero || (_BYTE)is_new_driving_animation )
  {
    this->m_equal = 0;
    if ( animation->m_time_driving_animation
      || !animation->m_operands_count
      || (v12 = (*((int (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                 + 3))(animation[1].__vftable),
          is_new_driving_animation = 1,
          !v12) )
    {
      is_new_driving_animation = 0;
    }
    m_time_synchronization_group_id = animation->m_time_synchronization_group_id;
    LOBYTE(v22) = 1;
    if ( m_time_synchronization_group_id != -1 )
    {
      for ( i = this->m_to->m_time_root; i; i = i->m_next_time_animation )
      {
        if ( i->m_time_synchronization_group_id == m_time_synchronization_group_id )
        {
          if ( i != animation )
          {
            LOBYTE(v22) = 0;
            is_new_driving_animation = 0;
          }
          break;
        }
      }
    }
    vostok::animation::mixing::n_ary_tree_comparer::new_animation(
      &v22,
      this,
      animation,
      &is_new_driving_animation,
      &v21,
      (const void *)v22);
    v15 = is_new_driving_animation;
    this->m_needed_buffer_size += 4 * is_new_driving_animation + 4;
    if ( v22 < v15 )
      vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(
        (vostok::animation::mixing::n_ary_tree_comparer *)animation[1].__vftable,
        (int)this);
    this->m_needed_buffer_size += 20;
    v16 = animation->m_operands_count
       && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 3))(animation[1].__vftable);
    v17 = animation->m_operands_count - v16;
    if ( v17 )
    {
      if ( v17 == 1 )
      {
        v20 = (*((int (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
               + 3))(animation[1].__vftable);
        vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(
          *((vostok::animation::mixing::n_ary_tree_comparer **)&animation[1].__vftable + (v20 != 0)),
          (int)this);
      }
      else
      {
        this->m_needed_buffer_size += 4 * v17 + 8;
        v18 = (vostok::animation::mixing::n_ary_tree_comparer **)(&animation[1].__vftable + animation->m_operands_count);
        for ( j = (vostok::animation::mixing::n_ary_tree_comparer **)(&animation[1].__vftable
                                                                    + ((*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                                                                        + 3))(animation[1].__vftable) != 0)); j != v18; ++j )
          vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(*j, (int)this);
      }
    }
    else
    {
      this->m_needed_buffer_size += 12;
    }
    this->m_needed_buffer_size += 12;
  }
  else
  {
    if ( !animation->m_operands_count
      || (v6 = (*((int (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                + 3))(animation[1].__vftable),
          is_new_driving_animation = 1,
          !v6) )
    {
      is_new_driving_animation = 0;
    }
    v7 = animation->m_time_synchronization_group_id;
    v8 = animation->m_operands_count - is_new_driving_animation;
    LOBYTE(v22) = 1;
    if ( v7 != -1 )
    {
      for ( k = this->m_to->m_time_root; k; k = k->m_next_time_animation )
      {
        if ( k->m_time_synchronization_group_id == v7 )
        {
          if ( k != animation )
          {
            is_new_driving_animation = 0;
            LOBYTE(v22) = 0;
          }
          break;
        }
      }
    }
    vostok::animation::mixing::n_ary_tree_comparer::new_animation(
      &v21,
      this,
      animation,
      &is_new_driving_animation,
      &v22,
      (const void *)v22);
    is_new_driving_animation += v8;
    v10 = (vostok::animation::mixing::n_ary_tree_comparer **)(&animation[1].__vftable + v22);
    v11 = (vostok::animation::mixing::n_ary_tree_comparer **)(&animation[1].__vftable + animation->m_operands_count);
    while ( v10 != v11 )
      vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(*v10++, (int)this);
    this->m_needed_buffer_size += 4 * is_new_driving_animation;
  }
}
