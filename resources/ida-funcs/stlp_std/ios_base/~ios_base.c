void __thiscall stlp_std::ios_base::~ios_base(stlp_std::ios_base *this)
{
  this->__vftable = (stlp_std::ios_base_vtbl *)&stlp_std::ios_base::`vftable';
  stlp_std::ios_base::_M_invoke_callbacks(this, erase_event);
  free(this->_M_callbacks);
  free(this->_M_iwords);
  free(this->_M_pwords);
  stlp_std::locale::~locale(&this->_M_locale);
}
