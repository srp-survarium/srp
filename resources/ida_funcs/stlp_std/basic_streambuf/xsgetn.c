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


int __thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::xsgetn(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        wchar_t *__s,
        __int64 __n)
{
  __int64 v4; // kr00_8
  unsigned __int8 *v5; // ebx
  unsigned __int8 *M_gnext; // edx
  wchar_t *M_gend; // eax
  unsigned int *p_s; // eax
  unsigned int v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned __int16 v12; // ax
  unsigned int v14; // [esp+Ch] [ebp-Ch] BYREF
  __int64 __result; // [esp+10h] [ebp-8h]

  __result = 0;
  v4 = 0;
  if ( __n > 0 )
  {
    v5 = (unsigned __int8 *)__s;
    do
    {
      M_gnext = (unsigned __int8 *)this->_M_gnext;
      M_gend = this->_M_gend;
      if ( M_gnext >= (unsigned __int8 *)M_gend )
      {
        v12 = this->uflow(this);
        if ( v12 == 0xFFFF )
          return v4;
        ++v4;
        *(_WORD *)v5 = v12;
        __result = v4;
        v5 += 2;
      }
      else
      {
        v14 = ((char *)M_gend - (char *)M_gnext) >> 1;
        __s = (wchar_t *)(__n - v4);
        p_s = (unsigned int *)&__s;
        if ( (int)__n - (int)v4 >= v14 )
          p_s = &v14;
        v9 = *p_s;
        v10 = 2 * *p_s;
        memcpy(v5, M_gnext, v10);
        __result += v9;
        v11 = HIDWORD(__result);
        v5 += v10;
        this->_M_gnext = (wchar_t *)((char *)this->_M_gnext + v10);
        v4 = __PAIR64__(v11, __result);
      }
    }
    while ( v4 < __n );
  }
  return v4;
}
