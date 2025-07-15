void __usercall boost::asio::detail::op_queue<boost::asio::detail::timer_op>::~op_queue<boost::asio::detail::timer_op>(
        boost::asio::detail::op_queue<boost::asio::detail::timer_op> *this@<ecx>,
        int *a2@<edi>)
{
  boost::asio::detail::win_iocp_operation *v2; // ecx
  int v3; // eax
  int v4; // esi

  while ( 1 )
  {
    v4 = *a2;
    if ( !*a2 )
      break;
    v2 = (boost::asio::detail::win_iocp_operation *)*a2;
    v3 = *(_DWORD *)(*a2 + 20);
    *a2 = v3;
    if ( !v3 )
      a2[1] = 0;
    v2->next_ = 0;
    boost::asio::detail::win_iocp_operation::destroy(v2, v4);
  }
}


void __usercall boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *this@<ecx>,
        int *a2@<edi>)
{
  boost::asio::detail::win_iocp_operation *v2; // ecx
  int v3; // esi

  while ( 1 )
  {
    v3 = *a2;
    if ( !*a2 )
      break;
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::pop(this, a2);
    boost::asio::detail::win_iocp_operation::destroy(v2, v3);
  }
}
