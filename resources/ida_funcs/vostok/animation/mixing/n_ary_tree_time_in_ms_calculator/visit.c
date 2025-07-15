void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  __debugbreak();
  JUMPOUT(0x5677F1);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  __debugbreak();
  JUMPOUT(0x567821);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  __debugbreak();
  JUMPOUT(0x5677D1);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  __debugbreak();
  JUMPOUT(0x5677E1);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  float m_time_scale; // xmm0_4
  float m_target_animation_time; // xmm1_4
  unsigned int m_start_time_in_ms; // ebx
  unsigned int m_time_scale_start_time_in_ms; // edi

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
      this->m_time_in_ms = m_start_time_in_ms
                         + vostok::math::floor(
                             (float)((float)(m_target_animation_time - this->m_start_animation_time) / m_time_scale)
                           * 1000.0);
    else
      this->m_time_in_ms = m_time_scale_start_time_in_ms
                         + vostok::math::floor(
                             (float)((float)(m_target_animation_time - node->m_animation_time_before_scale_starts)
                                   / m_time_scale)
                           * 1000.0);
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  float m_start_animation_time; // xmm0_4
  unsigned int m_start_time_in_ms; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edi
  int v6; // eax
  char v7; // al
  int v8; // eax
  float v9; // xmm1_4
  char v10; // al
  char v11; // al
  float m_target_animation_time; // xmm1_4
  float v13; // xmm0_4
  signed int v14; // esi
  bool has_time_direction_changed; // [esp+3h] [ebp-61h]
  float accumulated_animation_time; // [esp+4h] [ebp-60h]
  float current_time_direction; // [esp+8h] [ebp-5Ch]
  float current_time_directiona; // [esp+8h] [ebp-5Ch]
  unsigned int v20; // [esp+10h] [ebp-54h]
  vostok::animation::mixing::n_ary_tree_time_scale_calculator time_scale_calculator; // [esp+14h] [ebp-50h] BYREF
  vostok::animation::mixing::n_ary_tree_time_scale_calculator v22; // [esp+3Ch] [ebp-28h] BYREF

  m_start_animation_time = this->m_start_animation_time;
  if ( m_start_animation_time == this->m_target_animation_time )
  {
    this->m_time_in_ms = this->m_start_time_in_ms;
  }
  else
  {
    m_start_time_in_ms = node->m_start_time_in_ms;
    v4 = this->m_start_time_in_ms;
    v5 = (v4 - m_start_time_in_ms) / 0xA;
    accumulated_animation_time = m_start_animation_time;
    v20 = m_start_time_in_ms;
    if ( v5 )
      v6 = 2 * v5 - 1;
    else
      v6 = 0;
    time_scale_calculator.m_current_time_in_ms = v4;
    time_scale_calculator.m_previous_animation_time = m_start_animation_time;
    time_scale_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
    memset((void *)&time_scale_calculator.m_animation, 0, 12);
    time_scale_calculator.m_previous_time_in_ms = m_start_time_in_ms + ((unsigned int)(10 * v6) >> 1);
    memset(&time_scale_calculator.m_time_scale, 0, 12);
    vostok::animation::mixing::n_ary_tree_time_scale_calculator::visit(&time_scale_calculator, node);
    if ( time_scale_calculator.m_time_scale <= 0.0 )
    {
      if ( time_scale_calculator.m_time_scale >= 0.0 )
        v7 = 0;
      else
        v7 = -1;
    }
    else
    {
      v7 = 1;
    }
    current_time_direction = (float)v7;
    while ( 1 )
    {
      if ( v5 )
        v8 = 2 * v5 - 1;
      else
        v8 = 0;
      v22.__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
      memset((void *)&v22.m_animation, 0, 12);
      v22.m_current_time_in_ms = m_start_time_in_ms + ((20 * v5 + 10) >> 1);
      v22.m_previous_animation_time = m_start_animation_time;
      v22.m_previous_time_in_ms = m_start_time_in_ms + ((unsigned int)(10 * v8) >> 1);
      memset(&v22.m_time_scale, 0, 12);
      vostok::animation::mixing::n_ary_tree_time_scale_calculator::visit(&v22, node);
      v9 = current_time_direction;
      if ( current_time_direction == 0.0 )
      {
        if ( v22.m_time_scale != 0.0 )
        {
          if ( v22.m_time_scale <= 0.0 )
          {
            if ( v22.m_time_scale >= 0.0 )
              v10 = 0;
            else
              v10 = -1;
          }
          else
          {
            v10 = 1;
          }
          v9 = (float)v10;
          current_time_direction = v9;
        }
        if ( v9 == 0.0 )
          goto LABEL_30;
      }
      if ( v22.m_time_scale <= 0.0 )
        v11 = v22.m_time_scale >= 0.0 ? 0 : -1;
      else
        v11 = 1;
      has_time_direction_changed = 1;
      if ( (float)((float)v11 * v9) > 0.0 )
LABEL_30:
        has_time_direction_changed = 0;
      m_target_animation_time = this->m_target_animation_time;
      v13 = v22.m_time_scale * 0.0099999998;
      if ( m_target_animation_time > accumulated_animation_time
        && (float)(v13 + accumulated_animation_time) >= m_target_animation_time )
      {
        break;
      }
      if ( accumulated_animation_time > m_target_animation_time
        && m_target_animation_time >= (float)(v13 + accumulated_animation_time) )
      {
        break;
      }
      if ( has_time_direction_changed )
      {
        this->m_event_time = (float)(v13 * 0.5) + accumulated_animation_time;
        this->m_time_in_ms = m_start_time_in_ms + ((20 * v5 + 10) >> 1);
        this->m_event_type = 64;
        return;
      }
      m_start_animation_time = v13 + accumulated_animation_time;
      accumulated_animation_time = m_start_animation_time;
      ++v5;
    }
    current_time_directiona = (float)((float)(this->m_target_animation_time - accumulated_animation_time) / v13) * 10.0;
    v14 = ~(~(LODWORD(current_time_directiona) - 1) & 0x80000000) & LODWORD(current_time_directiona);
    this->m_time_in_ms = v20
                       + ((v14 >> 31)
                        ^ ((158 - (unsigned __int8)(v14 >> 23) - 96 + 64) >> 31)
                        & (((v14 | 0xFF800000) << 8 >> (-98 - (v14 >> 23)))
                         - ((v14 >> 31) & ((v14 & (((1 << (-98 - (v14 >> 23) - 96)) - 1) >> 8)) == 0))))
                       + ((20 * v5 + 10) >> 1);
    if ( has_time_direction_changed )
      this->m_event_type |= 0x40u;
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  __debugbreak();
  JUMPOUT(0x567801);
}


void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  __debugbreak();
  JUMPOUT(0x567811);
}
