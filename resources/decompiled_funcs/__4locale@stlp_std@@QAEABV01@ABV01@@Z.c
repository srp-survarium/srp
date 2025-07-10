const stlp_std::locale *__thiscall stlp_std::locale::operator=(stlp_std::locale *this, const stlp_std::locale *L)
{
  if ( this->_M_impl != L->_M_impl )
  {
    if ( this->_M_impl )
      stlp_std::_release_Locale_impl(&this->_M_impl);
    this->_M_impl = stlp_std::_get_Locale_impl(L->_M_impl);
  }
  return this;
}
