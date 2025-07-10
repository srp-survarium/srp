vostok::variant<32> *__thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_erase(
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this,
        vostok::variant<32> *__first,
        vostok::variant<32> *__last,
        const stlp_std::__false_type *__formal)
{
  vostok::variant<32> *v6; // [esp+10h] [ebp-14h]
  vostok::variant<32> *other; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]

  v6 = __first;
  other = __last;
  for ( i = this->_M_finish - __last; i > 0; --i )
    vostok::variant<32>::operator=(v6++, other++);
  stlp_std::_Destroy_Range<vostok::variant<32> *>(v6, this->_M_finish);
  this->_M_finish = v6;
  return __first;
}
