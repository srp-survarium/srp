void __thiscall survarium::options_item_float::apply(survarium::options_item_float *this)
{
  bool v2; // zf
  float m_current_value; // xmm0_4
  _DWORD v4[3]; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v5[8]; // [esp+18h] [ebp-8h] BYREF
  char vars0; // [esp+20h] [ebp+0h] BYREF

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
      (vostok::buffer_string *)this,
      (vostok::buffer_string *)"%.2f",
      (const char *)COERCE_UNSIGNED_INT64(m_current_value),
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(m_current_value)));
    this->m_console_command->execute(this->m_console_command, (const char *)v4[0]);
  }
}
