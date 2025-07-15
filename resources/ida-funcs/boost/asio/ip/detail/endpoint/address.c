boost::asio::ip::address *__userpurge boost::asio::ip::detail::endpoint::address@<eax>(
        boost::asio::ip::detail::endpoint *this@<ecx>,
        int a2@<eax>,
        boost::asio::ip::address *result)
{
  u_long v3; // eax
  in_addr::<unnamed_type_S_un> v4; // eax
  int v6; // [esp+0h] [ebp-1Ch]
  int v7; // [esp+4h] [ebp-18h]
  int v8; // [esp+8h] [ebp-14h]
  boost::asio::ip::address_v6 v9; // [esp+8h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-10h]

  if ( *(_WORD *)a2 == 2 )
  {
    v3 = ntohl(*(_DWORD *)(a2 + 4));
    v4.S_addr = ((int (__stdcall *)(u_long, int, int, int, int))(&off_8E3A98 + 10))(v3, v6, v7, v8, v10);
    result->type_ = ipv4;
    result->ipv4_address_.addr_.S_un = v4;
    *(_QWORD *)result->ipv6_address_.addr_.u.Byte = 0;
    *(_QWORD *)&result->ipv6_address_.addr_.u.Word[4] = 0;
    result->ipv6_address_.scope_id_ = 0;
  }
  else
  {
    v9.scope_id_ = *(_DWORD *)(a2 + 24);
    *(_QWORD *)v9.addr_.u.Byte = *(_QWORD *)(a2 + 8);
    *(_QWORD *)&v9.addr_.u.Word[4] = *(_QWORD *)(a2 + 16);
    result->type_ = ipv6;
    result->ipv4_address_.addr_.S_un.S_addr = 0;
    result->ipv6_address_ = v9;
  }
  return result;
}
