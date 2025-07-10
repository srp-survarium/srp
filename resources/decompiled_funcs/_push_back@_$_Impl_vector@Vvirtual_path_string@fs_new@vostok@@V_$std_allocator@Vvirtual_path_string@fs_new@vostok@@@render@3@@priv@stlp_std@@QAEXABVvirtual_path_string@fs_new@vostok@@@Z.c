void __userpurge stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::push_back(
        const stlp_std::__false_type *__x@<eax>,
        stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *a2@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *this)
{
  vostok::fs_new::virtual_path_string *M_finish; // esi
  unsigned __int8 *v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  unsigned int v7; // [esp+0h] [ebp-8h]
  bool v8; // [esp+4h] [ebp-4h]

  M_finish = this->_M_finish;
  if ( M_finish == this->_M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::_M_insert_overflow_aux(
      a2,
      (vostok::fs_new::virtual_path_string *)this,
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
      M_finish->m_string.m_max_end = &M_finish->m_separator;
      v6 = v5;
      M_finish->m_string.m_begin = M_finish->m_string.m_buffer;
      M_finish->m_string.m_end = M_finish->m_string.m_buffer;
      memcpy((unsigned __int8 *)M_finish->m_string.m_buffer, v4, v5);
      M_finish->m_string.m_end += v6;
      *M_finish->m_string.m_end = 0;
      M_finish->m_separator = 47;
    }
    ++this->_M_finish;
  }
}
