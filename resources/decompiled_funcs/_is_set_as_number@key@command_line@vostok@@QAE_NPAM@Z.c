char __userpurge vostok::command_line::key::is_set_as_number@<al>(
        vostok::command_line::key *this@<ecx>,
        unsigned int a2@<ebx>,
        float *out_value)
{
  vostok::command_line::key::type_enum m_type; // eax
  unsigned int v5; // eax
  char *m_begin; // [esp-4h] [ebp-Ch]

  if ( this->m_type == type_unset )
  {
    this->m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  m_type = this->m_type;
  if ( m_type == type_recursive )
    return 0;
  if ( !debug_macro_helper_ignore_always_7 && m_type != type_not_scanned )
  {
    v5 = occurances_left_7;
    if ( occurances_left_7 == -1 )
      v5 = 10;
    occurances_left_7 = v5 - 1;
    if ( v5 )
    {
      m_begin = this->m_string_value.m_begin;
      LOBYTE(out_value) = 0;
      vostok::debug::on_error(
        a2,
        (bool *)&out_value,
        process_error_false,
        &debug_macro_helper_ignore_always_7,
        assert_untyped,
        "assertion_failed",
        "m_type == type_number",
        ".\\command_line.cpp",
        "vostok::command_line::key::is_set_as_number",
        0x85u,
        "given value is not convertible to number: %s",
        m_begin);
      if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
        __debugbreak();
    }
    return 0;
  }
  if ( out_value )
    *out_value = this->m_number_value;
  return 1;
}
