stlp_std::fpos<int> *__thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        stlp_std::fpos<int> *result,
        __int64 a3,
        int __state)
{
  void *M_mmap_base; // eax
  stlp_std::fpos<int> *v6; // eax

  if ( (HIDWORD(a3) & (unsigned int)a3) != 0xFFFFFFFF )
  {
    if ( this->_M_in_input_mode )
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
    this->_M_in_input_mode = 0;
    this->_M_in_output_mode = 0;
    this->_M_in_putback_mode = 0;
    this->_M_in_error_mode = 0;
    this->_M_gbegin = 0;
    this->_M_gnext = 0;
    this->_M_gend = 0;
    this->_M_pbegin = 0;
    this->_M_pnext = 0;
    this->_M_pend = 0;
  }
  v6 = result;
  result->_M_pos = a3;
  result->_M_st = __state;
  return v6;
}
