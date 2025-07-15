vostok::animation::mixing::n_ary_tree_animation_time_calculator *__userpurge vostok::animation::mixing::n_ary_tree_animation_time_calculator::n_ary_tree_animation_time_calculator@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this@<ecx>,
        unsigned int a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *a3@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *a4@<esi>,
        float a5@<xmm0>,
        struct vostok::animation::mixing::n_ary_tree_animation_node *start_time_in_ms,
        unsigned int a7,
        float a8,
        unsigned int a9,
        bool a10)
{
  float m_animation_interval_length; // xmm0_4
  float start_time_in_msa; // [esp+18h] [ebp+4h]

  a4->__vftable = (vostok::animation::mixing::n_ary_tree_animation_time_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_animation_time_calculator::`vftable';
  a4->m_animation = a3;
  a4->m_start_time_in_ms = (const unsigned int)start_time_in_ms;
  a4->m_start_animation_time = a5;
  a4->m_target_time_in_ms = a2;
  a4->m_animation_interval_length = vostok::animation::mixing::animation_interval::length(&a3->m_animation_intervals[a3->m_animation_state->animation_interval_id]);
  a4->m_is_read_only = 0;
  if ( a3->m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))a3[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(a3[1].__vftable) )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_animation_time_calculator *))a3[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      a3[1].__vftable,
      a4);
    return a4;
  }
  else
  {
    start_time_in_msa = vostok::animation::mixing::n_ary_tree_animation_time_calculator::computed_animation_time(
                          a4,
                          a4->m_target_time_in_ms,
                          a4->m_start_animation_time,
                          (unsigned int)start_time_in_ms,
                          a4->m_start_time_in_ms,
                          1.0);
    m_animation_interval_length = start_time_in_msa;
    a4->m_animation_time = start_time_in_msa;
    if ( start_time_in_msa <= 0.0 )
      m_animation_interval_length = 0.0;
    if ( a4->m_animation_interval_length <= m_animation_interval_length )
      m_animation_interval_length = a4->m_animation_interval_length;
    a4->m_animation_time = m_animation_interval_length;
    return a4;
  }
}
