void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  float m_time_scale; // xmm0_4
  float m_target_animation_time; // xmm1_4
  unsigned int m_start_time_in_ms; // ebx
  unsigned int m_time_scale_start_time_in_ms; // edi
  unsigned int v7; // eax

  m_time_scale = node->m_time_scale;
  if ( m_time_scale == 0.0 )
  {
    this->m_time_in_ms = -1;
  }
  else
  {
    m_target_animation_time = this->m_target_animation_time;
    m_start_time_in_ms = this->m_start_time_in_ms;
    m_time_scale_start_time_in_ms = node->m_time_scale_start_time_in_ms;
    if ( m_time_scale_start_time_in_ms <= m_start_time_in_ms )
      v7 = m_start_time_in_ms
         + vostok::math::floor((float)((float)(m_target_animation_time - this->m_start_animation_time) / m_time_scale) * 1000.0);
    else
      v7 = m_time_scale_start_time_in_ms
         + vostok::math::floor(
             (float)((float)(m_target_animation_time - node->m_animation_time_before_scale_starts) / m_time_scale)
           * 1000.0);
    this->m_time_in_ms = v7;
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  int m_start_animation_time_low; // xmm0_4
  unsigned int m_start_time_in_ms; // ebx
  unsigned int v5; // esi
  vostok::animation::mixing::n_ary_tree_time_scale_calculator *v6; // eax
  char v7; // al
  int v8; // ebx
  float v9; // esi
  vostok::animation::mixing::n_ary_tree_time_scale_calculator *i; // eax
  float v11; // xmm2_4
  char v12; // al
  char v13; // al
  float m_target_animation_time; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  unsigned int v17; // [esp+4h] [ebp-70h]
  unsigned int v18; // [esp+4h] [ebp-70h]
  unsigned int v19; // [esp+4h] [ebp-70h]
  struct vostok::animation::mixing::n_ary_tree_animation_node *v20; // [esp+8h] [ebp-6Ch]
  struct vostok::animation::mixing::n_ary_tree_animation_node *v21; // [esp+8h] [ebp-6Ch]
  struct vostok::animation::mixing::n_ary_tree_animation_node *v22; // [esp+8h] [ebp-6Ch]
  char v23; // [esp+17h] [ebp-5Dh]
  float m_start_animation_time; // [esp+18h] [ebp-5Ch]
  unsigned int v25; // [esp+1Ch] [ebp-58h]
  float v26; // [esp+20h] [ebp-54h]
  _BYTE v27[28]; // [esp+24h] [ebp-50h] BYREF
  float v28; // [esp+40h] [ebp-34h]
  _BYTE v29[28]; // [esp+4Ch] [ebp-28h] BYREF
  float v30; // [esp+68h] [ebp-Ch]

  m_start_animation_time_low = SLODWORD(this->m_start_animation_time);
  if ( *(float *)&m_start_animation_time_low == this->m_target_animation_time )
  {
    this->m_time_in_ms = this->m_start_time_in_ms;
  }
  else
  {
    m_start_time_in_ms = node->m_start_time_in_ms;
    m_start_animation_time = this->m_start_animation_time;
    v25 = m_start_time_in_ms;
    v5 = (this->m_start_time_in_ms - m_start_time_in_ms) / 0xA;
    v6 = (vostok::animation::mixing::n_ary_tree_time_scale_calculator *)vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
                                                                          0,
                                                                          (int)v27,
                                                                          m_start_animation_time_low,
                                                                          this->m_start_time_in_ms,
                                                                          COERCE_FLOAT(
                                                                            m_start_time_in_ms
                                                                          + ((10 * (v5 != 0 ? 2 * v5 - 1 : 0)) >> 1)),
                                                                          v17,
                                                                          v20);
    vostok::animation::mixing::n_ary_tree_time_scale_calculator::visit(v6, m_start_time_in_ms, node);
    if ( v28 <= 0.0 )
    {
      if ( v28 >= 0.0 )
        v7 = 0;
      else
        v7 = -1;
    }
    else
    {
      v7 = 1;
    }
    v8 = v5;
    LODWORD(v9) = v25 + 10 * v5;
    v26 = (float)v7;
    for ( i = (vostok::animation::mixing::n_ary_tree_time_scale_calculator *)vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
                                                                               0,
                                                                               (int)v29,
                                                                               m_start_animation_time_low,
                                                                               LODWORD(v9) + 10,
                                                                               v9,
                                                                               v18,
                                                                               v21);
          ;
          i = (vostok::animation::mixing::n_ary_tree_time_scale_calculator *)vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
                                                                               0,
                                                                               (int)v29,
                                                                               COERCE_INT(v16 + v15),
                                                                               LODWORD(v9) + 10,
                                                                               v9,
                                                                               v19,
                                                                               v22) )
    {
      vostok::animation::mixing::n_ary_tree_time_scale_calculator::visit(i, v8, node);
      v11 = v26;
      if ( v26 == 0.0 )
      {
        if ( v30 != 0.0 )
        {
          if ( v30 <= 0.0 )
          {
            if ( v30 >= 0.0 )
              v12 = 0;
            else
              v12 = -1;
          }
          else
          {
            v12 = 1;
          }
          v11 = (float)v12;
          v26 = v11;
        }
        if ( v11 == 0.0 )
          goto LABEL_24;
      }
      if ( v30 <= 0.0 )
        v13 = v30 >= 0.0 ? 0 : -1;
      else
        v13 = 1;
      v23 = 1;
      if ( (float)((float)v13 * v11) > 0.0 )
LABEL_24:
        v23 = 0;
      m_target_animation_time = this->m_target_animation_time;
      v15 = m_start_animation_time;
      v16 = v30 * 0.0099999998;
      if ( m_target_animation_time > m_start_animation_time
        && (float)(v16 + m_start_animation_time) >= m_target_animation_time )
      {
        break;
      }
      if ( m_start_animation_time > m_target_animation_time
        && m_target_animation_time >= (float)(v16 + m_start_animation_time) )
      {
        break;
      }
      if ( v23 )
      {
        this->m_event_time = (float)(v16 * 0.5) + m_start_animation_time;
        this->m_time_in_ms = v25 + ((unsigned int)(20 * v8 + 10) >> 1);
        this->m_event_type = 64;
        return;
      }
      ++v8;
      m_start_animation_time = v16 + m_start_animation_time;
      LODWORD(v9) += 10;
    }
    this->m_time_in_ms = v25
                       + vostok::math::floor((float)((float)(this->m_target_animation_time - m_start_animation_time)
                                                   / v16) * 10.0)
                       + 10 * v8;
    if ( v23 )
      this->m_event_type |= 0x40u;
  }
}
