__int64 __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::xsgetn(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        char *__s,
        __int64 __n)
{
  unsigned int __a; // [esp+14h] [ebp-20h] BYREF
  unsigned int __b; // [esp+18h] [ebp-1Ch] BYREF
  int __c; // [esp+1Ch] [ebp-18h]
  unsigned int __chunk; // [esp+20h] [ebp-14h]
  __int64 __result; // [esp+24h] [ebp-10h]
  int __eof; // [esp+30h] [ebp-4h]

  __result = 0;
  __eof = -1;
  while ( __result < __n )
  {
    if ( this->_M_gnext >= this->_M_gend )
    {
      __c = stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::sbumpc(this);
      if ( __c == __eof )
        return __result;
      *__s = __c;
      ++__result;
      ++__s;
    }
    else
    {
      __b = __n - __result;
      __a = this->_M_gend - this->_M_gnext;
      __chunk = *stlp_std::min<unsigned int>(&__a, &__b);
      if ( __chunk )
        memcpy((unsigned __int8 *)__s, (unsigned __int8 *)this->_M_gnext, __chunk);
      __result += __chunk;
      __s += __chunk;
      this->_M_gnext += __chunk;
    }
  }
  return __result;
}
