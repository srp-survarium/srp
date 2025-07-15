vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::append_path<char const *>(
        vostok::fs_new::path_string_impl *this,
        char **s)
{
  char m_separator; // [esp+5h] [ebp-Bh]

  if ( vostok::fs_new::path_string_impl::length(this) )
    vostok::fs_new::path_string_impl::operator+=<char>((vostok::fs_new::native_path_string *)this, &this->m_separator);
  vostok::buffer_string::append(&this->m_string, *s);
  m_separator = this->m_separator;
  while ( this->m_string.m_end > this->m_string.m_begin && *(this->m_string.m_end - 1) == m_separator )
    --this->m_string.m_end;
  *this->m_string.m_end = 0;
  return this;
}


vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::append_path<vostok::fixed_string<260>>(
        vostok::fs_new::path_string_impl *this,
        const vostok::fixed_string<260> *s)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  char *v4; // eax
  vostok::buffer_string *v5; // eax
  const char *v7; // [esp-4h] [ebp-13Ch]
  char m_separator; // [esp+6h] [ebp-132h]
  vostok::fixed_string<260> v10; // [esp+24h] [ebp-114h] BYREF

  if ( vostok::fs_new::path_string_impl::length(this) )
    vostok::fs_new::path_string_impl::operator+=<char>((vostok::fs_new::native_path_string *)this, &this->m_separator);
  v7 = (const char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(v2);
  v4 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)s);
  v5 = vostok::buffer_string::append(&this->m_string, v4, v7);
  vostok::fixed_string<260>::fixed_string<260>(&v10, v5);
  m_separator = this->m_separator;
  while ( this->m_string.m_end > this->m_string.m_begin && *(this->m_string.m_end - 1) == m_separator )
    --this->m_string.m_end;
  *this->m_string.m_end = 0;
  return this;
}
