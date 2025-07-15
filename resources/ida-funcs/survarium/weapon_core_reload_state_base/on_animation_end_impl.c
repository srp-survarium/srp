void __thiscall survarium::weapon_core_reload_state_base::on_animation_end_impl(
        survarium::weapon_core_reload_state_base *this,
        bool *interrupt_animation_player_tick)
{
  survarium::weapon_core *m_weapon; // esi
  survarium::weapon_core *v3; // ecx

  m_weapon = this->m_weapon;
  survarium::weapon_core::load_magazine((survarium::weapon_core *)this, m_weapon);
  m_weapon->on_reload(m_weapon);
  m_weapon->m_recoil_calculator.m_weapon_calculator.m_time_to_start_side_compensation = -1;
  m_weapon->m_recoil_calculator.m_weapon_calculator.m_time_to_start_back_compensation = -1;
  m_weapon->m_recoil_calculator.m_weapon_calculator.m_time_of_last_shoot = -1;
  m_weapon->m_recoil_calculator.m_weapon_calculator.m_vertical_target = 0.0;
  m_weapon->m_recoil_calculator.m_weapon_calculator.m_horizontal_target = 0.0;
  m_weapon->m_recoil_calculator.m_weapon_calculator.m_back_target = 0.0;
  m_weapon->m_recoil_calculator.m_weapon_calculator.m_vertical_value_at_last_shoot = 0.0;
  m_weapon->m_recoil_calculator.m_weapon_calculator.m_horizontal_value_at_last_shoot = 0.0;
  m_weapon->m_recoil_calculator.m_weapon_calculator.m_player_recoil_multiplier = s_bm_current_air_resistance;
  survarium::weapon_core::reset_fire_queue(v3, (int)m_weapon);
  m_weapon->m_need_to_auto_reload = 0;
  *interrupt_animation_player_tick = 1;
}
