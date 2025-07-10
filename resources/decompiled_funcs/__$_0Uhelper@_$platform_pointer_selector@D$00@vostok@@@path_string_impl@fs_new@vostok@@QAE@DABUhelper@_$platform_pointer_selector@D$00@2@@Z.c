void __thiscall vostok::fs_new::path_string_impl::path_string_impl(
        vostok::fs_new::path_string_impl *this,
        char separator,
        const vostok::platform_pointer_selector<char,1>::helper *src)
{
  vostok::fixed_string<260>::fixed_string<260>(&this->m_string, src->pointer);
  this->m_separator = separator;
  vostok::fs_new::path_string_impl::verify_self(this);
}
