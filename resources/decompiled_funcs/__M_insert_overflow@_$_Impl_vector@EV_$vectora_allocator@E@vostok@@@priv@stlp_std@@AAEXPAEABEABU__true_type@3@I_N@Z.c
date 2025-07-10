void __userpurge stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char> > *this@<esi>,
        unsigned __int8 *__pos@<eax>,
        stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char> > *a3@<ecx>,
        unsigned __int8 *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int *v8; // eax
  unsigned __int8 *v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  unsigned __int8 *v12; // edi
  unsigned int v13; // ecx
  unsigned int v14; // [esp+0h] [ebp-18h]
  int v15; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  unsigned int size; // [esp+14h] [ebp-4h]

  size = stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char>>::_M_compute_next_size(
           a3,
           v14);
  v16 = size;
  v15 = 1;
  v8 = (unsigned int *)&v15;
  if ( size )
    v8 = &v16;
  v9 = (unsigned __int8 *)this->_M_end_of_storage.m_allocator->call_realloc(this->_M_end_of_storage.m_allocator, 0, *v8);
  v10 = __pos - this->_M_start;
  if ( v10 )
  {
    memmove(v9, this->_M_start, v10);
    v12 = (unsigned __int8 *)(v10 + v11);
  }
  else
  {
    v12 = v9;
  }
  *v12 = *__x;
  this->_M_end_of_storage.m_allocator->call_free(this->_M_end_of_storage.m_allocator, this->_M_start);
  v13 = size;
  this->_M_finish = v12 + 1;
  this->_M_start = v9;
  this->_M_end_of_storage._M_data = &v9[v13];
}
