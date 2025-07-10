void __thiscall vostok::console_commands::cc_u32::execute(vostok::console_commands::cc_u32 *this, char *args)
{
  const char *v2; // edi
  vostok::console_commands::console_command *v4; // ecx
  int v5; // ecx

  v2 = args;
  if ( sscanf_s(args, "%d", &args) == 1 && (unsigned int)args >= this->m_min && (unsigned int)args <= this->m_max )
  {
    *this->m_value = (unsigned int)args;
  }
  else
  {
    vostok::console_commands::console_command::on_invalid_syntax(v4, (const char **)this, v2);
    args = (char *)this->m_min;
  }
  v5 = -(this->m_on_change_event.vtable != 0);
  if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v5) != 0 )
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      (boost::function1<void,char const *> *)v5,
      &this->m_on_change_event.vtable,
      v2);
}
