void __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::~basic_filebuf<char,stlp_std::char_traits<char>>(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  this->__vftable = (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> >_vtbl *)&stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::close(this);
  if ( this->_M_int_buf_dynamic )
    free(this->_M_int_buf);
  free(this->_M_ext_buf);
  this->_M_int_buf = 0;
  this->_M_int_buf_EOS = 0;
  this->_M_ext_buf = 0;
  this->_M_ext_buf_EOS = 0;
  this->__vftable = (stlp_std::basic_filebuf<char,stlp_std::char_traits<char> >_vtbl *)&stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::locale::~locale(&this->_M_locale);
}
