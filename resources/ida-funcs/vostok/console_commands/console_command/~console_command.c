void __thiscall vostok::console_commands::console_command::~console_command(
        vostok::console_commands::console_command *this)
{
  this->__vftable = (vostok::console_commands::console_command_vtbl *)&vostok::console_commands::console_command::`vftable';
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_on_change_event);
}
