survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> *__thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state>::`scalar deleting destructor'(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> *this,
        char a2)
{
  survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state>::~weapon_sound_events_handler_state<survarium::weapon_core_hide_state>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
