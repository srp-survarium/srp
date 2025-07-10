const boost::system::error_code *__thiscall boost::asio::ssl::detail::engine::map_error_code(
        boost::asio::ssl::detail::engine *this,
        boost::system::error_code *ec)
{
  boost::asio::error::detail::ssl_category *v5; // [esp+8h] [ebp-2Ch]
  boost::asio::error::detail::ssl_category *ssl_category; // [esp+28h] [ebp-Ch]

  if ( ec->m_cat != boost::asio::error::get_misc_category() || ec->m_val != 2 )
    return ec;
  if ( BIO_ctrl(this->ext_bio_, 13, 0, 0) )
  {
    ssl_category = boost::asio::error::get_ssl_category();
    ec->m_val = 335544539;
    ec->m_cat = ssl_category;
    return ec;
  }
  else if ( this->ssl_ && this->ssl_->version == 2 )
  {
    return ec;
  }
  else
  {
    if ( (SSL_get_shutdown(this->ssl_) & 2) == 0 )
    {
      v5 = boost::asio::error::get_ssl_category();
      ec->m_val = 335544539;
      ec->m_cat = v5;
    }
    return ec;
  }
}
