void __thiscall vostok::animation::mixing::n_ary_tree_animation_node::fixup(
        vostok::animation::mixing::n_ary_tree_animation_node *this,
        vostok::resources::managed_resource *offset)
{
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // edx
  vostok::resources::managed_resource *v4; // edi
  vostok::animation::mixing::animation_interval *v5; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // eax
  vostok::animation::mixing::animation_state *m_animation_state; // eax
  vostok::animation::mixing::animation_state *v11; // eax
  const vostok::animation::base_interpolator *m_weight_interpolator; // eax
  const vostok::animation::base_interpolator *v13; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_weight_animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v15; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_time_animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v17; // eax
  vostok::animation::mixing::animation_interval *v18; // ebx
  float *p_m_start_time; // eax
  vostok::animation::mixing::animation_state *v20; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v22; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v23; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v24; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation_node; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v26; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> v27; // [esp+4h] [ebp-18h] BYREF
  float *v28; // [esp+14h] [ebp-8h]
  vostok::animation::mixing::animation_interval *v29; // [esp+18h] [ebp-4h]

  m_animation_intervals = this->m_animation_intervals;
  v4 = offset;
  if ( m_animation_intervals )
    v5 = (vostok::animation::mixing::animation_interval *)((char *)offset + (_DWORD)m_animation_intervals);
  else
    v5 = 0;
  m_time_driving_animation = this->m_time_driving_animation;
  this->m_animation_intervals = v5;
  if ( m_time_driving_animation )
    v7 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)m_time_driving_animation + (_DWORD)offset);
  else
    v7 = 0;
  this->m_time_driving_animation = v7;
  m_weight_driving_animation = this->m_weight_driving_animation;
  if ( m_weight_driving_animation )
    v9 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)m_weight_driving_animation + (_DWORD)offset);
  else
    v9 = 0;
  this->m_weight_driving_animation = v9;
  m_animation_state = this->m_animation_state;
  if ( m_animation_state )
    v11 = (vostok::animation::mixing::animation_state *)((char *)m_animation_state + (_DWORD)offset);
  else
    v11 = 0;
  this->m_animation_state = v11;
  m_weight_interpolator = this->m_weight_interpolator;
  if ( m_weight_interpolator )
    v13 = (const vostok::animation::base_interpolator *)((char *)m_weight_interpolator + (_DWORD)offset);
  else
    v13 = 0;
  this->m_weight_interpolator = v13;
  m_next_weight_animation = this->m_next_weight_animation;
  if ( m_next_weight_animation )
    v15 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)m_next_weight_animation + (_DWORD)offset);
  else
    v15 = 0;
  this->m_next_weight_animation = v15;
  m_next_time_animation = this->m_next_time_animation;
  if ( m_next_time_animation )
    v17 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)m_next_time_animation + (_DWORD)offset);
  else
    v17 = 0;
  v18 = &v5[this->m_animation_intervals_count];
  this->m_next_time_animation = v17;
  v29 = v5;
  if ( v5 != v18 )
  {
    p_m_start_time = &m_animation_intervals->m_start_time;
    v28 = &m_animation_intervals->m_start_time;
    do
    {
      if ( v29 )
      {
        vostok::animation::mixing::animation_interval::animation_interval(
          v29,
          (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_start_time
        - 3,
          *((_DWORD *)p_m_start_time - 1),
          *p_m_start_time,
          p_m_start_time[1]);
        p_m_start_time = v28;
        v4 = offset;
      }
      ++v29;
      p_m_start_time += 5;
      v28 = p_m_start_time;
    }
    while ( v29 != v18 );
  }
  v20 = this->m_animation_state;
  if ( v20 != (vostok::animation::mixing::animation_state *)-80 )
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      &v27,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v20->bone_matrices_computer.pinned_animation,
      0);
  m_animation = v20->event_iterator.m_animation_event_iterator.m_animation;
  if ( m_animation )
    v22 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)m_animation + (_DWORD)v4);
  else
    v22 = 0;
  v20->event_iterator.m_animation_event_iterator.m_animation = v22;
  v23 = v20->event_iterator.m_weight_event_iterator.m_animation;
  if ( v23 )
    v24 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v23 + (_DWORD)v4);
  else
    v24 = 0;
  v20->event_iterator.m_weight_event_iterator.m_animation = v24;
  m_animation_node = v20->event_iterator.m_animation_node;
  if ( m_animation_node )
    v26 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)m_animation_node + (_DWORD)v4);
  else
    v26 = 0;
  v27.m_resource.m_object = v4;
  v20->event_iterator.m_animation_node = v26;
  vostok::animation::mixing::n_ary_tree_n_ary_operation_node::fixup(this, 0x58u, (unsigned int)v27.m_resource.m_object);
}
