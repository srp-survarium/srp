void __usercall vostok::memory::writer_base::open_chunk(
        vostok::memory::writer_base *this@<edi>,
        unsigned int type@<eax>)
{
  unsigned int v2; // eax
  unsigned int *M_finish; // ecx
  vostok::memory::writer_base_vtbl *v4; // eax
  const stlp_std::__true_type *v5; // [esp+0h] [ebp-8h]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF
  BOOL savedregs; // [esp+8h] [ebp+0h]

  v6 = type;
  this->write(this, &v6, 4u);
  v2 = this->tell(this);
  M_finish = this->m_chunk_pos._M_impl._M_finish;
  v6 = v2;
  if ( M_finish == this->m_chunk_pos._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)M_finish,
      (stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::vectora_allocator<unsigned int> > *)&this->m_chunk_pos,
      (unsigned __int8 *)M_finish,
      &v6,
      v5,
      v6,
      savedregs);
  }
  else
  {
    *M_finish = v2;
    ++this->m_chunk_pos._M_impl._M_finish;
  }
  v4 = this->__vftable;
  v6 = 0;
  v4->write(this, &v6, 4u);
}
