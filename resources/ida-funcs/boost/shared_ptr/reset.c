void __usercall boost::shared_ptr<void>::reset(boost::shared_ptr<void> *this@<ecx>, _DWORD *a2@<eax>)
{
  volatile signed __int32 *v2; // ecx
  volatile signed __int32 *v3; // [esp+4h] [ebp-4h] BYREF

  *a2 = 0;
  v2 = (volatile signed __int32 *)a2[1];
  a2[1] = 0;
  v3 = v2;
  boost::detail::shared_count::~shared_count((boost::detail::shared_count *)v2, &v3);
}


void __userpurge boost::shared_ptr<void>::reset<void,boost::asio::detail::socket_ops::noop_deleter>(
        boost::shared_ptr<void> *this@<ecx>,
        int *a2@<esi>,
        void *p,
        boost::asio::detail::socket_ops::noop_deleter d)
{
  boost::detail::shared_count *v4; // eax
  int v5; // ecx
  const std::exception *v6; // eax
  int v7; // ecx
  boost::detail::shared_count *v8; // eax
  boost::detail::shared_count *v9; // ecx
  int v10; // [esp-4h] [ebp-20h]
  std::bad_alloc v11; // [esp+4h] [ebp-18h] BYREF
  int v12; // [esp+10h] [ebp-Ch]
  boost::detail::shared_count *v13; // [esp+14h] [ebp-8h] BYREF

  v12 = 0;
  v13 = 0;
  v4 = (boost::detail::shared_count *)operator new(0x14u);
  v5 = v10;
  if ( v4 )
  {
    v5 = 1;
    v4[1].pi_ = (boost::detail::sp_counted_base *)1;
    v4[2].pi_ = (boost::detail::sp_counted_base *)1;
    v4->pi_ = (boost::detail::sp_counted_base *)&boost::detail::sp_counted_impl_pd<void *,boost::asio::detail::socket_ops::noop_deleter>::`vftable';
    v4[3].pi_ = 0;
  }
  else
  {
    v4 = 0;
  }
  v13 = v4;
  if ( !v4 )
  {
    std::bad_alloc::bad_alloc(&v11);
    boost::throw_exception(v6);
    v11.__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
    std::exception::~exception(&v11);
  }
  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)v5);
  v7 = *a2;
  *a2 = v12;
  v8 = (boost::detail::shared_count *)a2[1];
  v12 = v7;
  v9 = v13;
  v13 = v8;
  a2[1] = (int)v9;
  boost::detail::shared_count::~shared_count(v9, (volatile signed __int32 **)&v13);
}
