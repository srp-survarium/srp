void __userpurge stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::insert(
        stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32> > > *this@<ecx>,
        const stlp_std::__false_type *__n@<esi>,
        const vostok::fixed_string<32> *__x@<eax>,
        vostok::fixed_string<32> *__pos)
{
  unsigned int v4; // [esp+0h] [ebp-8h]
  bool v5; // [esp+4h] [ebp-4h]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
      stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::_M_insert_overflow_aux(
        this,
        __pos,
        __x,
        __n,
        v4,
        v5);
    else
      stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::_M_fill_insert_aux(
        this,
        __pos,
        (unsigned int)__n,
        __x,
        (const stlp_std::__false_type *)&__pos);
  }
}
