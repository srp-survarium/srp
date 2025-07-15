void __thiscall survarium::game::register_console_commands_::_2_::_dynamic_atexit_destructor_for__game_exit_cc__(
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> *this)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    this,
    (int *)&game_exit_cc.m_functor);
  vostok::console_commands::console_command::~console_command(&game_exit_cc);
}
