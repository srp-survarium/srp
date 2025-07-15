stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__userpurge boost::asio::error::detail::ssl_category::message@<eax>(
        boost::asio::error::detail::ssl_category *this@<ecx>,
        int a2@<edi>,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result,
        unsigned int value)
{
  char *v4; // eax

  v4 = (char *)ERR_reason_error_string(a2, value);
  if ( !v4 )
    v4 = "asio.ssl error";
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    result,
    v4,
    (const stlp_std::allocator<char> *)&result + 3);
  return result;
}
