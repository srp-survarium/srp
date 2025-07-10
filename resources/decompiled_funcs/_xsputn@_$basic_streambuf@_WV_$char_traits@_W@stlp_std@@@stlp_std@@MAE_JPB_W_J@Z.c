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
  __int64 __result; // [esp+10h] [ebp-8h]

  __result = 0;
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
        __result = ++v4;
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
        __result += v9;
        v11 = HIDWORD(__result);
        v5 = (unsigned __int16 *)((char *)v5 + v10);
        this->_M_pnext = (wchar_t *)((char *)this->_M_pnext + v10);
        v4 = __PAIR64__(v11, __result);
      }
    }
    while ( v4 < __n );
  }
  return v4;
}
