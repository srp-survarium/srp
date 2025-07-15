char *__thiscall vostok::core::core_debug_engine::bugtrap_application_name(vostok::core::core_debug_engine *this)
{
  char *v1; // eax

  if ( (_S5_3 & 1) == 0 )
  {
    _S5_3 |= 1u;
    bugtrap_application_name.m_begin = bugtrap_application_name.m_buffer;
    bugtrap_application_name.m_end = bugtrap_application_name.m_buffer;
    bugtrap_application_name.m_max_end = (char *)&_S5_3;
    bugtrap_application_name.m_buffer[0] = 0;
  }
  if ( !initialized_1 )
  {
    v1 = (char *)vostok::core::application_name();
    if ( bugtrap_application_name.m_begin != v1 )
    {
      bugtrap_application_name.m_end = bugtrap_application_name.m_begin;
      *bugtrap_application_name.m_begin = 0;
      vostok::buffer_string::operator+=(&bugtrap_application_name, v1);
    }
    initialized_1 = 1;
  }
  return bugtrap_application_name.m_begin;
}
