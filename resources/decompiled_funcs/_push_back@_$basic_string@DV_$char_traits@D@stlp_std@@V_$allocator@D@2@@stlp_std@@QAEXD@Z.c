void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::push_back(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char __c)
{
  unsigned int size; // eax
  btBroadphasePair *Length; // eax
  int v4; // [esp+0h] [ebp-5Ch]

  if ( stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_using_static_buf(this) )
    v4 = 16 - (this->_M_finish - (char *)this);
  else
    v4 = this->_M_buffers._M_end_of_storage - this->_M_finish;
  if ( v4 == 1 )
  {
    size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_compute_next_size(
             this,
             1u);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_reserve(this, size);
  }
  Length = Scaleform::MemoryFile::GetLength((btNullPairCache *)this);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_construct_null(
    this,
    (char *)&Length->m_pProxy0 + 1);
  LOBYTE(Scaleform::MemoryFile::GetLength((btNullPairCache *)this)->m_pProxy0) = __c;
  ++this->_M_finish;
}
