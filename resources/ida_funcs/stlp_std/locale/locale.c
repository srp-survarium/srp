void __thiscall stlp_std::locale::locale(stlp_std::locale *this, stlp_std::_Locale_impl *impl)
{
  this->_M_impl = stlp_std::_get_Locale_impl(impl);
}


void __thiscall stlp_std::locale::locale(stlp_std::locale *this, const stlp_std::locale *L)
{
  this->_M_impl = stlp_std::_get_Locale_impl(L->_M_impl);
}


void __thiscall stlp_std::locale::locale(stlp_std::locale *this)
{
  stlp_std::locale *global_locale; // eax

  global_locale = stlp_std::_Stl_get_global_locale();
  this->_M_impl = stlp_std::_get_Locale_impl(global_locale->_M_impl);
}
