void __thiscall vostok::fs_new::physical_path_info::physical_path_info(
        vostok::fs_new::physical_path_info *this,
        const vostok::fs_new::physical_path_initializer *initializer)
{
  this->device = initializer->device;
  vostok::fs_new::physical_path_info_data::physical_path_info_data(&this->data, &initializer->data);
  this->parent = initializer->parent;
}
