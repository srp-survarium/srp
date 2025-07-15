void __thiscall survarium::weapon_core_hide_state::finalize(survarium::weapon_core_hide_state *this)
{
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_hide_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_show_state> *)&this->gap138 + 1);
  survarium::weapon_core_animation_end_aware_state::finalize(this);
}
