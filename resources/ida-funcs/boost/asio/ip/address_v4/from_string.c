boost::asio::ip::address_v4 *__cdecl boost::asio::ip::address_v4::from_string(
        boost::asio::ip::address_v4 *result,
        char *str,
        boost::system::error_code *ec)
{
  INT v3; // eax
  const boost::system::error_category *v4; // eax
  bool v5; // zf
  int v6; // esi
  boost::asio::ip::address_v4 *v7; // eax
  sockaddr Address; // [esp+10h] [ebp-94h] BYREF
  int AddressLength; // [esp+94h] [ebp-10h] BYREF
  int v10; // [esp+98h] [ebp-Ch]
  in_addr::<unnamed_type_S_un> v11; // [esp+9Ch] [ebp-8h]

  v11.S_addr = 0;
  WSASetLastError(0);
  AddressLength = 128;
  v3 = WSAStringToAddressA(str, 2, 0, &Address, &AddressLength);
  v10 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v3);
  if ( v10 == -1 )
  {
    if ( strcmp(str, "255.255.255.255") )
      goto LABEL_6;
    v11.S_addr = -1;
  }
  else
  {
    v11 = *(in_addr::<unnamed_type_S_un> *)&Address.sa_data[2];
  }
  v4 = boost::system::system_category();
  v5 = v10 == -1;
  ec->m_cat = v4;
  ec->m_val = 0;
  if ( !v5 )
  {
    v6 = 0;
    goto LABEL_9;
  }
LABEL_6:
  if ( ec->m_val )
    goto LABEL_10;
  v6 = 10022;
LABEL_9:
  ec->m_cat = boost::system::system_category();
  ec->m_val = v6;
LABEL_10:
  v7 = result;
  if ( 2 * (v10 != -1) - 1 > 0 )
    *result = (boost::asio::ip::address_v4)v11;
  else
    result->addr_.S_un.S_addr = 0;
  return v7;
}
