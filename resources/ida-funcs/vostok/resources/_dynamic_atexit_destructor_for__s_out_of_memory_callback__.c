void __thiscall vostok::resources::_dynamic_atexit_destructor_for__s_out_of_memory_callback__(
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> *this)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    this,
    (int *)&s_out_of_memory_callback);
}
