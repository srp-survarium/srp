stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__f,
        const char *__l)
{
  btPersistentManifold **v3; // eax
  char *Length; // [esp-4h] [ebp-98h]
  int count; // [esp+6Ch] [ebp-28h]
  unsigned __int8 *v8; // [esp+70h] [ebp-24h]
  unsigned __int8 *dst; // [esp+84h] [ebp-10h]
  unsigned int __n; // [esp+90h] [ebp-4h]

  __n = __l - __f;
  if ( __l - __f > (unsigned int)(this->_M_finish - this->_M_start_of_storage._M_data) )
  {
    count = this->_M_finish - this->_M_start_of_storage._M_data;
    v8 = (unsigned __int8 *)stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((btCollisionDispatcher *)this);
    if ( count )
      memcpy(v8, (unsigned __int8 *)__f, count);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_append(
      this,
      &__f[this->_M_finish - this->_M_start_of_storage._M_data],
      __l);
  }
  else
  {
    dst = (unsigned __int8 *)stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((btCollisionDispatcher *)this);
    if ( __n )
      memcpy(dst, (unsigned __int8 *)__f, __n);
    Length = (char *)Scaleform::MemoryFile::GetLength((btNullPairCache *)this);
    v3 = stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((btCollisionDispatcher *)this);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::erase(
      this,
      (char *)v3 + __n,
      Length);
  }
  return this;
}
