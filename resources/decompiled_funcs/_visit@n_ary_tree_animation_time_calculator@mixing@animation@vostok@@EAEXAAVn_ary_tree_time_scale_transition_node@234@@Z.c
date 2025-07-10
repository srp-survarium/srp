void __thiscall vostok::animation::mixing::n_ary_tree_animation_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  unsigned int v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // edi
  unsigned int m_start_time_in_ms; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // ecx
  float m_animation_time; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // eax
  unsigned int m_operands_count; // ebx
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *m_result; // eax
  float time_scale; // xmm0_4
  unsigned int m_target_time_in_ms; // eax
  float m_animation_interval_length; // xmm0_4
  unsigned int full_intervals_count; // [esp+24h] [ebp-38h]
  unsigned int start_interval_time_in_ms; // [esp+2Ch] [ebp-30h]
  float start_interval_time_in_msa; // [esp+2Ch] [ebp-30h]
  vostok::animation::mixing::n_ary_tree_time_scale_calculator time_scale_calculator; // [esp+34h] [ebp-28h] BYREF

  v3 = this->m_target_time_in_ms - this->m_start_time_in_ms;
  this->m_animation_time = this->m_start_animation_time;
  v4 = v3 / 0xA;
  full_intervals_count = v3 / 0xA;
  v5 = 0;
  while ( 1 )
  {
    if ( v5 >= v4 )
      start_interval_time_in_ms = this->m_target_time_in_ms;
    else
      start_interval_time_in_ms = this->m_start_time_in_ms + 10 * v5 + 5;
    if ( v5 >= v4 )
    {
      m_start_time_in_ms = this->m_start_time_in_ms + 10 * v4;
    }
    else if ( v5 )
    {
      m_start_time_in_ms = this->m_start_time_in_ms + 5 * (2 * v5 - 1);
    }
    else
    {
      m_start_time_in_ms = this->m_start_time_in_ms;
    }
    if ( this->m_is_read_only )
      m_animation = 0;
    else
      m_animation = this->m_animation;
    m_animation_time = this->m_animation_time;
    time_scale_calculator.m_animation = m_animation;
    time_scale_calculator.m_current_time_in_ms = start_interval_time_in_ms;
    time_scale_calculator.m_previous_time_in_ms = m_start_time_in_ms;
    v9 = this->m_animation;
    time_scale_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
    time_scale_calculator.m_result = 0;
    time_scale_calculator.m_interpolator = 0;
    time_scale_calculator.m_previous_animation_time = m_animation_time;
    memset(&time_scale_calculator.m_time_scale, 0, 12);
    m_operands_count = v9->m_operands_count;
    if ( !node )
      goto LABEL_20;
    node->accept(node, &time_scale_calculator);
    m_result = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)time_scale_calculator.m_result;
    if ( !time_scale_calculator.m_result )
      m_result = node;
    node = m_result;
    if ( m_operands_count != this->m_animation->m_operands_count )
    {
      node = 0;
LABEL_19:
      v4 = full_intervals_count;
LABEL_20:
      time_scale = *(float *)&clear_value;
      goto LABEL_21;
    }
    if ( !m_result )
      goto LABEL_19;
    time_scale = time_scale_calculator.m_time_scale;
    v4 = full_intervals_count;
LABEL_21:
    if ( v5 >= v4 )
      m_target_time_in_ms = this->m_target_time_in_ms;
    else
      m_target_time_in_ms = this->m_start_time_in_ms + 2 * (5 * v5 + 5);
    start_interval_time_in_msa = vostok::animation::mixing::n_ary_tree_animation_time_calculator::computed_animation_time(
                                   this,
                                   m_target_time_in_ms,
                                   this->m_animation_time,
                                   this->m_start_time_in_ms + 10 * v5,
                                   this->m_start_time_in_ms + 10 * v5,
                                   time_scale);
    m_animation_interval_length = start_interval_time_in_msa;
    this->m_animation_time = start_interval_time_in_msa;
    if ( start_interval_time_in_msa <= 0.0 )
      m_animation_interval_length = 0.0;
    if ( this->m_animation_interval_length <= m_animation_interval_length )
      m_animation_interval_length = this->m_animation_interval_length;
    ++v5;
    this->m_animation_time = m_animation_interval_length;
    if ( v5 > full_intervals_count )
      break;
    v4 = full_intervals_count;
  }
}
