void __thiscall survarium::weapon_core_fire_state_base::on_animation_end_impl(
        survarium::weapon_core_fire_state_base *this,
        bool *interrupt_animation_player_tick)
{
  bool v2; // al

  v2 = !this->m_keep_shooting;
  *interrupt_animation_player_tick = v2;
  this->m_animation_has_been_ended = v2;
}
