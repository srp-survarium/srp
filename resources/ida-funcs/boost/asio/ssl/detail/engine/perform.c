int __userpurge boost::asio::ssl::detail::engine::perform@<eax>(
        boost::asio::ssl::detail::engine *this@<eax>,
        boost::system::error_code *ec@<esi>,
        int (__thiscall *op)(boost::asio::ssl::detail::engine *this, void *, unsigned int),
        void *data,
        unsigned int length,
        unsigned int *bytes_transferred)
{
  int v7; // ebx
  unsigned int v8; // eax
  const boost::system::error_category *ssl_category; // eax
  int v11; // edi
  unsigned int v12; // [esp+8h] [ebp-4h]
  int error; // [esp+18h] [ebp+Ch]
  int v14; // [esp+1Ch] [ebp+10h]

  v12 = BIO_ctrl_pending(this->ext_bio_);
  v7 = op(this, data, length);
  error = SSL_get_error(this->ssl_, v7);
  v14 = ERR_get_error();
  v8 = BIO_ctrl_pending(this->ext_bio_);
  if ( error == 1 )
  {
    ssl_category = boost::asio::error::get_ssl_category();
LABEL_3:
    ec->m_val = v14;
    goto LABEL_19;
  }
  if ( error == 5 )
  {
    ssl_category = boost::system::system_category();
    goto LABEL_3;
  }
  if ( v7 > 0 && bytes_transferred )
    *bytes_transferred = v7;
  if ( error == 3 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 0;
    return -1;
  }
  if ( v8 > v12 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 0;
    return 2 * (v7 > 0) - 1;
  }
  if ( error == 2 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 0;
    return -2;
  }
  if ( (SSL_get_shutdown(this->ssl_) & 2) != 0 )
  {
    v11 = 2;
    ssl_category = boost::asio::error::get_misc_category();
  }
  else
  {
    v11 = 0;
    ssl_category = boost::system::system_category();
  }
  ec->m_val = v11;
LABEL_19:
  ec->m_cat = ssl_category;
  return 0;
}
