char *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::erase(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__first,
        char *__last)
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = (char *)Scaleform::MemoryFile::GetLength((btNullPairCache *)this) - __last;
    if ( v3 != -1 )
      memmove((unsigned __int8 *)__first, (unsigned __int8 *)__last, v3 + 1);
    this->_M_finish = (char *)Scaleform::MemoryFile::GetLength((btNullPairCache *)this) - (__last - __first);
  }
  return __first;
}
