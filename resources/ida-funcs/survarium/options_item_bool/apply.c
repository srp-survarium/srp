void __thiscall survarium::options_item_bool::apply(survarium::options_item_bool *this)
{
  bool v2; // zf
  bool m_current_value; // al
  _DWORD v4[3]; // [esp+4h] [ebp-14h] BYREF
  _BYTE v5[8]; // [esp+10h] [ebp-8h] BYREF
  char vars0; // [esp+18h] [ebp+0h] BYREF

  v2 = this->m_console_command == 0;
  m_current_value = this->m_current_value;
  this->m_source_value = m_current_value;
  if ( !v2 )
  {
    v4[0] = v5;
    v4[1] = v5;
    v4[2] = &vars0;
    v5[0] = 0;
    vostok::fs_new::path_string_impl::assignf(
      v4,
      (vostok::buffer_string *)&vars0,
      (vostok::buffer_string *)"%d",
      (const char *)m_current_value);
    this->m_console_command->execute(this->m_console_command, (const char *)v4[0]);
  }
}
