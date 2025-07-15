void __thiscall survarium::pistol_weapon_core_fire_state::finalize(survarium::weapon_core_fire_state *this)
{
  survarium::weapon_sound_events_channel_subscriber<survarium::pistol_weapon_core_fire_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *)&this->gap140 + 1);
  survarium::weapon_core_fire_state_base::finalize(this);
}
