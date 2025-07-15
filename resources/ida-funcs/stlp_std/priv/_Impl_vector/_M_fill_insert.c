void __userpurge stlp_std::priv::_Impl_vector<vostok::animation::EtKey,vostok::vectora_allocator<vostok::animation::EtKey>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::animation::EtKey,vostok::vectora_allocator<vostok::animation::EtKey> > *this@<ecx>,
        unsigned int __n@<esi>,
        vostok::animation::EtKey *__pos,
        const stlp_std::__true_type *__x)
{
  bool savedregs; // [esp+0h] [ebp+0h]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
      stlp_std::priv::_Impl_vector<vostok::animation::EtKey,vostok::vectora_allocator<vostok::animation::EtKey>>::_M_insert_overflow(
        this,
        (int)this,
        __pos,
        __x,
        __n,
        savedregs);
    else
      stlp_std::priv::_Impl_vector<vostok::animation::EtKey,vostok::vectora_allocator<vostok::animation::EtKey>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        (const vostok::animation::EtKey *)__x,
        (const stlp_std::__false_type *)&__x + 3);
  }
}
