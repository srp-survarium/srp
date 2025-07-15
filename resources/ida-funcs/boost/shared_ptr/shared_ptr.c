void __usercall boost::shared_ptr<boost::asio::detail::win_mutex>::shared_ptr<boost::asio::detail::win_mutex>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *this@<esi>,
        boost::asio::detail::win_mutex *p@<edi>)
{
  boost::detail::sp_counted_base *v2; // eax
  int v3; // ecx
  const std::exception *v4; // eax
  int v5; // [esp-4h] [ebp-14h]
  std::bad_alloc v6; // [esp+4h] [ebp-Ch] BYREF

  this->px = p;
  this->pn.pi_ = 0;
  v2 = (boost::detail::sp_counted_base *)operator new(0x10u);
  v3 = v5;
  if ( v2 )
  {
    v3 = 1;
    v2->use_count_ = 1;
    v2->weak_count_ = 1;
    v2->__vftable = (boost::detail::sp_counted_base_vtbl *)&boost::detail::sp_counted_impl_p<boost::asio::detail::win_mutex>::`vftable';
    v2[1].__vftable = (boost::detail::sp_counted_base_vtbl *)p;
  }
  else
  {
    v2 = 0;
  }
  this->pn.pi_ = v2;
  if ( !v2 )
  {
    if ( p )
    {
      DeleteCriticalSection(&p->crit_section_);
      operator delete(p);
    }
    std::bad_alloc::bad_alloc(&v6);
    boost::throw_exception(v4);
    v6.__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
    std::exception::~exception(&v6);
  }
  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)v3);
}


void __usercall boost::shared_ptr<boost::asio::detail::win_mutex>::shared_ptr<boost::asio::detail::win_mutex>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *this@<ecx>,
        boost::asio::detail::win_mutex **a2@<eax>)
{
  boost::detail::sp_counted_base *pi; // ecx

  *a2 = this->px;
  pi = this->pn.pi_;
  a2[1] = (boost::asio::detail::win_mutex *)pi;
  if ( pi )
    _InterlockedExchangeAdd(&pi->use_count_, 1u);
}
