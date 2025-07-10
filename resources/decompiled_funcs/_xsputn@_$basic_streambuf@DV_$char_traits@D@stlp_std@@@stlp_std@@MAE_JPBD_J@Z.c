__int64 __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::xsputn(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        char *__s,
        __int64 __n)
{
  int v5; // [esp+14h] [ebp-20h]
  unsigned int __a; // [esp+18h] [ebp-1Ch] BYREF
  unsigned int __b; // [esp+1Ch] [ebp-18h] BYREF
  unsigned int __chunk; // [esp+20h] [ebp-14h]
  __int64 __result; // [esp+24h] [ebp-10h]
  int __eof; // [esp+30h] [ebp-4h]

  __result = 0;
  __eof = -1;
  while ( __result < __n )
  {
    if ( this->_M_pnext >= this->_M_pend )
    {
      v5 = this->overflow(this, (unsigned __int8)*__s);
      if ( v5 == __eof )
        return __result;
      ++__result;
      ++__s;
    }
    else
    {
      __b = __n - __result;
      __a = this->_M_pend - this->_M_pnext;
      __chunk = *stlp_std::min<unsigned int>(&__a, &__b);
      if ( __chunk )
        memcpy((unsigned __int8 *)this->_M_pnext, (unsigned __int8 *)__s, __chunk);
      __result += __chunk;
      __s += __chunk;
      this->_M_pnext += __chunk;
    }
  }
  return __result;
}
