const vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::append_with_conversion<char const [13]>@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        vostok::fs_new::path_string_impl *a2@<esi>)
{
  unsigned __int8 *m_end; // ebx
  unsigned int v3; // edi

  m_end = (unsigned __int8 *)a2->m_string.m_end;
  v3 = strlen("/replication");
  memcpy(m_end, "/replication", v3);
  a2->m_string.m_end += v3;
  *a2->m_string.m_end = 0;
  vostok::fs_new::path_string_impl::convert(a2, (char *)m_end, a2->m_string.m_end);
  return a2;
}


const vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::append_with_conversion<char const *>@<eax>(
        vostok::fs_new::path_string_impl *this@<esi>,
        const char **s@<eax>)
{
  char *v2; // ecx
  unsigned __int8 *m_end; // ebx
  unsigned int v4; // edi

  v2 = (char *)*s;
  m_end = (unsigned __int8 *)this->m_string.m_end;
  v4 = strlen(*s);
  memcpy(m_end, (unsigned __int8 *)v2, v4);
  this->m_string.m_end += v4;
  *this->m_string.m_end = 0;
  vostok::fs_new::path_string_impl::convert(this, (char *)m_end, this->m_string.m_end);
  return this;
}


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
