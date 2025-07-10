boost::system::error_condition *__thiscall boost::system::error_category::default_error_condition(
        boost::system::error_category *this,
        boost::system::error_condition *result,
        int ev)
{
  result->m_val = ev;
  result->m_cat = this;
  return result;
}
