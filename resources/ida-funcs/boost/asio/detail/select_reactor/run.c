void __userpurge boost::asio::detail::select_reactor::run(
        boost::asio::detail::select_reactor *this@<ecx>,
        int a2@<eax>,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *block,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  _RTL_CRITICAL_SECTION *v5; // edi
  int v6; // eax
  int v7; // ecx
  boost::asio::detail::reactor_op_queue<unsigned int> *v8; // ecx
  _DWORD *i; // edi
  char v10; // al
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *v11; // edi
  _DWORD *v12; // ebx
  boost::asio::detail::reactor_op_queue<unsigned int> *v13; // ecx
  fd_set **v14; // edi
  _DWORD *v15; // ebx
  int v16; // eax
  boost::asio::detail::reactor_op_queue<unsigned int> *v17; // ecx
  boost::asio::detail::reactor_op_queue<unsigned int> *v18; // ecx
  boost::asio::detail::reactor_op_queue<unsigned int> *v19; // ecx
  const boost::asio::detail::win_fd_set_adapter *v20; // ebx
  _DWORD *j; // esi
  char v22; // [esp+10h] [ebp-42Ch] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+410h] [ebp-2Ch]
  boost::system::error_code v24; // [esp+418h] [ebp-24h] BYREF
  timeval v25; // [esp+420h] [ebp-1Ch] BYREF
  _WSABUF v26; // [esp+428h] [ebp-14h] BYREF
  bool v27; // [esp+433h] [ebp-9h]
  int front; // [esp+434h] [ebp-8h]

  v5 = (_RTL_CRITICAL_SECTION *)(a2 + 24);
  lpCriticalSection = (LPCRITICAL_SECTION)(a2 + 24);
  EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 24));
  if ( *(_BYTE *)(a2 + 208) )
  {
    LeaveCriticalSection(v5);
  }
  else
  {
    v6 = a2 + 168;
    v7 = 3;
    do
    {
      **(_DWORD **)v6 = 0;
      *(_DWORD *)(v6 + 8) = -1;
      v6 += 12;
      --v7;
    }
    while ( v7 );
    boost::asio::detail::win_fd_set_adapter::set(0, (unsigned int **)(a2 + 168), *(_DWORD *)(a2 + 48));
    front = 0;
    for ( i = *(_DWORD **)(a2 + 204); ; i = (_DWORD *)i[1] )
    {
      if ( !i )
      {
        v10 = 1;
        goto LABEL_10;
      }
      if ( !(*(unsigned __int8 (__thiscall **)(_DWORD *))(*i + 4))(i) )
        break;
    }
    v10 = 0;
LABEL_10:
    v27 = v10 == 0;
    v11 = (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)(a2 + 176);
    v12 = (_DWORD *)(a2 + 60);
    v26.buf = (char *)3;
    do
    {
      if ( v27 || (v27 = 0, (_DWORD *)*v12 != v12) )
        v27 = 1;
      boost::asio::detail::reactor_op_queue<unsigned int>::get_descriptors<boost::asio::detail::win_fd_set_adapter>(
        v8,
        (boost::asio::detail::win_fd_set_adapter *)(v12 - 1),
        v11 - 1,
        block);
      if ( v11->front_ > (boost::asio::detail::win_iocp_operation *)front )
        front = (int)v11->front_;
      v12 += 7;
      v11 = (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)((char *)v11 + 12);
      --v26.buf;
    }
    while ( v26.buf );
    boost::asio::detail::reactor_op_queue<unsigned int>::get_descriptors<boost::asio::detail::win_fd_set_adapter>(
      v8,
      (boost::asio::detail::win_fd_set_adapter *)(a2 + 140),
      (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)(a2 + 180),
      block);
    if ( *(_DWORD *)(a2 + 188) > (unsigned int)front )
      front = *(_DWORD *)(a2 + 188);
    v14 = (fd_set **)(a2 + 192);
    boost::asio::detail::reactor_op_queue<unsigned int>::get_descriptors<boost::asio::detail::win_fd_set_adapter>(
      v13,
      (boost::asio::detail::win_fd_set_adapter *)(a2 + 140),
      (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)(a2 + 192),
      block);
    if ( *(_DWORD *)(a2 + 200) > (unsigned int)front )
      front = *(_DWORD *)(a2 + 200);
    v25.tv_sec = 0;
    v25.tv_usec = 0;
    v15 = *(_DWORD **)(a2 + 204);
    v16 = 300000000;
    while ( v15 )
    {
      v16 = (*(int (__thiscall **)(_DWORD *, int))(*v15 + 12))(v15, v16);
      v15 = (_DWORD *)v15[1];
    }
    v25.tv_sec = v16 / (int)&loc_F4240;
    v25.tv_usec = v16 % (int)&loc_F4240;
    LeaveCriticalSection(lpCriticalSection);
    boost::system::system_category();
    front = boost::asio::detail::socket_ops::select(
              &v25,
              &v24,
              front + 1,
              *(fd_set **)(a2 + 168),
              *(fd_set **)(a2 + 180),
              *v14);
    if ( front > 0 && __WSAFDIsSet(*(_DWORD *)(a2 + 48), *(fd_set **)(a2 + 168)) )
    {
      v24.m_val = 0;
      v26.buf = &v22;
      v26.len = 1024;
      v24.m_cat = boost::system::system_category();
      while ( boost::asio::detail::socket_ops::recv(&v24, *(_DWORD *)(a2 + 48), &v26) == 1024 )
        ;
      --front;
    }
    EnterCriticalSection(lpCriticalSection);
    if ( front > 0 )
    {
      boost::asio::detail::reactor_op_queue<unsigned int>::perform_operations_for_descriptors<boost::asio::detail::win_fd_set_adapter>(
        v17,
        (const boost::asio::detail::win_fd_set_adapter *)(a2 + 140),
        (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)(a2 + 192),
        block);
      boost::asio::detail::reactor_op_queue<unsigned int>::perform_operations_for_descriptors<boost::asio::detail::win_fd_set_adapter>(
        v18,
        (const boost::asio::detail::win_fd_set_adapter *)(a2 + 140),
        (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)(a2 + 180),
        block);
      front = 2;
      v20 = (const boost::asio::detail::win_fd_set_adapter *)(a2 + 112);
      do
      {
        boost::asio::detail::reactor_op_queue<unsigned int>::perform_operations_for_descriptors<boost::asio::detail::win_fd_set_adapter>(
          v19,
          v20,
          (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)v14,
          block);
        --front;
        v14 -= 3;
        v20 = (const boost::asio::detail::win_fd_set_adapter *)((char *)v20 - 28);
      }
      while ( front >= 0 );
    }
    for ( j = *(_DWORD **)(a2 + 204); j; j = (_DWORD *)j[1] )
      (*(void (__thiscall **)(_DWORD *, boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *))(*j + 16))(
        j,
        block);
    LeaveCriticalSection(lpCriticalSection);
  }
}
