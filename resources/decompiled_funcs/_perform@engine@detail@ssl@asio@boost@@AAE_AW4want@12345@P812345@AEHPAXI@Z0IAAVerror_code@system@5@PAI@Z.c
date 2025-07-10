int __thiscall boost::asio::ssl::detail::engine::perform(
        boost::asio::ssl::detail::engine *this,
        int (__thiscall *op)(boost::asio::ssl::detail::engine *this, void *, unsigned int),
        void *data,
        unsigned int length,
        boost::system::error_code *ec,
        unsigned int *bytes_transferred)
{
  const boost::system::error_category *v7; // edx
  const boost::system::error_category *v8; // edx
  const boost::system::error_category *v9; // edx
  boost::asio::error::detail::misc_category *misc_category; // edx
  const boost::system::error_category *v12; // [esp+34h] [ebp-28h]
  boost::asio::error::detail::ssl_category *ssl_category; // [esp+44h] [ebp-18h]
  unsigned int sys_error; // [esp+48h] [ebp-14h]
  int result; // [esp+4Ch] [ebp-10h]
  unsigned int pending_output_after; // [esp+50h] [ebp-Ch]
  unsigned int pending_output_before; // [esp+54h] [ebp-8h]
  int ssl_error; // [esp+58h] [ebp-4h]

  pending_output_before = BIO_ctrl_pending(this->ext_bio_);
  result = op(this, data, length);
  ssl_error = SSL_get_error(this->ssl_, result);
  sys_error = ERR_get_error();
  pending_output_after = BIO_ctrl_pending(this->ext_bio_);
  if ( ssl_error == 1 )
  {
    ssl_category = boost::asio::error::get_ssl_category();
    ec->m_val = sys_error;
    ec->m_cat = ssl_category;
    return 0;
  }
  else if ( ssl_error == 5 )
  {
    v7 = boost::system::system_category();
    ec->m_val = sys_error;
    ec->m_cat = v7;
    return 0;
  }
  else
  {
    if ( result > 0 && bytes_transferred )
      *bytes_transferred = result;
    if ( ssl_error == 3 )
    {
      v12 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v12;
      return -1;
    }
    else if ( pending_output_after <= pending_output_before )
    {
      if ( ssl_error == 2 )
      {
        v9 = boost::system::system_category();
        ec->m_val = 0;
        ec->m_cat = v9;
        return -2;
      }
      else
      {
        if ( (SSL_get_shutdown(this->ssl_) & 2) != 0 )
        {
          misc_category = boost::asio::error::get_misc_category();
          ec->m_val = 2;
        }
        else
        {
          misc_category = (boost::asio::error::detail::misc_category *)boost::system::system_category();
          ec->m_val = 0;
        }
        ec->m_cat = misc_category;
        return 0;
      }
    }
    else
    {
      v8 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v8;
      return 2 * (result > 0) - 1;
    }
  }
}
