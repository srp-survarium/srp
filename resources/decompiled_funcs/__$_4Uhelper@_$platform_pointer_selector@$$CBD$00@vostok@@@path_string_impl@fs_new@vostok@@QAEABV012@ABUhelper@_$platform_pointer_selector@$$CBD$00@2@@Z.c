const vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::operator=<vostok::platform_pointer_selector<char const,1>::helper>(
        vostok::fs_new::path_string_impl *this,
        const vostok::platform_pointer_selector<char const ,1>::helper *s)
{
  vostok::buffer_string::operator=(&this->m_string, s->pointer);
  vostok::fs_new::path_string_impl::verify_self(this);
  return this;
}
