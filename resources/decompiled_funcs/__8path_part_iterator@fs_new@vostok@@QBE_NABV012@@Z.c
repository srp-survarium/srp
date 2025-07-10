bool __thiscall vostok::fs_new::path_part_iterator::operator==(
        vostok::fs_new::path_part_iterator *this,
        const vostok::fs_new::path_part_iterator *it)
{
  return this->m_include_empty_string_in_iteration == it->m_include_empty_string_in_iteration
      && this->m_cur_str == it->m_cur_str;
}
