boost::system::error_code *__thiscall boost::asio::detail::win_iocp_socket_service_base::cancel(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::system::error_code *result,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        boost::system::error_code *ec)
{
  const boost::system::error_category *m_cat; // eax
  HMODULE ModuleHandleA; // eax
  const boost::system::error_category *v7; // ecx
  const boost::system::error_category *v9; // [esp+64h] [ebp-44h]
  const boost::system::error_category *v10; // [esp+74h] [ebp-34h]
  const boost::system::error_category *v11; // [esp+7Ch] [ebp-2Ch]
  const boost::system::error_category *v12; // [esp+84h] [ebp-24h]
  const boost::system::error_category *v13; // [esp+8Ch] [ebp-1Ch]
  boost::asio::detail::select_reactor *r; // [esp+90h] [ebp-18h]
  DWORD last_error; // [esp+94h] [ebp-14h]
  int (__stdcall *cancel_io_ex_ptr)(); // [esp+A4h] [ebp-4h]

  if ( impl->socket_ == -1 )
  {
    v10 = boost::system::system_category();
    ec->m_val = 10009;
    ec->m_cat = v10;
    m_cat = ec->m_cat;
    result->m_val = ec->m_val;
    result->m_cat = m_cat;
    return result;
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(&stru_984D24.m_working_macro_list.m_buffer[1].m_store[392]);
    cancel_io_ex_ptr = GetProcAddress(ModuleHandleA, &stru_984D24.m_working_macro_list.m_buffer[1].m_store[380]);
    if ( cancel_io_ex_ptr )
    {
      if ( ((int (__stdcall *)(unsigned int, _DWORD))cancel_io_ex_ptr)(impl->socket_, 0) )
      {
        v11 = boost::system::system_category();
        ec->m_val = 0;
        ec->m_cat = v11;
      }
      else
      {
        last_error = GetLastError();
        if ( last_error == 1168 )
        {
          v13 = boost::system::system_category();
          ec->m_val = 0;
          ec->m_cat = v13;
        }
        else
        {
          v12 = boost::system::system_category();
          ec->m_val = last_error;
          ec->m_cat = v12;
        }
      }
    }
    else
    {
      v9 = boost::system::system_category();
      ec->m_val = 10045;
      ec->m_cat = v9;
    }
    if ( !ec->m_val )
    {
      r = (boost::asio::detail::select_reactor *)InterlockedCompareExchange((volatile LONG *)&this->reactor_, 0, 0);
      if ( r )
        boost::asio::detail::select_reactor::cancel_ops(r, impl->socket_, &impl->reactor_data_);
    }
    v7 = ec->m_cat;
    result->m_val = ec->m_val;
    result->m_cat = v7;
    return result;
  }
}
