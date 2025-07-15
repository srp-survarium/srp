survarium::breath_state_holding *__thiscall survarium::breath_state_holding::`vector deleting destructor'(
        survarium::breath_state_holding *this,
        char a2)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_callback);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
