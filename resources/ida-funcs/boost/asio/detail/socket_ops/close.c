int __usercall boost::asio::detail::socket_ops::close@<eax>(
        boost::system::error_code *ec@<eax>,
        unsigned int s,
        unsigned __int8 *state,
        bool destruction)
{
  int v5; // eax
  int v6; // eax
  const boost::system::error_category *v7; // eax
  int v9; // [esp+0h] [ebp-1Ch]
  int v10; // [esp+0h] [ebp-1Ch]
  int v11; // [esp+0h] [ebp-1Ch]
  int v12; // [esp+4h] [ebp-18h]
  int v13; // [esp+4h] [ebp-18h]
  int v14; // [esp+4h] [ebp-18h]
  int v15; // [esp+8h] [ebp-14h]
  int v16; // [esp+8h] [ebp-14h]
  boost::system::error_code v17; // [esp+Ch] [ebp-10h] BYREF
  _DWORD v18[2]; // [esp+14h] [ebp-8h] BYREF

  v18[0] = 0;
  if ( s == -1 )
    goto LABEL_12;
  if ( destruction && (*state & 8) != 0 )
  {
    v18[0] = 0;
    boost::system::system_category();
    boost::asio::detail::socket_ops::setsockopt(state, &v17, s, 0xFFFF, 128, v18, 4u);
  }
  WSASetLastError(0);
  v5 = ((int (__stdcall *)(unsigned int, int, int, int, int))(&off_8E3A98 + 23))(s, v9, v12, v15, v17.m_val);
  v18[0] = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v5);
  if ( !v18[0] )
    goto LABEL_12;
  if ( ec->m_cat == boost::system::system_category() && ec->m_val == 10035
    || ec->m_cat == boost::system::system_category() && ec->m_val == 1237 )
  {
    v18[0] = 0;
    ((void (__stdcall *)(unsigned int, int, _DWORD *, int, int))(&off_8E3A98 + 22))(s, -2147195266, v18, v10, v13);
    *state &= 0xFCu;
    WSASetLastError(0);
    v6 = ((int (__stdcall *)(unsigned int, int, int, int, int))(&off_8E3A98 + 23))(s, v11, v14, v16, v17.m_val);
    v18[0] = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v6);
  }
  if ( !v18[0] )
  {
LABEL_12:
    v7 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v7;
  }
  return v18[0];
}
