survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate> *__thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate>::`vector deleting destructor'(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate> *this,
        char a2)
{
  survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate>::~weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
