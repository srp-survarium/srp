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
