__int64 __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::xsgetn(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        char *__s,
        __int64 __n)
{
  unsigned __int8 *M_gnext; // edx
  char *M_gend; // eax
  bool v7; // cf
  unsigned int *v8; // eax
  unsigned int v9; // esi
  int v10; // eax
  unsigned int v11; // kr04_4
  int v13; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-Ch] BYREF
  __int64 v15; // [esp+18h] [ebp-8h]

  v15 = 0;
  while ( v15 < __n )
  {
    M_gnext = (unsigned __int8 *)this->_M_gnext;
    M_gend = this->_M_gend;
    if ( M_gnext >= (unsigned __int8 *)M_gend )
    {
      v10 = stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::sbumpc(this);
      if ( v10 == -1 )
        return v15;
      v11 = v15;
      LODWORD(v15) = v15 + 1;
      *__s = v10;
      HIDWORD(v15) = (__PAIR64__(HIDWORD(v15), v11) + 1) >> 32;
      ++__s;
    }
    else
    {
      v14 = M_gend - (char *)M_gnext;
      v7 = (int)__n - (int)v15 < (unsigned int)(M_gend - (char *)M_gnext);
      v13 = __n - v15;
      v8 = (unsigned int *)&v13;
      if ( !v7 )
        v8 = (unsigned int *)&v14;
      v9 = *v8;
      if ( *v8 )
        memcpy((unsigned __int8 *)__s, M_gnext, *v8);
      v15 += v9;
      this->_M_gnext += v9;
      __s += v9;
    }
  }
  return v15;
}


int __thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::xsgetn(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        wchar_t *__s,
        __int64 __n)
{
  signed __int64 v4; // kr00_8
  unsigned __int8 *v5; // ebx
  unsigned __int8 *M_gnext; // edx
  wchar_t *M_gend; // eax
  unsigned int *p_s; // eax
  unsigned int v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned __int16 v12; // ax
  unsigned int v14; // [esp+Ch] [ebp-Ch] BYREF
  signed __int64 v15; // [esp+10h] [ebp-8h]

  v15 = 0;
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
        v15 = v4;
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
        v15 += v9;
        v11 = HIDWORD(v15);
        v5 += v10;
        this->_M_gnext = (wchar_t *)((char *)this->_M_gnext + v10);
        v4 = __PAIR64__(v11, v15);
      }
    }
    while ( v4 < __n );
  }
  return v4;
}
