void __userpurge boost::asio::detail::select_reactor::cancel_ops_unlocked(
        boost::asio::detail::select_reactor *this@<ecx>,
        int a2@<eax>,
        stlp_std::priv::_List_node_base *descriptor,
        stlp_std::priv::_List_node_base *ec)
{
  char v5; // bl
  int v6; // esi
  boost::asio::detail::socket_select_interrupter *v7; // ecx
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+14h] [ebp-4h]

  v8.front_ = 0;
  v5 = 0;
  v8.back_ = 0;
  v6 = a2 + 56;
  v9 = 4;
  do
  {
    if ( boost::asio::detail::reactor_op_queue<unsigned int>::cancel_operations(
           (boost::asio::detail::reactor_op_queue<unsigned int> *)this,
           v6,
           (unsigned int)descriptor,
           &v8,
           ec)
      || v5 )
    {
      v5 = 1;
    }
    v6 += 28;
    --v9;
  }
  while ( v9 );
  boost::asio::detail::win_iocp_io_service::post_deferred_completions(
    (boost::asio::detail::win_iocp_io_service *)this,
    *(_DWORD *)(a2 + 20),
    &v8);
  if ( v5 )
    boost::asio::detail::socket_select_interrupter::interrupt(v7, a2 + 48);
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(
    (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)v7,
    (int *)&v8);
}
