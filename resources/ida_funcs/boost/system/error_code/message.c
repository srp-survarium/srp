stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall boost::system::error_code::message(
        boost::system::error_code *this,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result)
{
  this->m_cat->message(this->m_cat, result, this->m_val);
  return result;
}
