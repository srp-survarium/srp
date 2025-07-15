bool __thiscall vostok::fs_new::path_part_iterator::operator==(
        vostok::fs_new::path_part_iterator *this,
        const vostok::fs_new::path_part_iterator *it)
{
  return this->m_include_empty_string_in_iteration == it->m_include_empty_string_in_iteration
      && this->m_cur_str == it->m_cur_str;
}


void __thiscall vostok::fs_new::path_part_iterator::operator++(vostok::fs_new::path_part_iterator *this)
{
  if ( this->m_cur_str )
  {
    if ( this->m_include_empty_string_in_iteration == include_empty_string_in_iteration_true )
    {
      this->m_include_empty_string_in_iteration = include_empty_string_in_iteration_false;
    }
    else if ( this->m_cur_end == this->m_path_end )
    {
      this->m_cur_str = 0;
    }
    else
    {
      if ( this->m_cur_end != this->m_path_str )
      {
        this->m_cur_str = this->m_cur_end + 1;
        this->m_cur_end = this->m_cur_str;
      }
      while ( this->m_cur_end != this->m_path_end && *this->m_cur_end != this->m_separator )
        ++this->m_cur_end;
    }
  }
}
