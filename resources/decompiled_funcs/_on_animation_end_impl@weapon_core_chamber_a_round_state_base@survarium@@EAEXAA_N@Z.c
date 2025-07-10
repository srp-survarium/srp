void __thiscall survarium::weapon_core_chamber_a_round_state_base::on_animation_end_impl(
        survarium::weapon_core_chamber_a_round_state_base *this,
        bool *animation_player_tick_result)
{
  survarium::weapon_core::instant_chamber_a_round(this->m_weapon);
  *animation_player_tick_result = 1;
}
