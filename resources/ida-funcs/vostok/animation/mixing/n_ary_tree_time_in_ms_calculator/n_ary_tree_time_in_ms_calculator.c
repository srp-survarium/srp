void __userpurge vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::n_ary_tree_time_in_ms_calculator(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this@<esi>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<eax>,
        unsigned __int16 event_type@<cx>,
        unsigned int start_time_in_ms,
        float start_animation_time,
        float target_animation_time)
{
  float v6; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v7; // edi
  unsigned int m_time_in_ms; // eax
  unsigned int v9; // eax

  v6 = target_animation_time;
  this->m_event_type = event_type;
  this->__vftable = (vostok::animation::mixing::n_ary_tree_time_in_ms_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::`vftable';
  this->m_target_animation_time = target_animation_time;
  this->m_start_animation_time = start_animation_time;
  this->m_event_time = target_animation_time;
  this->m_start_time_in_ms = start_time_in_ms;
  if ( animation->m_operands_count )
    v7 = animation[1].__vftable;
  else
    v7 = 0;
  if ( !v7 )
    goto LABEL_9;
  if ( !(*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v7->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
         + 3))(v7) )
  {
    v6 = target_animation_time;
LABEL_9:
    v9 = this->m_start_time_in_ms + vostok::math::floor((float)(v6 - start_animation_time) * 1000.0);
    goto LABEL_10;
  }
  (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *))v7->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
   + 2))(
    v7,
    this);
  m_time_in_ms = this->m_time_in_ms;
  if ( m_time_in_ms == -1 )
    return;
  v9 = m_time_in_ms - (m_time_in_ms < this->m_start_time_in_ms ? m_time_in_ms - this->m_start_time_in_ms : 0);
LABEL_10:
  this->m_time_in_ms = v9;
}
