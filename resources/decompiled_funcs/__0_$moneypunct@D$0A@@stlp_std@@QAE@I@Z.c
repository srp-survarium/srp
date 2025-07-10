void __thiscall stlp_std::moneypunct<char,0>::moneypunct<char,0>(
        stlp_std::moneypunct<char,0> *this,
        unsigned int __refs)
{
  this->_M_ref_count = __refs != 0;
  this->__vftable = (stlp_std::moneypunct<char,0>_vtbl *)&stlp_std::moneypunct<char,0>::`vftable';
  this->_M_pos_format.field[0] = 2;
  this->_M_pos_format.field[1] = 3;
  this->_M_pos_format.field[2] = 0;
  this->_M_pos_format.field[3] = 4;
  this->_M_neg_format.field[0] = 2;
  this->_M_neg_format.field[1] = 3;
  this->_M_neg_format.field[2] = 0;
  this->_M_neg_format.field[3] = 4;
}
