void __thiscall survarium::jump_logic::initialize_weight_for_on_site_move_animation(survarium::jump_logic *this)
{
  survarium::jump_type_enum m_jump_type; // edx
  survarium::base_player *m_user; // eax
  float m_linear_horizontal_speed; // xmm1_4
  float v4; // xmm2_4
  float *p_jump_from_site_speed; // eax
  float v6; // xmm0_4
  float *v7; // eax
  float v8; // [esp+0h] [ebp-Ch] BYREF
  float v9; // [esp+4h] [ebp-8h] BYREF
  float jump_from_site_speed; // [esp+8h] [ebp-4h] BYREF

  m_jump_type = this->m_jump_type;
  if ( m_jump_type == jump_type_on_site )
  {
    this->m_move_animation_weight = 0.0;
  }
  else
  {
    m_user = this->m_user;
    m_linear_horizontal_speed = m_user->m_linear_horizontal_speed;
    v4 = m_user->m_speed_parameters.m_landing_speed.m_begin[m_jump_type - 7];
    jump_from_site_speed = m_user->m_jump_params.jump_from_site_speed;
    v9 = m_linear_horizontal_speed;
    p_jump_from_site_speed = &jump_from_site_speed;
    if ( jump_from_site_speed <= m_linear_horizontal_speed )
      p_jump_from_site_speed = &v9;
    v6 = *p_jump_from_site_speed / v4;
    v8 = FLOAT_0_99000001;
    v9 = v6;
    v7 = &v8;
    if ( v6 <= 0.99000001 )
      v7 = &v9;
    this->m_move_animation_weight = *v7;
  }
}
