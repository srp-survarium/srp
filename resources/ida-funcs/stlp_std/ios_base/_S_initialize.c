int stlp_std::ios_base::_S_initialize()
{
  stlp_std::priv::stdio_streambuf_base *v0; // esi
  _iobuf *v1; // eax
  _iobuf *v2; // eax
  stlp_std::priv::stdio_streambuf_base *v3; // esi
  _iobuf *v4; // eax
  stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *v5; // ebp
  stlp_std::priv::stdio_streambuf_base *v6; // edi
  _iobuf *v7; // eax
  stlp_std::priv::stdio_streambuf_base *v8; // esi
  _iobuf *v9; // eax
  _iobuf *v10; // eax
  _iobuf *v11; // eax
  _iobuf *v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // ebp
  int v17; // eax
  int v18; // edi
  _iobuf *v19; // eax
  stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *wfilebuf; // esi
  _iobuf *v21; // eax
  stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *v22; // edi
  _iobuf *v23; // eax
  stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *v24; // ebp
  _iobuf *v25; // eax
  int v26; // eax
  int v27; // esi
  int v28; // eax
  int v29; // eax
  int v30; // edi
  int result; // eax
  stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *filebuf__iobuf; // [esp+14h] [ebp-34h]
  stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *v33; // [esp+18h] [ebp-30h]
  stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *v34; // [esp+30h] [ebp-18h]
  int v35; // [esp+34h] [ebp-14h]

  if ( stlp_std::ios_base::_S_is_synced )
  {
    v0 = (stlp_std::priv::stdio_streambuf_base *)operator new(0x24u);
    if ( v0 )
    {
      v1 = __iob_func();
      stlp_std::priv::stdio_streambuf_base::stdio_streambuf_base(v0, v1);
      v0->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_istreambuf::`vftable';
      filebuf__iobuf = (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)v0;
    }
    else
    {
      filebuf__iobuf = 0;
    }
  }
  else
  {
    v2 = __iob_func();
    filebuf__iobuf = stlp_std::_Stl_create_filebuf__iobuf___(v2, 8);
  }
  if ( stlp_std::ios_base::_S_is_synced )
  {
    v3 = (stlp_std::priv::stdio_streambuf_base *)operator new(0x24u);
    if ( v3 )
    {
      v4 = __iob_func();
      stlp_std::priv::stdio_streambuf_base::stdio_streambuf_base(v3, v4 + 1);
      v3->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_ostreambuf::`vftable';
    }
    else
    {
      v3 = 0;
    }
    v5 = (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)v3;
    v6 = (stlp_std::priv::stdio_streambuf_base *)operator new(0x24u);
    if ( v6 )
    {
      v7 = __iob_func();
      stlp_std::priv::stdio_streambuf_base::stdio_streambuf_base(v6, v7 + 2);
      v6->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_ostreambuf::`vftable';
    }
    else
    {
      v6 = 0;
    }
    v8 = (stlp_std::priv::stdio_streambuf_base *)operator new(0x24u);
    if ( v8 )
    {
      v9 = __iob_func();
      stlp_std::priv::stdio_streambuf_base::stdio_streambuf_base(v8, v9 + 2);
      v8->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_ostreambuf::`vftable';
      v33 = (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)v8;
    }
    else
    {
      v33 = 0;
    }
  }
  else
  {
    v10 = __iob_func();
    v5 = stlp_std::_Stl_create_filebuf__iobuf___(v10 + 1, 16);
    v11 = __iob_func();
    v6 = (stlp_std::priv::stdio_streambuf_base *)stlp_std::_Stl_create_filebuf__iobuf___(v11 + 2, 16);
    v12 = __iob_func();
    v33 = stlp_std::_Stl_create_filebuf__iobuf___(v12 + 2, 16);
  }
  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::basic_istream<char,stlp_std::char_traits<char>>(
    &stlp_std::cin,
    filebuf__iobuf,
    1);
  v14 = v13;
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::basic_ostream<char,stlp_std::char_traits<char>>(
    &stlp_std::cout,
    v5,
    1);
  v16 = v15;
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::basic_ostream<char,stlp_std::char_traits<char>>(
    &stlp_std::cerr,
    v6,
    1);
  v18 = v17;
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::basic_ostream<char,stlp_std::char_traits<char>>(
    &stlp_std::clog,
    v33,
    1);
  *(_DWORD *)(v14 + *(_DWORD *)(*(_DWORD *)v14 + 4) + 92) = v16;
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v18 + 4) + v18 + 8) |= 0x2000u;
  v19 = __iob_func();
  wfilebuf = stlp_std::_Stl_create_wfilebuf(v19, 8);
  v21 = __iob_func();
  v22 = stlp_std::_Stl_create_wfilebuf(v21 + 1, 16);
  v23 = __iob_func();
  v24 = stlp_std::_Stl_create_wfilebuf(v23 + 2, 16);
  v25 = __iob_func();
  v34 = stlp_std::_Stl_create_wfilebuf(v25 + 2, 16);
  stlp_std::basic_istream<wchar_t,stlp_std::char_traits<wchar_t>>::basic_istream<wchar_t,stlp_std::char_traits<wchar_t>>(
    &stlp_std::wcin,
    wfilebuf,
    1);
  v27 = v26;
  stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>(
    &stlp_std::wcout,
    v22,
    1);
  v35 = v28;
  stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>(
    &stlp_std::wcerr,
    v24,
    1);
  v30 = v29;
  stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>(
    &stlp_std::wclog,
    v34,
    1);
  *(_DWORD *)(v27 + *(_DWORD *)(*(_DWORD *)v27 + 4) + 92) = v35;
  result = v30 + *(_DWORD *)(*(_DWORD *)v30 + 4);
  *(_DWORD *)(result + 8) |= 0x2000u;
  return result;
}
