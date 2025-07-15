vostok::animation::mixing::n_ary_tree_animation_time_calculator *__userpurge vostok::animation::mixing::n_ary_tree_animation_time_calculator::n_ary_tree_animation_time_calculator@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this@<ecx>,
        unsigned int a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *a3@<edi>,
        float a4@<xmm0>,
        struct vostok::animation::mixing::n_ary_tree_animation_node *start_time_in_ms,
        unsigned int a6,
        float a7,
        unsigned int a8,
        bool a9)
{
  vostok::animation::mixing::n_ary_tree_animation_time_calculator *m_animation_intervals; // ecx
  double v11; // st7

  this->m_target_time_in_ms = a2;
  this->__vftable = (vostok::animation::mixing::n_ary_tree_animation_time_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_animation_time_calculator::`vftable';
  this->m_animation = a3;
  this->m_start_time_in_ms = (const unsigned int)start_time_in_ms;
  this->m_start_animation_time = a4;
  m_animation_intervals = (vostok::animation::mixing::n_ary_tree_animation_time_calculator *)a3->m_animation_intervals;
  v11 = *((float *)&m_animation_intervals->m_target_time_in_ms + 5 * a3->m_animation_state->animation_interval_id);
  this->m_is_read_only = 0;
  this->m_animation_interval_length = v11;
  if ( a3->m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))a3[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(a3[1].__vftable) )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_animation_time_calculator *))a3[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      a3[1].__vftable,
      this);
  }
  else
  {
    vostok::animation::mixing::n_ary_tree_animation_time_calculator::fill_time(
      m_animation_intervals,
      this,
      1.0,
      this->m_start_animation_time,
      (unsigned int)start_time_in_ms);
  }
  return this;
}
