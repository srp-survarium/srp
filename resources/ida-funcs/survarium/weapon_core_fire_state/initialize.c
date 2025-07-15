void __thiscall survarium::weapon_core_fire_state::initialize(survarium::weapon_core_fire_state *this)
{
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *v2; // ecx

  survarium::weapon_core_fire_state_base::initialize(this);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_fire_state>::subscribe_sound_events_channel(
    v2,
    &this->gap140 + 1);
}
