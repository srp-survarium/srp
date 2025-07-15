void __usercall vostok::fs_new::init_from_os_struct(
        vostok::fs_new::physical_path_info_data *out_data@<esi>,
        _finddata32i64_t *in_struct@<eax>)
{
  char *m_begin; // ecx

  out_data->file_size = in_struct->size;
  out_data->type = ((in_struct->attrib & 0x10) != 0) + 1;
  out_data->last_time_of_write = in_struct->time_write;
  m_begin = out_data->path.m_string.m_begin;
  if ( m_begin != in_struct->name )
  {
    out_data->path.m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&out_data->path.m_string, in_struct->name);
  }
  out_data->path_type = path_type_contains_name;
}
