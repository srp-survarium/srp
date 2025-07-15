unsigned int __userpurge boost::asio::detail::win_iocp_io_service::do_one@<eax>(
        boost::asio::detail::win_iocp_io_service *this@<ecx>,
        int a2@<eax>,
        bool block,
        boost::system::error_code *ec)
{
  boost::system::error_code *v4; // ebx
  DWORD v5; // edi
  boost::asio::detail::win_iocp_io_service *v7; // ecx
  _DWORD *j; // edi
  boost::asio::detail::win_iocp_io_service *v9; // ecx
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *v10; // ecx
  DWORD LastError; // eax
  LPOVERLAPPED v12; // edi
  const struct boost::system::error_category *v13; // eax
  unsigned int Internal; // ecx
  DWORD v15; // esi
  const struct boost::system::error_category *v16; // eax
  boost::asio::detail::win_iocp_io_service *v18; // ecx
  unsigned int Offset; // [esp+Ch] [ebp-24h] BYREF
  const struct boost::system::error_category *v20; // [esp+10h] [ebp-20h]
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> v21; // [esp+14h] [ebp-1Ch] BYREF
  BOOL QueuedCompletionStatus; // [esp+1Ch] [ebp-14h]
  DWORD v23; // [esp+20h] [ebp-10h]
  DWORD i; // [esp+24h] [ebp-Ch]
  unsigned int CompletionKey; // [esp+28h] [ebp-8h] BYREF
  LPOVERLAPPED Overlapped; // [esp+2Ch] [ebp-4h] BYREF

  v4 = ec;
  v5 = block ? 0x1F4 : 0;
  for ( i = v5; ; v5 = i )
  {
    while ( 1 )
    {
      if ( InterlockedCompareExchange((volatile LONG *)(a2 + 44), 0, 1) == 1 )
      {
        EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 48));
        v21.front_ = 0;
        v21.back_ = 0;
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::push<boost::asio::detail::win_iocp_operation>(
          &v21,
          (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)(a2 + 76));
        for ( j = *(_DWORD **)(a2 + 72); j; j = (_DWORD *)j[1] )
          (*(void (__thiscall **)(_DWORD *, boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *))(*j + 16))(
            j,
            &v21);
        boost::asio::detail::win_iocp_io_service::post_deferred_completions(v7, a2, &v21);
        boost::asio::detail::win_iocp_io_service::update_timeout(v9, a2);
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(
          v10,
          (int *)&v21);
        LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 48));
        v5 = i;
      }
      ec = 0;
      CompletionKey = 0;
      Overlapped = 0;
      SetLastError(0);
      QueuedCompletionStatus = GetQueuedCompletionStatus(
                                 *(HANDLE *)(a2 + 20),
                                 (LPDWORD)&ec,
                                 &CompletionKey,
                                 &Overlapped,
                                 v5);
      LastError = GetLastError();
      v23 = LastError;
      if ( Overlapped )
        break;
      if ( QueuedCompletionStatus )
      {
        if ( CompletionKey != 1 && InterlockedExchangeAdd((volatile LONG *)(a2 + 28), 0) )
        {
          if ( PostQueuedCompletionStatus(*(HANDLE *)(a2 + 20), 0, 0, 0) )
LABEL_16:
            v15 = 0;
          else
            v15 = GetLastError();
          v16 = boost::system::system_category();
          v4->m_val = v15;
LABEL_18:
          v4->m_cat = v16;
          return 0;
        }
      }
      else
      {
        if ( LastError != 258 )
        {
          v16 = boost::system::system_category();
          v4->m_val = v23;
          goto LABEL_18;
        }
        if ( !block )
          goto LABEL_16;
      }
    }
    v12 = Overlapped;
    v13 = boost::system::system_category();
    Offset = v23;
    v20 = v13;
    if ( CompletionKey == 2 )
    {
      Internal = v12->Internal;
      Offset = v12->Offset;
      v20 = (const struct boost::system::error_category *)Internal;
      ec = (boost::system::error_code *)v12->OffsetHigh;
    }
    else
    {
      v12->Internal = (unsigned int)v13;
      v12->Offset = Offset;
      v12->OffsetHigh = (unsigned int)ec;
    }
    if ( InterlockedCompareExchange((volatile LONG *)&v12[1].8, 1, 0) == 1 )
      break;
  }
  ((void (__cdecl *)(int, LPOVERLAPPED, unsigned int *, boost::system::error_code *))v12[1].InternalHigh)(
    a2,
    v12,
    &Offset,
    ec);
  v4->m_cat = boost::system::system_category();
  v4->m_val = 0;
  if ( !InterlockedDecrement((volatile LONG *)(a2 + 24)) )
    boost::asio::detail::win_iocp_io_service::stop(v18, a2);
  return 1;
}
