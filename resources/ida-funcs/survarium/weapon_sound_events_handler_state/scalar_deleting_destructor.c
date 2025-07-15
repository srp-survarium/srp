survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state> *__thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state>::`scalar deleting destructor'(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state> *this,
        char a2)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // ebx
  survarium::weapon_sound_effect::sounds *v4; // ecx
  survarium::weapon_core_chamber_a_round_state *v5; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::weapon_sound_effect::sounds::~sounds(
    (survarium::weapon_sound_effect::sounds *)this,
    (int)&this->m_sound_effect.m_third_view_sounds);
  survarium::weapon_sound_effect::sounds::~sounds(v4, (int)p_m_sound_effect);
  survarium::weapon_core_chamber_a_round_state::~weapon_core_chamber_a_round_state(v5, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> *__thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state>::`scalar deleting destructor'(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> *this,
        char a2)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // ebx
  survarium::weapon_sound_effect::sounds *v4; // ecx
  survarium::weapon_core_show_state *v5; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::weapon_sound_effect::sounds::~sounds(
    (survarium::weapon_sound_effect::sounds *)this,
    (int)&this->m_sound_effect.m_third_view_sounds);
  survarium::weapon_sound_effect::sounds::~sounds(v4, (int)p_m_sound_effect);
  survarium::weapon_core_show_state::~weapon_core_show_state(v5, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> *__thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>::`scalar deleting destructor'(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> *this,
        char a2)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // ebx
  survarium::weapon_sound_effect::sounds *v4; // ecx
  survarium::weapon_core_reload_state *v5; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::weapon_sound_effect::sounds::~sounds(
    (survarium::weapon_sound_effect::sounds *)this,
    (int)&this->m_sound_effect.m_third_view_sounds);
  survarium::weapon_sound_effect::sounds::~sounds(v4, (int)p_m_sound_effect);
  survarium::weapon_core_reload_state::~weapon_core_reload_state(v5, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
