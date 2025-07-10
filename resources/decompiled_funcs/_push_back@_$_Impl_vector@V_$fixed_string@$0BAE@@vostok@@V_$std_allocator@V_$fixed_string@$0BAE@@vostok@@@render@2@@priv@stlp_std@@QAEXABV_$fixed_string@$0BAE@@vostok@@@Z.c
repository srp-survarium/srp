void __userpurge stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260>>>::push_back(
        const stlp_std::__false_type *__x@<eax>,
        stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *a2@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *this)
{
  vostok::fixed_string<260> *M_finish; // esi
  unsigned __int8 *v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  unsigned int v7; // [esp+0h] [ebp-8h]
  bool v8; // [esp+4h] [ebp-4h]

  M_finish = this->_M_finish;
  if ( M_finish == this->_M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260>>>::_M_insert_overflow_aux(
      a2,
      (vostok::fixed_string<260> *)this,
      M_finish,
      __x,
      v7,
      v8);
  }
  else
  {
    if ( M_finish )
    {
      v4 = *(unsigned __int8 **)__x;
      v5 = *(_DWORD *)&__x[4] - *(_DWORD *)__x;
      M_finish->m_max_end = (char *)&M_finish[1];
      v6 = v5;
      M_finish->m_begin = M_finish->m_buffer;
      M_finish->m_end = M_finish->m_buffer;
      memcpy((unsigned __int8 *)M_finish->m_buffer, v4, v5);
      M_finish->m_end += v6;
      *M_finish->m_end = 0;
    }
    ++this->_M_finish;
  }
}
