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
  char _Dest[16384]; // [esp+4h] [ebp-4000h] BYREF

  if ( call_stack_id >= this->m_num_first_to_ignore && call_stack_id < num_call_stack_lines - this->m_num_last_to_ignore )
  {
    if ( line_number <= 0 )
      sprintf_s<16384>((char (*)[16384])_Dest, "%-60s       : %-70s : 0x%08x", module_name, function, address);
    else
      sprintf_s<16384>(
        (char (*)[16384])_Dest,
        "%-60s(%-3d) : %-70s : %-36s : 0x%08x",
        file_name,
        line_number,
        function,
        module_name,
        address);
    if ( (s_log_disable_counter == 0 ? (unsigned int)s_log_callback : 0) != 0 )
      ((void (__cdecl *)(helper *, bool, int, char *))(s_log_disable_counter == 0 ? (unsigned int)s_log_callback : 0))(
        this,
        this->m_use_error_verbosity,
        1,
        _Dest);
  }
  return 1;
}
