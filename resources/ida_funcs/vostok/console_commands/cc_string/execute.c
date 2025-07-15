void __thiscall vostok::console_commands::cc_string::execute(
        vostok::console_commands::cc_string *this,
        const char *args)
{
  int v3; // ecx

  strncpy_s(this->m_value, this->m_size, args, this->m_size);
  v3 = -(this->m_on_change_event.vtable != 0);
  if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v3) != 0 )
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      (boost::function1<void,char const *> *)v3,
      &this->m_on_change_event.vtable,
      args);
}
