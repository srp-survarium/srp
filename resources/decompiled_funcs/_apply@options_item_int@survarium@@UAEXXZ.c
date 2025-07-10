void __thiscall survarium::options_item_int::apply(survarium::options_item_int *this)
{
  bool v2; // zf
  unsigned __int8 m_current_value; // al
  vostok::fixed_string<8> args; // [esp+4h] [ebp-14h] BYREF
  _UNKNOWN *retaddr; // [esp+18h] [ebp+0h] BYREF

  v2 = this->m_console_command == 0;
  m_current_value = this->m_current_value;
  this->m_source_value = m_current_value;
  if ( !v2 )
  {
    args.m_end = args.m_buffer;
    args.m_begin = args.m_buffer;
    args.m_max_end = (char *)&retaddr;
    args.m_buffer[0] = 0;
    vostok::buffer_string::assignf(&args, "%d", m_current_value);
    this->m_console_command->execute(this->m_console_command, args.m_begin);
  }
}
