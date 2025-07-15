survarium::player_logic_jump_state *__thiscall survarium::player_logic_jump_state::`vector deleting destructor'(
        survarium::player_logic_jump_state *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  survarium::jump_logic *v4; // ecx

  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_sprint_finalize_callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&this->m_sprint_initialize_callback);
  survarium::jump_logic::~jump_logic(v4, (int)&this->m_logic);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
