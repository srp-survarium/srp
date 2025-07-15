stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall boost::asio::error::detail::misc_category::message(
        boost::asio::error::detail::misc_category *this,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result,
        int value)
{
  switch ( value )
  {
    case 1:
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        result,
        "Already open",
        (const stlp_std::allocator<char> *)&result + 3);
      break;
    case 2:
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        result,
        "End of file",
        (const stlp_std::allocator<char> *)&result + 3);
      break;
    case 3:
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        result,
        "Element not found",
        (const stlp_std::allocator<char> *)&result + 3);
      break;
    case 4:
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        result,
        "The descriptor does not fit into the select call's fd_set",
        (const stlp_std::allocator<char> *)&result + 3);
      break;
    default:
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        result,
        "asio.misc error",
        (const stlp_std::allocator<char> *)&result + 3);
      break;
  }
  return result;
}
