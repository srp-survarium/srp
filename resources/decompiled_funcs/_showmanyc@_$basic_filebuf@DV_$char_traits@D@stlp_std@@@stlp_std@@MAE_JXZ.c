__int64 __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::showmanyc(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  stlp_std::_Filebuf_base *p_M_base; // esi
  __int64 v3; // kr00_8
  __int64 v4; // rax

  if ( !this->_M_base._M_is_open || this->_M_in_output_mode || this->_M_in_error_mode )
    return -1;
  if ( this->_M_in_putback_mode )
    return this->_M_gend - this->_M_gnext;
  if ( !this->_M_constant_width )
    return 0;
  p_M_base = &this->_M_base;
  v3 = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, 0, 2);
  v4 = stlp_std::_Filebuf_base::_M_file_size(p_M_base);
  if ( v3 < 0 || v4 <= v3 )
    return 0;
  else
    return v4 - v3;
}
