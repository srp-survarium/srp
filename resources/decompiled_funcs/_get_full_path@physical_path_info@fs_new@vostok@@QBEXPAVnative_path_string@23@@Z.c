void __thiscall vostok::fs_new::physical_path_info::get_full_path(
        vostok::fs_new::physical_path_info *this,
        vostok::fs_new::native_path_string *out_path)
{
  vostok::fs_new::physical_path_info::initialize_full_path_if_needed(this);
  if ( out_path != &this->data.path )
    vostok::buffer_string::operator=((vostok::fixed_string<32> *)&this->data.path, (vostok::fixed_string<32> *)out_path);
  vostok::fs_new::path_string_impl::verify_self(out_path);
}
