void __thiscall vostok::console_commands::cc_token::execute(vostok::console_commands::cc_token *this, const char *args)
{
  unsigned int id; // eax
  vostok::console_commands::console_command *v4; // ecx
  boost::function1<void,char const *> *m_value; // ecx

  id = vostok::console_commands::cc_token::find_id(this, (int)this, args);
  if ( id == -1 )
  {
    vostok::console_commands::console_command::on_invalid_syntax(v4, (const char **)this, args);
  }
  else
  {
    m_value = (boost::function1<void,char const *> *)this->m_value;
    m_value->vtable = (boost::detail::function::vtable_base *)id;
  }
  if ( (this->m_on_change_event.vtable != 0 ? (unsigned int)survarium::weapon_user_dead_state::finalize : 0) != 0 )
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      m_value,
      &this->m_on_change_event.vtable,
      args);
}
