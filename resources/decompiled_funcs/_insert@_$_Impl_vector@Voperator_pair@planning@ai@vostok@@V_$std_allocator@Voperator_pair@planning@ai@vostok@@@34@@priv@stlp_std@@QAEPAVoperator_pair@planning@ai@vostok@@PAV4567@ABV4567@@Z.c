vostok::ai::planning::operator_pair *__thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::insert(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *this,
        vostok::ai::planning::operator_pair *__pos,
        const vostok::ai::planning::operator_pair *__x)
{
  unsigned int __n; // [esp+Ch] [ebp-4h]

  __n = __pos - this->_M_start;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_fill_insert(
    this,
    __pos,
    1u,
    __x);
  return &this->_M_start[__n];
}
