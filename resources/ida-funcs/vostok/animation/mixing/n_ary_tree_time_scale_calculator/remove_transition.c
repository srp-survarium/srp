void __usercall vostok::animation::mixing::n_ary_tree_time_scale_calculator::remove_transition(
        vostok::animation::mixing::n_ary_tree_time_scale_calculator *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node@<eax>)
{
  unsigned int m_current_time_in_ms; // ebx
  unsigned int v5; // eax
  int v6; // ecx
  unsigned int m_previous_time_in_ms; // edx
  vostok::animation::mixing::n_ary_tree_base_node *m_to; // eax
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v9; // ecx
  float v10; // xmm0_4
  float m_length; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node *m_from; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // ecx
  unsigned int *v14; // eax
  int v15; // edx
  unsigned int *i; // ecx
  float v17; // [esp+0h] [ebp-18h]
  unsigned int m_start_time_in_ms; // [esp+10h] [ebp-8h]
  float v19; // [esp+10h] [ebp-8h]
  void **v20; // [esp+14h] [ebp-4h] BYREF

  if ( this->m_animation )
  {
    m_start_time_in_ms = node->m_start_time_in_ms;
    m_current_time_in_ms = this->m_current_time_in_ms;
    v17 = ((double (__thiscall *)(const vostok::animation::base_interpolator *))node->m_interpolator->transition_time)(node->m_interpolator)
        * 1000.0;
    v5 = vostok::math::floor(v17);
    v6 = m_start_time_in_ms + v5 < m_current_time_in_ms ? m_start_time_in_ms + v5 - m_current_time_in_ms : 0;
    m_previous_time_in_ms = this->m_previous_time_in_ms;
    m_to = node->m_to;
    v9 = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)(m_current_time_in_ms + v6);
    if ( (unsigned int)v9 < m_previous_time_in_ms )
    {
      v10 = 0.0;
    }
    else
    {
      v19 = (float)((unsigned int)v9 - m_previous_time_in_ms);
      v10 = v19;
    }
    m_length = (float)((float)(v10 * 0.001) * this->m_time_scale) + (float)this->m_previous_animation_time;
    if ( m_length <= 0.0 )
      m_length = 0.0;
    if ( this->m_animation->m_animation_intervals[this->m_animation->m_animation_state->animation_interval_id].m_length <= m_length )
      m_length = this->m_animation->m_animation_intervals[this->m_animation->m_animation_state->animation_interval_id].m_length;
    m_to[4].__vftable = v9;
    *(float *)&m_to[3].__vftable = m_length;
    this->m_result = node->m_to;
    m_from = node->m_from;
    v20 = &vostok::animation::mixing::n_ary_tree_destroyer::`vftable';
    m_from->accept(m_from, (vostok::animation::mixing::n_ary_tree_visitor *)&v20);
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_time_scale_transition_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
      node,
      0);
    if ( this->m_recursion_level == 1 )
    {
      if ( this->m_time_scale == s_bm_current_air_resistance )
      {
        m_animation = this->m_animation;
        v14 = (unsigned int *)&m_animation[1];
        v15 = (int)&m_animation[1] + 4 * m_animation->m_operands_count;
        for ( i = &m_animation[1].m_operands_count; i != (unsigned int *)v15; ++i )
          *v14++ = *i;
        this->m_result->accept(this->m_result, (vostok::animation::mixing::n_ary_tree_visitor *)&v20);
        --this->m_animation->m_operands_count;
      }
      else
      {
        this->m_animation[1].__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)this->m_result;
      }
    }
  }
}
