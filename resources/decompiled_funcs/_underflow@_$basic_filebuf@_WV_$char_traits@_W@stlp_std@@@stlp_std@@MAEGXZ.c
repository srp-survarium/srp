int __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::underflow(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  wchar_t *M_saved_egptr; // ecx
  wchar_t *M_saved_gptr; // eax

  if ( this->_M_in_input_mode )
  {
    if ( this->_M_in_putback_mode )
    {
      M_saved_egptr = this->_M_saved_egptr;
      this->_M_gbegin = this->_M_saved_eback;
      M_saved_gptr = this->_M_saved_gptr;
      this->_M_gnext = M_saved_gptr;
      this->_M_gend = M_saved_egptr;
      this->_M_in_putback_mode = 0;
      if ( M_saved_gptr != M_saved_egptr )
        return *M_saved_gptr;
    }
  }
  else if ( !stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_switch_to_input_mode(this) )
  {
    return 0xFFFF;
  }
  return stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_underflow_aux(this);
}
