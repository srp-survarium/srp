void __thiscall vostok::console_commands::cc_float::execute(vostok::console_commands::cc_float *this, float args)
{
  const char *v2; // edi
  vostok::console_commands::console_command *v4; // ecx
  boost::function1<void,char const *> *m_value; // ecx

  v2 = (const char *)LODWORD(args);
  if ( sscanf_s((char *)LODWORD(args), (const char *)&stru_95AF78.m_key_bindings[63].m_keyboard[1], &args) == 1
    && this->m_min <= args
    && args <= this->m_max )
  {
    m_value = (boost::function1<void,char const *> *)this->m_value;
    *(float *)&m_value->vtable = args;
  }
  else
  {
    vostok::console_commands::console_command::on_invalid_syntax(v4, (const char **)this, v2);
    args = this->m_min;
  }
  if ( (this->m_on_change_event.vtable != 0 ? (unsigned int)survarium::weapon_user_dead_state::finalize : 0) != 0 )
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      m_value,
      &this->m_on_change_event.vtable,
      v2);
}
