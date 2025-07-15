void __userpurge stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(
        stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *this@<ecx>,
        int a2@<edi>,
        const char *__s)
{
  _DWORD *v3; // esi
  stlp_std::basic_ios<char,stlp_std::char_traits<char> > *v4; // ecx
  int v5; // esi
  bool v6; // al
  unsigned int M_width; // edx
  unsigned int M_width_high; // eax
  int v9; // ebx
  unsigned __int64 v10; // kr00_8
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_streambuf; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // edx
  bool v15; // zf
  int v16; // edx
  int v17; // edx
  int v18; // eax
  int v19; // [esp+10h] [ebp-Ch]
  unsigned int v20; // [esp+18h] [ebp-4h]

  v3 = (_DWORD *)(*(_DWORD *)a2 + 4);
  v4 = (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)(*v3 + a2);
  if ( v4->_M_iostate )
  {
    v6 = 0;
  }
  else
  {
    if ( !v4->_M_streambuf )
      stlp_std::basic_ios<char,stlp_std::char_traits<char>>::clear(v4, v4->_M_iostate | 1);
    v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) + a2 + 92);
    if ( v5 )
      stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::flush(
        (stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *)v4,
        v5);
    v3 = (_DWORD *)(*(_DWORD *)a2 + 4);
    v4 = (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)(*v3 + a2);
    v6 = v4->_M_iostate == 0;
  }
  if ( v6 )
  {
    v20 = strlen(__s);
    M_width = v4->_M_width;
    M_width_high = HIDWORD(v4->_M_width);
    if ( __SPAIR64__(M_width_high, M_width) <= v20 )
    {
      v9 = 0;
      v19 = 0;
    }
    else
    {
      v10 = __PAIR64__(M_width_high, M_width) - v20;
      v19 = HIDWORD(v10);
      v9 = v10;
    }
    if ( v19 | v9 )
    {
      if ( (v4->_M_fmtflags & 7) == 1 )
      {
        if ( ((int (__thiscall *)(stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *, const char *, unsigned int, _DWORD))v4->_M_streambuf->xsputn)(
               v4->_M_streambuf,
               __s,
               v20,
               0) != v20 )
          goto LABEL_26;
        if ( v12 )
          goto LABEL_26;
        v13 = a2 + *(_DWORD *)(*(_DWORD *)a2 + 4);
        LOBYTE(__s) = *(_BYTE *)(v13 + 84);
        if ( (*(int (__thiscall **)(_DWORD, const char *, int, int))(**(_DWORD **)(v13 + 88) + 44))(
               *(_DWORD *)(v13 + 88),
               __s,
               v9,
               v19) != v9 )
          goto LABEL_26;
        v15 = v14 == v19;
        goto LABEL_24;
      }
      if ( (*(int (__thiscall **)(_DWORD, _BYTE, int, int))(**(_DWORD **)(a2 + *v3 + 88) + 44))(
             *(_DWORD *)(a2 + *v3 + 88),
             *(_BYTE *)(a2 + *v3 + 84),
             v9,
             v19) != v9
        || v16 != v19 )
      {
        goto LABEL_26;
      }
      M_streambuf = *(stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > **)(*(_DWORD *)(*(_DWORD *)a2 + 4)
                                                                                     + a2
                                                                                     + 88);
    }
    else
    {
      M_streambuf = v4->_M_streambuf;
    }
    if ( ((int (__thiscall *)(stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *, const char *, unsigned int, _DWORD))M_streambuf->xsputn)(
           M_streambuf,
           __s,
           v20,
           0) != v20 )
      goto LABEL_26;
    v15 = v17 == 0;
LABEL_24:
    if ( v15 )
    {
      LOBYTE(v4) = 0;
      goto LABEL_27;
    }
LABEL_26:
    LOBYTE(v4) = 1;
LABEL_27:
    v18 = *(_DWORD *)(*(_DWORD *)a2 + 4);
    *(_DWORD *)(v18 + a2 + 40) = 0;
    *(_DWORD *)(v18 + a2 + 44) = 0;
    if ( (_BYTE)v4 )
      stlp_std::basic_ios<char,stlp_std::char_traits<char>>::clear(
        (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)(a2 + *(_DWORD *)(*(_DWORD *)a2 + 4)),
        *(_DWORD *)(a2 + *(_DWORD *)(*(_DWORD *)a2 + 4) + 12) | 4);
  }
  if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) + a2 + 8) & 0x2000) != 0 )
    stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::flush(
      (stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *)v4,
      a2);
}
