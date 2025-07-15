void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_animation(
        unsigned int *target_operands_offset@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *animation,
        unsigned int *time_scale_operands_count,
        unsigned int *source_operands_offset,
        const void *can_be_time_driving_animation)
{
  char v7; // al
  bool v8; // zf
  vostok::animation::mixing::n_ary_tree_comparer *v9; // esi
  vostok::animation::mixing::animated_object_holder *m_animated_objects_end; // esi

  *source_operands_offset = 0;
  *target_operands_offset = 0;
  v7 = 0;
  if ( !(_BYTE)can_be_time_driving_animation || !animation->m_is_time_driving_animation )
  {
    HIBYTE(can_be_time_driving_animation) = 0;
    goto LABEL_7;
  }
  v8 = animation->m_time_synchronization_group_id == -1;
  HIBYTE(can_be_time_driving_animation) = 1;
  if ( v8 )
  {
LABEL_7:
    v9 = this;
    goto LABEL_8;
  }
  v9 = this;
  v7 = vostok::animation::mixing::n_ary_tree_comparer::new_time_scale(animation, this);
  if ( v7 )
  {
    *time_scale_operands_count = 1;
    *target_operands_offset = 1;
  }
LABEL_8:
  if ( animation->m_time_synchronization_group_id != -1
    && (!HIBYTE(can_be_time_driving_animation) || v7)
    && animation->m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(animation[1].__vftable) )
  {
    *source_operands_offset = 1;
  }
  v9->m_needed_buffer_size += 20 * animation->m_animation_intervals_count + 92;
  ++v9->m_animations_count;
  m_animated_objects_end = v9->m_animated_objects_end;
  can_be_time_driving_animation = animation->m_animated_object;
  if ( stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
         this->m_animated_objects,
         &can_be_time_driving_animation,
         m_animated_objects_end) == m_animated_objects_end )
  {
    this->m_animated_objects_end = m_animated_objects_end + 1;
    if ( m_animated_objects_end )
    {
      m_animated_objects_end->animated_object = animation->m_animated_object;
      m_animated_objects_end->animated_object_id = 0;
      m_animated_objects_end->need_new_transform = 0;
    }
  }
}
