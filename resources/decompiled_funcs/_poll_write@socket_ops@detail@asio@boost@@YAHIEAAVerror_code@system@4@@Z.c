int __cdecl boost::asio::detail::socket_ops::poll_write(
        unsigned int s,
        unsigned __int8 state,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v3; // edx
  const boost::system::error_category *v5; // eax
  int *v6; // [esp+0h] [ebp-168h]
  int v7; // [esp+10h] [ebp-158h]
  const boost::system::error_category *v8; // [esp+20h] [ebp-148h]
  const boost::system::error_category *v9; // [esp+34h] [ebp-134h]
  _DWORD v10[2]; // [esp+38h] [ebp-130h] BYREF
  _DWORD v11[3]; // [esp+40h] [ebp-128h] BYREF
  unsigned int __i; // [esp+4Ch] [ebp-11Ch]
  timeval *timeout; // [esp+50h] [ebp-118h]
  int result; // [esp+54h] [ebp-114h]
  timeval zero_timeout; // [esp+58h] [ebp-110h] BYREF
  fd_set fds; // [esp+60h] [ebp-108h] BYREF

  if ( s == -1 )
  {
    v3 = boost::system::system_category();
    ec->m_val = 10009;
    ec->m_cat = v3;
    return -1;
  }
  else
  {
    __i = 0;
    fds.fd_array[0] = s;
    fds.fd_count = 1;
    zero_timeout.tv_sec = 0;
    zero_timeout.tv_usec = 0;
    timeout = (state & 1) != 0 ? &zero_timeout : 0;
    WSASetLastError(0);
    v7 = select(s, 0, &fds, 0, timeout);
    v8 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v8;
    result = v7;
    if ( v7 )
    {
      if ( result > 0 )
      {
        v9 = boost::system::system_category();
        ec->m_val = 0;
        ec->m_cat = v9;
      }
    }
    else
    {
      if ( (state & 1) != 0 )
      {
        v11[0] = 10035;
        v11[1] = boost::system::system_category();
        v6 = v11;
      }
      else
      {
        v10[0] = 0;
        v10[1] = boost::system::system_category();
        v6 = v10;
      }
      v11[2] = v6;
      v5 = (const boost::system::error_category *)v6[1];
      ec->m_val = *v6;
      ec->m_cat = v5;
    }
    return result;
  }
}
