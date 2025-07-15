int __cdecl boost::asio::detail::socket_ops::poll_connect(unsigned int s, boost::system::error_code *ec)
{
  const boost::system::error_category *v2; // edx
  const boost::system::error_category *v4; // edx
  int v5; // [esp+0h] [ebp-244h]
  const boost::system::error_category *v6; // [esp+8h] [ebp-23Ch]
  fd_set write_fds; // [esp+34h] [ebp-210h] BYREF
  fd_set except_fds; // [esp+13Ch] [ebp-108h] BYREF

  if ( s == -1 )
  {
    v2 = boost::system::system_category();
    ec->m_val = 10009;
    ec->m_cat = v2;
    return -1;
  }
  else
  {
    write_fds.fd_array[0] = s;
    write_fds.fd_count = 1;
    except_fds.fd_array[0] = s;
    except_fds.fd_count = 1;
    WSASetLastError(0);
    v5 = select(s, 0, &write_fds, &except_fds, 0);
    v6 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v6;
    if ( v5 >= 0 )
    {
      v4 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v4;
    }
    return v5;
  }
}
