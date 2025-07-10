void __thiscall stlp_std::priv::stdio_streambuf_base::stdio_streambuf_base(
        stlp_std::priv::stdio_streambuf_base *this,
        _iobuf *file)
{
  this->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::`vftable';
  this->_M_gbegin = 0;
  this->_M_gnext = 0;
  this->_M_gend = 0;
  this->_M_pbegin = 0;
  this->_M_pnext = 0;
  this->_M_pend = 0;
  stlp_std::locale::locale(&this->_M_locale);
  this->_M_file = file;
  this->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_streambuf_base::`vftable';
}
