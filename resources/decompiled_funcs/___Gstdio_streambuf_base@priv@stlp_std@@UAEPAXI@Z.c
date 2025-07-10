stlp_std::priv::stdio_streambuf_base *__thiscall stlp_std::priv::stdio_streambuf_base::`scalar deleting destructor'(
        stlp_std::priv::stdio_streambuf_base *this,
        char a2)
{
  _iobuf *M_file; // [esp-4h] [ebp-8h]

  M_file = this->_M_file;
  this->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::priv::stdio_streambuf_base::`vftable';
  fflush(M_file);
  this->__vftable = (stlp_std::priv::stdio_streambuf_base_vtbl *)&stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::locale::~locale(&this->_M_locale);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
