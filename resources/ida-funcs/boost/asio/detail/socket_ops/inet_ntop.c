char *__usercall boost::asio::detail::socket_ops::inet_ntop@<eax>(
        char *src@<eax>,
        int af,
        char *dest,
        unsigned int length,
        boost::system::error_code *scope_id)
{
  DWORD v7; // eax
  char *v8; // esi
  INT v9; // eax
  int v10; // edi
  int v11; // esi
  sockaddr saAddress; // [esp+10h] [ebp-88h] BYREF
  int v13; // [esp+20h] [ebp-78h]
  int v14; // [esp+24h] [ebp-74h]
  unsigned int v15; // [esp+28h] [ebp-70h]
  unsigned int dwAddressStringLength; // [esp+94h] [ebp-4h] BYREF

  WSASetLastError(0);
  if ( af == 2 )
  {
    v7 = 16;
    saAddress.sa_family = 2;
    *(_WORD *)saAddress.sa_data = 0;
    *(_DWORD *)&saAddress.sa_data[2] = *(_DWORD *)src;
  }
  else
  {
    if ( af != 23 )
    {
      scope_id->m_cat = boost::system::system_category();
      scope_id->m_val = 10047;
      return 0;
    }
    v7 = 28;
    saAddress.sa_family = 23;
    *(_DWORD *)&saAddress.sa_data[2] = 0;
    *(_WORD *)saAddress.sa_data = 0;
    v15 = length;
    *(_DWORD *)&saAddress.sa_data[6] = *(_DWORD *)src;
    v8 = src + 4;
    *(_DWORD *)&saAddress.sa_data[10] = *(_DWORD *)v8;
    v8 += 4;
    v13 = *(_DWORD *)v8;
    v14 = *((_DWORD *)v8 + 1);
  }
  dwAddressStringLength = 256;
  v9 = WSAAddressToStringA(&saAddress, v7, 0, dest, &dwAddressStringLength);
  v10 = boost::asio::detail::socket_ops::error_wrapper<int>(scope_id, v9);
  if ( v10 != -1 )
  {
    v11 = 0;
LABEL_10:
    scope_id->m_cat = boost::system::system_category();
    scope_id->m_val = v11;
    return v10 != -1 ? dest : 0;
  }
  if ( !scope_id->m_val )
  {
    v11 = 10022;
    goto LABEL_10;
  }
  return v10 != -1 ? dest : 0;
}
