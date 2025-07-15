int __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_input_error(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  if ( this->_M_mmap_base )
  {
    UnmapViewOfFile(this->_M_mmap_base);
    if ( this->_M_base._M_view_id )
      CloseHandle(this->_M_base._M_view_id);
    this->_M_base._M_view_id = 0;
    this->_M_mmap_base = 0;
    LODWORD(this->_M_mmap_len) = 0;
    HIDWORD(this->_M_mmap_len) = 0;
  }
  this->_M_in_input_mode = 0;
  this->_M_in_output_mode = 0;
  this->_M_gbegin = 0;
  this->_M_gnext = 0;
  this->_M_gend = 0;
  this->_M_in_error_mode = 1;
  return -1;
}


int __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_input_error(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  void *M_mmap_base; // eax

  M_mmap_base = this->_M_mmap_base;
  if ( M_mmap_base )
  {
    stlp_std::_Filebuf_base::_M_unmap(&this->_M_base, M_mmap_base, this->_M_mmap_len);
    this->_M_mmap_base = 0;
    LODWORD(this->_M_mmap_len) = 0;
    HIDWORD(this->_M_mmap_len) = 0;
  }
  this->_M_in_input_mode = 0;
  this->_M_in_output_mode = 0;
  this->_M_gbegin = 0;
  this->_M_gnext = 0;
  this->_M_gend = 0;
  this->_M_in_error_mode = 1;
  return 0xFFFF;
}
