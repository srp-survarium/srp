bool __thiscall vostok::logging::compare_nodes::operator()(
        vostok::logging::compare_nodes *this,
        const vostok::logging::node_base *left,
        const vostok::logging::node_base *right)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  const vostok::variant<32> **v6; // [esp-4h] [ebp-Ch]

  v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&right->name);
  v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)&left->name);
  return vostok::detail::strcmp_s((const char *)v4, (const char *)v6) == -1;
}
