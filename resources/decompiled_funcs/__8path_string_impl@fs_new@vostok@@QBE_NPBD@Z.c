BOOL __thiscall vostok::fs_new::path_string_impl::operator==(vostok::fs_new::path_string_impl *this, const char *path)
{
  return vostok::operator==(&this->m_string, path);
}
