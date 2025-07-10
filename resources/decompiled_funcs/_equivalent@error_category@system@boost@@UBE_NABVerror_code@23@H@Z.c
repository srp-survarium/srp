bool __thiscall boost::system::error_category::equivalent(
        boost::system::error_category *this,
        const boost::system::error_code *code,
        int condition)
{
  return this == code->m_cat && code->m_val == condition;
}
