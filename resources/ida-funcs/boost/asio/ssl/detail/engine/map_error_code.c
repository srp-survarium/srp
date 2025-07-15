const boost::system::error_code *__userpurge boost::asio::ssl::detail::engine::map_error_code@<eax>(
        boost::system::error_code *ec@<esi>,
        boost::asio::ssl::detail::engine *this)
{
  boost::system::error_code rhs; // [esp+8h] [ebp-Ch] BYREF

  rhs.m_cat = boost::asio::error::get_misc_category();
  rhs.m_val = 2;
  if ( !boost::system::operator!=(ec, &rhs)
    && (BIO_ctrl(this->ext_bio_, 13, 0, 0)
     || (!this->ssl_ || this->ssl_->version != 2) && (SSL_get_shutdown(this->ssl_) & 2) == 0) )
  {
    ec->m_cat = boost::asio::error::get_ssl_category();
    ec->m_val = 335544539;
  }
  return ec;
}
