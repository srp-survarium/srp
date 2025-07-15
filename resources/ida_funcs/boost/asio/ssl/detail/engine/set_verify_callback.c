boost::system::error_code *__thiscall boost::asio::ssl::detail::engine::set_verify_callback(
        boost::asio::ssl::detail::engine *this,
        boost::system::error_code *result,
        boost::asio::ssl::detail::verify_callback_base *callback,
        boost::system::error_code *ec)
{
  int verify_mode; // eax
  const boost::system::error_category *m_cat; // eax
  const boost::system::error_category *v8; // [esp+Ch] [ebp-Ch]
  void (__thiscall ***v9)(void *, int); // [esp+14h] [ebp-4h]

  if ( SSL_get_ex_data(this->ssl_, 0) )
  {
    v9 = (void (__thiscall ***)(void *, int))SSL_get_ex_data(this->ssl_, 0);
    if ( v9 )
      (**v9)(v9, 1);
  }
  SSL_set_ex_data(this->ssl_, 0, callback);
  verify_mode = SSL_get_verify_mode(this->ssl_);
  SSL_set_verify(this->ssl_, verify_mode, boost::asio::ssl::detail::engine::verify_callback_function);
  v8 = boost::system::system_category();
  ec->m_val = 0;
  ec->m_cat = v8;
  m_cat = ec->m_cat;
  result->m_val = ec->m_val;
  result->m_cat = m_cat;
  return result;
}
