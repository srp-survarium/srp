void __usercall boost::asio::detail::socket_select_interrupter::close_descriptors(
        boost::asio::detail::socket_select_interrupter *this@<ecx>,
        unsigned int *a2@<eax>)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  boost::system::error_code v5; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int8 v6; // [esp+Fh] [ebp-1h] BYREF

  v5.m_val = 0;
  v5.m_cat = boost::system::system_category();
  v3 = *a2;
  v6 = 2;
  if ( v3 != -1 )
    boost::asio::detail::socket_ops::close(&v5, v3, &v6, 1);
  v4 = a2[1];
  if ( v4 != -1 )
    boost::asio::detail::socket_ops::close(&v5, v4, &v6, 1);
}
