void __thiscall survarium::_dynamic_atexit_destructor_for__force_hash_mismatch_cc__(
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> *this)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    this,
    (int *)&force_hash_mismatch_cc.m_functor);
  vostok::console_commands::console_command::~console_command(&force_hash_mismatch_cc);
}
