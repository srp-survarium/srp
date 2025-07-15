unsigned int __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::xsputn(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        char *__s,
        __int64 __n)
{
  unsigned int v3; // ebx
  unsigned __int8 *M_pnext; // edx
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
      M_pnext = (unsigned __int8 *)this->_M_pnext;
      M_pend = this->_M_pend;
      if ( M_pnext >= (unsigned __int8 *)M_pend )
      {
        if ( this->overflow(this, (unsigned __int8)*__s) == -1 )
          return v3;
        v11 = (__PAIR64__(v15, v3++) + 1) >> 32;
        v15 = v11;
        ++__s;
      }
      else
      {
        v14 = M_pend - (char *)M_pnext;
        v7 = (unsigned int)__n - v3 < M_pend - (char *)M_pnext;
        v13 = __n - v3;
        v8 = (unsigned int *)&v13;
        if ( !v7 )
          v8 = (unsigned int *)&v14;
        v9 = *v8;
        if ( *v8 )
          memcpy(M_pnext, (unsigned __int8 *)__s, *v8);
        v10 = (v9 + __PAIR64__(v15, v3)) >> 32;
        v3 += v9;
        v15 = v10;
        __s += v9;
        this->_M_pnext += v9;
      }
    }
    while ( __SPAIR64__(v15, v3) < __n );
  }
  return v3;
}


int __thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::xsputn(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        wchar_t *__s,
        __int64 __n)
{
  signed __int64 v4; // kr00_8
  unsigned __int16 *v5; // ebp
  unsigned __int8 *M_pnext; // edx
  wchar_t *M_pend; // eax
  unsigned int *p_s; // eax
  unsigned int v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned int v13; // [esp+Ch] [ebp-Ch] BYREF
  signed __int64 v14; // [esp+10h] [ebp-8h]

  v14 = 0;
  v4 = 0;
  if ( __n > 0 )
  {
    v5 = __s;
    do
    {
      M_pnext = (unsigned __int8 *)this->_M_pnext;
      M_pend = this->_M_pend;
      if ( M_pnext >= (unsigned __int8 *)M_pend )
      {
        if ( this->overflow(this, *v5) == 0xFFFF )
          return v4;
        v14 = ++v4;
        ++v5;
      }
      else
      {
        v13 = ((char *)M_pend - (char *)M_pnext) >> 1;
        __s = (wchar_t *)(__n - v4);
        p_s = (unsigned int *)&__s;
        if ( (int)__n - (int)v4 >= v13 )
          p_s = &v13;
        v9 = *p_s;
        v10 = 2 * *p_s;
        memcpy(M_pnext, (unsigned __int8 *)v5, v10);
        v14 += v9;
        v11 = HIDWORD(v14);
        v5 = (unsigned __int16 *)((char *)v5 + v10);
        this->_M_pnext = (wchar_t *)((char *)this->_M_pnext + v10);
        v4 = __PAIR64__(v11, v14);
      }
    }
    while ( v4 < __n );
  }
  return v4;
}
