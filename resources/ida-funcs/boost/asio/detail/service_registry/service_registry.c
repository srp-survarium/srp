void __userpurge boost::asio::detail::service_registry::service_registry(
        boost::asio::detail::service_registry *this@<ecx>,
        boost::asio::detail::win_mutex *a2@<edi>,
        _RTL_CRITICAL_SECTION_DEBUG *o,
        boost::asio::detail::win_iocp_io_service *__formal,
        unsigned int arg)
{
  boost::asio::detail::win_iocp_io_service *v5; // esi
  int v6; // eax
  boost::asio::detail::win_mutex *v7; // [esp-4h] [ebp-Ch]

  boost::asio::detail::win_mutex::win_mutex(&this->mutex_, a2);
  a2[1].crit_section_.DebugInfo = o;
  v5 = (boost::asio::detail::win_iocp_io_service *)operator new(0x54u);
  if ( v5 )
    boost::asio::detail::win_iocp_io_service::win_iocp_io_service(v5, (boost::asio::io_service *)o, v7, (DWORD)__formal);
  else
    v6 = 0;
  a2[1].crit_section_.LockCount = v6;
  *(_DWORD *)(v6 + 4) = &boost::asio::detail::typeid_wrapper<boost::asio::detail::win_iocp_io_service> `RTTI Type Descriptor';
  *(_DWORD *)(v6 + 8) = 0;
  *(_DWORD *)(a2[1].crit_section_.LockCount + 16) = 0;
}
