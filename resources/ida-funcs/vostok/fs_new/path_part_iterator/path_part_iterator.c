void __userpurge vostok::fs_new::path_part_iterator::path_part_iterator(
        vostok::fs_new::path_part_iterator *this@<esi>,
        char *path_str@<ecx>,
        vostok::fs_new::include_empty_string_in_iteration_bool include_empty_string_in_iteration@<eax>,
        char separator)
{
  unsigned int v4; // eax

  this->m_include_empty_string_in_iteration = include_empty_string_in_iteration;
  this->m_separator = separator;
  this->m_path_str = path_str;
  if ( path_str )
    v4 = strlen(path_str);
  else
    v4 = 0;
  this->m_path_end = &path_str[v4];
  this->m_cur_str = path_str;
  this->m_cur_end = path_str;
  vostok::fs_new::path_part_iterator::operator++((vostok::fs_new::path_part_iterator *)path_str, (int)this);
}
