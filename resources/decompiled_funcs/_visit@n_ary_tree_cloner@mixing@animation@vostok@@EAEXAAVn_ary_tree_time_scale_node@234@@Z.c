void __userpurge vostok::animation::mixing::n_ary_tree_cloner::visit(
        vostok::animation::mixing::n_ary_tree_cloner *this@<ecx>,
        bool a2@<bl>,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  char *m_data; // esi
  vostok::animation::mixing::n_ary_tree_cloner *m_animation_interval_time; // ecx
  unsigned int m_start_time_in_ms; // ebx
  float m_animation_time_before_scale_starts; // xmm0_4
  const vostok::animation::base_interpolator *v8; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *m_constructor; // edx
  vostok::mutable_buffer *m_buffer; // eax
  float m_time_scale; // [esp+8h] [ebp-4h]

  m_data = this->m_constructor->m_buffer->m_data;
  if ( m_data )
  {
    m_animation_interval_time = (vostok::animation::mixing::n_ary_tree_cloner *)this->m_animation_interval_time;
    if ( m_animation_interval_time )
      m_start_time_in_ms = this->m_start_time_in_ms;
    else
      m_start_time_in_ms = node->m_time_scale_start_time_in_ms;
    if ( m_animation_interval_time )
      m_animation_time_before_scale_starts = *(float *)&m_animation_interval_time->__vftable;
    else
      m_animation_time_before_scale_starts = node->m_animation_time_before_scale_starts;
    m_time_scale = node->m_time_scale;
    v8 = vostok::animation::mixing::n_ary_tree_cloner::clone(
           m_animation_interval_time,
           (int)this,
           node->m_interpolator,
           a2);
    *((float *)m_data + 2) = this->m_time_scale_factor * m_time_scale;
    *((_DWORD *)m_data + 4) = m_start_time_in_ms;
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
    *((_DWORD *)m_data + 1) = v8;
    *((float *)m_data + 3) = m_animation_time_before_scale_starts;
  }
  else
  {
    m_data = 0;
  }
  m_constructor = this->m_constructor;
  this->m_result = (vostok::animation::mixing::n_ary_tree_base_node *)m_data;
  m_buffer = m_constructor->m_buffer;
  m_buffer->m_data += 20;
  m_buffer->m_size -= 20;
}
