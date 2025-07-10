bool __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_switch_to_output_mode(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  bool result; // al
  wchar_t *M_int_buf; // ecx

  if ( !this->_M_base._M_is_open
    || (this->_M_base._M_openmode & 0x10) == 0
    || this->_M_in_input_mode
    || this->_M_in_error_mode
    || !this->_M_int_buf && !stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_allocate_buffers(this) )
  {
    return 0;
  }
  result = 1;
  if ( (this->_M_base._M_openmode & 1) != 0 )
    this->_M_state = 0;
  M_int_buf = this->_M_int_buf;
  this->_M_pbegin = M_int_buf;
  this->_M_pnext = M_int_buf;
  this->_M_pend = this->_M_int_buf_EOS - 1;
  this->_M_in_output_mode = 1;
  return result;
}
