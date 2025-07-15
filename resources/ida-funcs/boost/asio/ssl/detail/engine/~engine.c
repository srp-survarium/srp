void __thiscall boost::asio::ssl::detail::engine::~engine(boost::asio::ssl::detail::engine *this)
{
  void (__thiscall ***v2)(void *, int); // [esp+Ch] [ebp-4h]

  if ( SSL_get_ex_data(this->ssl_, 0) )
  {
    v2 = (void (__thiscall ***)(void *, int))SSL_get_ex_data(this->ssl_, 0);
    if ( v2 )
      (**v2)(v2, 1);
    SSL_set_ex_data(this->ssl_, 0, 0);
  }
  BIO_free(this->ext_bio_);
  SSL_free(this->ssl_);
}
