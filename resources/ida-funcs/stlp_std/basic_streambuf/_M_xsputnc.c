unsigned int __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::_M_xsputnc(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        char __c,
        __int64 __n)
{
  unsigned int v3; // ebx
  char *M_pnext; // edx
  char *M_pend; // eax
  bool v7; // cf
  unsigned int *v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // et0
  unsigned int v11; // et0
  int v13; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+1Ch] [ebp-4h]

  v3 = 0;
  v15 = 0;
  if ( __n > 0 )
  {
    do
    {
      M_pnext = this->_M_pnext;
      M_pend = this->_M_pend;
      if ( M_pnext >= M_pend )
      {
        if ( this->overflow(this, (unsigned __int8)__c) == -1 )
          return v3;
        v11 = (__PAIR64__(v15, v3++) + 1) >> 32;
        v15 = v11;
      }
      else
      {
        v14 = M_pend - M_pnext;
        v7 = (unsigned int)__n - v3 < M_pend - M_pnext;
        v13 = __n - v3;
        v8 = (unsigned int *)&v13;
        if ( !v7 )
          v8 = (unsigned int *)&v14;
        v9 = *v8;
        memset((int)M_pnext, __c, *v8);
        v10 = (v9 + __PAIR64__(v15, v3)) >> 32;
        v3 += v9;
        v15 = v10;
        this->_M_pnext += v9;
      }
    }
    while ( __SPAIR64__(v15, v3) < __n );
  }
  return v3;
}


unsigned int __thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_xsputnc(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        int __c,
        __int64 __n)
{
  unsigned int v3; // ebx
  unsigned int v4; // ebp
  wchar_t *M_pend; // eax
  wchar_t *M_pnext; // edi
  unsigned int *v8; // eax
  unsigned int v9; // edx
  wchar_t *v10; // edi
  int i; // ecx
  int v13; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v14; // [esp+10h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+18h] [ebp-4h]

  v3 = 0;
  v4 = 0;
  v15 = 0;
  if ( __n > 0 )
  {
    do
    {
      M_pend = this->_M_pend;
      M_pnext = this->_M_pnext;
      if ( M_pnext >= M_pend )
      {
        if ( this->overflow(this, __c) == 0xFFFF )
          return v3;
        v4 = (__PAIR64__(v4, v3++) + 1) >> 32;
      }
      else
      {
        v14 = M_pend - M_pnext;
        v13 = __n - v3;
        v8 = (unsigned int *)&v13;
        if ( (unsigned int)__n - v3 >= v14 )
          v8 = &v14;
        v9 = *v8;
        if ( *v8 )
        {
          v4 = v15;
          memset32(M_pnext, ((unsigned __int16)__c << 16) | (unsigned __int16)__c, v9 >> 1);
          v10 = &M_pnext[2 * (v9 >> 1)];
          for ( i = v9 & 1; i; --i )
            *v10++ = __c;
        }
        v4 = (__PAIR64__(v4, v9) + v3) >> 32;
        v3 += v9;
        this->_M_pnext += v9;
      }
      v15 = v4;
    }
    while ( __SPAIR64__(v4, v3) < __n );
  }
  return v3;
}
