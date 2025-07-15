void __userpurge boost::asio::ssl::detail::stream_core::stream_core(
        boost::asio::ssl::detail::stream_core *this@<ecx>,
        int a2@<eax>,
        int *a3@<edi>,
        ssl_ctx_st *context,
        boost::asio::io_service *io_service)
{
  stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *v6; // ecx
  stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *v7; // ecx
  int v8; // edi
  int v9; // edi
  boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *v10; // ecx
  const boost::posix_time::time_duration *v11; // eax
  const boost::posix_time::time_duration *v12; // ebx
  boost::gregorian::date *v13; // ecx
  const boost::gregorian::date *v14; // eax
  boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *v15; // ecx
  const unsigned __int8 *v16; // [esp+0h] [ebp-20h]
  const unsigned __int8 *v17; // [esp+0h] [ebp-20h]
  const stlp_std::allocator<unsigned char> *v18; // [esp+4h] [ebp-1Ch]
  const stlp_std::allocator<unsigned char> *v19; // [esp+4h] [ebp-1Ch]
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> v20; // [esp+10h] [ebp-10h] BYREF
  boost::posix_time::time_duration time_of_day; // [esp+18h] [ebp-8h] BYREF

  boost::asio::ssl::detail::engine::engine(&this->engine_, a2, a3, context);
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
    io_service,
    (boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *)(a2 + 8));
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
    io_service,
    (boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *)(a2 + 48));
  HIBYTE(io_service) = 0;
  stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::vector<unsigned char,stlp_std::allocator<unsigned char>>(
    v6,
    a2 + 88,
    (unsigned __int8 *)&io_service + 3,
    v16,
    v18);
  v7 = *(stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > **)(a2 + 88);
  v8 = *(_DWORD *)(a2 + 92) - (_DWORD)v7;
  *(_DWORD *)(a2 + 100) = *(_DWORD *)(a2 + 92) != (_DWORD)v7 ? v7 : 0;
  *(_DWORD *)(a2 + 104) = v8;
  HIBYTE(io_service) = 0;
  stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::vector<unsigned char,stlp_std::allocator<unsigned char>>(
    v7,
    a2 + 108,
    (unsigned __int8 *)&io_service + 3,
    v17,
    v19);
  v9 = *(_DWORD *)(a2 + 112) - *(_DWORD *)(a2 + 108);
  *(_DWORD *)(a2 + 120) = *(_DWORD *)(a2 + 112) != *(_DWORD *)(a2 + 108) ? *(_DWORD *)(a2 + 108) : 0;
  *(_DWORD *)(a2 + 124) = v9;
  *(_DWORD *)(a2 + 128) = 0;
  *(_DWORD *)(a2 + 132) = 0;
  time_of_day.ticks_.value_ = 0x8000000000000000uLL;
  io_service = 0;
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>(
    &v20,
    (const boost::gregorian::date *)&io_service,
    &time_of_day);
  boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::expires_at(
    v10,
    a2 + 8,
    (const boost::posix_time::ptime *)&v20);
  boost::posix_time::time_duration::time_duration((boost::posix_time::time_duration *)1, &time_of_day);
  v12 = v11;
  boost::gregorian::date::date(v13, (int *)&io_service, neg_infin);
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>(
    &v20,
    v14,
    v12);
  boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::expires_at(
    v15,
    a2 + 48,
    (const boost::posix_time::ptime *)&v20);
}
