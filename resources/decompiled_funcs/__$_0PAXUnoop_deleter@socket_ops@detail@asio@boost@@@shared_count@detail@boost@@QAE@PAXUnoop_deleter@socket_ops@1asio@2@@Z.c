void __thiscall boost::detail::shared_count::shared_count(
        boost::detail::shared_count *this,
        boost::detail::sp_counted_base_vtbl *p,
        boost::asio::detail::socket_ops::noop_deleter d)
{
  const std::exception *v3; // eax
  boost::detail::sp_counted_base *v4; // [esp+0h] [ebp-18h]
  std::bad_alloc v6; // [esp+8h] [ebp-10h] BYREF
  boost::detail::sp_counted_base *v7; // [esp+14h] [ebp-4h]

  this->pi_ = 0;
  v7 = (boost::detail::sp_counted_base *)operator new(0x14u);
  if ( v7 )
  {
    v7->__vftable = (boost::detail::sp_counted_base_vtbl *)&boost::detail::sp_counted_base::`vftable';
    v7->use_count_ = 1;
    v7->weak_count_ = 1;
    v7->__vftable = (boost::detail::sp_counted_base_vtbl *)&boost::detail::sp_counted_impl_pd<void *,boost::asio::detail::socket_ops::noop_deleter>::`vftable';
    v7[1].__vftable = p;
    v4 = v7;
  }
  else
  {
    v4 = 0;
  }
  this->pi_ = v4;
  if ( !this->pi_ )
  {
    std::bad_alloc::bad_alloc(&v6);
    boost::throw_exception(v3);
    std::bad_alloc::~bad_alloc(&v6);
  }
}
