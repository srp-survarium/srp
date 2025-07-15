const vostok::fs_new::virtual_path_string *__thiscall vostok::fs_new::path_string_impl::append<char const *>(
        vostok::fs_new::virtual_path_string *this,
        char **s)
{
  vostok::buffer_string::append(&this->m_string, *s);
  return this;
}


vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(
        vostok::fs_new::path_string_impl *this,
        const vostok::fixed_string<260> *s)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  char *v3; // eax
  vostok::buffer_string *v4; // eax
  const char *v6; // [esp-4h] [ebp-138h]
  vostok::fixed_string<260> v8; // [esp+24h] [ebp-110h] BYREF

  v6 = (const char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end((stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this);
  v3 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)s);
  v4 = vostok::buffer_string::append(&this->m_string, v3, v6);
  vostok::fixed_string<260>::fixed_string<260>(&v8, v4);
  return this;
}
