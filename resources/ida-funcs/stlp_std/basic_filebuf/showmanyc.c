unsigned __int64 __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::showmanyc(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  stlp_std::_Filebuf_base *p_M_base; // esi
  int v3; // ebx
  int v4; // edx
  int v5; // edi
  __int64 v6; // rax

  if ( !this->_M_base._M_is_open || this->_M_in_output_mode || this->_M_in_error_mode )
    return -1;
  if ( this->_M_in_putback_mode )
    return this->_M_gend - this->_M_gnext;
  if ( !this->_M_constant_width )
    return 0;
  p_M_base = &this->_M_base;
  v3 = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, 0, 2);
  v5 = v4;
  LODWORD(v6) = stlp_std::_Filebuf_base::_M_file_size(p_M_base);
  if ( v5 < 0 || v6 <= __SPAIR64__(v5, v3) )
    return 0;
  else
    return v6 - __PAIR64__(v5, v3);
}


unsigned __int64 __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::showmanyc(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  stlp_std::_Filebuf_base *p_M_base; // esi
  int v3; // ebx
  int v4; // edx
  int v5; // edi
  __int64 v6; // rax

  if ( !this->_M_base._M_is_open || this->_M_in_output_mode || this->_M_in_error_mode )
    return -1;
  if ( this->_M_in_putback_mode )
    return this->_M_gend - this->_M_gnext;
  if ( !this->_M_constant_width )
    return 0;
  p_M_base = &this->_M_base;
  v3 = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, 0, 2);
  v5 = v4;
  LODWORD(v6) = stlp_std::_Filebuf_base::_M_file_size(p_M_base);
  if ( v5 < 0 || v6 <= __SPAIR64__(v5, v3) )
    return 0;
  else
    return v6 - __PAIR64__(v5, v3);
}
