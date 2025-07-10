void __thiscall vostok::fs_new::path_part_iterator::path_part_iterator(
        vostok::fs_new::path_part_iterator *this,
        const char *path_str,
        int len,
        char separator,
        vostok::fs_new::include_empty_string_in_iteration_bool include_empty_string_in_iteration)
{
  this->m_include_empty_string_in_iteration = include_empty_string_in_iteration;
  this->m_separator = separator;
  this->m_path_str = path_str;
  this->m_path_end = &path_str[len];
  this->m_cur_str = path_str;
  this->m_cur_end = path_str;
  vostok::fs_new::path_part_iterator::operator++(this);
}
