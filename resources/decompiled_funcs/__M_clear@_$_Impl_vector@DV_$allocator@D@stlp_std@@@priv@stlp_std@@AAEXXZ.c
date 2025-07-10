void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_clear(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this)
{
  char *v1; // [esp-8h] [ebp-58h] BYREF
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *v2; // [esp-4h] [ebp-54h] BYREF
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *thisa; // [esp+0h] [ebp-50h]
  char **v4; // [esp+38h] [ebp-18h]
  char *M_finish; // [esp+3Ch] [ebp-14h]
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > **v6; // [esp+40h] [ebp-10h]
  char *M_start; // [esp+44h] [ebp-Ch]

  thisa = this;
  v2 = this;
  v6 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *)M_start;
  v1 = M_start;
  v4 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  stlp_std::allocator<char>::deallocate(
    &thisa->_M_end_of_storage,
    thisa->_M_start,
    thisa->_M_end_of_storage._M_data - thisa->_M_start);
}
