void __cdecl boost::checked_delete<boost::asio::ssl::detail::openssl_init_base::do_init>(
        boost::asio::ssl::detail::openssl_init_base::do_init *x)
{
  if ( x )
  {
    boost::asio::ssl::detail::openssl_init_base::do_init::~do_init(x);
    operator delete(x);
  }
}


void __cdecl boost::checked_delete<boost::asio::detail::win_mutex>(boost::asio::detail::win_mutex *x)
{
  if ( x )
  {
    DeleteCriticalSection(&x->crit_section_);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)x);
    operator delete(x);
  }
}
