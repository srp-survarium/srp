void __thiscall boost::detail::shared_count::shared_count(
        boost::detail::shared_count *this,
        boost::asio::detail::win_mutex *p)
{
  const std::exception *v2; // eax
  boost::detail::sp_counted_base *v3; // [esp+0h] [ebp-20h]
  std::bad_alloc v5; // [esp+10h] [ebp-10h] BYREF
  boost::detail::sp_counted_base *v6; // [esp+1Ch] [ebp-4h]

  this->pi_ = 0;
  v6 = (boost::detail::sp_counted_base *)operator new(0x10u);
  if ( v6 )
  {
    v6->__vftable = (boost::detail::sp_counted_base_vtbl *)&boost::detail::sp_counted_base::`vftable';
    v6->use_count_ = 1;
    v6->weak_count_ = 1;
    v6->__vftable = (boost::detail::sp_counted_base_vtbl *)&boost::detail::sp_counted_impl_p<boost::asio::detail::win_mutex>::`vftable';
    v6[1].__vftable = (boost::detail::sp_counted_base_vtbl *)p;
    v3 = v6;
  }
  else
  {
    v3 = 0;
  }
  this->pi_ = v3;
  if ( !this->pi_ )
  {
    boost::checked_delete<boost::asio::detail::win_mutex>(p);
    std::bad_alloc::bad_alloc(&v5);
    boost::throw_exception(v2);
    std::bad_alloc::~bad_alloc(&v5);
  }
}
