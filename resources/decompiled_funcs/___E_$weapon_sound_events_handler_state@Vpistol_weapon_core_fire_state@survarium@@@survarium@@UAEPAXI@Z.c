survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_show_state> *__thiscall survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state>::`vector deleting destructor'(
        survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_show_state> *this,
        char a2)
{
  survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>::~weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
