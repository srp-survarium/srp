boost::system::error_code *__usercall boost::asio::detail::socket_ops::translate_addrinfo_error@<eax>(
        int error@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  const struct boost::system::error_category *v4; // eax
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  const struct boost::system::error_category *v8; // edi

  v2 = 10047;
  if ( error > 10047 )
  {
    v2 = 10109;
    v5 = error - 10109;
    if ( v5 )
    {
      v6 = v5 - 892;
      if ( !v6 )
      {
        v3 = 11001;
        goto LABEL_20;
      }
      v7 = v6 - 1;
      if ( !v7 )
      {
        v3 = 11002;
        goto LABEL_20;
      }
      if ( v7 == 1 )
      {
        v3 = 11003;
        goto LABEL_20;
      }
      goto LABEL_15;
    }
LABEL_19:
    v3 = v2;
    goto LABEL_20;
  }
  switch ( error )
  {
    case 10047:
      goto LABEL_19;
    case 0:
      *a2 = 0;
      v4 = boost::system::system_category();
LABEL_21:
      a2[1] = (int)v4;
      return (boost::system::error_code *)a2;
    case 8:
      v3 = 14;
      goto LABEL_20;
    case 10022:
      v3 = 10022;
      goto LABEL_20;
    case 10044:
      v3 = 10044;
LABEL_20:
      v4 = boost::system::system_category();
      *a2 = v3;
      goto LABEL_21;
  }
LABEL_15:
  v8 = boost::system::system_category();
  *a2 = WSAGetLastError();
  a2[1] = (int)v8;
  return (boost::system::error_code *)a2;
}
