const vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::assign_with_conversion<char [260]>(
        vostok::fs_new::path_string_impl *this,
        vostok::fixed_string<16> *s)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  char *v4; // eax
  char *v6; // [esp-4h] [ebp-10h]

  vostok::fixed_string<16>::operator=(s, &this->m_string);
  v6 = (char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(v2);
  v4 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)this);
  vostok::fs_new::path_string_impl::convert(this, v4, v6);
  return this;
}
