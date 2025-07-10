vostok::fs_new::path_part_iterator *__cdecl vostok::fs_new::path_part_iterator::end(
        vostok::fs_new::path_part_iterator *result)
{
  result->m_include_empty_string_in_iteration = include_empty_string_in_iteration_false;
  result->m_separator = 0;
  result->m_path_str = 0;
  result->m_path_end = 0;
  result->m_cur_str = 0;
  result->m_cur_end = 0;
  vostok::fs_new::path_part_iterator::operator++(result);
  return result;
}
