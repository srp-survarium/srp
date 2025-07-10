void __thiscall boost::detail::shared_count::shared_count(
        boost::detail::shared_count *this,
        boost::detail::sp_counted_base_vtbl *p)
{
  const std::exception *v2; // eax
  boost::detail::sp_counted_base *v3; // [esp+0h] [ebp-50h]
  std::bad_alloc v5; // [esp+40h] [ebp-10h] BYREF
  boost::detail::sp_counted_base *v6; // [esp+4Ch] [ebp-4h]

  this->pi_ = 0;
  v6 = (boost::detail::sp_counted_base *)operator new(0x10u);
  if ( v6 )
  {
    v6->__vftable = (boost::detail::sp_counted_base_vtbl *)&boost::detail::sp_counted_base::`vftable';
    v6->use_count_ = 1;
    v6->weak_count_ = 1;
    v6->__vftable = (boost::detail::sp_counted_base_vtbl *)&boost::detail::sp_counted_impl_p<boost::asio::ssl::detail::openssl_init_base::do_init>::`vftable';
    v6[1].__vftable = p;
    v3 = v6;
  }
  else
  {
    v3 = 0;
  }
  this->pi_ = v3;
  if ( !this->pi_ )
  {
    boost::checked_delete<boost::asio::ssl::detail::openssl_init_base::do_init>((boost::asio::ssl::detail::openssl_init_base::do_init *)p);
    std::bad_alloc::bad_alloc(&v5);
    boost::throw_exception(v2);
    std::bad_alloc::~bad_alloc(&v5);
  }
}
