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
