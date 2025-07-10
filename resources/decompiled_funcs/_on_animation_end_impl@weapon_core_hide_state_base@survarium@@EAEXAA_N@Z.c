void __thiscall survarium::weapon_core_hide_state_base::on_animation_end_impl(
        survarium::weapon_core_hide_state_base *this,
        bool *animation_player_tick_result)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  *this->m_is_shown = 0;
  *animation_player_tick_result = 1;
}
