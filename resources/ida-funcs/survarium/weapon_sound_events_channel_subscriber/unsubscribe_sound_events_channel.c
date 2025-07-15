void __thiscall survarium::weapon_sound_events_channel_subscriber<survarium::pistol_weapon_core_fire_state>::unsubscribe_sound_events_channel(
        survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *this)
{
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *v1; // eax

  if ( this )
    v1 = this - 321;
  else
    v1 = 0;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    *(_DWORD *)(*(_DWORD *)&v1[288] + 8),
    "sound_events",
    this);
}


void __thiscall survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_hide_state>::unsubscribe_sound_events_channel(
        survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_show_state> *this)
{
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_show_state> *v1; // eax

  if ( this )
    v1 = this - 313;
  else
    v1 = 0;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    *(_DWORD *)(*(_DWORD *)&v1[288] + 8),
    "sound_events",
    this);
}


void __thiscall survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_one_round_substate>::unsubscribe_sound_events_channel(
        survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *this)
{
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *v1; // eax

  if ( this )
    v1 = this - 344;
  else
    v1 = 0;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    *(_DWORD *)(*(_DWORD *)&v1[288] + 8),
    "sound_events",
    this);
}
