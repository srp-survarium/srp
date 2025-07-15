BOOL __cdecl boost::system::operator==(
        const boost::system::error_condition *lhs,
        const boost::system::error_condition *rhs)
{
  return lhs->m_cat == rhs->m_cat && lhs->m_val == rhs->m_val;
}


bool __usercall boost::system::operator!=@<al>(
        const boost::system::error_code *lhs@<ecx>,
        const boost::system::error_code *rhs@<eax>)
{
  bool v2; // al

  v2 = lhs->m_cat == rhs->m_cat && lhs->m_val == rhs->m_val;
  return !v2;
}
