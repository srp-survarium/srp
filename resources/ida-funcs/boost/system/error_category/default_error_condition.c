boost::system::error_condition *__thiscall boost::system::error_category::default_error_condition(
        boost::system::error_category *this,
        boost::system::error_condition *result,
        int ev)
{
  boost::system::error_condition *v3; // eax

  v3 = result;
  result->m_val = ev;
  result->m_cat = this;
  return v3;
}
