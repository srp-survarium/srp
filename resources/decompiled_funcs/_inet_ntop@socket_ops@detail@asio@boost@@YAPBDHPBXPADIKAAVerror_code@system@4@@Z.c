char *__cdecl boost::asio::detail::socket_ops::inet_ntop(
        int af,
        in_addr::<unnamed_type_S_un> *src,
        char *dest,
        unsigned int length,
        unsigned int scope_id,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v6; // edx
  const boost::system::error_category *v8; // edx
  const boost::system::error_category *v9; // [esp+8h] [ebp-BCh]
  INT v10; // [esp+Ch] [ebp-B8h]
  const boost::system::error_category *v11; // [esp+1Ch] [ebp-A8h]
  boost::asio::detail::socket_ops::inet_ntop::__l5::<unnamed_type_address> address; // [esp+34h] [ebp-90h] BYREF
  unsigned int address_length; // [esp+B8h] [ebp-Ch]
  int result; // [esp+BCh] [ebp-8h]
  unsigned int string_length; // [esp+C0h] [ebp-4h] BYREF

  WSASetLastError(0);
  if ( af == 2 || af == 23 )
  {
    if ( af == 2 )
    {
      address_length = 16;
      *(_DWORD *)&address.base.sa_family = 2;
      address.v4.sin_addr.S_un = *src;
    }
    else
    {
      address_length = 28;
      *(_QWORD *)&address.base.sa_family = 23;
      address.v6.sin6_scope_id = scope_id;
      address.storage.__ss_align = *(_QWORD *)&src->S_un_b.s_b1;
      *(_QWORD *)&address.v6.sin6_addr.u.Word[4] = *(_QWORD *)&src[2].S_un_b.s_b1;
    }
    string_length = length;
    v10 = WSAAddressToStringA(&address.base, address_length, 0, dest, &string_length);
    v11 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v11;
    result = v10;
    if ( v10 == -1 )
    {
      if ( !ec->m_val )
      {
        v9 = boost::system::system_category();
        ec->m_val = 10022;
        ec->m_cat = v9;
      }
    }
    else
    {
      v8 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v8;
    }
    return result != -1 ? dest : 0;
  }
  else
  {
    v6 = boost::system::system_category();
    ec->m_val = 10047;
    ec->m_cat = v6;
    return 0;
  }
}
