void __userpurge vostok::animation::mixing::n_ary_tree_time_scale_calculator::remove_transition(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node@<eax>,
        int a2@<ebp>,
        int a3@<edi>,
        vostok::animation::mixing::n_ary_tree_time_scale_calculator *this,
        int a5,
        float a6)
{
  unsigned int m_start_time_in_ms; // ebp
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v9; // edi
  unsigned int m_previous_time_in_ms; // eax
  vostok::animation::mixing::n_ary_tree_base_node *m_to; // ecx
  unsigned int v12; // edx
  double v13; // st7
  float v14; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node *m_from; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // eax
  _DWORD *v17; // ecx
  int v18; // edx
  unsigned int *i; // eax
  float valuea; // [esp+8h] [ebp-10h]
  float animation_time_when_transition_ended; // [esp+1Ch] [ebp+4h]

  if ( this->m_animation )
  {
    m_start_time_in_ms = node->m_start_time_in_ms;
    valuea = ((double (__thiscall *)(const vostok::animation::base_interpolator *, int, int))node->m_interpolator->transition_time)(
               node->m_interpolator,
               a3,
               a2)
           * 1000.0;
    v9 = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)(m_start_time_in_ms + vostok::math::floor(valuea));
    animation_time_when_transition_ended = vostok::animation::mixing::animation_interval::length(&this->m_animation->m_animation_intervals[this->m_animation->m_animation_state->animation_interval_id]);
    m_previous_time_in_ms = this->m_previous_time_in_ms;
    m_to = node->m_to;
    if ( (unsigned int)v9 < m_previous_time_in_ms )
      v12 = 0;
    else
      v12 = (unsigned int)v9 - m_previous_time_in_ms;
    a6 = *(float *)&v12;
    v13 = (double)v12 * this->m_time_scale * 0.001 + (float)this->m_previous_animation_time;
    a6 = v13;
    if ( v13 <= 0.0 )
      v14 = 0.0;
    else
      v14 = a6;
    if ( animation_time_when_transition_ended <= v14 )
      v14 = animation_time_when_transition_ended;
    m_to[4].__vftable = v9;
    *(float *)&m_to[3].__vftable = v14;
    this->m_result = node->m_to;
    m_from = node->m_from;
    a6 = COERCE_FLOAT(&vostok::animation::mixing::n_ary_tree_destroyer::`vftable');
    m_from->accept(m_from, (vostok::animation::mixing::n_ary_tree_visitor *)&a6);
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_time_scale_transition_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
      node,
      0);
    if ( this->m_recursion_level == 1 )
    {
      if ( this->m_time_scale == *(float *)&clear_value )
      {
        m_animation = this->m_animation;
        v17 = &m_animation[1].__vftable;
        v18 = (int)&m_animation[1] + 4 * m_animation->m_operands_count;
        for ( i = &m_animation[1].m_operands_count; i != (unsigned int *)v18; ++v17 )
          *v17 = *i++;
        --this->m_animation->m_operands_count;
      }
      else
      {
        this->m_animation[1].__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)this->m_result;
      }
    }
  }
}
