char __cdecl vostok::operator==(vostok::fs_new::path_string_impl *s1, vostok::fs_new::path_string_impl *s2)
{
  unsigned int v2; // esi
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  char v6; // [esp+4h] [ebp-24h]
  unsigned int v7; // [esp+8h] [ebp-20h]
  unsigned int v8; // [esp+10h] [ebp-18h]
  vostok::const_buffer buffer1; // [esp+18h] [ebp-10h] BYREF
  vostok::const_buffer buffer2; // [esp+20h] [ebp-8h] BYREF

  v2 = vostok::fs_new::path_string_impl::length(s1);
  v6 = 0;
  if ( v2 == vostok::fs_new::path_string_impl::length(s2) )
  {
    v8 = vostok::fs_new::path_string_impl::length(s2);
    buffer2.m_data = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                     v3,
                                     (int)s2);
    buffer2.m_size = v8;
    v7 = vostok::fs_new::path_string_impl::length(s1);
    buffer1.m_data = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                     v4,
                                     (int)s1);
    buffer1.m_size = v7;
    if ( !vostok::memory::compare(&buffer1, &buffer2) )
      return 1;
  }
  return v6;
}


BOOL __usercall vostok::operator==@<eax>(const vostok::buffer_string *s1@<ecx>, const char *s2@<eax>)
{
  return vostok::detail::strcmp_s(s1->m_begin, s2) == 0;
}


vostok::mutable_buffer *__cdecl vostok::operator+(
        vostok::mutable_buffer *result,
        const vostok::mutable_buffer *buffer,
        vostok::mutable_buffer *offs)
{
  unsigned int m_size; // edx
  vostok::mutable_buffer resulta; // [esp+4h] [ebp-8h] BYREF

  m_size = buffer->m_size;
  resulta.m_data = buffer->m_data;
  resulta.m_size = m_size;
  vostok::mutable_buffer::operator+=(offs, &resulta);
  *result = resulta;
  return result;
}


bool __cdecl vostok::operator<(const vostok::buffer_string *s1, const vostok::buffer_string *s2)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  const vostok::variant<32> **v6; // [esp-4h] [ebp-8h]

  v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)s2);
  v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)s1);
  return vostok::detail::strcmp_s((const char *)v4, (const char *)v6) == -1;
}
