void __thiscall boost::asio::ssl::detail::openssl_init_base::do_init::~do_init(
        boost::asio::ssl::detail::openssl_init_base::do_init *this)
{
  CRYPTO_set_id_callback(0);
  CRYPTO_set_locking_callback(0);
  ERR_free_strings();
  ERR_remove_state(0);
  EVP_cleanup();
  CRYPTO_cleanup_all_ex_data();
  CONF_modules_unload(1);
  ENGINE_cleanup();
  stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::~_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>(&this->mutexes_._M_impl);
}
