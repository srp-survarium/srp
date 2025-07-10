void __thiscall stlp_std::locale::locale(stlp_std::locale *this, const stlp_std::locale *L)
{
  this->_M_impl = stlp_std::_get_Locale_impl(L->_M_impl);
}
