survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> *__thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state>::`scalar deleting destructor'(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> *this,
        char a2)
{
  survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state>::~weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
