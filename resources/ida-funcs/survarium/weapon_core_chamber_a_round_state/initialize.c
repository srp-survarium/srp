void __thiscall survarium::weapon_core_chamber_a_round_state::initialize(
        survarium::weapon_core_chamber_a_round_state *this)
{
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *v2; // ecx

  survarium::weapon_core_animation_end_aware_state::initialize(this);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_fire_state>::subscribe_sound_events_channel(
    v2,
    &this->gap140 + 1);
}
