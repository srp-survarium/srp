void *__usercall boost::asio::ssl::detail::openssl_init_base::do_init::`scalar deleting destructor'@<eax>(
        boost::asio::ssl::detail::openssl_init_base::do_init *this@<ecx>,
        void *a2@<eax>,
        int a3@<edi>)
{
  stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *v4; // ecx

  CRYPTO_set_id_callback(0);
  CRYPTO_set_locking_callback(0);
  ERR_free_strings(a3);
  ERR_remove_state(a3);
  EVP_cleanup();
  CRYPTO_cleanup_all_ex_data(a3);
  CONF_modules_unload(1);
  ENGINE_cleanup();
  stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::~_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>(
    v4,
    (int)a2);
  operator delete(a2);
  return a2;
}
