void __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::imbue(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        stlp_std::locale *__loc)
{
  if ( !this->_M_in_input_mode && !this->_M_in_output_mode && !this->_M_in_error_mode )
    stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_setup_codecvt(this, __loc, 1);
}
