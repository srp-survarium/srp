boost::system::error_code *__userpurge boost::asio::detail::win_iocp_socket_service_base::cancel@<eax>(
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl@<eax>,
        boost::system::error_code *ec@<esi>,
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::system::error_code *a4)
{
  const boost::system::error_category *v5; // eax
  boost::system::error_code *result; // eax
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *CancelIoEx)(HANDLE, LPOVERLAPPED); // eax
  DWORD LastError; // ebx
  _RTL_CRITICAL_SECTION *v10; // ebx
  stlp_std::priv::_List_node_base v11; // [esp+8h] [ebp-8h] BYREF
  stlp_std::priv::_List_node_base *socket; // [esp+18h] [ebp+8h]

  if ( impl->socket_ == -1 )
  {
    v5 = boost::system::system_category();
    ec->m_cat = v5;
    a4->m_cat = v5;
    ec->m_val = 10009;
    a4->m_val = 10009;
    return a4;
  }
  else
  {
    ModuleHandleA = GetModuleHandleA("KERNEL32");
    CancelIoEx = (BOOL (__stdcall *)(HANDLE, LPOVERLAPPED))GetProcAddress(ModuleHandleA, "CancelIoEx");
    LastError = 0;
    if ( CancelIoEx )
    {
      if ( !CancelIoEx((HANDLE)impl->socket_, 0) )
      {
        LastError = GetLastError();
        if ( LastError == 1168 )
          LastError = 0;
      }
    }
    else
    {
      LastError = 10045;
    }
    ec->m_cat = boost::system::system_category();
    ec->m_val = LastError;
    if ( !LastError )
    {
      v10 = (_RTL_CRITICAL_SECTION *)InterlockedCompareExchange((volatile LONG *)&this->reactor_, 0, 0);
      if ( v10 )
      {
        socket = (stlp_std::priv::_List_node_base *)impl->socket_;
        EnterCriticalSection(v10 + 1);
        v11._M_prev = (stlp_std::priv::_List_node_base *)boost::system::system_category();
        v11._M_next = (stlp_std::priv::_List_node_base *)995;
        boost::asio::detail::select_reactor::cancel_ops_unlocked(
          (boost::asio::detail::select_reactor *)0x3E3,
          (int)v10,
          socket,
          &v11);
        LeaveCriticalSection(v10 + 1);
      }
    }
    result = a4;
    *a4 = *ec;
  }
  return result;
}
