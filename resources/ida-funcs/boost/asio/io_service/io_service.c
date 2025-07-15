void __usercall boost::asio::io_service::io_service(
        boost::asio::io_service *this@<ecx>,
        _RTL_CRITICAL_SECTION_DEBUG *a2@<esi>)
{
  boost::asio::detail::win_mutex *v2; // eax
  int v3; // eax
  boost::asio::detail::service_registry *v4; // [esp-4h] [ebp-8h]
  unsigned int v5; // [esp+0h] [ebp-4h]

  boost::asio::detail::winsock_init<2,0>::winsock_init<2,0>(&this->init_, (bool)a2, 1);
  v2 = (boost::asio::detail::win_mutex *)operator new(0x20u);
  if ( v2 )
    boost::asio::detail::service_registry::service_registry(
      v4,
      v2,
      a2,
      (boost::asio::detail::win_iocp_io_service *)0xFFFFFFFF,
      v5);
  else
    v3 = 0;
  a2->CriticalSection = (_RTL_CRITICAL_SECTION *)v3;
  a2->ProcessLocksList.Flink = *(_LIST_ENTRY **)(v3 + 28);
}
