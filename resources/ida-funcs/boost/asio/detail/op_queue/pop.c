void __fastcall boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::pop(
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *this,
        int *a2)
{
  int v2; // ecx
  int v3; // eax

  v2 = *a2;
  if ( *a2 )
  {
    v3 = *(_DWORD *)(v2 + 20);
    *a2 = v3;
    if ( !v3 )
      a2[1] = 0;
    *(_DWORD *)(v2 + 20) = 0;
  }
}
