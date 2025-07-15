void __usercall vostok::command_line::command_line_key_adder::operator()(
        vostok::command_line::command_line_key_adder *this@<ecx>,
        vostok::command_line::key *const command_line_key@<edi>)
{
  unsigned int v2; // kr00_4
  unsigned int v3; // kr04_4
  vostok::buffer_vector<vostok::command_line::key *> *keys; // esi
  vostok::command_line::key **m_end; // eax
  const char *v6; // [esp+0h] [ebp-10h]
  bool do_debug_break; // [esp+Fh] [ebp-1h] BYREF

  v2 = strlen(command_line_key->m_short_name);
  this->longest_short_key_name -= this->longest_short_key_name < v2 ? this->longest_short_key_name - v2 : 0;
  v3 = strlen(command_line_key->m_full_name);
  keys = this->keys_;
  this->longest_full_key_name -= this->longest_full_key_name < v3 ? this->longest_full_key_name - v3 : 0;
  if ( keys->m_end >= keys->m_max_end
    && !`vostok::buffer_vector<vostok::command_line::key *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::command_line::key *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v6);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  m_end = keys->m_end;
  if ( m_end )
    *m_end = command_line_key;
  ++keys->m_end;
}
