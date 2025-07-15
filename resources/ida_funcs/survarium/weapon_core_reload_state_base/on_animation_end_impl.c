void __thiscall survarium::weapon_core_reload_state_base::on_animation_end_impl(
        survarium::weapon_core_reload_state_base *this,
        bool *animation_player_tick_result)
{
  survarium::weapon_core::instant_reload(this->m_weapon);
  *animation_player_tick_result = 1;
}
