void __cdecl dynamic_atexit_destructor_for__boost::asio::ssl::detail::openssl_init_1_::instance___()
{
  if ( boost::asio::ssl::detail::openssl_init<1>::instance_.ref_.pn.pi_ )
    boost::detail::sp_counted_base::release(boost::asio::ssl::detail::openssl_init<1>::instance_.ref_.pn.pi_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&boost::asio::ssl::detail::openssl_init<1>::instance_);
}
