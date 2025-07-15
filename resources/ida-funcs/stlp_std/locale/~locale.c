void __thiscall stlp_std::locale::~locale(stlp_std::locale *this)
{
  if ( this->_M_impl )
    stlp_std::_release_Locale_impl(&this->_M_impl);
}
