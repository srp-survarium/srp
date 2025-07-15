boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> *__cdecl boost::asio::ssl::detail::openssl_init_base::instance(
        boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> *result)
{
  boost::asio::ssl::detail::openssl_init_base::do_init *v1; // eax
  boost::asio::ssl::detail::openssl_init_base::do_init *p; // [esp+8h] [ebp-74h]
  boost::asio::ssl::detail::openssl_init_base::do_init *v4; // [esp+78h] [ebp-4h]

  if ( (`boost::asio::ssl::detail::openssl_init_base::instance'::`2'::`local static guard' & 1) == 0 )
  {
    `boost::asio::ssl::detail::openssl_init_base::instance'::`2'::`local static guard' |= 1u;
    v4 = (boost::asio::ssl::detail::openssl_init_base::do_init *)operator new(0xCu);
    if ( v4 )
    {
      boost::asio::ssl::detail::openssl_init_base::do_init::do_init(v4);
      p = v1;
    }
    else
    {
      p = 0;
    }
    `boost::asio::ssl::detail::openssl_init_base::instance'::`2'::init.px = p;
    boost::detail::shared_count::shared_count(&`boost::asio::ssl::detail::openssl_init_base::instance'::`2'::init.pn, p);
    boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>();
    atexit(`boost::asio::ssl::detail::openssl_init_base::instance'::`2'::`dynamic atexit destructor for 'init'');
  }
  *result = `boost::asio::ssl::detail::openssl_init_base::instance'::`2'::init;
  if ( result->pn.pi_ )
    _InterlockedExchangeAdd(&result->pn.pi_->use_count_, 1u);
  return result;
}
