boost::system::error_code *__cdecl boost::asio::detail::socket_ops::translate_addrinfo_error(
        boost::system::error_code *result,
        int error)
{
  const boost::system::error_category *v3; // edx
  const boost::system::error_category *v4; // edx
  const boost::system::error_category *v5; // edx
  const boost::system::error_category *v6; // [esp+8h] [ebp-64h]
  const boost::system::error_category *v7; // [esp+14h] [ebp-58h]
  const boost::system::error_category *v8; // [esp+2Ch] [ebp-40h]
  const boost::system::error_category *v9; // [esp+38h] [ebp-34h]
  const boost::system::error_category *v10; // [esp+50h] [ebp-1Ch]
  const boost::system::error_category *v11; // [esp+5Ch] [ebp-10h]

  if ( error > 10047 )
  {
    if ( error > 11002 )
    {
      if ( error == 11003 )
      {
        v10 = boost::system::system_category();
        result->m_val = 11003;
        result->m_cat = v10;
        return result;
      }
    }
    else
    {
      switch ( error )
      {
        case 11002:
          v3 = boost::system::system_category();
          result->m_val = 11002;
          result->m_cat = v3;
          return result;
        case 10109:
          v5 = boost::system::system_category();
          result->m_val = 10109;
          result->m_cat = v5;
          return result;
        case 11001:
          v8 = boost::system::system_category();
          result->m_val = 11001;
          result->m_cat = v8;
          return result;
      }
    }
  }
  else
  {
    if ( error == 10047 )
    {
      v4 = boost::system::system_category();
      result->m_val = 10047;
      result->m_cat = v4;
      return result;
    }
    if ( error > 10022 )
    {
      if ( error == 10044 )
      {
        v7 = boost::system::system_category();
        result->m_val = 10044;
        result->m_cat = v7;
        return result;
      }
    }
    else
    {
      switch ( error )
      {
        case 10022:
          v11 = boost::system::system_category();
          result->m_val = 10022;
          result->m_cat = v11;
          return result;
        case 0:
          result->m_val = 0;
          result->m_cat = boost::system::system_category();
          return result;
        case 8:
          v9 = boost::system::system_category();
          result->m_val = 14;
          result->m_cat = v9;
          return result;
      }
    }
  }
  v6 = boost::system::system_category();
  result->m_val = WSAGetLastError();
  result->m_cat = v6;
  return result;
}
