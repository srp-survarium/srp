void __thiscall survarium::weapon_core_show_state::initialize(survarium::weapon_core_show_state *this)
{
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_show_state> *v2; // ecx

  survarium::weapon_core_animation_end_aware_state::initialize(this);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_hide_state>::subscribe_sound_events_channel(
    v2,
    &this->gap138 + 1);
}
