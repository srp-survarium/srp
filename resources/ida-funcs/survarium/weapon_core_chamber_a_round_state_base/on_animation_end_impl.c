void __thiscall survarium::weapon_core_chamber_a_round_state_base::on_animation_end_impl(
        survarium::weapon_core_chamber_a_round_state_base *this,
        bool *interrupt_animation_player_tick)
{
  survarium::weapon_core::instant_chamber_a_round((survarium::weapon_core *)this, (int *)this->m_weapon);
  *interrupt_animation_player_tick = 1;
}
