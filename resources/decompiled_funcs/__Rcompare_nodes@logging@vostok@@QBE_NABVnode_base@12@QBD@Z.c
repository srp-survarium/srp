bool __thiscall vostok::logging::compare_nodes::operator()(
        vostok::logging::compare_nodes *this,
        const vostok::logging::node_base *left,
        const char *right)
{
  const vostok::variant<32> **v3; // eax

  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&left->name);
  return compare_parts((const char *)v3, right);
}
