void __userpurge survarium::weapon_recoil_calculator::fire(
        survarium::weapon_recoil_calculator *this@<ecx>,
        survarium::weapon_recoil_calculator *a2@<eax>,
        unsigned int time_in_ms)
{
  float m_vertical_target; // xmm4_4
  float v5; // xmm0_4
  survarium::weapon_recoil_calculator *v6; // ecx
  survarium::weapon_recoil_params *p_m_recoil_params; // esi
  float v8; // xmm0_4
  double v9; // st7
  survarium::weapon_recoil_params *v10; // eax
  float back_recoil_max_limit; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  double v15; // st7
  unsigned __int64 v16; // rax
  float v17; // [esp+0h] [ebp-1Ch]
  float v18; // [esp+0h] [ebp-1Ch]
  float m_horizontal_value_at_last_shoot; // [esp+8h] [ebp-14h]
  float v20; // [esp+14h] [ebp-8h]
  float m_horizontal_target; // [esp+18h] [ebp-4h]
  float v22; // [esp+18h] [ebp-4h]
  float v23; // [esp+18h] [ebp-4h]

  m_vertical_target = a2->m_vertical_target;
  LODWORD(v5) = survarium::weapon_recoil_calculator::get_side_value_impl(
                  a2,
                  time_in_ms,
                  m_vertical_target,
                  a2->m_vertical_value_at_last_shoot).m128_u32[0];
  m_horizontal_target = a2->m_horizontal_target;
  m_horizontal_value_at_last_shoot = a2->m_horizontal_value_at_last_shoot;
  a2->m_vertical_value_at_last_shoot = v5;
  LODWORD(a2->m_horizontal_value_at_last_shoot) = survarium::weapon_recoil_calculator::get_side_value_impl(
                                                    v6,
                                                    time_in_ms,
                                                    m_horizontal_target,
                                                    m_horizontal_value_at_last_shoot).m128_u32[0];
  LODWORD(v20) = survarium::weapon_recoil_calculator::get_back_value(a2, time_in_ms).m128_u32[0];
  if ( m_vertical_target == 0.0 && m_horizontal_target == 0.0 )
    p_m_recoil_params = &a2->m_weapon->m_recoil_params;
  else
    p_m_recoil_params = (survarium::weapon_recoil_params *)&a2->m_weapon->m_recoil_params.queue_shoot;
  v22 = vostok::math::random32::random_f(
          &a2->m_random,
          p_m_recoil_params->first_shoot.min_right_recoil,
          p_m_recoil_params->first_shoot.max_right_recoil);
  v17 = (v22
       - vostok::math::random32::random_f(
           &a2->m_random,
           p_m_recoil_params->first_shoot.min_left_recoil,
           p_m_recoil_params->first_shoot.max_left_recoil))
      * a2->m_player_recoil_multiplier;
  v8 = survarium::player_params_modifiers_container::apply_modifier(
         (survarium::player_params_modifiers_container *)(*(_DWORD *)((char *)&loc_11066
                                                                    + (unsigned int)a2->m_weapon->m_user
                                                                    + 2)
                                                        + 448),
         recoil_modifier,
         0.0,
         v17,
         1.0)
     + a2->m_horizontal_value_at_last_shoot;
  a2->m_horizontal_target = v8;
  v18 = vostok::math::random32::random_f(
          &a2->m_random,
          p_m_recoil_params->first_shoot.min_top_recoil,
          p_m_recoil_params->first_shoot.max_top_recoil)
      * a2->m_player_recoil_multiplier;
  a2->m_vertical_target = survarium::player_params_modifiers_container::apply_modifier(
                            (survarium::player_params_modifiers_container *)(*(_DWORD *)((char *)&loc_11066
                                                                                       + (unsigned int)a2->m_weapon->m_user
                                                                                       + 2)
                                                                           + 448),
                            recoil_modifier,
                            v8,
                            v18,
                            1.0)
                        + a2->m_vertical_value_at_last_shoot;
  v9 = vostok::math::random32::random_f(
         &a2->m_random,
         p_m_recoil_params->first_shoot.min_back_recoil,
         p_m_recoil_params->first_shoot.max_back_recoil);
  v10 = &a2->m_weapon->m_recoil_params;
  v23 = v9 + v20;
  a2->m_back_target = v23;
  back_recoil_max_limit = v10->back_recoil_max_limit;
  if ( back_recoil_max_limit > v23 )
    back_recoil_max_limit = v9 + v20;
  a2->m_back_target = back_recoil_max_limit;
  v12 = a2->m_horizontal_target;
  v13 = FLOAT_N0_5;
  if ( v12 > -0.5 )
  {
    if ( v12 > 0.5 )
      v12 = c_anim_center;
  }
  else
  {
    v12 = FLOAT_N0_5;
  }
  a2->m_horizontal_target = v12;
  v14 = a2->m_vertical_target;
  if ( v14 > -0.5 )
  {
    if ( v14 > 0.5 )
      v13 = c_anim_center;
    else
      v13 = a2->m_vertical_target;
  }
  a2->m_vertical_target = v13;
  v15 = a2->m_back_target - v20;
  a2->m_time_to_start_side_compensation = time_in_ms + v10->side_compensation_delay;
  v16 = (unsigned __int64)(v15 / v10->back_increase_speed * -1000.0);
  a2->m_time_of_last_shoot = time_in_ms;
  a2->m_time_to_start_back_compensation = time_in_ms - v16;
}
