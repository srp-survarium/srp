char __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_init(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        bool __do_unshift)
{
  bool v3; // al
  bool v4; // zf
  char *M_saved_gptr; // ecx
  char *M_saved_egptr; // edx

  this->_M_in_error_mode = 0;
  if ( this->_M_in_output_mode )
  {
    v3 = this->overflow(this, -1) != -1;
    if ( __do_unshift )
    {
      if ( !v3 )
      {
LABEL_7:
        this->_M_in_output_mode = 0;
        this->_M_pbegin = 0;
        this->_M_pnext = 0;
        this->_M_pend = 0;
        this->_M_in_error_mode = 1;
        return 0;
      }
      v4 = stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_unshift(this) == 0;
    }
    else
    {
      v4 = !v3;
    }
    if ( v4 )
      goto LABEL_7;
  }
  if ( this->_M_in_input_mode )
  {
    if ( this->_M_in_putback_mode )
    {
      M_saved_gptr = this->_M_saved_gptr;
      M_saved_egptr = this->_M_saved_egptr;
      this->_M_gbegin = this->_M_saved_eback;
      this->_M_gnext = M_saved_gptr;
      this->_M_gend = M_saved_egptr;
      this->_M_in_putback_mode = 0;
    }
  }
  return 1;
}


char __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_seek_init(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        bool __do_unshift)
{
  bool v3; // al
  bool v4; // zf
  wchar_t *M_saved_gptr; // eax
  wchar_t *M_saved_egptr; // ecx

  this->_M_in_error_mode = 0;
  if ( this->_M_in_output_mode )
  {
    v3 = this->overflow(this, 0xFFFFu) != 0xFFFF;
    if ( __do_unshift )
    {
      if ( !v3 )
      {
LABEL_7:
        this->_M_in_output_mode = 0;
        this->_M_pbegin = 0;
        this->_M_pnext = 0;
        this->_M_pend = 0;
        this->_M_in_error_mode = 1;
        return 0;
      }
      v4 = !stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_unshift((stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *)this);
    }
    else
    {
      v4 = !v3;
    }
    if ( v4 )
      goto LABEL_7;
  }
  if ( this->_M_in_input_mode )
  {
    if ( this->_M_in_putback_mode )
    {
      M_saved_gptr = this->_M_saved_gptr;
      M_saved_egptr = this->_M_saved_egptr;
      this->_M_gbegin = this->_M_saved_eback;
      this->_M_gnext = M_saved_gptr;
      this->_M_gend = M_saved_egptr;
      this->_M_in_putback_mode = 0;
    }
  }
  return 1;
}
