const vostok::fs_new::virtual_path_string *__thiscall vostok::fs_new::virtual_path_string::operator=(
        vostok::fs_new::virtual_path_string *this,
        vostok::fs_new::virtual_path_string *s)
{
  if ( this != s )
    vostok::buffer_string::operator=((vostok::fixed_string<32> *)s, (vostok::fixed_string<32> *)this);
  vostok::fs_new::path_string_impl::verify_self(this);
  return this;
}
