void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_animation(
        unsigned int *operands_offset@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *a2@<ecx>,
        vostok::animation::mixing::n_ary_tree_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *animation,
        unsigned int *time_scale_operands_count)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // ebp
  bool v6; // zf
  unsigned int m_animation_intervals_count; // eax
  vostok::animation::mixing::animated_object_holder *m_animated_objects_end; // esi
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // ecx

  v5 = animation;
  v6 = animation->m_time_driving_animation == 0;
  *operands_offset = 0;
  if ( v6
    && v5->m_time_synchronization_group_id != -1
    && vostok::animation::mixing::n_ary_tree_comparer::new_time_scale(a2, this, v5) )
  {
    *time_scale_operands_count = 1;
    *operands_offset = 1;
  }
  m_animation_intervals_count = v5->m_animation_intervals_count;
  ++this->m_animations_count;
  m_animated_objects_end = this->m_animated_objects_end;
  this->m_needed_buffer_size += 12 * m_animation_intervals_count + 92;
  m_animated_objects = this->m_animated_objects;
  animation = (vostok::animation::mixing::n_ary_tree_animation_node *)v5->m_animated_object;
  if ( stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
         m_animated_objects,
         m_animated_objects_end,
         (const void *const *)&animation) == m_animated_objects_end )
  {
    this->m_animated_objects_end = m_animated_objects_end + 1;
    if ( m_animated_objects_end )
    {
      m_animated_objects_end->animated_object = v5->m_animated_object;
      m_animated_objects_end->need_new_transform = 0;
    }
  }
}
