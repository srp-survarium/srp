BOOL __thiscall vostok::buffer_string::empty(vostok::fs_new::path_string_impl *this)
{
  return this->m_string.m_begin == this->m_string.m_end;
}
