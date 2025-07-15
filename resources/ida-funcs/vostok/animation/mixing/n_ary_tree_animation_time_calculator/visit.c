void __thiscall vostok::animation::mixing::n_ary_tree_animation_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  vostok::animation::mixing::n_ary_tree_animation_time_calculator::fill_time(
    this,
    this,
    node->m_time_scale,
    node->m_animation_time_before_scale_starts,
    node->m_time_scale_start_time_in_ms);
}


void __thiscall vostok::animation::mixing::n_ary_tree_animation_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  unsigned int v3; // eax
  unsigned int m_target_time_in_ms; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // ecx
  unsigned int m_operands_count; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  float m_animation_interval_length; // xmm0_4
  unsigned int v11; // [esp+10h] [ebp-48h]
  struct vostok::animation::mixing::n_ary_tree_animation_node *v12; // [esp+14h] [ebp-44h]
  int v13; // [esp+1Ch] [ebp-3Ch]
  unsigned int v14; // [esp+20h] [ebp-38h]
  unsigned int v15; // [esp+24h] [ebp-34h]
  float v16; // [esp+2Ch] [ebp-2Ch]
  _BYTE v17[8]; // [esp+30h] [ebp-28h] BYREF
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v18; // [esp+38h] [ebp-20h]
  float v19; // [esp+4Ch] [ebp-Ch]

  v3 = this->m_target_time_in_ms - this->m_start_time_in_ms;
  this->m_animation_time = this->m_start_animation_time;
  v14 = 0;
  v13 = 0;
  v15 = v3 / 0xA;
  do
  {
    if ( v14 >= v15 )
      m_target_time_in_ms = this->m_target_time_in_ms;
    else
      m_target_time_in_ms = this->m_start_time_in_ms + v13 + 10;
    if ( this->m_is_read_only )
      m_animation = 0;
    else
      m_animation = this->m_animation;
    vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
      (vostok::animation::mixing::n_ary_tree_time_scale_calculator *)m_animation,
      (int)v17,
      LODWORD(this->m_animation_time),
      m_target_time_in_ms,
      COERCE_FLOAT(v13 + this->m_start_time_in_ms),
      v11,
      v12);
    m_operands_count = this->m_animation->m_operands_count;
    if ( !node )
      goto LABEL_15;
    node->accept(node, (vostok::animation::mixing::n_ary_tree_visitor *)v17);
    if ( v18 )
      node = v18;
    if ( m_operands_count != this->m_animation->m_operands_count )
      node = 0;
    if ( node )
      v8 = v19;
    else
LABEL_15:
      v8 = s_bm_current_air_resistance;
    if ( v14 >= v15 )
      v9 = this->m_target_time_in_ms;
    else
      v9 = this->m_start_time_in_ms + v13 + 10;
    v16 = vostok::animation::mixing::n_ary_tree_animation_time_calculator::computed_animation_time(
            this,
            v9,
            this->m_animation_time,
            v13 + this->m_start_time_in_ms,
            v13 + this->m_start_time_in_ms,
            v8);
    m_animation_interval_length = 0.0;
    this->m_animation_time = v16;
    if ( v16 > 0.0 )
      m_animation_interval_length = v16;
    if ( this->m_animation_interval_length <= m_animation_interval_length )
      m_animation_interval_length = this->m_animation_interval_length;
    ++v14;
    v13 += 10;
    this->m_animation_time = m_animation_interval_length;
  }
  while ( v14 <= v15 );
}
