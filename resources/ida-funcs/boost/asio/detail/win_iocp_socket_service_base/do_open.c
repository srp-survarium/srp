boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *__thiscall boost::asio::detail::win_iocp_socket_service_base::do_open(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::system::error_code *result,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        int family,
        int type,
        void *protocol,
        boost::system::error_code *ec,
        int FileHandle)
{
  unsigned int *v8; // ebx
  boost::asio::error::detail::misc_category *misc_category; // eax
  boost::shared_ptr<void> *v11; // ecx
  boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *v12; // edi
  const struct boost::system::error_category *v13; // eax
  DWORD LastError; // esi
  int v15; // eax
  boost::asio::detail::socket_ops::noop_deleter v16; // [esp+0h] [ebp-14h]

  v8 = (unsigned int *)FileHandle;
  if ( *(_DWORD *)family == -1 )
  {
    FileHandle = boost::asio::detail::socket_ops::socket(
                   (boost::system::error_code *)FileHandle,
                   type,
                   (int)protocol,
                   (int)ec);
    if ( FileHandle == -1 )
    {
      v12 = impl;
      impl->socket_ = *v8;
      v13 = (const struct boost::system::error_category *)v8[1];
    }
    else
    {
      LastError = 0;
      if ( !CreateIoCompletionPort((HANDLE)FileHandle, result->m_cat[5].__vftable, 0, 0) )
        LastError = GetLastError();
      v8[1] = (unsigned int)boost::system::system_category();
      v11 = (boost::shared_ptr<void> *)v8[1];
      *v8 = LastError;
      if ( (LastError != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      {
        v12 = impl;
        impl->socket_ = LastError;
        v13 = (const struct boost::system::error_category *)v11;
      }
      else
      {
        v15 = FileHandle;
        FileHandle = -1;
        *(_DWORD *)family = v15;
        if ( protocol == (void *)1 )
        {
          *(_BYTE *)(family + 4) = 16;
        }
        else if ( protocol == (void *)2 )
        {
          *(_BYTE *)(family + 4) = 32;
        }
        else
        {
          *(_BYTE *)(family + 4) = 0;
        }
        LOBYTE(protocol) = 0;
        boost::shared_ptr<void>::reset<void,boost::asio::detail::socket_ops::noop_deleter>(
          v11,
          (int *)(family + 8),
          protocol,
          v16);
        v13 = boost::system::system_category();
        v12 = impl;
        *v8 = 0;
        v8[1] = (unsigned int)v13;
        impl->socket_ = 0;
      }
    }
    *(_DWORD *)&v12->state_ = v13;
    boost::asio::detail::socket_holder::~socket_holder(
      (boost::asio::detail::socket_holder *)v11,
      (unsigned int *)&FileHandle);
    return v12;
  }
  else
  {
    misc_category = boost::asio::error::get_misc_category();
    v8[1] = (unsigned int)misc_category;
    *(_DWORD *)&impl->state_ = misc_category;
    *v8 = 1;
    impl->socket_ = 1;
    return impl;
  }
}
