vostok::console_commands::cc_delegate *__thiscall vostok::console_commands::cc_delegate::`scalar deleting destructor'(
        vostok::console_commands::cc_delegate *this,
        char a2)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_functor);
  vostok::console_commands::console_command::~console_command(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
