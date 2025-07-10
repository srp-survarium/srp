const vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::append_with_conversion<char const *>(
        vostok::fs_new::path_string_impl *this,
        char *begin,
        const char *end)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v3; // ecx
  char *v4; // eax
  char *it_begin; // [esp+Ch] [ebp-4h]

  it_begin = (char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end((stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this);
  vostok::buffer_string::append(&this->m_string, begin, end);
  v4 = (char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(v3);
  vostok::fs_new::path_string_impl::convert(this, it_begin, v4);
  return this;
}
