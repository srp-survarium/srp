void __thiscall vostok::logging::filter_tree::build_tree(vostok::logging::filter_tree *this)
{
  char *v1; // eax
  int M_data; // [esp-10h] [ebp-18h]
  unsigned int M_start; // [esp-Ch] [ebp-14h]
  vostok::memory::base_allocator *allocator; // [esp-8h] [ebp-10h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *it; // [esp+4h] [ebp-4h]

  vostok::logging::node::clean(this->initiator_tree, this->allocator);
  for ( it = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this->filter_stack.m_first;
        it;
        it = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)it->_M_impl._M_start )
  {
    if ( !vostok::logging::filter_tree::filter_is_overwritten(this, (vostok::logging::initiator_filter *)it) )
    {
      allocator = this->allocator;
      M_start = (unsigned int)it[1]._M_impl._M_start;
      M_data = (int)it->_M_impl._M_end_of_storage._M_data;
      v1 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                     it,
                     (int)&it[1]._M_impl._M_finish);
      vostok::logging::node::set(this->initiator_tree, v1, M_data, M_start, allocator, 0);
    }
  }
}
