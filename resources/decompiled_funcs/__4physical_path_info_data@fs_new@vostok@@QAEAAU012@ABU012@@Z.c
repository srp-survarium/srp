vostok::fs_new::physical_path_info_data *__thiscall vostok::fs_new::physical_path_info_data::operator=(
        vostok::fs_new::physical_path_info_data *this,
        const vostok::fs_new::physical_path_info_data *__that)
{
  vostok::fs_new::native_path_string *p_path; // [esp+Ch] [ebp-14h]

  this->file_size = __that->file_size;
  this->last_time_of_write = __that->last_time_of_write;
  this->type = __that->type;
  p_path = &this->path;
  if ( &this->path != &__that->path )
    vostok::buffer_string::operator=((vostok::fixed_string<32> *)&__that->path, (vostok::fixed_string<32> *)p_path);
  vostok::fs_new::path_string_impl::verify_self(p_path);
  this->path_type = __that->path_type;
  return this;
}
