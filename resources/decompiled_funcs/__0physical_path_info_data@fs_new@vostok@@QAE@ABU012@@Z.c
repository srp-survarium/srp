void __thiscall vostok::fs_new::physical_path_info_data::physical_path_info_data(
        vostok::fs_new::physical_path_info_data *this,
        const vostok::fs_new::physical_path_info_data *__that)
{
  this->file_size = __that->file_size;
  this->last_time_of_write = __that->last_time_of_write;
  this->type = __that->type;
  vostok::fs_new::native_path_string::native_path_string(&this->path, &__that->path);
  this->path_type = __that->path_type;
}
