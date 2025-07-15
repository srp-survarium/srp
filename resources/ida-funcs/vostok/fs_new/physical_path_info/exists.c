bool __thiscall vostok::fs_new::physical_path_info::exists(vostok::fs_new::physical_path_info *this)
{
  return this->data.type != type_error_no_path;
}
