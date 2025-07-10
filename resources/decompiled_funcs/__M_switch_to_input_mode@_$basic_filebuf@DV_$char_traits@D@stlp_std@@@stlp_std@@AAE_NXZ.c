bool __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_switch_to_input_mode(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  char *M_ext_buf; // eax
  bool result; // al

  if ( !this->_M_base._M_is_open
    || (this->_M_base._M_openmode & 8) == 0
    || this->_M_in_output_mode
    || this->_M_in_error_mode
    || !this->_M_int_buf && !stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_allocate_buffers(this) )
  {
    return 0;
  }
  M_ext_buf = this->_M_ext_buf;
  this->_M_ext_buf_converted = M_ext_buf;
  this->_M_ext_buf_end = M_ext_buf;
  this->_M_end_state = this->_M_state;
  result = 1;
  this->_M_in_input_mode = 1;
  return result;
}
