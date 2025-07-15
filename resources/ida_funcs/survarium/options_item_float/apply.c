void __thiscall survarium::options_item_float::apply(survarium::options_item_float *this)
{
  bool v2; // zf
  float m_current_value; // xmm0_4
  vostok::fixed_string<8> args; // [esp+Ch] [ebp-14h] BYREF
  _UNKNOWN *retaddr; // [esp+20h] [ebp+0h] BYREF

  v2 = this->m_console_command == 0;
  m_current_value = this->m_current_value;
  this->m_source_value = m_current_value;
  if ( !v2 )
  {
    args.m_begin = args.m_buffer;
    args.m_end = args.m_buffer;
    args.m_max_end = (char *)&retaddr;
    args.m_buffer[0] = 0;
    vostok::buffer_string::assignf(&args, "%.2f", m_current_value);
    this->m_console_command->execute(this->m_console_command, args.m_begin);
  }
}
