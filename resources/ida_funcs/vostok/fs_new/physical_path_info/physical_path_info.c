void __thiscall vostok::fs_new::physical_path_info::physical_path_info(
        vostok::fs_new::physical_path_info *this,
        const vostok::fs_new::physical_path_initializer *initializer)
{
  this->device = initializer->device;
  vostok::fs_new::physical_path_info_data::physical_path_info_data(&this->data, &initializer->data);
  this->parent = initializer->parent;
}


void __thiscall vostok::fs_new::physical_path_info::physical_path_info(vostok::fs_new::physical_path_info *this)
{
  vostok::fs_new::physical_path_info_data *p_data; // [esp+4h] [ebp-10h]

  this->device = 0;
  p_data = &this->data;
  this->data.file_size = -1;
  this->data.last_time_of_write = -1;
  this->data.type = type_error_no_path;
  vostok::fs_new::native_path_string::native_path_string(&this->data.path);
  p_data->path_type = path_type_unitialized;
  this->parent = 0;
}
