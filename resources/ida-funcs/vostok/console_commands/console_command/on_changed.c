void __usercall vostok::console_commands::console_command::on_changed(
        vostok::console_commands::console_command *this@<eax>,
        const char *args@<edx>)
{
  boost::detail::function::vtable_base *vtable; // ecx
  boost::function<void __cdecl(char const *)> *p_m_on_change_event; // eax
  int v4; // ecx

  vtable = this->m_on_change_event.vtable;
  p_m_on_change_event = &this->m_on_change_event;
  v4 = -(vtable != 0);
  if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v4) != 0 )
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      (boost::function1<void,char const *> *)v4,
      p_m_on_change_event,
      args);
}
