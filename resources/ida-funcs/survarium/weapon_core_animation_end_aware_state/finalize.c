void __thiscall survarium::weapon_core_animation_end_aware_state::finalize(
        survarium::weapon_core_animation_end_aware_state *this)
{
  survarium::weapon_core::remove_animation_callback(this->m_weapon, channel_id_on_animation_end, this);
}
