void __userpurge boost::asio::detail::resolver_service_base::start_resolve_op(
        boost::asio::detail::resolver_service_base *this@<ecx>,
        int a2@<eax>,
        boost::asio::detail::win_iocp_operation *op)
{
  boost::asio::detail::win_thread *v4; // eax
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *v5; // ecx
  HANDLE *v6; // eax
  int v7; // esi
  boost::asio::detail::win_iocp_io_service *v8; // ecx
  boost::asio::detail::win_thread *v9; // [esp-4h] [ebp-14h]
  unsigned int v10; // [esp+0h] [ebp-10h]

  EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 4));
  if ( !*(_DWORD *)(a2 + 40) )
  {
    v4 = (boost::asio::detail::win_thread *)operator new(0xCu);
    v5 = (boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *)v9;
    if ( v4 )
      boost::asio::detail::win_thread::win_thread(
        v9,
        v4,
        *(boost::asio::detail::resolver_service_base::work_io_service_runner *)(a2 + 28),
        v10);
    else
      v6 = 0;
    boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(v5, (HANDLE **)(a2 + 40), v6);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 4));
  InterlockedIncrement((volatile LONG *)(*(_DWORD *)a2 + 24));
  v7 = *(_DWORD *)(a2 + 32);
  InterlockedIncrement((volatile LONG *)(v7 + 24));
  boost::asio::detail::win_iocp_io_service::post_deferred_completion(v8, v7, op);
}
