char __thiscall helper::predicate(
        helper *this,
        unsigned int call_stack_id,
        unsigned int num_call_stack_lines,
        const char *module_name,
        const char *file_name,
        int line_number,
        const char *function,
        unsigned int address)
{
  char _Dest[4096]; // [esp+4h] [ebp-1008h] BYREF
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+1008h] [ebp-4h]

  if ( call_stack_id < this->m_num_first_to_ignore )
    return 1;
  if ( call_stack_id >= num_call_stack_lines - this->m_num_last_to_ignore )
    return 1;
  if ( line_number > 0 )
    JUMPOUT(0x60000);
  sprintf_s<4096>((char (*)[4096])_Dest, s_call_stack_line_format, module_name, function, address);
  log_callback = vostok::debug::get_log_callback();
  if ( log_callback )
    log_callback(this->m_initiator, this->m_use_error_verbosity, 1, _Dest);
  return 1;
}
