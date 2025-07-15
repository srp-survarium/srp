void __userpurge vostok::animation::mixing::n_ary_tree::update_synchronization_group_using_integration(
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node@<eax>,
        float a2@<xmm4>,
        vostok::animation::mixing::n_ary_tree *this,
        unsigned int start_time_in_ms,
        const unsigned int target_time_in_ms)
{
  vostok::animation::mixing::animation_state *m_animation_state; // edi
  unsigned int v7; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v8; // ecx
  vostok::animation::mixing::n_ary_tree *v9; // edi
  unsigned int v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int m_operands_count; // edi
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  bool v15; // zf
  float v16; // xmm0_4
  double v17; // st7
  unsigned int v18; // edi
  unsigned int v19; // eax
  float m_time_scale; // xmm0_4
  double v21; // st7
  float v22; // xmm0_4
  bool v23; // cf
  unsigned int v24; // ebx
  unsigned int m_time_synchronization_group_id; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *i; // edi
  vostok::animation::mixing::animation_state *v27; // eax
  float current_time_in_ms; // [esp+10h] [ebp-68h]
  float current_time_in_msa; // [esp+10h] [ebp-68h]
  float v30; // [esp+14h] [ebp-64h]
  bool is_time_scale_node; // [esp+2Bh] [ebp-4Dh]
  vostok::animation::mixing::n_ary_tree *accumulated_animation_time; // [esp+2Ch] [ebp-4Ch]
  float accumulated_animation_timea; // [esp+2Ch] [ebp-4Ch]
  vostok::animation::mixing::n_ary_tree_base_node *time_scale_node; // [esp+30h] [ebp-48h]
  float animation_interval_length; // [esp+34h] [ebp-44h]
  vostok::animation::mixing::animation_state *animation_state; // [esp+44h] [ebp-34h]
  unsigned int time_synchronization_group_id; // [esp+48h] [ebp-30h]
  vostok::animation::mixing::n_ary_tree_time_scale_calculator time_scale_calculator; // [esp+4Ch] [ebp-2Ch] BYREF

  m_animation_state = animation_node->m_animation_state;
  v7 = 0;
  animation_state = m_animation_state;
  if ( animation_node->m_operands_count )
  {
    v8 = animation_node[1].__vftable;
    time_scale_node = (vostok::animation::mixing::n_ary_tree_base_node *)v8;
    if ( v8 )
    {
      is_time_scale_node = 1;
      if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v8->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
            + 3))(v8) )
        goto LABEL_5;
    }
  }
  else
  {
    time_scale_node = 0;
  }
  is_time_scale_node = 0;
LABEL_5:
  accumulated_animation_time = (vostok::animation::mixing::n_ary_tree *)LODWORD(m_animation_state->animation_interval_time);
  animation_interval_length = vostok::animation::mixing::animation_interval::length(&animation_node->m_animation_intervals[m_animation_state->animation_interval_id]);
  v9 = this;
  v10 = (start_time_in_ms - (unsigned int)this) / 0xA;
  while ( 1 )
  {
    if ( v7 >= v10 )
    {
      v11 = (unsigned int)v9 + 10 * v10;
    }
    else if ( v7 )
    {
      v11 = (unsigned int)v9 + 8 * v7 + 2 * v7 - 5;
    }
    else
    {
      v11 = (unsigned int)v9;
    }
    if ( v7 >= v10 )
      v12 = start_time_in_ms;
    else
      v12 = (unsigned int)&v9->m_weight_root + 10 * v7 + 1;
    LODWORD(time_scale_calculator.m_previous_animation_time) = accumulated_animation_time;
    time_scale_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
    time_scale_calculator.m_animation = animation_node;
    time_scale_calculator.m_result = 0;
    time_scale_calculator.m_interpolator = 0;
    time_scale_calculator.m_current_time_in_ms = v12;
    time_scale_calculator.m_previous_time_in_ms = v11;
    memset(&time_scale_calculator.m_time_scale, 0, 12);
    if ( is_time_scale_node )
    {
      m_operands_count = animation_node->m_operands_count;
      time_scale_node->accept(time_scale_node, &time_scale_calculator);
      m_result = time_scale_calculator.m_result;
      if ( !time_scale_calculator.m_result )
        m_result = time_scale_node;
      v15 = m_operands_count == animation_node->m_operands_count;
      v9 = this;
      time_scale_node = m_result;
      if ( !v15 )
      {
        time_scale_node = 0;
        is_time_scale_node = 0;
      }
    }
    if ( v7 >= v10 )
    {
      if ( is_time_scale_node )
        m_time_scale = time_scale_calculator.m_time_scale;
      else
        m_time_scale = *(float *)&clear_value;
      v19 = start_time_in_ms;
      v17 = m_time_scale;
      v18 = (unsigned int)v9 + 10 * v7;
    }
    else
    {
      if ( is_time_scale_node )
        v16 = time_scale_calculator.m_time_scale;
      else
        v16 = *(float *)&clear_value;
      v17 = v16;
      v18 = (unsigned int)v9 + 10 * v7;
      v19 = v18 + 10;
    }
    current_time_in_ms = v17;
    v21 = vostok::animation::mixing::n_ary_tree::computed_animation_time(
            animation_node,
            v19,
            accumulated_animation_time,
            *(const float *)&v18,
            v18,
            current_time_in_ms,
            v30);
    if ( v21 <= 0.0 )
    {
      v22 = 0.0;
    }
    else
    {
      accumulated_animation_timea = v21;
      v22 = accumulated_animation_timea;
    }
    if ( animation_interval_length <= v22 )
      v22 = animation_interval_length;
    v23 = v7 < v10;
    accumulated_animation_time = (vostok::animation::mixing::n_ary_tree *)LODWORD(v22);
    v24 = v18 + 10;
    if ( !v23 )
      v24 = start_time_in_ms;
    if ( animation_state->are_there_any_weight_transitions )
      vostok::animation::mixing::n_ary_tree::accumulate_object_movement(
        animation_node,
        v24,
        a2,
        (vostok::animation::mixing::n_ary_tree *)LODWORD(v22),
        v30);
    m_time_synchronization_group_id = animation_node->m_time_synchronization_group_id;
    time_synchronization_group_id = m_time_synchronization_group_id;
    if ( m_time_synchronization_group_id != -1 )
    {
      for ( i = animation_node->m_next_time_animation; i; i = i->m_next_time_animation )
      {
        if ( i->m_time_synchronization_group_id != m_time_synchronization_group_id )
          break;
        v27 = i->m_animation_state;
        if ( v27->are_there_any_weight_transitions )
        {
          current_time_in_msa = vostok::animation::mixing::animation_interval::length(&i->m_animation_intervals[v27->animation_interval_id])
                              / animation_interval_length
                              * v22;
          vostok::animation::mixing::n_ary_tree::accumulate_object_movement(
            i,
            v24,
            a2,
            (vostok::animation::mixing::n_ary_tree *)LODWORD(current_time_in_msa),
            v30);
          m_time_synchronization_group_id = time_synchronization_group_id;
        }
      }
    }
    if ( ++v7 > (start_time_in_ms - (unsigned int)this) / 0xA )
      break;
    v10 = (start_time_in_ms - (unsigned int)this) / 0xA;
    v9 = this;
  }
}
