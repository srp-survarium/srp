int __cdecl boost::asio::detail::socket_ops::inet_pton(
        INT af,
        char *src,
        __int64 *dest,
        unsigned int *scope_id,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v5; // edx
  const boost::system::error_category *v7; // edx
  const boost::system::error_category *v8; // edx
  const boost::system::error_category *v9; // [esp+1Ch] [ebp-CCh]
  INT v10; // [esp+20h] [ebp-C8h]
  const boost::system::error_category *v11; // [esp+28h] [ebp-C0h]
  const boost::system::error_category *v12; // [esp+44h] [ebp-A4h]
  const boost::system::error_category *v13; // [esp+54h] [ebp-94h]
  boost::asio::detail::socket_ops::inet_pton::__l5::<unnamed_type_address> address; // [esp+60h] [ebp-88h] BYREF
  int address_length; // [esp+E0h] [ebp-8h] BYREF
  int result; // [esp+E4h] [ebp-4h]

  WSASetLastError(0);
  if ( af == 2 || af == 23 )
  {
    address_length = 128;
    v10 = WSAStringToAddressA(src, af, 0, &address.base, &address_length);
    v11 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v11;
    result = v10;
    if ( af == 2 )
    {
      if ( result == -1 )
      {
        if ( !strcmp(src, &stru_984D24.m_working_macro_list.m_buffer[1].m_store[364]) )
        {
          *(_DWORD *)dest = -1;
          v13 = boost::system::system_category();
          ec->m_val = 0;
          ec->m_cat = v13;
        }
      }
      else
      {
        *(_DWORD *)dest = address.v4.sin_addr.S_un.S_addr;
        v7 = boost::system::system_category();
        ec->m_val = 0;
        ec->m_cat = v7;
      }
    }
    else if ( result != -1 )
    {
      *dest = address.storage.__ss_align;
      dest[1] = *(_QWORD *)&address.v6.sin6_addr.u.Word[4];
      if ( scope_id )
        *scope_id = address.v6.sin6_scope_id;
      v8 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v8;
    }
    if ( result == -1 && !ec->m_val )
    {
      v9 = boost::system::system_category();
      ec->m_val = 10022;
      ec->m_cat = v9;
    }
    if ( result != -1 )
    {
      v12 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v12;
    }
    return 2 * (result != -1) - 1;
  }
  else
  {
    v5 = boost::system::system_category();
    ec->m_val = 10047;
    ec->m_cat = v5;
    return -1;
  }
}
