stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *__cdecl stlp_std::_Stl_create_filebuf__iobuf___(
        _iobuf *x,
        int mode)
{
  stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)operator new(0x88u);
  if ( v2 )
  {
    stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::basic_filebuf<char,stlp_std::char_traits<char>>(v2);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  stlp_std::_Filebuf_base::_M_open((stlp_std::_Filebuf_base *)(v4 + 32), x->_file, mode);
  if ( *(_BYTE *)(v4 + 40) )
    return (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)v4;
  (**(void (__thiscall ***)(int, int))v4)(v4, 1);
  return 0;
}
