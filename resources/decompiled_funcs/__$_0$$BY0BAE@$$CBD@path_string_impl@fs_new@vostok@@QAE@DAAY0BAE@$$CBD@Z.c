void __thiscall vostok::fs_new::path_string_impl::path_string_impl(
        vostok::fs_new::path_string_impl *this,
        char separator,
        const char (*src)[1])
{
  vostok::fixed_string<260>::fixed_string<260>(&this->m_string, (const char *)src);
  this->m_separator = separator;
  vostok::fs_new::path_string_impl::verify_self(this);
}
