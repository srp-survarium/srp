bool __thiscall error_helper::predicate(
        error_helper *this,
        unsigned int call_stack_id,
        unsigned int num_call_stack_lines,
        const char *module_name,
        const char *file_name,
        int line_number,
        const char *function,
        unsigned int address)
{
  int v9; // eax

  if ( call_stack_id < this->m_ignore_level_count )
    return 1;
  if ( line_number <= 0 )
    v9 = sprintf_s(
           this->m_buffer,
           this->m_buffer_size - (this->m_buffer - this->m_start_buffer),
           `error_helper::predicate'::`2'::s_call_stack_line_format_local,
           module_name,
           function,
           address);
  else
    v9 = sprintf_s(
           this->m_buffer,
           this->m_buffer_size - (this->m_buffer - this->m_start_buffer),
           `error_helper::predicate'::`2'::s_full_call_stack_line_format_local,
           file_name,
           line_number,
           function,
           module_name,
           address);
  this->m_buffer += v9;
  this->m_buffer += sprintf_s(this->m_buffer, this->m_buffer_size - (this->m_buffer - this->m_start_buffer), "\r\n");
  return this->m_buffer_size - (this->m_buffer - this->m_start_buffer) >= 0x180;
}
