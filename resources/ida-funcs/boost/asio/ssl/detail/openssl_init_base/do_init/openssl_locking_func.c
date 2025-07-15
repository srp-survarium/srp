void __cdecl boost::asio::ssl::detail::openssl_init_base::do_init::openssl_locking_func(char mode, int n)
{
  boost::detail::shared_count *v2; // ecx
  boost::asio::detail::win_mutex *px; // [esp-4h] [ebp-Ch]
  boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> result; // [esp+0h] [ebp-8h] BYREF

  px = boost::asio::ssl::detail::openssl_init_base::instance(&result)->px->mutexes_._M_impl._M_start[n].px;
  if ( (mode & 1) != 0 )
    EnterCriticalSection(&px->crit_section_);
  else
    LeaveCriticalSection(&px->crit_section_);
  boost::detail::shared_count::~shared_count(v2, (volatile signed __int32 **)&result.pn);
}
