stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *__thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::setbuf(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        char *__buf,
        __int64 __n)
{
  if ( !this->_M_in_input_mode && !this->_M_in_output_mode && !this->_M_in_error_mode && !this->_M_int_buf )
  {
    if ( __buf )
    {
      if ( __n > 0 )
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_allocate_buffers(this, __buf, __n);
    }
    else if ( !__n )
    {
      stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_allocate_buffers(this, 0, 1);
      return this;
    }
  }
  return this;
}


stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::setbuf(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        wchar_t *__buf,
        __int64 __n)
{
  if ( !this->_M_in_input_mode && !this->_M_in_output_mode && !this->_M_in_error_mode && !this->_M_int_buf )
  {
    if ( __buf )
    {
      if ( __n > 0 )
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_allocate_buffers(this, __buf, __n);
    }
    else if ( !__n )
    {
      stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_allocate_buffers(this, 0, 1);
      return this;
    }
  }
  return this;
}
