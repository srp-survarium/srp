__int64 __thiscall stlp_std::_Filebuf_base::_M_get_offset(stlp_std::_Filebuf_base *this, char *__first, char *__last)
{
  int v4; // eax
  char *i; // ecx

  if ( (this->_M_openmode & 4) != 0 )
    return __last - __first;
  v4 = 0;
  for ( i = __first; i != __last; ++i )
  {
    if ( *i == 10 )
      ++v4;
  }
  return (int)&__last[v4 - (_DWORD)__first];
}
