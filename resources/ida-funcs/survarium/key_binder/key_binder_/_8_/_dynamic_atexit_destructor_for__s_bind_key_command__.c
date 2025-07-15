void __thiscall survarium::key_binder::key_binder_::_8_::_dynamic_atexit_destructor_for__s_bind_key_command__(
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> *this)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    this,
    (int *)&s_bind_key_command.m_functor);
  vostok::console_commands::console_command::~console_command(&s_bind_key_command);
}
