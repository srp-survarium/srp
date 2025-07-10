bool __cdecl stlp_std::ios_base::sync_with_stdio(bool sync)
{
  bool result; // al
  stlp_std::priv::stdio_streambuf_base *v2; // esi
  _iobuf *v3; // eax
  stlp_std::priv::stdio_streambuf_base *v4; // esi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *filebuf__iobuf; // ebp
  _iobuf *v9; // eax
  stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *v10; // edi
  _iobuf *v11; // eax
  stlp_std::priv::stdio_streambuf_base *v12; // esi
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v13; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v14; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v15; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v16; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v17; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v18; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v19; // eax
  bool v20; // bl
  stlp_std::priv::stdio_streambuf_base *v21; // esi
  _iobuf *v22; // eax
  _iobuf *v23; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v24; // [esp+4h] [ebp-38h]
  stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *cin_buf; // [esp+1Ch] [ebp-20h]

  result = sync;
  if ( sync != stlp_std::ios_base::_S_is_synced )
  {
    if ( stlp_std::ios_base::Init::_S_count )
    {
      if ( sync )
      {
        v2 = (stlp_std::priv::stdio_streambuf_base *)operator new(0x24u);
        if ( v2 )
        {
          v3 = __iob_func();
          stlp_std::priv::stdio_streambuf_base::stdio_streambuf_base(v2, v3);
          v2->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_istreambuf::`vftable';
        }
        else
        {
          v2 = 0;
        }
        cin_buf = (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)v2;
        v4 = (stlp_std::priv::stdio_streambuf_base *)operator new(0x24u);
        if ( v4 )
        {
          v5 = __iob_func();
          stlp_std::priv::stdio_streambuf_base::stdio_streambuf_base(v4, v5 + 1);
          v4->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_ostreambuf::`vftable';
        }
        else
        {
          v4 = 0;
        }
        filebuf__iobuf = (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)v4;
        v21 = (stlp_std::priv::stdio_streambuf_base *)operator new(0x24u);
        if ( v21 )
        {
          v22 = __iob_func();
          stlp_std::priv::stdio_streambuf_base::stdio_streambuf_base(v21, v22 + 2);
          v21->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_ostreambuf::`vftable';
        }
        else
        {
          v21 = 0;
        }
        v10 = (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)v21;
        v12 = (stlp_std::priv::stdio_streambuf_base *)operator new(0x24u);
        if ( v12 )
        {
          v23 = __iob_func();
          stlp_std::priv::stdio_streambuf_base::stdio_streambuf_base(v12, v23 + 2);
          v12->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_ostreambuf::`vftable';
        }
        else
        {
          v12 = 0;
        }
      }
      else
      {
        v6 = __iob_func();
        cin_buf = stlp_std::_Stl_create_filebuf__iobuf___(v6, 8);
        v7 = __iob_func();
        filebuf__iobuf = stlp_std::_Stl_create_filebuf__iobuf___(v7 + 1, 16);
        v9 = __iob_func();
        v10 = stlp_std::_Stl_create_filebuf__iobuf___(v9 + 2, 16);
        v11 = __iob_func();
        v12 = (stlp_std::priv::stdio_streambuf_base *)stlp_std::_Stl_create_filebuf__iobuf___(v11 + 2, 16);
      }
      if ( cin_buf && filebuf__iobuf && v10 && v12 )
      {
        v24 = cin_buf;
        cin_buf = 0;
        v13 = stlp_std::basic_ios<char,stlp_std::char_traits<char>>::rdbuf(
                (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&stlp_std::cin.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cin.gap0 + 4)],
                v24);
        if ( v13 )
          ((void (__thiscall *)(stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *, int))v13->~stlp_std::basic_streambuf<char,stlp_std::char_traits<char> >)(
            v13,
            1);
        v14 = filebuf__iobuf;
        filebuf__iobuf = 0;
        v15 = stlp_std::basic_ios<char,stlp_std::char_traits<char>>::rdbuf(
                (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&stlp_std::cout.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cout.gap0 + 4)],
                v14);
        if ( v15 )
          ((void (__thiscall *)(stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *, int))v15->~stlp_std::basic_streambuf<char,stlp_std::char_traits<char> >)(
            v15,
            1);
        v16 = v10;
        v10 = 0;
        v17 = stlp_std::basic_ios<char,stlp_std::char_traits<char>>::rdbuf(
                (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&stlp_std::cerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cerr.gap0 + 4)],
                v16);
        if ( v17 )
          ((void (__thiscall *)(stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *, int))v17->~stlp_std::basic_streambuf<char,stlp_std::char_traits<char> >)(
            v17,
            1);
        v18 = v12;
        v12 = 0;
        v19 = stlp_std::basic_ios<char,stlp_std::char_traits<char>>::rdbuf(
                (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&stlp_std::clog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::clog.gap0 + 4)],
                v18);
        if ( v19 )
          ((void (__thiscall *)(stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *, int))v19->~stlp_std::basic_streambuf<char,stlp_std::char_traits<char> >)(
            v19,
            1);
        stlp_std::ios_base::_S_is_synced = sync;
      }
      v20 = stlp_std::ios_base::_S_is_synced;
      if ( v12 )
        ((void (__thiscall *)(stlp_std::priv::stdio_streambuf_base *, int))v12->~stlp_std::priv::stdio_streambuf_base)(
          v12,
          1);
      if ( v10 )
        ((void (__thiscall *)(stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *, int))v10->~stlp_std::basic_filebuf<char,stlp_std::char_traits<char> >)(
          v10,
          1);
      if ( filebuf__iobuf )
        ((void (__thiscall *)(stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *, int))filebuf__iobuf->~stlp_std::basic_filebuf<char,stlp_std::char_traits<char> >)(
          filebuf__iobuf,
          1);
      if ( cin_buf )
        ((void (__thiscall *)(stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *, int))cin_buf->~stlp_std::basic_filebuf<char,stlp_std::char_traits<char> >)(
          cin_buf,
          1);
      return v20;
    }
    else
    {
      stlp_std::ios_base::_S_is_synced = sync;
    }
  }
  return result;
}
