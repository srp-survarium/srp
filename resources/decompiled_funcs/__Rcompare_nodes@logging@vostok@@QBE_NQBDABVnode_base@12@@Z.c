bool __thiscall vostok::logging::compare_nodes::operator()(
        vostok::logging::compare_nodes *this,
        const char *left,
        const vostok::logging::node_base *right)
{
  const vostok::variant<32> **v3; // eax

  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&right->name);
  return compare_parts(left, (const char *)v3);
}
