int __cdecl boost::asio::detail::socket_ops::getsockopt(
        SOCKET s,
        unsigned __int8 state,
        int level,
        int optname,
        char *optval,
        unsigned int *optlen,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v7; // eax
  const boost::system::error_category *v9; // eax
  const boost::system::error_category *v10; // eax
  const boost::system::error_category *v11; // eax
  const boost::system::error_category *v12; // eax
  const boost::system::error_category *v13; // eax
  const boost::system::error_category *v14; // [esp+10h] [ebp-4Ch]
  int v15; // [esp+14h] [ebp-48h] BYREF
  int v16; // [esp+18h] [ebp-44h]
  const boost::system::error_category *v17; // [esp+1Ch] [ebp-40h]
  int v18; // [esp+20h] [ebp-3Ch]
  const boost::system::error_category *v19; // [esp+24h] [ebp-38h]
  const boost::system::error_category *v20; // [esp+28h] [ebp-34h]
  int v21; // [esp+2Ch] [ebp-30h]
  const boost::system::error_category *v22; // [esp+30h] [ebp-2Ch]
  const boost::system::error_category *v23; // [esp+34h] [ebp-28h]
  int v24; // [esp+38h] [ebp-24h]
  const boost::system::error_category *v25; // [esp+3Ch] [ebp-20h]
  int v26; // [esp+40h] [ebp-1Ch]
  const boost::system::error_category *v27; // [esp+44h] [ebp-18h]
  int v28; // [esp+48h] [ebp-14h]
  const boost::system::error_category *v29; // [esp+4Ch] [ebp-10h]
  const boost::system::error_category *v30; // [esp+54h] [ebp-8h]
  int result; // [esp+58h] [ebp-4h]

  if ( s == -1 )
  {
    v7 = boost::system::system_category();
    v23 = v7;
    v24 = 10009;
    v25 = v7;
    ec->m_val = 10009;
    ec->m_cat = v7;
    return -1;
  }
  else if ( level == -1525678080 && optname == 2 )
  {
    v9 = boost::system::system_category();
    v20 = v9;
    v21 = 10022;
    v22 = v9;
    ec->m_val = 10022;
    ec->m_cat = v9;
    return -1;
  }
  else if ( level == -1525678080 && optname == 1 )
  {
    if ( *optlen == 4 )
    {
      *(_DWORD *)optval = (state & 4) != 0;
      v11 = boost::system::system_category();
      v30 = v11;
      ec->m_val = 0;
      ec->m_cat = v11;
      return 0;
    }
    else
    {
      v10 = boost::system::system_category();
      v17 = v10;
      v18 = 10022;
      v19 = v10;
      ec->m_val = 10022;
      ec->m_cat = v10;
      return -1;
    }
  }
  else
  {
    WSASetLastError(0);
    v15 = *optlen;
    v16 = getsockopt(s, level, optname, optval, &v15);
    *optlen = v15;
    v14 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v14;
    result = v16;
    if ( v16 && level == 41 && optname == 27 && ec->m_val == 10042 && *optlen == 4 )
    {
      *(_DWORD *)optval = 1;
      v28 = 0;
      v12 = boost::system::system_category();
      v29 = v12;
      ec->m_val = v28;
      ec->m_cat = v12;
    }
    if ( !result )
    {
      v26 = 0;
      v13 = boost::system::system_category();
      v27 = v13;
      ec->m_val = v26;
      ec->m_cat = v13;
    }
    return result;
  }
}
