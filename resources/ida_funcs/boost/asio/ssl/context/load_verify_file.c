void __thiscall boost::asio::ssl::context::load_verify_file(
        boost::asio::ssl::context *this,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *filename)
{
  boost::system::error_code result; // [esp+178h] [ebp-10h] BYREF
  boost::system::error_code ec; // [esp+180h] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::ssl::context::load_verify_file(this, &result, filename, &ec);
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "load_verify_file");
}


boost::system::error_code *__thiscall boost::asio::ssl::context::load_verify_file(
        boost::asio::ssl::context *this,
        boost::system::error_code *result,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *filename,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v4; // eax
  const boost::system::error_category *m_cat; // ecx
  const boost::system::error_category *v7; // [esp+14h] [ebp-Ch]
  boost::asio::error::detail::ssl_category *ssl_category; // [esp+1Ch] [ebp-4h]

  if ( SSL_CTX_load_verify_locations(this->handle_, filename->_M_start_of_storage._M_data, 0) == 1 )
  {
    v7 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v7;
    m_cat = ec->m_cat;
    result->m_val = ec->m_val;
    result->m_cat = m_cat;
  }
  else
  {
    ssl_category = boost::asio::error::get_ssl_category();
    ec->m_val = ERR_get_error();
    ec->m_cat = ssl_category;
    v4 = ec->m_cat;
    result->m_val = ec->m_val;
    result->m_cat = v4;
  }
  return result;
}
