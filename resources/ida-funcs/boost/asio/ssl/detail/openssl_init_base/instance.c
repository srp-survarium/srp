boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> *__cdecl boost::asio::ssl::detail::openssl_init_base::instance(
        boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> *result)
{
  boost::shared_ptr<boost::asio::detail::win_mutex> *v1; // eax
  boost::asio::ssl::detail::openssl_init_base::do_init *v2; // eax
  boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> *v3; // eax
  boost::detail::sp_counted_base *pi; // ecx
  boost::asio::ssl::detail::openssl_init_base::do_init *v5; // [esp-4h] [ebp-4h]
  boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> *savedregs; // [esp+0h] [ebp+0h]

  if ( (`boost::asio::ssl::detail::openssl_init_base::instance'::`2'::`local static guard' & 1) == 0 )
  {
    `boost::asio::ssl::detail::openssl_init_base::instance'::`2'::`local static guard' |= 1u;
    v1 = (boost::shared_ptr<boost::asio::detail::win_mutex> *)operator new(0xCu);
    if ( v1 )
      boost::asio::ssl::detail::openssl_init_base::do_init::do_init(v5, v1);
    else
      v2 = 0;
    boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init>::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init>(
      v2,
      savedregs);
    atexit((int (__cdecl *)())`boost::asio::ssl::detail::openssl_init_base::instance'::`2'::`dynamic atexit destructor for 'init'');
  }
  v3 = result;
  result->px = `boost::asio::ssl::detail::openssl_init_base::instance'::`2'::init.px;
  pi = `boost::asio::ssl::detail::openssl_init_base::instance'::`2'::init.pn.pi_;
  result->pn.pi_ = `boost::asio::ssl::detail::openssl_init_base::instance'::`2'::init.pn.pi_;
  if ( pi )
    _InterlockedExchangeAdd(&pi->use_count_, 1u);
  return v3;
}
