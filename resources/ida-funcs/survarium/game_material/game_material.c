void __thiscall survarium::game_material::game_material(survarium::game_material *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  vostok::fixed_string<64>::fixed_string<64>(&this->m_name, &result.m_buffer[40]);
  this->m_material_resistance = 50.0;
  LODWORD(this->m_bullet_reflection_speed_down) = clear_value;
  this->m_width = FLOAT_0_1;
  this->m_ricochet_koef = s_aim_transition_time;
  this->m_id = -1;
  this->m_mine_can_place = 0;
  this->m_mine_can_stick = 0;
}
