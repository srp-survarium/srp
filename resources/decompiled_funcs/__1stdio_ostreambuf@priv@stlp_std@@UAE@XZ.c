void __thiscall stlp_std::priv::stdio_ostreambuf::~stdio_ostreambuf(stlp_std::priv::stdio_ostreambuf *this)
{
  _iobuf *M_file; // [esp-4h] [ebp-8h]

  M_file = this->_M_file;
  this->__vftable = (stlp_std::priv::stdio_ostreambuf_vtbl *)&stlp_std::priv::stdio_streambuf_base::`vftable';
  fflush(M_file);
  this->__vftable = (stlp_std::priv::stdio_ostreambuf_vtbl *)&stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::locale::~locale(&this->_M_locale);
}
