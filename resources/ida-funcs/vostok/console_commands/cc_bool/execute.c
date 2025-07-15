void __thiscall vostok::console_commands::cc_bool::execute(vostok::console_commands::cc_bool *this, const char *args)
{
  vostok::console_commands::console_command *v3; // ecx
  char v4; // al
  boost::function1<void,char const *> *m_value; // ecx

  if ( !strcmp(args, (const char *)stru_95AF78.m_key_bindings[4].m_keyboard)
    || !strcmp(args, (const char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1])
    || !strcmp(args, (const char *)stru_95AF78.m_key_bindings[5].m_keyboard) )
  {
    v4 = 1;
  }
  else
  {
    if ( !vostok::strings::equal(args, (const char *)&stru_95AF78.m_key_bindings[5].m_keyboard[1])
      && !vostok::strings::equal(args, (const char *)&stru_95AF78.m_key_bindings[6])
      && !vostok::strings::equal(args, (const char *)&stru_95AF78.m_key_bindings[6].m_keyboard[1]) )
    {
      vostok::console_commands::console_command::on_invalid_syntax(v3, (const char **)this, args);
      return;
    }
    v4 = 0;
  }
  m_value = (boost::function1<void,char const *> *)this->m_value;
  LOBYTE(m_value->vtable) = v4;
  if ( (this->m_on_change_event.vtable != 0 ? (unsigned int)survarium::weapon_user_dead_state::finalize : 0) != 0 )
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      m_value,
      &this->m_on_change_event.vtable,
      args);
}
