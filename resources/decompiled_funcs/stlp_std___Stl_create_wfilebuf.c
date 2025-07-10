stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::_Stl_create_wfilebuf(
        _iobuf *f,
        int mode)
{
  stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *)operator new(0x90u);
  if ( v2 )
  {
    stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>(v2);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  stlp_std::_Filebuf_base::_M_open((stlp_std::_Filebuf_base *)(v4 + 32), f->_file, mode);
  if ( *(_BYTE *)(v4 + 40) )
    return (stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *)v4;
  (**(void (__thiscall ***)(int, int))v4)(v4, 1);
  return 0;
}
