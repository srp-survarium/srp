int __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::sync(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  if ( this->_M_in_output_mode )
    return (this->overflow(this, -1) != -1) - 1;
  else
    return 0;
}


int __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::sync(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  if ( this->_M_in_output_mode )
    return (this->overflow(this, 0xFFFFu) != 0xFFFF) - 1;
  else
    return 0;
}
