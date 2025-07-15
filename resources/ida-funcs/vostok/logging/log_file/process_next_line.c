char __thiscall vostok::logging::log_file::process_next_line<void (__cdecl *)(char)>(
        vostok::logging::log_file *this,
        unsigned int buffer_size,
        void (__cdecl *const *processor)(char))
{
  int last_pos; // [esp+4h] [ebp-8h]
  char current_char; // [esp+Bh] [ebp-1h]

  if ( this->m_current_pos == this->m_file_size )
    return 0;
  last_pos = vostok::math::min(this->m_file_size, this->m_current_pos + buffer_size - 1);
  for ( current_char = 0; current_char != 10; (*processor)(current_char) )
  {
    if ( (signed int)this->m_current_pos >= last_pos )
      break;
    current_char = vostok::logging::log_file::read_next_char(this);
  }
  (*processor)(0);
  while ( current_char != 10 && this->m_current_pos != this->m_file_size )
    current_char = vostok::logging::log_file::read_next_char(this);
  return 1;
}


char __thiscall vostok::logging::log_file::process_next_line<vostok::logging::processor>(
        vostok::logging::log_file *this,
        unsigned int buffer_size,
        const vostok::logging::processor *processor)
{
  int last_pos; // [esp+4h] [ebp-8h]
  char current_char; // [esp+Bh] [ebp-1h]

  if ( this->m_current_pos == this->m_file_size )
    return 0;
  last_pos = vostok::math::min(this->m_file_size, this->m_current_pos + buffer_size - 1);
  for ( current_char = 0; current_char != 10; *processor->buffer_ptr++ = current_char )
  {
    if ( (signed int)this->m_current_pos >= last_pos )
      break;
    current_char = vostok::logging::log_file::read_next_char(this);
  }
  *processor->buffer_ptr++ = 0;
  while ( current_char != 10 && this->m_current_pos != this->m_file_size )
    current_char = vostok::logging::log_file::read_next_char(this);
  return 1;
}
