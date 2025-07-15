BOOL __thiscall type_info::operator==(type_info *this, const type_info *rhs)
{
  int v2; // eax

  strcmp((unsigned __int8 *)&rhs->_m_d_name[1], (unsigned __int8 *)&this->_m_d_name[1]);
  return v2 == 0;
}
