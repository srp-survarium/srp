BOOL __thiscall boost::system::error_category::equivalent(
        boost::system::error_category *this,
        const boost::system::error_code *code,
        int condition)
{
  return this == code->m_cat && code->m_val == condition;
}


BOOL __thiscall boost::system::error_category::equivalent(
        boost::system::error_category *this,
        int code,
        const boost::system::error_condition *condition)
{
  const boost::system::error_condition *v3; // eax
  boost::system::error_condition v5; // [esp+0h] [ebp-8h] BYREF

  v3 = (const boost::system::error_condition *)((int (__thiscall *)(boost::system::error_category *))this->default_error_condition)(this);
  return boost::system::operator==(v3, &v5);
}
