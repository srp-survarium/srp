void __cdecl vostok::fs_new::init_from_os_struct(
        vostok::fs_new::physical_path_info_data *out_data,
        _finddata32i64_t *in_struct)
{
  out_data->file_size = in_struct->size;
  out_data->type = ((in_struct->attrib & 0x10) != 0) + 1;
  out_data->last_time_of_write = in_struct->time_write;
  vostok::fs_new::native_path_string::operator=<char [260]>(
    (vostok::fs_new::native_path_string *)in_struct->name,
    &out_data->path.m_string);
  out_data->path_type = path_type_contains_name;
}
