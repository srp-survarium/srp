__int64 __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::_M_xsputnc(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        unsigned __int8 __c,
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
      v5 = this->overflow(this, __c);
      if ( v5 == __eof )
        return __result;
      ++__result;
    }
    else
    {
      __b = __n - __result;
      __a = this->_M_pend - this->_M_pnext;
      __chunk = *stlp_std::min<unsigned int>(&__a, &__b);
      memset((unsigned __int8 *)this->_M_pnext, __c, __chunk);
      __result += __chunk;
      this->_M_pnext += __chunk;
    }
  }
  return __result;
}
