bool __thiscall boost::system::error_category::equivalent(
        boost::system::error_category *this,
        int code,
        const boost::system::error_condition *condition)
{
  boost::system::error_condition *v5; // [esp+8h] [ebp-Ch]
  _BYTE v6[8]; // [esp+Ch] [ebp-8h] BYREF

  v5 = this->default_error_condition(this, v6, code);
  return v5->m_cat == condition->m_cat && v5->m_val == condition->m_val;
}
