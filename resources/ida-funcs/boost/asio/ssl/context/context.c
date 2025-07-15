void __thiscall boost::asio::ssl::context::context(
        boost::asio::ssl::context *this,
        boost::asio::ssl::context_base::method m)
{
  const ssl_method_st *v2; // eax
  const ssl_method_st *v3; // eax
  const ssl_method_st *v4; // eax
  const ssl_method_st *v5; // eax
  const ssl_method_st *v6; // eax
  const ssl_method_st *v7; // eax
  const ssl_method_st *v8; // eax
  const ssl_method_st *v9; // eax
  const ssl_method_st *v10; // eax
  const ssl_method_st *v11; // eax
  const ssl_method_st *v12; // eax
  const ssl_method_st *v13; // eax
  boost::asio::error::detail::ssl_category *ssl_category; // [esp+160h] [ebp-20h]
  unsigned __int8 dst[4]; // [esp+174h] [ebp-Ch] BYREF
  boost::system::error_code ec; // [esp+178h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)(&this->gap0 + 1));
  this->handle_ = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->init_);
  boost::asio::ssl::detail::openssl_init_base::instance(&this->init_.ref_);
  *(_DWORD *)dst = &boost::asio::ssl::detail::openssl_init<1>::instance_;
  memmove(dst, dst, 4u);
  switch ( m )
  {
    case sslv2:
      v2 = SSLv2_method();
      this->handle_ = SSL_CTX_new(v2);
      break;
    case sslv2_client:
      v3 = SSLv2_client_method();
      this->handle_ = SSL_CTX_new(v3);
      break;
    case sslv2_server:
      v4 = SSLv2_server_method();
      this->handle_ = SSL_CTX_new(v4);
      break;
    case sslv3:
      v5 = SSLv3_method();
      this->handle_ = SSL_CTX_new(v5);
      break;
    case sslv3_client:
      v6 = SSLv3_client_method();
      this->handle_ = SSL_CTX_new(v6);
      break;
    case sslv3_server:
      v7 = SSLv3_server_method();
      this->handle_ = SSL_CTX_new(v7);
      break;
    case tlsv1:
      v8 = TLSv1_method();
      this->handle_ = SSL_CTX_new(v8);
      break;
    case tlsv1_client:
      v9 = TLSv1_client_method();
      this->handle_ = SSL_CTX_new(v9);
      break;
    case tlsv1_server:
      v10 = TLSv1_server_method();
      this->handle_ = SSL_CTX_new(v10);
      break;
    case sslv23:
      v11 = SSLv23_method();
      this->handle_ = SSL_CTX_new(v11);
      break;
    case sslv23_client:
      v12 = SSLv23_client_method();
      this->handle_ = SSL_CTX_new(v12);
      break;
    case sslv23_server:
      v13 = SSLv23_server_method();
      this->handle_ = SSL_CTX_new(v13);
      break;
    default:
      this->handle_ = SSL_CTX_new(0);
      break;
  }
  if ( !this->handle_ )
  {
    ssl_category = boost::asio::error::get_ssl_category();
    ec.m_val = ERR_get_error();
    ec.m_cat = ssl_category;
    if ( (ec.m_val != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
      boost::asio::detail::do_throw_error(&ec, "context");
  }
}
