void __thiscall survarium::weapon_core_hide_state_base::on_animation_end_impl(
        survarium::weapon_core_hide_state_base *this,
        bool *interrupt_animation_player_tick)
{
  *interrupt_animation_player_tick = 1;
  this->m_is_ready_to_be_deactivated = 1;
}
