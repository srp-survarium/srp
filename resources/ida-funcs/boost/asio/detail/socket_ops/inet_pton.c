int __usercall boost::asio::detail::socket_ops::inet_pton@<eax>(
        INT af@<eax>,
        char *src,
        _DWORD *dest,
        unsigned int *scope_id,
        boost::system::error_code *ec)
{
  INT v7; // eax
  int v8; // eax
  const boost::system::error_category *v9; // eax
  bool v10; // zf
  const boost::system::error_category *v11; // eax
  const boost::system::error_category *v12; // eax
  sockaddr Address; // [esp+10h] [ebp-88h] BYREF
  int v14; // [esp+20h] [ebp-78h]
  int v15; // [esp+24h] [ebp-74h]
  unsigned int v16; // [esp+28h] [ebp-70h]
  int AddressLength; // [esp+90h] [ebp-8h] BYREF
  int v18; // [esp+94h] [ebp-4h]

  WSASetLastError(0);
  if ( af != 2 && af != 23 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 10047;
    return -1;
  }
  AddressLength = 128;
  v7 = WSAStringToAddressA(src, af, 0, &Address, &AddressLength);
  v8 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v7);
  v18 = v8;
  if ( af == 2 )
  {
    if ( v8 == -1 )
    {
      if ( strcmp(src, "255.255.255.255") )
        goto LABEL_13;
      *dest = -1;
    }
    else
    {
      *dest = *(_DWORD *)&Address.sa_data[2];
    }
  }
  else
  {
    if ( v8 == -1 )
      goto LABEL_13;
    *dest = *(_DWORD *)&Address.sa_data[6];
    dest[1] = *(_DWORD *)&Address.sa_data[10];
    dest[2] = v14;
    dest[3] = v15;
    if ( scope_id )
      *scope_id = v16;
  }
  v9 = boost::system::system_category();
  v10 = v18 == -1;
  ec->m_val = 0;
  ec->m_cat = v9;
  if ( v10 )
  {
LABEL_13:
    if ( !ec->m_val )
    {
      v11 = boost::system::system_category();
      ec->m_val = 10022;
      ec->m_cat = v11;
    }
    if ( v18 == -1 )
      return 2 * (v18 != -1) - 1;
  }
  v12 = boost::system::system_category();
  ec->m_val = 0;
  ec->m_cat = v12;
  return 2 * (v18 != -1) - 1;
}
