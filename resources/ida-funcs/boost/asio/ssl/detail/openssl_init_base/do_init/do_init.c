void __thiscall boost::asio::ssl::detail::openssl_init_base::do_init::do_init(
        boost::asio::ssl::detail::openssl_init_base::do_init *this,
        boost::shared_ptr<boost::asio::detail::win_mutex> *__first)
{
  boost::shared_ptr<boost::asio::detail::win_mutex> *v2; // ebx
  Scaleform::GFx::AS2::BevelFilterObject *v3; // ecx
  unsigned int v4; // eax
  boost::shared_ptr<boost::asio::detail::win_mutex> *pi; // edx
  unsigned int v6; // ecx
  boost::shared_ptr<boost::asio::detail::win_mutex> *v7; // eax
  boost::shared_ptr<boost::asio::detail::win_mutex> *v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  boost::asio::detail::win_mutex *v11; // eax
  boost::asio::detail::win_mutex *v12; // eax
  boost::detail::shared_count *v13; // ecx
  boost::detail::sp_counted_base_vtbl **v14; // eax
  boost::detail::sp_counted_base *v15; // edx
  boost::detail::sp_counted_base *v16; // edx
  int v17; // eax
  unsigned int (__cdecl *func)(); // [esp+0h] [ebp-28h]
  unsigned int v19; // [esp+4h] [ebp-24h]
  bool v20; // [esp+8h] [ebp-20h]
  boost::shared_ptr<boost::asio::detail::win_mutex> v21; // [esp+14h] [ebp-14h] BYREF
  boost::shared_ptr<boost::asio::detail::win_mutex> __x; // [esp+1Ch] [ebp-Ch] BYREF

  v2 = __first;
  __first->px = 0;
  v2->pn.pi_ = 0;
  v2[1].px = 0;
  SSL_library_init(0);
  SSL_load_error_strings();
  OPENSSL_add_all_algorithms_noconf();
  __x.px = 0;
  __x.pn.pi_ = 0;
  v4 = CRYPTO_num_locks(v3);
  pi = (boost::shared_ptr<boost::asio::detail::win_mutex> *)v2->pn.pi_;
  v6 = ((char *)pi - (char *)v2->px) >> 3;
  if ( v4 >= v6 )
  {
    v8 = (boost::shared_ptr<boost::asio::detail::win_mutex> *)(v4 - v6);
    if ( v8 )
    {
      v9 = ((char *)v2[1].px - (char *)pi) >> 3;
      if ( v9 < (unsigned int)v8 )
        stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::_M_insert_overflow_aux(
          (stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *)v9,
          (int)v2,
          pi,
          &__x,
          v8,
          v19,
          v20);
      else
        stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::_M_fill_insert_aux(
          (stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *)v2,
          pi,
          (unsigned int)v8,
          &__x,
          (const stlp_std::__false_type *)&__first + 3);
    }
  }
  else
  {
    v7 = (boost::shared_ptr<boost::asio::detail::win_mutex> *)((char *)v2->px + 8 * v4);
    if ( v7 != pi )
      stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::_M_erase(
        (stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *)v6,
        v2,
        v7,
        (const stlp_std::__false_type *)v2->pn.pi_);
  }
  boost::detail::shared_count::~shared_count((boost::detail::shared_count *)v6, (volatile signed __int32 **)&__x.pn);
  v10 = (char *)v2->pn.pi_ - (char *)v2->px;
  __first = 0;
  if ( v10 >> 3 )
  {
    do
    {
      v11 = (boost::asio::detail::win_mutex *)operator new(0x18u);
      if ( v11 )
        boost::asio::detail::win_mutex::win_mutex((boost::asio::detail::win_mutex *)func, v11);
      else
        v12 = 0;
      __x.pn.pi_ = (boost::detail::sp_counted_base *)((char *)v2->px + 8 * (_DWORD)__first);
      boost::shared_ptr<boost::asio::detail::win_mutex>::shared_ptr<boost::asio::detail::win_mutex>(&v21, v12);
      v13 = (boost::detail::shared_count *)__x.pn.pi_;
      v15 = (boost::detail::sp_counted_base *)*v14;
      *v14 = __x.pn.pi_->__vftable;
      v13->pi_ = v15;
      v16 = v13[1].pi_;
      v13[1].pi_ = (boost::detail::sp_counted_base *)v14[1];
      v14[1] = (boost::detail::sp_counted_base_vtbl *)v16;
      boost::detail::shared_count::~shared_count(v13, (volatile signed __int32 **)&v21.pn);
      v17 = (char *)v2->pn.pi_ - (char *)v2->px;
      __first = (boost::shared_ptr<boost::asio::detail::win_mutex> *)((char *)__first + 1);
    }
    while ( (unsigned int)__first < v17 >> 3 );
  }
  CRYPTO_set_locking_callback((void (__cdecl *)(int, int, const char *, int))boost::asio::ssl::detail::openssl_init_base::do_init::openssl_locking_func);
  CRYPTO_set_id_callback(boost::asio::ssl::detail::openssl_init_base::do_init::openssl_id_func);
}
