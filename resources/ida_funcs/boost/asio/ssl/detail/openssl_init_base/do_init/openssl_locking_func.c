void __cdecl boost::asio::ssl::detail::openssl_init_base::do_init::openssl_locking_func(char mode, int n)
{
  boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> *v2; // [esp+10h] [ebp-38h]
  boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> *v3; // [esp+2Ch] [ebp-1Ch]
  boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> v4; // [esp+38h] [ebp-10h] BYREF
  boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> result; // [esp+40h] [ebp-8h] BYREF

  if ( (mode & 1) != 0 )
  {
    v3 = boost::asio::ssl::detail::openssl_init_base::instance(&result);
    EnterCriticalSection(&v3->px->mutexes_._M_impl._M_start[n].px->crit_section_);
    if ( result.pn.pi_ )
      boost::detail::sp_counted_base::release(result.pn.pi_);
  }
  else
  {
    v2 = boost::asio::ssl::detail::openssl_init_base::instance(&v4);
    LeaveCriticalSection(&v2->px->mutexes_._M_impl._M_start[n].px->crit_section_);
    if ( v4.pn.pi_ )
      boost::detail::sp_counted_base::release(v4.pn.pi_);
  }
}
