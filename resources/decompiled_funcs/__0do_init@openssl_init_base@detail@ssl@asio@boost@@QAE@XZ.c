void __thiscall boost::asio::ssl::detail::openssl_init_base::do_init::do_init(
        boost::asio::ssl::detail::openssl_init_base::do_init *this)
{
  boost::asio::detail::win_mutex *v1; // eax
  Scaleform::GFx::AS2::ObjectInterface::ObjectType __new_size; // [esp+1A0h] [ebp-2Ch]
  boost::asio::detail::win_mutex *v4; // [esp+1B8h] [ebp-14h]
  boost::shared_ptr<boost::asio::detail::win_mutex> __x; // [esp+1BCh] [ebp-10h] BYREF
  vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> __a; // [esp+1C7h] [ebp-5h] BYREF
  unsigned int i; // [esp+1C8h] [ebp-4h]

  this->mutexes_._M_impl._M_start = 0;
  this->mutexes_._M_impl._M_finish = 0;
  boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>(
    (stlp_std::priv::_STLP_alloc_proxy<vostok::sound::search::vertex_id_type *,vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)&this->mutexes_._M_impl._M_end_of_storage,
    &__a,
    0);
  SSL_library_init();
  SSL_load_error_strings();
  OPENSSL_add_all_algorithms_noconf();
  __x.px = 0;
  __x.pn.pi_ = 0;
  __new_size = CRYPTO_num_locks((Scaleform::GFx::AS2::BevelFilterObject *)&__x.pn);
  stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::resize(
    &this->mutexes_._M_impl,
    __new_size,
    &__x);
  if ( __x.pn.pi_ )
    boost::detail::sp_counted_base::release(__x.pn.pi_);
  for ( i = 0; i < this->mutexes_._M_impl._M_finish - this->mutexes_._M_impl._M_start; ++i )
  {
    v4 = (boost::asio::detail::win_mutex *)operator new(0x18u);
    if ( v4 )
    {
      boost::asio::detail::win_mutex::win_mutex(v4);
      boost::shared_ptr<boost::asio::detail::win_mutex>::reset<boost::asio::detail::win_mutex>(
        &this->mutexes_._M_impl._M_start[i],
        v1);
    }
    else
    {
      boost::shared_ptr<boost::asio::detail::win_mutex>::reset<boost::asio::detail::win_mutex>(
        &this->mutexes_._M_impl._M_start[i],
        0);
    }
  }
  CRYPTO_set_locking_callback(boost::asio::ssl::detail::openssl_init_base::do_init::openssl_locking_func);
  CRYPTO_set_id_callback(boost::asio::ssl::detail::openssl_init_base::do_init::openssl_id_func);
}
