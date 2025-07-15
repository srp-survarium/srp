void __thiscall survarium::double_barreled_weapon_core_reload_state::initialize(
        survarium::weapon_core_reload_state *this)
{
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *v2; // ecx

  survarium::weapon_core_reload_state_base::initialize(this);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_fire_state>::subscribe_sound_events_channel(
    v2,
    &this->gap140 + 1);
}
