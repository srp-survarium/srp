bool __cdecl vostok::build::print_build_id_command_line()
{
  unsigned int is_set; // eax
  bool result; // al

  is_set = s_out_result_1;
  if ( s_out_result_1 != -1 )
    return is_set != 0;
  if ( !s_command_line_initialized )
  {
    is_set = vostok::command_line::key_is_set((const char *)&s_spin_count.m_end);
    s_out_result_1 = (unsigned __int8)is_set;
    return is_set != 0;
  }
  if ( s_print_build_id.m_type == type_unset )
  {
    s_print_build_id.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  result = s_print_build_id.m_type != type_recursive;
  s_out_result_1 = s_print_build_id.m_type != type_recursive;
  return result;
}
