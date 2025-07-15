void __thiscall stlp_std::ios_base::ios_base(stlp_std::ios_base *this)
{
  this->__vftable = (stlp_std::ios_base_vtbl *)&stlp_std::ios_base::`vftable';
  this->_M_fmtflags = 0;
  this->_M_iostate = 0;
  this->_M_openmode = 0;
  this->_M_seekdir = 0;
  this->_M_exception_mask = 0;
  this->_M_precision = 0;
  this->_M_width = 0;
  stlp_std::locale::locale(&this->_M_locale);
  this->_M_callbacks = 0;
  this->_M_num_callbacks = 0;
  this->_M_callback_index = 0;
  this->_M_iwords = 0;
  this->_M_num_iwords = 0;
  this->_M_pwords = 0;
  this->_M_num_pwords = 0;
}
