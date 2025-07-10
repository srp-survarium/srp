void __userpurge stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item> > *this,
        const survarium::account_list_item *__x)
{
  survarium::account_list_item *M_finish; // edi
  int v4; // ecx
  survarium::account_list_item *v5; // esi
  const stlp_std::random_access_iterator_tag *v6; // [esp+0h] [ebp-10h]
  int *v7; // [esp+4h] [ebp-Ch]

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 52 )
  {
    stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item>>::insert(
      this,
      this->_M_finish,
      __new_size - v4 / 52,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = stlp_std::priv::__copy<survarium::account_list_item *,survarium::account_list_item *,int>(
                          M_finish,
                          M_finish,
                          v5,
                          v6,
                          v7);
  }
}
