char *__thiscall vostok::core::core_debug_engine::bugtrap_application_name(vostok::core::core_debug_engine *this)
{
  void **v1; // eax
  unsigned int v3; // [esp-4h] [ebp-4h]

  if ( (_S3_6 & 1) == 0 )
  {
    _S3_6 |= 1u;
    bugtrap_application_name.m_begin = bugtrap_application_name.m_buffer;
    bugtrap_application_name.m_end = bugtrap_application_name.m_buffer;
    bugtrap_application_name.m_max_end = (char *)&_S3_6;
    bugtrap_application_name.m_buffer[0] = 0;
  }
  if ( !*((_BYTE *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.vostok::size_policy
        + 4) )
  {
    v3 = vostok::build::build_station_build_id();
    v1 = vostok::core::application_name();
    vostok::buffer_string::assignf(&bugtrap_application_name, "%s-#%d", (const char *)v1, v3);
    *((_BYTE *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.vostok::size_policy
    + 4) = 1;
  }
  return bugtrap_application_name.m_begin;
}
