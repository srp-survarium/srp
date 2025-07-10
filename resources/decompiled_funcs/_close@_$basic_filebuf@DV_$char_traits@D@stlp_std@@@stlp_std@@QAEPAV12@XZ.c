stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *__thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::close(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  void *M_mmap_base; // eax
  bool v3; // al
  bool __ok; // [esp+Bh] [ebp-1h]

  __ok = this->_M_base._M_is_open != 0;
  if ( this->_M_in_output_mode )
  {
    if ( !this->_M_base._M_is_open || (__ok = 1, this->overflow(this, -1) == -1) )
      __ok = 0;
    stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_unshift(this);
  }
  else if ( this->_M_in_input_mode )
  {
    M_mmap_base = this->_M_mmap_base;
    if ( M_mmap_base )
    {
      stlp_std::_Filebuf_base::_M_unmap(&this->_M_base, M_mmap_base, this->_M_mmap_len);
      this->_M_mmap_base = 0;
      LODWORD(this->_M_mmap_len) = 0;
      HIDWORD(this->_M_mmap_len) = 0;
    }
    this->_M_in_input_mode = 0;
  }
  v3 = stlp_std::_Filebuf_base::_M_close(&this->_M_base) && __ok;
  this->_M_end_state = 0;
  this->_M_state = 0;
  this->_M_ext_buf_end = 0;
  this->_M_ext_buf_converted = 0;
  this->_M_mmap_base = 0;
  LODWORD(this->_M_mmap_len) = 0;
  HIDWORD(this->_M_mmap_len) = 0;
  this->_M_gbegin = 0;
  this->_M_gnext = 0;
  this->_M_gend = 0;
  this->_M_pbegin = 0;
  this->_M_pnext = 0;
  this->_M_pend = 0;
  this->_M_saved_egptr = 0;
  this->_M_saved_gptr = 0;
  this->_M_saved_eback = 0;
  this->_M_in_putback_mode = 0;
  this->_M_in_error_mode = 0;
  this->_M_in_output_mode = 0;
  this->_M_in_input_mode = 0;
  return v3 ? this : 0;
}
